#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

// Rotation angles
double A, B, C;

// Cube and screen parameters
float cubeWidth = 20;
int width = 160, height = 44;
float zBuffer[160 * 44];
char buffer[160 * 44];
int backgroundASCIICode = ' ';
int distanceFromCam = 100;
float horizontalOffset;
float K1 = 40;

// Increment speed for the cube rotation
float incrementSpeed = 0.6f;

// Variables for calculations
float x, y, z;
float ooz;
int xp, yp;
int idx;

// Function to calculate the X coordinate after rotation
float calculateX(int i, int j, int k) {
  return j * sin(A) * sin(B) * cos(C) - k * cos(A) * sin(B) * cos(C) +
         j * cos(A) * sin(C) + k * sin(A) * sin(C) + i * cos(B) * cos(C);
}

// Function to calculate the Y coordinate after rotation
float calculateY(int i, int j, int k) {
  return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
         j * sin(A) * sin(B) * sin(C) + k * cos(A) * sin(B) * sin(C) -
         i * cos(B) * sin(C);
}

// Function to calculate the Z coordinate after rotation
float calculateZ(int i, int j, int k) {
  return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}

// Function to calculate the surface coordinates and update the buffer
void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch) {
    x = calculateX(cubeX, cubeY, cubeZ);
    y = calculateY(cubeX, cubeY, cubeZ);
    z = calculateZ(cubeX, cubeY, cubeZ) + distanceFromCam;

    ooz = 1 / z;

    xp = (int)(width / 2 - 2 * cubeWidth + horizontalOffset + K1 * ooz * x * 2);
    yp = (int)(height / 2 + K1 * ooz * y);

    idx = xp + yp * width;
    if (idx >= 0 && idx < width * height) {
        if (ooz > zBuffer[idx]) {
            zBuffer[idx] = ooz;
            buffer[idx] = ch;
        }
    }
}

int main() {
    // Clear the screen
    printf("\x1b[2J");
    while (1) {
        // Reset the buffer and zBuffer
        memset(buffer, backgroundASCIICode, width * height);
        memset(zBuffer, 0, width * height * 4);

        // Loop over the range of cubeX from -cubeWidth to cubeWidth with steps of incrementSpeed
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            // Loop over the range of cubeY from -cubeWidth to cubeWidth with steps of incrementSpeed
            for (float cubeY = -cubeWidth; cubeY < cubeWidth; cubeY += incrementSpeed) {
                //  front surface of the cube
                calculateForSurface(cubeX, cubeY, -cubeWidth, '.');
                //  right surface of the cube
                calculateForSurface(cubeWidth, cubeY, cubeX, '$');
                //  left surface of the cube
                calculateForSurface(-cubeWidth, cubeY, -cubeX, '~');
                //  back surface of the cube
                calculateForSurface(-cubeX, cubeY, cubeWidth, '#');
                //  bottom surface of the cube
                calculateForSurface(cubeX, -cubeWidth, -cubeY, ';');
                //  top surface of the cube
                calculateForSurface(cubeX, cubeWidth, cubeY, '+');
            }
        }

        // Move the cursor to the top-left corner
        printf("\x1b[H");

        // Print the buffer to the screen
        for (int k = 0; k < width * height; k++) {
            putchar(k % width ? buffer[k] : 10);
        }

        // Increment the rotation angles
        A += 0.005;
        B += 0.005;
    }
    return 0;
}