
use strict;
use warnings;

# Sub rotina para ler todas as linhas de um arquivo.
# Esta rotina recebe um nome de arquivo e retorna um array com as todas as linhas.
# uso: @array = getLines ($nome_arquivo)

sub getLines {
    my @array;
    
    open (my $in, "<", "./alarms/$_[0]") or die "Error: Can't open file: $!";
    @array = <$in>;
    close $in or die "Can't close file: $!";

    #print "getLines ->";
    return @array;
}

# Sub rotina para limpar as linhas sem dados.
# Busca facilitar a coleta de dados dos sensores.
# Uso : @array = removeEmptyLines (@array_original)
sub removeEmptyLines {
    my @arrayFull = @_;
    my @arrayClean;

    foreach my $line (0 .. $#arrayFull) {
        unless ($arrayFull[$line] =~ /^[\s-]/) { #or $arrayFull[$i] =~ /^-/) {
            push @arrayClean, $arrayFull[$line];
        }
    }

    #print "removeEmptyLines ->";
    return @arrayClean;
}

# Sub rotina para recupear os dados de identificação do alarme.
# Recebe um array como argumento e retorna um hash, onde as chaves são os parametros desejados.
# Uso : %hash = getHeaderDdata (@array).
sub getHeaderData {
    my @array = removeEmptyLines(getLines($_[0]));
    my @header;

    if ($array[0] =~ /(\S+)\s(\S+\s[A,P]M)\s/) {
        $header[0] = $1;
        $header[1] = $2;
    }

    if ($array[0] =~ /from\s(\S+)\sat\s(\S+)\s/) {
        $header[2] = $1;
        $header[3] = $2;
    }

    if ($array[$#array] =~ /=\s(\S+\.X[3,4])\s/) {
        $header[4] = $1;
    }

    if ($array[$#array] =~ /Protocol=(\S+),/) {
        $header[5] = $1;
    }

    if ($array[$#array] =~ /\sTotal\sAlarms\s=\s(\S+)/) {
        $header[6] = $1;
    }
    
    #print "getHeaderData ->"; 
    return @header;
}


# Sub rotina para verificar se o nome da planta de origem é o mesmo do emissor do alarme.
# Esta rotina compara duas strings, onde a primera deve ser o nome da planta e a segunda o nome do arquivo.
# Uso : checkPlant ($planta, $nome_arquivo)
# 1 : São iguais
# 0 : São Diferentes
sub checkPlant {
    #print "--",$_[1],"--",$_[0],"--  -> correto eh achar ";   

    if ($_[1] =~ /^($_[0])/) 
    {
        print $_[1];
        return 1;
    }
    else {
        print $_[0];
        return 0;
    }
}

# Sub rotina para verificar a integridade do arquivo.
# Buscando por caracteres especiais, oriundos de falhas na comunicação.
# Retorna o número de caracteres com erro.
# Uso : $qtd_erros = verifyIntegrity (@array)
sub verifyIntegrity {
    my @array = getLines($_[0]);
    my $errors = 0;

    foreach my $line (0 .. $#array) {
        if ($array[$line] =~ /[!@\$%¨&\*\?\^~]/) {
            ++$errors;
            print "\nqtd de erros", $errors;
        }
    }
    #print "verifyIntegrity ->";
    return $errors;
}

# Sub rotina para recuperar os dados de sensores.
# utiliza a função removeEmptyLines para facilitar a extração
# Recebe um array e retorna um array de hashes.
# Uso : @array_hashes = getSensorsData (@array)
sub getSensorsData {
    my @array = removeEmptyLines(getLines($_[0]));
    my @sensor;
    my @arrayOfSensors;

    foreach my $line (1 .. $#array-1) {
        if($array[$line] =~ /(\d{1,2}:\d{2}:\d{2}.\d)\s+(\S+)\s+(\S+)\s+(\S+)\s+([\w\s:#\d\/]+)/) {
            # $sensor{'time'} = $1;
            # $sensor{'sensor'} = $2;
            # $sensor{'status'} = $3;
            # $sensor{'level'} = $4;
            # $sensor{'obs'} = $5; 
            $sensor[0] = $1;
            $sensor[1] = $2;
            $sensor[2] = $3;
            $sensor[3] = $4;
            $sensor[4] = $5; 
        }
        push @arrayOfSensors, @sensor;
    }
    #print "getSensorData ->";
    return @arrayOfSensors;
}

# Sub rotina para mover um arquivo já lido para uma pasta de archive.
# Visa impedir que um arquivo seja lido mais de uma vez.
# Uso : moveFile($nome_arquivo)
sub moveFile {
    my @lines = getLines($_[0]);

    open (my $in, '>',  "./archive/$_[0]") or die "Error: Can't create file: $!";
    print $in @lines;
    close $in or die "Can't close file: $!";
    unlink $_[0];
    print "moveFile";
}
