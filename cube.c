#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

float A, B, C;

float cubeWidth = 20;
int width = 320, height = 88;
float zBuffer[320*88];
char *buffer[320*88];
int backgroundASCIICode = ' ';
int distanceFromCam = 90;
float K1 = 40;

float incrementSpeed = 0.8;

float x, y, z;
float ooz;
int xp, yp;
int idx;

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

void calculateForSurface(float cubeX, float cubeY, float cubeZ, int ch){
    x = calculate(cubeX, cubeY, cubeZ);
    y = calculate(cubeX, cubeY, cubeZ);
    z = calculate(cubeX, cubeY, cubeZ);

    float ooz = 1 / z;
    xp = (int)(width / 2 + K1 * ooz * x * 2);
    yp = (int)(height / 2 - K1 * ooz * y);

    idx = xp + yp * width;
    if (idx>=0 && idx<width*height && zBuffer[idx] < ooz) {
        zBuffer[idx] = ooz;
        *buffer[idx] = ch;
    }

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