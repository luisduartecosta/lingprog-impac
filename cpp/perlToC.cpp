#include <stddef.h>
#include <string>
#include <iostream>
#include "perlToC.h" 

// EXTERN_c void xs_init (pTHX);

// EXTERN_C void boot_DynaLoader (pTHX_CV* cv);

// EXTERN_C void 
// xs_init(pTHX)  
// {
//     static const char file[] = __FILE__;
//     dXSUB_SYS;
//     PERL_UNUSED_CONTEXT;

//     newXS("DynaLoader::boot_DynaLoader",boot_DynaLoader,file);
// }

PerlWrapper::PerlWrapper(string script) {
    int dummy_argc = 0;
    char*** dummy_env = 0;
    char string[]={};
    
    PERL_SYS_INIT3(&dummy_argc, dummy_env, dummy_env); //macro de inicio

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
}

PerlWrapper::~PerlWrapper() {
    perl_destruct (my_perl);
    perl_free (my_perl);
    PERL_SYS_TERM();
}

void PerlWrapper::interpreterPerl (){
    char _MYARGV_PERL_MODULE_NAME[] = "../perl/main.pl";
    char _MYARGV_NOTHING_NAME[]=""; // nao por nada aqui
    char *my_argv[]={static_cast<char*>(_MYARGV_NOTHING_NAME), static_cast<char*>(_MYARGV_PERL_MODULE_NAME)};

    perl_parse(my_perl,0,2,my_argv,NULL );
    perl_run(my_perl);
}

int PerlWrapper::checkPlant (string nomePlanta, string nomeArq,string perlFunc){
    dSP; // inicializa pointer da pilha
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);

    XPUSHs(sv_2mortal(newSVpv(nomePlanta.c_str(),nomePlanta.length())));
    XPUSHs(sv_2mortal(newSVpv(nomeArq.c_str(),nomeArq.length())));
    
    PUTBACK;
    call_pv (perlFunc.c_str(), G_SCALAR);
    SPAGAIN;

    int resultado = POPi; //POPp para retornar string
    PUTBACK;
    FREETMPS; //libera o valor de retorno
    LEAVE;

    return resultado;
}




