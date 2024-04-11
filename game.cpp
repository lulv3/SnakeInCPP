#include "game.h"
#include <iostream>

// Constructor: Initialize member variables
Game::Game() : isRunning(true), window(nullptr), renderer(nullptr), snake(nullptr), food(), score(0) {}

// Destructor: Clean up resources
Game::~Game() {
    clean(); // Release resources
}

// Initialize SDL, create window and renderer, initialize snake and food objects
bool Game::init() {

    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL initialization failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create window
    window = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // Create renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Renderer creation failed: " << SDL_GetError() << std::endl;
        return false;
    }

    // Initialize snake and food objects
    snake = Snake(renderer);
    food = Food();

    return true;
}

// Handle SDL events
void Game::handleEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
            isRunning = false; // Quit the game loop if the window is closed
        }
        snake.handleInput(event); // Handle snake input events
    }
}

// Helper function to compare two SDL points
bool comparePoints(const SDL_Point& point1, const SDL_Point& point2) {
    return (point1.x == point2.x) && (point1.y == point2.y);
}

// Update game logic
void Game::update() {
    snake.move(); // Move the snake

    // Check if the snake has reached the food
    if (comparePoints(snake.getHeadPosition(), food.getPosition())) {
        food.spawn(SCREEN_WIDTH / SNAKE_BLOCK_SIZE, SCREEN_HEIGHT / SNAKE_BLOCK_SIZE); // Spawn new food
        snake.grow(); // Grow the snake
        score++; // Increase score
    }

    // Check for self-collision
    if (snake.checkSelfCollision()) {
        // Reset the game
        resetGame();
        return;
    }

    // Check for border collision
    if (snake.checkBorderCollision(SCREEN_WIDTH, SCREEN_HEIGHT)) {
        // Reset the game
        resetGame();
        return;
    }
}

// Reset the game state
void Game::resetGame() {
    snake = Snake(renderer); // Reinitialize the snake
    food.spawn(SCREEN_WIDTH / SNAKE_BLOCK_SIZE, SCREEN_HEIGHT / SNAKE_BLOCK_SIZE); // Respawn food
    score = 0; // Reset score
}

// Render game objects
void Game::render() {
    // Draw window border
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set white color
    SDL_RenderDrawLine(renderer, 0, 0, SCREEN_WIDTH, 0); // Top line
    SDL_RenderDrawLine(renderer, 0, SCREEN_HEIGHT - 1, SCREEN_WIDTH, SCREEN_HEIGHT - 1); // Bottom line
    SDL_RenderDrawLine(renderer, 0, 0, 0, SCREEN_HEIGHT); // Left line
    SDL_RenderDrawLine(renderer, SCREEN_WIDTH - 1, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT); // Right line

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    // Draw snake and food
    snake.draw();
    food.draw(renderer);

    SDL_RenderPresent(renderer); // Update screen
}

// Main game loop
void Game::run() {
    if (!init()) {
        std::cerr << "Initialization failed. Exiting..." << std::endl;
        return;
    }

    while (isRunning) {
        handleEvents(); // Handle input events
        update();  // Update game logic
        render(); // Render game objects
        SDL_Delay(1000 / FPS); // Control framerate
    }

    clean(); // Clean up resources
}

// Clean up SDL resources
void Game::clean() {
    // Release SDL resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
