#include <stdio.h>
#include <stdlib.h>

void renameFile(){
    char oldName[10] = "";
    char newName[10] = "";

    printf("Old Path Name: ");
    scanf("%s", oldName);

    printf("new Path Name: ");
    scanf("%s", newName);


    rename(oldName, newName);
    return;
}