#include "myecho.h"
#include "myenv.h"
#include "isset.h"
#include "myprocess.h"
/*
    #include <readline/readline.h>
    #include <readline/history.h>
*/

#define ARGC 3

#include <stdlib.h>

int main(int argc, char* argv[], char* envp[]){

    /* ------------- AUFGABE 1 ------------- */
    /* Erste, nicht so schöne Variante für echo */
    char* myArray[ARGC] = {"fancyWord", "anotherFancyWord", "thirdFancyString"};
    myecho(ARGC, &myArray);

    /* Zweite, schönere Variante für echo */
    myechoAlt(ARGC, "string", "stringsSoundNice", "wohooILoveStrings!");

    /* Umgebungsvariablen ausgeben */
    myenv(envp);


    /* ------------- AUFGABE 2 ------------- */
    /* Überprüfen, ob Umgebungsvariablen gesetzt */
    int isMyVarSet = isset("HOME", argc);
    printf("isset returned %d.\n\n", isMyVarSet);

    /* Namen und Wert der Umgebungsvariablen ausgeben lassen */
    isMyVarSet = isset("HOME", argc, "-v");
    printf("isset returned %d\n\n", isMyVarSet);


    /* ------------- AUFGABE 3 ------------- */
    /* Prozess starten, pid ausgeben lassen*/
    pid_t myPid = fork();
    printf("%d\n\n", (int)myPid);

    myProcess("/usr/bin/gedit", argv);

    /* Aufgabe 4 hat nicht so richtig geklappt */

    /* folgendes wurde unternommen:
        error: readline/readline.h could not be resolved
        Lösung: Mit Terminal installieren
        sudo apt-get install libreadline-dev

        #include <readline/readline.h>
        #include <readline/history.h>

        char* path = readline(const char* path);
        error: expected expression before const.

        Frage: wozu wird hier history verwendet?
        werde nicht so ganz schlau aus der man-page

        bzw. andere Varianten mit
        scanf und fgets, z.B:

        #define MAX_ARGC = 100;
        ...

        char* path[100];

        printf("Geben Sie einen Pfad an.");
        fgets(path, 100, stdin);

        char* pArgv[100]
        char quit = 'n';
        int i = 1;
        while((quit!='j') && i<MAX_ARGC){
            printf("Wollen Sie noch ein Argument eingeben [j\n]");
            scanf("%c", &quit);
            fgets(pArgv, 100, stdin);
            i++;
        }

        ...
        myProcess(path, pArgv);

        verschiedene Varianten dieses Ansatzes führten
        zu segmentation faults oder undefined behaviour.
    */

    /* ---------------- Sonstiges/Testfunktionen --------------- */
    printf("\n\n");


    return EXIT_SUCCESS;
}
