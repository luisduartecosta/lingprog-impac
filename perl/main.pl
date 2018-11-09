use warnings;
use strict;
use IMPAC;

my $fileName;
my @lines;
my %header;
my @sensors;
my $verified = 0;
my $ans = 0;

print "Entre com o nome do arquivo: ";
$fileName = <STDIN>;
chomp $fileName;

print "\nFunção 1 - Ler Arquivo de Texto\n\n";
@lines = getLines ($fileName);
print "@lines\n\n";

print "Função 2 - Verificando a integridade do arquivo...\n";
unless (my $errors = verifyIntegrity (@lines)) {
    print "\tErros: $errors\n";
    print "Verificação completa! Arquivo sem falhas.\n";
    

    print "\nFunção 3 - Capturando dados do alarme...\n";
    %header = getHeaderData (@lines);
    foreach my $key (sort keys %header) {
        print "\tCampo: $key - $header{$key}\n";
    }

    print "\n Função 4 - Validando origem da planta...\n";
    if (checkPlant($header{plantName}, $header{fileName})) {
        print "\tPlanta validada!\n";

        print "\nFunção 5 - Obtendo dados dos sensores...\n";
        @sensors = getSensorsData(@lines);
        print "@sensors\n";

        print "\nFunção 6 - Movendo o arquivo...\n";
        moveFile($fileName);
        print "\tArquivo movido para pasta 'archive'\n";

        $verified = 1;

    }
    else {
        print "Erro: Planta não condiz com o emissor do alarme.\n";
    }
}
else {
    print "Erro: Arquivo corrompido.\n";
}


