#ifndef SNAKE_H
#define SNAKE_H

#include <SDL.h>
#include <vector>
#include "block.h"

// Enum for directions
enum class Direction { UP, DOWN, LEFT, RIGHT };

// Constants for the Snake
const int SNAKE_BLOCK_SIZE = 20;

// Class for the Snake
class Snake {
private:
    std::vector<Block> blocks; // Vector to store the blocks of the snake
    SDL_Renderer* renderer; // Pointer to the SDL renderer
    Direction direction; // Current direction of the snake

public:
    // Constructor
    Snake(SDL_Renderer* rend);

    // Method to move the snake
    void move();

    // Method to make the snake grow
    void grow();

    // Method to handle user input for changing snake direction
    void handleInput(SDL_Event& event);

    // Method to draw the snake on the screen
    void draw();

    // Method to check if the snake collides with itself
    bool checkSelfCollision();

    // Method to check if the snake collides with the screen borders
    bool checkBorderCollision(int screenWidth, int screenHeight);

    // Method to get the position of the snake's head
    SDL_Point getHeadPosition();
};

#endif // SNAKE_H
