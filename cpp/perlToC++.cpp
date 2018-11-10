#include "perlToC++.h" 


PerlWrapper::PerlWrapper() {
    PERL_SYS_INIT3(); //macro de inicio

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
}

PerlWrapper::~PerlWrapper() {
    perl_destruct (my_perl);
    perl_free (my_perl);
    PERL_SYS_TERM();
}

void PerlWrapper::runInterpreterPerlFile (char *file){
    my_argv[0]= **;
    my_argv[1]= file;
    perl_parse(my_perl,0,2,my_argv,(char **)NULL );
    perl_run(my_perl);
}

int PerlWrapper::checkPlant (string nomePlanta, string nomeArq,string perlFunc){
    dSP; // inicializa pointer da pilha
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    XPUSHs(sv_2mortal(newSVpv(nomePlanta.c_str()),nomeArq.c_str());
    PUTBACK;
    call_pv (perlFunc.c_str(), G_SCALAR);
    SPAGAIN;

    int resultado= POPi;
    PUTBACK;
    FREETMPS; //libera o valor de retorno
    LEAVE;

    return resultado;
}




