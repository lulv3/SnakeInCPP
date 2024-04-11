#ifndef FOOD_H
#define FOOD_H

#include <SDL.h> // Including SDL library for SDL_Point
#include <random> // Including <random> for random number generation
#include "snake.h" // Including the snake.h header file

// Class definition for Food
class Food {
private:
    SDL_Point position; // Position of the food item

public:
    // Constructor for Food
    Food();

    // Function to spawn food at a random position within specified bounds
    void spawn(int maxX, int maxY);

    // Function to draw the food on the renderer
    void draw(SDL_Renderer* renderer);

    // Function to get the position of the food
    SDL_Point getPosition();
};

#endif // FOOD_H
