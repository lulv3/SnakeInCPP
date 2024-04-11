#include "snake.h"

// Constructor for the Snake class
Snake::Snake(SDL_Renderer* rend) : renderer(rend), direction(Direction::RIGHT) {
    // Initialize the snake with a few blocks
    blocks.push_back(Block(10, 10));
    blocks.push_back(Block(9, 10));
    blocks.push_back(Block(8, 10));
}

// Method to move the snake
void Snake::move() {
    // Move the snake - Shift the head one unit forward in the direction of current movement
    int headX = blocks[0].x;
    int headY = blocks[0].y;

    // Update head position based on current direction
    switch (direction) {
    case Direction::UP:
        headY--;
        break;
    case Direction::DOWN:
        headY++;
        break;
    case Direction::LEFT:
        headX--;
        break;
    case Direction::RIGHT:
        headX++;
        break;
    }

    // Add the new head to the snake
    blocks.insert(blocks.begin(), Block(headX, headY));

    // Remove the last block of the snake to simulate movement
    blocks.pop_back();
}

// Method to make the snake grow
void Snake::grow() {
    // Add a new block at the end of the snake
    int tailX = blocks.back().x;
    int tailY = blocks.back().y;
    blocks.push_back(Block(tailX, tailY));
}

// Method to handle user input for changing snake direction
void Snake::handleInput(SDL_Event& event) {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_UP:
            if (direction != Direction::DOWN) {
                direction = Direction::UP;
            }
            break;
        case SDLK_DOWN:
            if (direction != Direction::UP) {
                direction = Direction::DOWN;
            }
            break;
        case SDLK_LEFT:
            if (direction != Direction::RIGHT) {
                direction = Direction::LEFT;
            }
            break;
        case SDLK_RIGHT:
            if (direction != Direction::LEFT) {
                direction = Direction::RIGHT;
            }
            break;
        }
    }
}

// Method to draw the snake on the screen
void Snake::draw() {
    // Draw the snake
    for (const auto& block : blocks) {
        SDL_Rect rect = { block.x * SNAKE_BLOCK_SIZE, block.y * SNAKE_BLOCK_SIZE,
                           SNAKE_BLOCK_SIZE, SNAKE_BLOCK_SIZE };
        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Green for the snake
        SDL_RenderFillRect(renderer, &rect);
    }
}

// Method to get the position of the snake's head
SDL_Point Snake::getHeadPosition() {
    // Return the position of the snake's head
    return { blocks[0].x, blocks[0].y };
}

// Method to check if the snake collides with itself
bool Snake::checkSelfCollision() {
    SDL_Point head = { blocks[0].x, blocks[0].y };
    // Check if the head of the snake collides with any of its own body parts
    for (size_t i = 1; i < blocks.size(); ++i) {
        if (head.x == blocks[i].x && head.y == blocks[i].y) {
            return true; // Collision with itself
        }
    }
    return false;
}

// Method to check if the snake collides with the screen borders
bool Snake::checkBorderCollision(int screenWidth, int screenHeight) {
    SDL_Point head = { blocks[0].x, blocks[0].y };
    // Check if the head of the snake collides with the borders of the screen
    return (head.x < 0 || head.x >= screenWidth / SNAKE_BLOCK_SIZE ||
        head.y < 0 || head.y >= screenHeight / SNAKE_BLOCK_SIZE);
}
