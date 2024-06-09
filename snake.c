#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>

//Dependecias: libncurses5-dev libncursesw5-dev;

#define DELAY 800000
int width = 30;
int height = 30;
int posX = 1;
int posY = 2;
char key[] = "";
int game_running = 1;


void draw(){
    system("clear");

    for(int indexHeight = 0; indexHeight < height; indexHeight++){
        for(int indexWidth = 0; indexWidth < width; indexWidth++){
            //indexHeight == 0; Pega a altura e desenha
            //indexHeight == width-1; Verifica se a altura é o penultimo valor para desenha as bordas de baixo
            //indexWidth == 0 ; Se for o primeiro elemento signfica que é a primeira borda;
            //indexWidth == height-1; Se for o penultimo elemento signfica que é a ultima;

            if(indexHeight == 0 || indexHeight == width-1 || indexWidth == 0 || indexWidth == height-1){
                printf("#"); 
            } else {
                // printf("indexHeight = %i; posY=%i\n", indexHeight, posY);
                if(indexWidth == posX && indexHeight == posY){
                    printf("[]");
                } else {
                    printf(" ");
                }
            }
        }

        //Pra cada caracter criado de altura vamos quebrar a linha
        printf("\n"); 
    }
}

void input(){
    char input_key[80];
    getstr(input_key);

    printw("%s", input_key);
    // if(input_key == "q"){
    //     printw("1");
    // }
    // if(input_key == "q"){
    //     game_running = 0;
    // }

    // if(input_key == W_OK(1)){
    //     printw("opa");
    // }

    // printf("value=%s\n", input_key);

    // if(strcmp(input_key, "w") == 0){
    //     posY = posY-1;
    // }

    // if(strcmp(input_key, "s") == 0){
    //     posY = posY+1;
    // }

    // if(strcmp(input_key, "d") == 0){
    //     posX = posX+1;
    // }

    // if(strcmp(input_key, "a") == 0){
    //     posX = posX-1;
    // }
}

int snake_move_auto(){
    // sleep(0.01);
    posY = posY+1;
    posX = posX+1;
}

int snake_game(){
    // initscr();	

    // getch();  
    // raw();				
    // keypad(stdscr, TRUE);		
    // noecho();		

    while (game_running)
    {
        draw();
        // input();
        snake_move_auto();
        usleep(DELAY);
    }
    
    // endwin();
    return 0;
}