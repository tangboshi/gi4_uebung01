#include "myecho.h"

void myecho(int argc, char* argv[]){
    int i;

    for(i=0;i<argc;++i){
        printf("%s ", argv[i]);
    }

    printf("\n\n");
}

void myechoAlt(int argc,...){
    va_list fancyWords;
    va_start(fancyWords, argc);

    int i;

    for(i=0;i<argc;++i){
        printf("%s ", va_arg(fancyWords, char*));
    }

    va_end(fancyWords);

    printf("\n\n");
}
