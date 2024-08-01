# 3D Rotating Cube

A simple C program that displays a rotating 3D cube in the terminal using ASCII characters. The program demonstrates basic 3D graphics principles, including rotation and depth buffering.

![cube2](https://github.com/user-attachments/assets/71a3aa88-8b7b-4baf-a9d9-60074fec6a60)

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

- `cube.c`: The main source code file containing the 3D cube rotation logic.

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

![image](https://github.com/user-attachments/assets/b4751dad-1b22-407b-8f5d-4f2d3617b0eb)

![image](https://github.com/user-attachments/assets/c7f5188e-4a62-4d4f-a5c0-457678cfb30e)

## Acknowledgements

Inspired by various ASCII art and 3D graphics tutorials.

For more information on rotation matrices, visit the [Wikipedia page](https://en.wikipedia.org/wiki/Rotation_matrix).

Special thanks to the [YouTube video](https://www.youtube.com/watch?v=p09i_hoFdd0) for inspiration and guidance.
