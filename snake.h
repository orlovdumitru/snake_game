#ifndef SNAKE_H
#define SNAKE_H

#include <map>

class Snake{
    std::map<char, int> position;
    int len;
    int vel;
    char direction;

    public:
        Snake(int x, int y, int vel);
        void change_direction(char dir);
        void move_snake();
        std::map<char, int> get_pos();
        bool eat_food(std::map<char, int> food_pos);
        void grow();
        bool snake_colide(int width, int height);
};


#endif