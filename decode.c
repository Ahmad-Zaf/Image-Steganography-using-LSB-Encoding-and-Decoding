#include <stdio.h>
#include <stdlib.h>

#define HEADER_SIZE 54

void decodeLSB(const char *inputImage) {
    FILE *inFile = fopen(inputImage, "rb");
    if (!inFile) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(inFile, HEADER_SIZE, SEEK_SET);

    unsigned char ch, decodedChar = 0;
    int bitIndex = 0;

    printf("Decoded Message: ");

    while (fread(&ch, sizeof(unsigned char), 1, inFile) == 1) {
        decodedChar |= (ch & 1) << bitIndex;
        bitIndex++;

        if (bitIndex == 8) {
            if (decodedChar == '\0') break;
            printf("%c", decodedChar);
            decodedChar = 0;
            bitIndex = 0;
        }
    }
    printf("\n");

    fclose(inFile);
}

int main() {
    char inputImage[100];

    printf("=== LSB DECODER ===\n");
    printf("Enter BMP image to decode: ");
    scanf("%s", inputImage);

    decodeLSB(inputImage);

    return 0;
}
