#include "p2cpp.h" 

P2CPP::P2CPP() {
    PERL_SYS_INIT3(NULL, NULL, NULL); //macro de inicio

    my_perl = perl_alloc();
    perl_construct(my_perl);
    PL_exit_flags |= PERL_EXIT_DESTRUCT_END;
};

P2CPP::~P2CPP() {
    perl_destruct (my_perl);
    perl_free (my_perl);
    PERL_SYS_TERM();
};

void P2CPP::runInterpreterPerlFile (char *file) {
    my_argv[0]= (char*)"";
    my_argv[1]= file;
    perl_parse(my_perl,0,2,my_argv,(char **)NULL );
    perl_run(my_perl);
};

int P2CPP::perlVerifyIntegrity(string file) {
    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);

    int integridade;

    EXTEND(SP,2);
    XPUSHs(sv_2mortal(newSVpv(file.c_str(), file.length())));
    PUTBACK;
    
    call_pv("verifyIntegrity", G_SCALAR);

    SPAGAIN;

    integridade = POPi;
    PUTBACK;
    FREETMPS;
    LEAVE;
    return integridade;
};

void P2CPP::perlMoveFile(string file) {
    dSP;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    EXTEND(SP,2);
    XPUSHs(sv_2mortal(newSVpv(file.c_str(), file.length())));
    PUTBACK;
    
    call_pv("moveFile", G_SCALAR);

    SPAGAIN;

    PUTBACK;
    FREETMPS;
    LEAVE;
};

void P2CPP::perlGetArray(string file, string function, vector<string> &vec) {
    dSP;
    int count;
    ENTER;
    SAVETMPS;
    PUSHMARK(SP);
    EXTEND(SP,2);
    XPUSHs(sv_2mortal(newSVpv(file.c_str(), file.length())));
    PUTBACK;

    count = call_pv(function.c_str(), G_ARRAY);

    SPAGAIN;
   
    for (unsigned i=0; i < count; i++) {
        vec.push_back(POPp);
    }

    PUTBACK;
    FREETMPS;
    LEAVE;
};






