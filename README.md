Image Steganography using LSB Encoding and Decoding

Overview --

This project implements a simple image steganography system that allows you to hide and extract text messages inside BMP images using Least Significant Bit (LSB) encoding. It is developed in C using file operations and bitwise manipulation.

Features

Encode a message into a BMP image without visually altering it.

Decode a message hidden inside a BMP image.

Supports uncompressed 24-bit BMP images.

Simple and easy-to-use command-line interface.

How It Works --

Encoding -

Reads the BMP header (54 bytes) unchanged.

Hides each bit of the message into the least significant bit of each pixel byte.

Writes the modified pixel data into a new BMP file.

Decoding -

Reads the pixel data from the BMP.

Extracts the LSBs sequentially to reconstruct the hidden message.


Screenshot of the Output---

[Output}(https://github.com/Ahmad-Zaf/Image-Steganography-using-LSB-Encoding-and-Decoding/blob/main/Output/Output.png?raw=true)
