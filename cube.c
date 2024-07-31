#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

float A, B, C;

float cubeWidth = 20;
int width = 320, height = 88;
float zBuffer[320][88];
char buffer[320][88];
int backgroundASCIICode = ' ';
int distanceFromCam = 90;
float incrementSpeed = 0.8;

float calculateX(int i, int j, int k) {
return j *sin(A) * sin(B) * cos(C) - k* cos(A) * sin(B) * cos(C) +
j* cos(A) * sin(C) + k* sin(A) * sin(C) + i * cos(B) * cos(C);
}

float calculateY(int i, int j, int k) {
return j * cos(A) * cos(C) + k * sin(A) * cos(C) -
j* sin(A) * sin(B) * sin(C) + k* cos(A) * sin(B) * sin(C) -
i * cos(B) * sin(C);
}

float calcuateZ(int i, int j, int k) {
return k * cos(A) * cos(B) - j * sin(A) * cos(B) + i * sin(B);
}


int main() {
    printf("\x1b[2]");
    while (1) {
    memset(buffer, backgroundASCIICode, width * height);
    memset(zBuffer, 0, width * height * 4);
        for (float cubeX = -cubeWidth; cubeX < cubeWidth; cubeX += incrementSpeed) {
            for (float cubeY = -cubeWidth; cubeY < cubeWidth;
            cubeY += incrementSpeed) {
            return 0;
            }
        }
    }    
}    