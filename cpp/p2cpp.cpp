#include "p2cpp.h" 

P2CPP::P2CPP() {
    PERL_SYS_INIT3(NULL, NULL, NULL); //macro de inicio

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
};

P2CPP::~P2CPP() {
    cout << "ENTROU NO DESTRUTOR DE P2CPP" << endl;
    perl_destruct (my_perl);
    perl_free (my_perl);
    PERL_SYS_TERM();
};

void P2CPP::runInterpreterPerlFile (char *file){
    my_argv[0]=(char*)"";  //typecast pra parrar de dar warning mas nao sei se ta certo
    my_argv[1]= file;
    perl_parse(my_perl,0,2,my_argv,(char **)NULL );
    perl_run(my_perl);
};

 string P2CPP::perlGetHeaderData(string fileName) {
    //vector <string> tmp;
    string tmp;
    dSP;
    int count;
    ENTER;
    SAVETMPS;

    PUSHMARK(SP);
    EXTEND(SP,2);
    PUSHs(sv_2mortal(newSVpv(fileName.c_str(), fileName.length())));
    PUTBACK;

    count = call_pv("getHeaderData", G_SCALAR);
    SPAGAIN;

    cout <<  "\n\nANTES DAONDE TAVA DANDO MERDA\n\n" << endl;
    // for (unsigned i=0; i < 3; i++) {
    //    tmp.push_back(POPp);
    // }
    tmp = POPp;
    PUTBACK;
    FREETMPS;
    LEAVE;
    return tmp;
};
// int P2CPP::checkPlant (string nomePlanta, string nomeArq,string perlFunc){
//     dSP; // inicializa pointer da pilha
//     ENTER;
//     SAVETMPS;
//     PUSHMARK(SP);
//     XPUSHs(sv_2mortal(newSVpv(nomePlanta.c_str()),nomeArq.c_str());
//     PUTBACK;
//     call_pv (perlFunc.c_str(), G_SCALAR);
//     SPAGAIN;

//     int resultado= POPi;
//     PUTBACK;
//     FREETMPS; //libera o valor de retorno
//     LEAVE;

//     return resultado;
// }




