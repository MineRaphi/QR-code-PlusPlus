#include <stdio.h>

int main() {
    char input[108];
    int inputInt[108];
    int inputOctal[108][3];

    FILE *fptr;
    fptr = fopen("input.txt", "r");
    int width = 3;
    int height; 

    FILE* output;
	output = fopen("output.ppm", "wb"); 

    fgets(input, 108, fptr);
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

    fprintf(output, "P3\n"); 

    height = strLen;
    fprintf(output, "%d %d\n", width, height); 
    fprintf(output, "255\n");

    for(int i=0; i<strLen; i++) {
        for(int j=2; j>=0; j--) {
            switch(inputOctal[i][j]) {
                case 0:
                    printf("black ");
                    fprintf(output, "0 0 0 ");
                    break;
                case 1:
                    printf("red ");
                    fprintf(output, "255 0 0 ");
                    break;
                case 2:
                    printf("green ");
                    fprintf(output, "0 255 0 ");
                    break;
                case 3:
                    printf("blue ");
                    fprintf(output, "0 0 255 ");
                    break;
                case 4:
                    printf("yellow ");
                    fprintf(output, "255 255 0 ");
                    break;
                case 5:
                    printf("cyan ");
                    fprintf(output, "0 255 255 ");
                    break;
                case 6:
                    printf("magenta ");
                    fprintf(output, "255 0 255 ");
                    break;
                case 7:
                    printf("white ");
                    fprintf(output, "255 255 255 ");
                    break;
            }
        }
        printf("\n");
        fprintf(output, "\n"); 
    }
    printf("\n");
    fprintf(output, "0 0 0\n");
}
