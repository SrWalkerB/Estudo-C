#include <stdio.h>
#include <string.h>


int main(){
    char value[] = "";
    char blank[] = "";
    char inputComplete[100] = "";
    int spaceBlank = 0;

    scanf("%s", value);
    fgets(inputComplete, sizeof(inputComplete), stdin);
    int countString = strlen(value);

    for(int i = 0; i < countString; i++){
        char compare[2] = "";
        compare[0] = value[i];
        compare[1] = '\0';

        if(strcmp(compare, " ") == 0){
            spaceBlank += 1;
        }
    }

    printf("Input: %s\n", value);
    printf("Blank Space: %d\n", spaceBlank);
    printf("Count Keywords: %d\n", countString);
    
    return 0;
}