#include <stdio.h>

int main() {
    char input[64];
    int inputInt[64];
    int inputOctal[64][3];

    FILE *fptr;

    fptr = fopen("input.txt", "r");

    fgets(input, 64, fptr);
    printf("%s\n", input);
    fclose(fptr);

    int strLen = 0;
    for(int i=0; input[i] != '\0'; i++) {
        strLen++;
    }

    for(int i=0; i<strLen; i++) {
        inputInt[i] = input[i];
    }

    for(int i=0; i<strLen; i++) {
        for(int j=0; j<3; j++) {
            inputOctal[i][j] = inputInt[i] % 8;
            inputInt[i] = inputInt[i] / 8;
        }
    }

    for(int i=0; i<strLen; i++) {
        for(int j=2; j>=0; j--) {
            printf("%d", inputOctal[i][j]);
        }
        printf(" ");
    }
    printf("\n");

    for(int i=0; i<strLen; i++) {
        for(int j=2; j>=0; j--) {
            switch(inputOctal[i][j]) {
                case 0:
                    printf("\x1b[31m▉"); // Red
                    break;
                case 1:
                    printf("\x1b[32m▉"); // Green
                    break;
                case 2:
                    printf("\x1b[33m▉"); // Yellow
                    break;
                case 3:
                    printf("\x1b[34m▉"); // Blue
                    break;
                case 4:
                    printf("\x1b[35m▉"); // Magenta
                    break;
                case 5:
                    printf("\x1b[36m▉"); // Cyan
                    break;
                case 6:
                    printf("\x1b[37m▉"); // White
                    break;
                case 7:
                    printf("\x1b[30m▉"); // Black
                    break;
            }
        }
        printf("\n");
    }
    printf("\n");

}
