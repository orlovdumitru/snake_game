#include <iostream>
#include <string>
#include "kbhit.h"
#include <ctime>

#include "snake.h"
#include "food.h"


const int WIDTH = 50, HEIGHT = 25; // pixels
Snake snake( WIDTH/2, HEIGHT/2, 1 );
Food food(WIDTH, HEIGHT);


void board(){
    std::map<char, int> snake_pos = snake.get_pos();
    std::map<char, int> food_pos = food.get_position();
    
    for(int i = 0; i < HEIGHT; i++){
        std::cout << "\t\t\t#";
        for(int j = 0; j < WIDTH - 1; j++){
            if(i == 0 || i == HEIGHT-1){
                std::cout << "#";
            }
            else if(i == snake_pos['Y'] && j == snake_pos['X']){
                std::cout << "0";
            }
            else if(i == food_pos['Y'] && j == food_pos['X']){
                std::cout << "@";
            }
            else{
                std::cout << " ";
            }
        }
        std::cout << "#\n";
    }
}

void clear_screen(int height){
   std::cout << "\033[" + std::to_string(height) + "A";
}

int main(){
    // random seed
    srand(time(NULL));
    std::cout << "\t\t\t\t\t\tSnake game" << std::endl;
    keyboard keyb;
    char key;
    int key_nr;
    int sleep_time = 1000;
    bool game_over = false;
    std::map<char, int> snake_pos = snake.get_pos();
    
    while( !game_over ){
        board();
        if( keyb.kbhit() ){
            key_nr = keyb.getch();
            key = key_nr;
            if(key == 'w'){ snake.change_direction('u'); }
            else if(key == 's'){ snake.change_direction('d'); }
            else if(key == 'a'){ snake.change_direction('l'); }
            else if(key == 'd'){ snake.change_direction('r'); }
            else if(key == 'q'){ break; }
        }

        if(sleep_time <= 0){
            snake.move_snake();
            if(snake.eat_food(food.get_position())){
                food.generate_food(WIDTH, HEIGHT);
                snake.grow();
            }
            game_over = snake.snake_colide(WIDTH, HEIGHT);
            sleep_time = 1000;
        }
        sleep_time--;

        clear_screen(HEIGHT);
    }

    return 0;
}