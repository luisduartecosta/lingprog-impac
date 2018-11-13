package IMPAC;

use 5.026001;
use strict;
use warnings;

require Exporter;

our @ISA = qw(Exporter);

# Items to export into callers namespace by default. Note: do not export
# names by default without a very good reason. Use EXPORT_OK instead.
# Do not simply export all your public functions/methods/constants.

# This allows declaration	use IMPAC ':all';
# If you do not need this, moving things directly into @EXPORT or @EXPORT_OK
# will save memory.
our %EXPORT_TAGS = ( 'all' => [ qw(
	
) ] );

our @EXPORT_OK = ( @{ $EXPORT_TAGS{'all'} } );

our @EXPORT = qw(
  getLines
  removeEmptyLines
  getHeaderData
  getSensorsData
  verifyIntegrity
  moveFile
  checkPlant
);

our $VERSION = '0.01';

# Sub rotina para ler todas as linhas de um arquivo.
# Esta rotina recebe um nome de arquivo e retorna um array com as todas as linhas.
# uso: @array = getLines ($nome_arquivo)
sub getLines {
    my @array;
    
    open (my $in, "<", "../$_[0]") or die "Error: Can't open file: $!";
    @array = <$in>;
    close $in or die "Can't close file: $!";

    return @array;
}

# Sub rotina para limpar as linhas sem dados.
# Busca facilitar a coleta de dados dos sensores.
# Uso : @array = removeEmptyLines (@array_original)
sub removeEmptyLines {
    my @arrayFull = getlines($_[0]);
    my @arrayClean;

    foreach my $line (0 .. $#arrayFull) {
        unless ($arrayFull[$line] =~ /^[\s-]/) { #or $arrayFull[$i] =~ /^-/) {
            push @arrayClean, $arrayFull[$line];
        }
    }

    return @arrayClean;
}

# Sub rotina para recupear os dados de identificação do alarme.
# Recebe um array como argumento e retorna um hash, onde as chaves são os parametros desejados.
# Uso : %hash = getHeaderDdata (@array).
sub getHeaderData {
    my @array = removeEmptyLines(getlines($_[0]));
    # my %hash;
    my @retArray;

    if ($array[0] =~ /(\S+)\s(\S+\s[A,P]M)\s/) {
        # $hash{'date'} = $1;
        # $hash{'time'} = $2;
        $retArray[0] = $1;
        $retArray[1] = $2;
    }

    if ($array[0] =~ /from\s(\S+)\sat\s(\S+)\s/) {
        # $hash{'type'} = $1;
        # $hash{'plantName'} = $2;
        $retArray[2] = $1;
        $retArray[3] = $2;
    }

    if ($array[$#array] =~ /=\s(\S+\.X[3,4])\s/) {
        # $hash{'fileName'} = $1;
        $retArray[4] = $1;
    }

    if ($array[$#array] =~ /Protocol=(\S+),/) {
        # $hash{'protocol'} = $1;
        $retArray[5] = $1;
    }

    if ($array[$#array] =~ /\sTotal\sAlarms\s=\s(\S+)/) {
        # $hash{'totalAlarms'} = $1;
        $retArray[6] = $1;
    }

    #print do array a ser passado para c++
    print "\nValor de retArray: ", @retArray;
    
    return @retArray;
}

# Sub rotina para verificar se o nome da planta de origem é o mesmo do emissor do alarme.
# Esta rotina compara duas strings, onde a primera deve ser o nome da planta e a segunda o nome do arquivo.
# Uso : checkPlant ($planta, $nome_arquivo)
# 1 : São iguais
# 0 : São Diferentes
sub checkPlant {    
    if ($_[1] =~ /^($_[0])/) {
        return 1;
    }
    else {
        return 0;
    }
}

# Sub rotina para verificar a integridade do arquivo.
# Buscando por caracteres especiais, oriundos de falhas na comunicação.
# Retorna o número de caracteres com erro.
# Uso : $qtd_erros = verifyIntegrity (@array)
sub verifyIntegrity {
    my @array = getlines($_[0]);
    my $errors = 0;

    foreach my $line (0 .. $#array) {
        if ($array[$line] =~ /[!@\$%¨&\*\?\^~]/) {
            ++$errors;
        }
    }
    return $errors;
}

# Sub rotina para recuperar os dados de sensores.
# utiliza a função removeEmptyLines para facilitar a extração
# Recebe um array e retorna um array de hashes.
# Uso : @array_hashes = getSensorsData (@array)
sub getSensorsData {
    my @array = removeEmptyLines(getlines($_[0]));
    my %hash;
    my @arrayOfHash;

    foreach my $line (1 .. $#array-1) {
        if($array[$line] =~ /(\d{1,2}:\d{2}:\d{2}.\d)\s+(\S+)\s+(\S+)\s+(\S+)\s+([\w\s:\/]+)/) {
            $hash{'time'} = $1;
            $hash{'sensor'} = $2;
            $hash{'status'} = $3;
            $hash{'level'} = $4;
            $hash{'obs'} = $5; 
        }
        push @arrayOfHash, %hash;
    }

    return @arrayOfHash;
}

# Sub rotina para mover um arquivo já lido para uma pasta de archive.
# Visa impedir que um arquivo seja lido mais de uma vez.
# Uso : moveFile($nome_arquivo)
sub moveFile {
    my @lines = getLines($_[0]);

    open (my $in, '>',  "../archive/$_[0]") or die "Error: Can't create file: $!";
    print $in @lines;
    close $in or die "Can't close file: $!";
    unlink $_[0];
}

__END__
# Below is stub documentation for your module. You'd better edit it!

=head1 NAME

IMPAC - Perl extension for IMPAC Application for monitoring.

=head1 SYNOPSIS

  use IMPAC;
  blah blah blah

=head1 DESCRIPTION

Stub documentation for IMPAC, created by h2xs. It looks like the
author of the extension was negligent enough to leave the stub
unedited.

Blah blah blah.

=head2 EXPORT

None by default.



=head1 SEE ALSO

Mention other useful documentation such as the documentation of
related modules or operating system documentation (such as man pages
in UNIX), or any relevant external documentation such as RFCs or
standards.

If you have a mailing list set up for your module, mention it here.

If you have a web site set up for your module, mention it here.

=head1 AUTHOR

A. U. Thor, E<lt>luisduartecosta@E<gt>

=head1 COPYRIGHT AND LICENSE

Copyright (C) 2018 by A. U. Thor

This library is free software; you can redistribute it and/or modify
it under the same terms as Perl itself, either Perl version 5.26.1 or,
at your option, any later version of Perl 5 you may have available.


=cut
