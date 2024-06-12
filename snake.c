#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ncurses.h>
#include <ctype.h>

//Dependecias: libncurses5-dev libncursesw5-dev;

int DELAY = 400000;
int width = 30;
int height = 30;
int posX = 0;
int posY = 0;
int direction_x = 0;
int direction_y = 1;
char key[] = "";
int game_running = 1;
int game_closing = 0;

int posX_fruit = 0;
int posY_fruit = 0;
int score = 0;
int snake_body[50] = {};

void close_game(){
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

int randomInt(int min, int max){
    return rand() % max + min;
}

int renderSyrup(){
    int length = sizeof(snake_body) / sizeof(snake_body[0]); 
    // printw("size = %i\n",length);

    // for(int x = 0; x < length; x++){
    //     if(snake_body[x] == 1){
    //         printw("body = %i\n", snake_body[x]);
    //     }
    // }
}

void draw(){
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
                 int lengthSnakeBody = sizeof(snake_body) / sizeof(snake_body[0]);

                for(int indexSnake = 0; indexSnake < lengthSnakeBody; indexSnake++){
                    if(snake_body[indexSnake] == 1){
                        if(direction_y == 1){
                            if(indexWidth == posX && indexHeight == posY-(indexSnake+1)){
                                printw("|");
                            }
                        }

                        if(direction_y == -1){
                            if(indexWidth == posX && indexHeight == posY+(indexSnake+1)){
                                printw("|");
                            }
                        }

                        if(direction_x == 1){
                            if(indexWidth == posX-(indexSnake+1) && indexHeight == posY){
                                printw("-");
                            }
                        }

                         if(direction_x == -1){
                            if(indexWidth == posX+(indexSnake+1) && indexHeight == posY){
                                printw("-");
                            }
                        }
                    }
                }

                if(indexWidth == posX && indexHeight == posY){
                    printw("0");
                } else {
                    printw(" ");                    
                }

                if(indexWidth == posX_fruit && indexHeight == posY_fruit){
                    printw("*");
                }

                if(posX_fruit == posX-1 && posY_fruit == posY){
                    posX_fruit = randomInt(2, width-4);
                    posY_fruit = randomInt(3, height-4);
                    score = score+1;
                    snake_body[score-1] = 1;

                    int speed = score % 2;

                    if(speed == 1){
                        DELAY = DELAY - 100000;
                    } 
                    renderSyrup();
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

    printw("posX = %i, posY = %i\n", posX, posY);
    printw("posX_fruit = %i, posY_fruit = %i\n", posX_fruit, posY_fruit);
    printw("score = %i\n", score);

}

int snake_game(){
    initscr();	     // Inicia a lib n curses;
    cbreak();
    noecho();        // Desativa caracteres digitados;
    curs_set(FALSE); // Oculta Cursor
    nodelay(stdscr, TRUE);

    posX = width / 2;
    posY = height / 2;
    posX_fruit = width / 3;
    posY_fruit = height / 3;

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