# 3D Rotating Cube

A simple C program that displays a rotating 3D cube in the terminal using ASCII characters. The program demonstrates basic 3D graphics principles, including rotation and depth buffering.

## Features

- Real-time 3D cube rotation
- ASCII art rendering
- Depth buffering for correct rendering of surfaces

## Requirements

- GCC or any C compiler

## How to Build and Run

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/3d-rotating-cube.git
    ```
2. Change into the project directory:
    ```bash
    cd cube
    ```
3. Compile the program:
    ```bash
    gcc cube.c -lm -o cube
    ```
4. Run the program:
    ```bash
    ./cube
    ```

## Code Structure

- `main.c`: The main source code file containing the 3D cube rotation logic.

## Explanation of Key Components

- **Rotation Angles**: Variables `A`, `B`, and `C` represent the rotation angles for the cube.
- **Cube and Screen Parameters**: Variables such as `cubeWidth`, `width`, `height`, and `zBuffer` are used to set up the cube dimensions and the screen buffer.
- **Increment Speed**: The speed at which the cube rotates.
- **Functions**:
  - `calculateX`, `calculateY`, `calculateZ`: Calculate the X, Y, and Z coordinates after rotation.
  - `calculateForSurface`: Updates the screen buffer with the calculated coordinates and characters.

## Customization

- **Rotation Speed**: Adjust the `incrementSpeed` and angle increments (`A += 0.005`, `B += 0.005`) to change the rotation speed.
- **Cube Dimensions**: Modify the `cubeWidth` variable to change the size of the cube.
- **Screen Size**: Change `width` and `height` to fit different terminal sizes.

## Screenshot

## Acknowledgements

Inspired by various ASCII art and 3D graphics tutorials.
