#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 100

int main()
{
    int number[SIZE];
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        number[i] = (rand() % 10000) + 1;
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%3d\t", number[i]);
    }
    printf("\n\n");

    for (int i = 0; i < SIZE - 1; i++) {
        int swapped = 0;  

        for (int j = 0; j < SIZE - 1 - i; j++) {
            if (number[j] < number[j + 1]) {
                int temp = number[j];
                number[j] = number[j + 1];
                number[j + 1] = temp;
                swapped = 1; 
            }
        }

        if (!swapped) {
            break;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        printf("%3d\t", number[i]);
    }
}
