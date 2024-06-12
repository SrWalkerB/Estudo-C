#include <stdio.h>

int main(){
    int inputValue = 0;

    printf("Insert Value Int: ");
    scanf(" %i", &inputValue);

    for(int x = 2; x < 10; x++){
        printf("%i x %i = %i\n",x, inputValue, x * inputValue);
    }

    return 0;
}