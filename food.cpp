#include "food.h"

// Constructor for the Food class
Food::Food() {
    // Initialize food position to (0, 0)
    position.x = 0;
    position.y = 0;
}

// Method to spawn food at a random position within the specified range
void Food::spawn(int maxX, int maxY) {
    // Seed for random number generation
    std::random_device dev;
    std::mt19937 rng(dev());

    // Define distributions for x and y positions
    std::uniform_int_distribution<std::mt19937::result_type> distX(0, maxX - 1);
    std::uniform_int_distribution<std::mt19937::result_type> distY(0, maxY - 1);

    // Generate random x and y positions within the specified range
    position.x = distX(rng);
    position.y = distY(rng);
}

// Method to draw the food on the screen
void Food::draw(SDL_Renderer* renderer) {
    // Define a rectangle representing the food's position and size
    SDL_Rect rect = { position.x * SNAKE_BLOCK_SIZE, position.y * SNAKE_BLOCK_SIZE,
                       SNAKE_BLOCK_SIZE, SNAKE_BLOCK_SIZE };

    // Set the color to red
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    // Fill the rectangle with the specified color to represent the food
    SDL_RenderFillRect(renderer, &rect);
}

// Method to get the current position of the food
SDL_Point Food::getPosition() {
    return position;
}
