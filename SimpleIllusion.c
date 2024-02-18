#include <stdio.h>
#include <stdbool.h>
#include <windows.h>
#include <conio.h>
#define size 21
#define fill 127

// Function to print the map
void Print(char map[size][size]){
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++)
            printf("%2.c",map[i][j]);
        printf("\n");
    }
}

// Function to fill the borders of the map with a filling character
void FillMap(int x, char map[size][size]){
    int m = x;
    int M = size - x;
    while(m < M){
        for(int i = m; i < M; i++){         // Fill top and bottom borders
            map[i][m] = fill;               // Fill left border
            map[i][M - 1] = fill;           // Fill right border
        }
        for(int i = m; i < M; i++){ // Fill top and bottom borders
            map[m][i] = fill; // Fill left border
            map[M - 1][i] = fill; // Fill right border
        }
        m += 2; // Move the start position two steps inward
        M -= 2; // Move the end position two steps inward
    }
}

int main() {
    char map[size][size];
    bool a = false;
    while(true) {
        system("cls");
        memset(map, 46, sizeof(map)); // Initialize the map with ASCII value 46 (.)
        FillMap(a, map);
        Print(map);
        if(a)
            a = false;
        else
            a = true;
        Sleep(100); // Pause the program execution for 100 milliseconds
    }
    return 0;
}
