#ifndef GAME_H
#define GAME_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <string>
#include "snake.h"
#include "food.h"

// Constant for the frame rate
const int FPS = 10;
static int SCREEN_WIDTH = 800;
static int SCREEN_HEIGHT = 600;

// Class for the game
class Game {
private:
    bool isRunning;
    int score;
    SDL_Window* window;
    SDL_Renderer* renderer;
    Snake snake;
    Food food;

public:
    Game(); // Constructor
    ~Game(); // Destructor

    bool init(); // Initialize SDL and game components
    void handleEvents(); // Handle SDL events
    void update(); // Update game logic
    void render(); // Render game objects
    void run(); // Main game loop
    void clean(); // Clean up resources
    void resetGame(); // Reset game state
};

#endif // GAME_H
