#include "food.h"

Food::Food(int width, int height){
    Food::generate_food(width, height);
}

void Food::generate_food(int width, int height){
    int x = rand() % width + 1;
    int y = rand() % height + 1;
    position = {
        {'X', x},
        {'Y', y}
    };
}

std::map<char, int> Food::get_position(){
    return position;
}
