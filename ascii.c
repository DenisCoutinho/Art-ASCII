/*-------------------------------------------------------------------------
 *             Unifal - Universidade Federal de Alfenas
 *                BACHARELADO EM CIENCIA DA COMPUTACAO
 * Trabalho..: Imagem ASCII
 * Disciplina: Processamento de Imagens
 * Professor.: Luiz Eduardo da Silva
 * Aluno.....: Denis Mendes Coutinho
 * Dara......: 25/04/2023
 *-------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "imagelib.h"

void msg(char *programName) {
    printf("\nARTE ASCII");
    printf("\n-------------------------------");
    printf("\nUso:  %s  <nome=arquivo=imagem> <ncolunas> <nlinhas> <string>[.pgm]\"\n\n", programName);
    exit(1);
}

void process_image(char *inName, char *outName, int userNumCols, int userNumRows, char *charString) {
    int numRows, numCols, maxLevel;

    img_name(inName, inName, outName, GRAY);
    image inputImage = img_get(inName, &numRows, &numCols, &maxLevel, GRAY);
    image outputImage = img_alloc(numRows, numCols);

    int charStringLength = strlen(charString);
    char characterArray[charStringLength + 1];
    for (int i = 0; i < charStringLength; i++) {
        characterArray[i] = charString[i];
    }

    int rowSkip = numRows / userNumRows;
    int colSkip = numCols / userNumCols;

    int px, py;
    for (int i = 0; i < userNumRows; i++) {
        for (int j = 0; j < userNumCols; j++) {
            px = j * colSkip;
            py = i * rowSkip;
            outputImage[i * userNumCols + j] = inputImage[py * numCols + px];
        }
    }

    char result[userNumRows * userNumCols];
    for (int i = 0; i < userNumRows * userNumCols; i++) {
        int newLevel = pow(outputImage[i], 0.5) / pow(maxLevel, 0.5) * charStringLength;
        outputImage[i] = newLevel;
        result[i] = characterArray[outputImage[i]];
    }

    FILE *filePointer;
    filePointer = fopen("result.txt", "w");
    if (filePointer == NULL) {
        printf("Erro ao criar arquivo de saida.\n");
        exit(1);
    }
    for (int i = 0; i < userNumRows; i++) {
        for (int j = 0; j < userNumCols; j++) {
            fprintf(filePointer, "%c", result[i * userNumCols + j]);
        }
        fprintf(filePointer, "\n");
    }
    fclose(filePointer);

    img_put(outputImage, outName, userNumRows, userNumCols, charStringLength, GRAY);
    char cmd[110];
    sprintf(cmd, "%s %s &", VIEW, outName);
    system(cmd);
    img_free(inputImage);
    img_free(outputImage);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        msg(argv[0]);
    }

    char inName[100], outName[100];
    strcpy(inName, argv[1]);
    int userNumCols = atoi(argv[2]);
    int userNumRows = atoi(argv[3]);
    char charString[strlen(argv[4]) + 1];
    strcpy(charString, argv[4]);

    process_image(inName, outName, userNumCols, userNumRows, charString);

    return 0;
}
