#include "myprocess.h"

void myProcess(char* path, char* argv[]){
    execv(path, argv);
}
