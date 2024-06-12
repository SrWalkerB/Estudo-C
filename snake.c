#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <ctype.h>

//Dependecias: libncurses5-dev libncursesw5-dev;

#define DELAY 500000
int width = 30;
int height = 30;
int posX = 0;
int posY = 0;
int direction_x = 0;
int direction_y = 1;
char key[] = "";
int game_running = 1;
int game_closing = 0;

void close_game(){
    printw("colidiu");
    game_running = 0;
}

void check_game_over(){
 if(posY == height || posY == -1){
        close_game();
    } 

    if(posX == width || posX == 0){
        close_game();
    }

}

void draw(){
    // system("clear")
    clear();

    for(int indexHeight = 0; indexHeight < height; indexHeight++){
        for(int indexWidth = 0; indexWidth < width; indexWidth++){
            //indexHeight == 0; Pega a altura e desenha
            //indexHeight == width-1; Verifica se a altura é o penultimo valor para desenha as bordas de baixo
            //indexWidth == 0 ; Se for o primeiro elemento signfica que é a primeira borda;
            //indexWidth == height-1; Se for o penultimo elemento signfica que é a ultima;


            if(indexHeight == 0 || indexHeight == width-1 || indexWidth == 0 || indexWidth == height-1){
                printw("#");

            } else {
                // printw("indexHeight = %i; posY=%i\n", indexHeight, posY);
                if(indexWidth == posX && indexHeight == posY){
                    printw("[]");
                } else {
                    printw(" ");                    
                }
            }
        }

        //Pra cada caracter criado de altura vamos quebrar a linha
        printw("\n"); 
    }
}

void input(){
    int key;

    key = getch();

    if(key != ERR){
        key = tolower(key);

        switch (key)
        {
        case 'w':
            direction_y = -1;
            direction_x = 0;
            break;

        case 's':
            direction_y = 1;
            direction_x = 0;
            break;

        case 'd':
            direction_x = 1;
            direction_y = 0;
            break;

        case 'a':
            direction_x = -1;
            direction_y = 0;
            break;

         case 'p':
            game_running = 0;
            break;
        }
    }
}

int snake_move_auto(){
    if(direction_y == 1){
        posY = posY+1;
        direction_x = 0;
    }

    if(direction_y == -1){
        posY = posY-1;
        direction_x = 0;
    }

    if(direction_x == 1){
        posX = posX + 1;
        direction_y = 0;
    }

    if(direction_x == -1){
        posX = posX - 1;
        direction_y = 0;
    }

    printw("posX = %i, posY = %i", posX, posY);
}

int snake_game(){
    initscr();	     // Inicia a lib n curses;
    cbreak();
    noecho();        // Desativa caracteres digitados;
    curs_set(FALSE); // Oculta Cursor
    nodelay(stdscr, TRUE);

    posX = width / 2;
    posY = height / 2;

    while (game_running)
    {
        draw();
        check_game_over();
        input();
        snake_move_auto();
        refresh();
        usleep(DELAY);
    }


    // getch();  //responsivevel por fechar o jogo ao clicar em CTRL+C
    
    endwin();
    return 0;
}