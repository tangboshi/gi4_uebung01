#include "myenv.h"

int myenv(char* envp[]){
    int i;
    for(i=0;envp[i]!=NULL;i++) printf("%s\n",envp[i]);

    printf("\n\n");
    return EXIT_SUCCESS;
}
