#include <SDL.h>
#include "game.h"

// Entry point of the program
int SDL_main(int argc, char* argv[]) {
    // Create an instance of the Game class
    Game game;

    // Run the game loop
    game.run();

    return 0;
}
