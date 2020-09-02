#ifndef FOOD_H
#define FOOD_H

#include <map>
#include <cstdlib>

class Food{
    std::map<char, int> position;

    public:
        Food(int width, int height);
        void generate_food(int width, int height);
        std::map<char, int> get_position();
        

};

#endif