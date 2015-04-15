#include "isset.h"

int isset(char* var, int argc,...){
    va_list options;
    va_start(options, argc);

    if (strcmp(va_arg(options, char*), "-v") == 0)
    printf("%s: %s\n", var, getenv(var));

    if (getenv(var)!=NULL)
    return 1;
    return 0;
}
