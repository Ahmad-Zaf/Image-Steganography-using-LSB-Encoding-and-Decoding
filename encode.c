#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HEADER_SIZE 54

void encodeLSB(const char *inputImage, const char *outputImage, const char *message) {
    FILE *inFile = fopen(inputImage, "rb");
    FILE *outFile = fopen(outputImage, "wb");

    if (!inFile || !outFile) {
        printf("Error opening files.\n");
        exit(1);
    }

    // Copy BMP header
    unsigned char header[HEADER_SIZE];
    fread(header, sizeof(unsigned char), HEADER_SIZE, inFile);
    fwrite(header, sizeof(unsigned char), HEADER_SIZE, outFile);

    int msgLen = strlen(message);
    unsigned char ch;
    int bitIndex = 0, charIndex = 0;

    while (fread(&ch, sizeof(unsigned char), 1, inFile) == 1) {
        if (charIndex <= msgLen) {
            unsigned char msgChar = (charIndex < msgLen) ? message[charIndex] : '\0';
            unsigned char bit = (msgChar >> bitIndex) & 1;
            ch = (ch & 0xFE) | bit;

            bitIndex++;
            if (bitIndex == 8) {
                bitIndex = 0;
                charIndex++;
            }
        }
        fwrite(&ch, sizeof(unsigned char), 1, outFile);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Message successfully encoded into %s\n", outputImage);
}

int main() {
    char inputImage[100], outputImage[100], message[512];

    printf("=== LSB ENCODER ===\n");
    printf("Enter input BMP image: ");
    scanf("%s", inputImage);
    printf("Enter output BMP image: ");
    scanf("%s", outputImage);
    getchar(); // clear newline
    printf("Enter message to encode: ");
    fgets(message, sizeof(message), stdin);
    message[strcspn(message, "\n")] = 0;

    encodeLSB(inputImage, outputImage, message);

    return 0;
}
