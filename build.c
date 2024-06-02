#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("Compile main File... \n");
    system("gcc -o main main.c");
    printf("Execution main file...\n");
    system("./main");
    printf("Finished main\n");

    return 0;
}