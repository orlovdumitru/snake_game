#include "snake.h"

Snake::Snake(int x, int y, int vel){
    position = {
        {'X', x},
        {'Y', y}
    };

    this->vel = vel;
    len = 1;
    direction = 'n';
}

void Snake::change_direction(char dir){
    direction = dir;
}

void Snake::move_snake(){
    if(direction == 'u'){ position['Y'] -= vel; }
    else if(direction == 'd'){ position['Y'] += vel; }
    else if(direction == 'l'){ position['X'] -= vel; }
    else if(direction == 'r'){ position['X'] += vel; }
}

std::map<char, int> Snake::get_pos(){
    return position;
}

bool Snake::eat_food(std::map<char, int> food_pos){
    if((food_pos['X'] == position['X']) && (food_pos['Y'] == position['Y'])){
        return true;
    }
    return false;
}

void Snake::grow(){
    len++;
}

bool Snake::snake_colide(int width, int height){
    if(position['X'] < 1 || position['X'] > width || position['Y'] < 1 || position['Y'] > height){
        return true;
    }
    return false;
}