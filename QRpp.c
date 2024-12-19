#include <stdio.h>
#include <math.h>

#define BLACK "000 000 000"
#define RED "255 000 000"
#define GREEN "000 255 000"
#define BLUE "000 000 255"
#define YELLOW "255 255 000"
#define CYAN "000 255 255"
#define MAGENTA "255 000 255"
#define WHITE "255 255 255"

#define FILL "128 128 128"

int getInputSize(char filename[]);
void getInput(char filename[], char input[], int size);

int main() {
    char filename[] = "input.txt";
    int size = getInputSize(filename);
    char input[size];
    int inputOctal[size][3];
    getInput(filename, input, size);
    
    for(int i=0; i<size; i++) {
        for(int j=0; j<3; j++) {
            inputOctal[i][j] = input[i] % 8;
            input[i] = input[i] / 8;
        }
    }

    int side = sqrt(size*3);

    if(side*side < size*3) {
        side++;
    }

    FILE *output;
    output = fopen("output.ppm", "w");

    fprintf(output, "P3\n");
    fprintf(output, "%d %d\n", side, side);
    fprintf(output, "255\n");
    // WIP
    for (int i=0; i<size; i++) {
        for (int k=0; k<3; k++) {
            switch (inputOctal[i][k]) {
                case 0:
                    fprintf(output, BLACK);
                    break;
                case 1:
                    fprintf(output, RED);
                    break;
                case 2:
                    fprintf(output, GREEN);
                    break;
                case 3:
                    fprintf(output, BLUE);
                    break;
                case 4:
                    fprintf(output, YELLOW);
                    break;
                case 5:
                    fprintf(output, CYAN);
                    break;
                case 6:
                    fprintf(output, MAGENTA);
                    break;
                case 7:
                    fprintf(output, WHITE);
                    break;
            }
            fprintf(output, "  ");
        }
        fprintf(output, "\n");
    }

    for(int i=0; i<(side*side)-size; i++) {
        fprintf(output, FILL);
        fprintf(output, "  ");
    }

    fclose(output);
    return 0;
}

int getInputSize(char filename[]) {
    FILE *file;
    char ch;
    int count = 0;

    file = fopen(filename, "r");
    while ((ch = fgetc(file)) != EOF) {
        count++;
    }

    fclose(file);
    return count;
}

void getInput(char filename[], char input[], int size) {
    FILE *file;
    file = fopen(filename, "r");

    for(int i=0; i<size; i++) {
        input[i] = fgetc(file);
    }
    fclose(file);
}