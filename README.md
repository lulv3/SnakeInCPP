# Snake Game in C++ with SDL2

This is a simple Snake game implemented in C++ using the SDL2 library.

## Overview

The Snake game is a classic arcade game where the player controls a snake that moves around the screen, eating food to grow longer. The game ends if the snake collides with itself or the game borders.

## Features

- Simple yet addictive gameplay.
- Smooth graphics and controls.
- Score tracking.
- Game over and reset functionality.

## Prerequisites

Before running the game, make sure you have the following installed:

- Visual Studio (or any C++ compiler).
- SDL2 library.

## Installation and Setup

1. **Download SDL2 Library**:
   - Visit the [SDL download page](https://www.libsdl.org/download-2.0.php) and download the SDL2 development libraries appropriate for your platform (Windows, macOS, Linux).

2. **Extract the SDL2 Files**:
   - Extract the downloaded SDL2 development libraries to a location on your computer.

3. **Include SDL2 Headers in Visual Studio**:
   - In Visual Studio, create a new C++ project or open an existing one.
   - Right-click on your project in Solution Explorer and select "Properties".
   - Navigate to "Configuration Properties" > "VC++ Directories".
   - Add the path to the SDL2 `include` directory in "Include Directories".

4. **Link SDL2 Libraries**:
   - Still in the project properties, navigate to "Linker" > "Input".
   - Add the path to the SDL2 `lib` directory in "Additional Library Directories".
   - Add `SDL2.lib` and `SDL2main.lib` to the "Additional Dependencies".

## Usage

1. Clone or download this repository to your local machine.
2. Open the source files in Visual Studio or any text editor of your choice.
3. Compile the source files to generate the executable.
4. Run the executable to start the Snake game.

## Contributing

Contributions are welcome! Fork the repository, make your changes, and submit a pull request.

## License

This project is licensed under the [MIT License](LICENSE).
