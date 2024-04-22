#ifndef __ANSWER04_H__
#define __ANSWER04_H__

#include <stdint.h>


#pragma pack(push)  // save the original data alignment
#pragma pack(1)     // Set data alignment to 1 byte boundary

/*
 * BMP files are laid out in the following fashion:
 *   --------------------------
 *   |          Header        |   54 bytes
 *   |-------------------------
 *   |       Image Data       |   file size - 54 (for 24-bit images)
 *   --------------------------
 */

/** 
 * BMP header (54 bytes).
 * uint16_t is 16-bit unsigned integer
 * uint32_t is 32-bit unsigned integer
 * int32_t is 32-bit signed integer
 */

typedef struct _BMP_header {
    uint16_t type;			// Magic identifier
    uint32_t size;			// File size in bytes
    uint16_t reserved1;			// Not used
    uint16_t reserved2;			// Not used
    uint32_t offset;			// Offset to image data in bytes from 
                                        // beginning of file (54 bytes)
    uint32_t DIB_header_size;		// DIB header size in bytes (40 bytes)
    int32_t  width;			// Width of the image
    int32_t  height;			// Height of image
    uint16_t planes;			// Number of color planes
    uint16_t bits;			// Bits per pixel
    uint32_t compression;		// Compression type
    uint32_t imagesize;			// Image size in bytes
    int32_t  xresolution;		// Pixels per meter
    int32_t  yresolution;		// Pixels per meter
    uint32_t ncolours;			// Number of colors  
    uint32_t importantcolours;		// Important colors
} BMP_header;

#pragma pack(pop) // restore the previous pack setting

typedef struct _BMP_image {
    BMP_header header;
    unsigned char *data; 
} BMP_image;

// Functions to be defined by students

// Read BMP_image from a given file
//
BMP_image *read_BMP_image(char *filename);

// Check the validity of the header with the file from which the header is read
//
int is_BMP_header_valid(BMP_header *bmp_hdr, FILE *fptr);

// Write BMP_image to a given file
//
int write_BMP_image(char *filename, BMP_image *image);

// Free memory in a given image
//
void free_BMP_image(BMP_image *image);

// Given a BMP_image, create a new 16-bit image that is converted from a given
// 24-bit image
//
BMP_image *convert_24_to_16_BMP_image(BMP_image *image);

// Given a BMP_image, create a new 16-bit image that is converted from a given
// 24-bit image
//
BMP_image *convert_16_to_24_BMP_image(BMP_image *image);

// Given a BMP_image, create with dithering a new 16-bit image that is 
// converted from a given 24-bit image 
//
BMP_image *convert_24_to_16_BMP_image_with_dithering(BMP_image *image);

#endif /* answer04.h */
