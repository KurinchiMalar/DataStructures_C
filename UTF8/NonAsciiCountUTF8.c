/* 
 * File:   NonAsciiCountUTF8.c
 * Author: KurinchiMalar
 *
 * Created on June 16, 2014, 8:20 PM
 */

#include <stdlib.h>

/*
 * 
 */
#include<stdio.h>
#include<string.h>

#define ASCII_LIMIT 0x80 // decimal --> 128

// macros for determining how many bytes 'ON' in input
#define TWO 0xC0 //   (1100 0000)
#define THREE 0xE0 // (1110 0000)
#define FOUR 0xF0 // (1111 0000)
#define FIVE 0xF8 // (1111 1000)
#define SIX 0xFC // (1111 1100)

#define BUFFER_SIZE 255 

int getNonAsciiCount(char str[]) {
    unsigned int nonAsciiCount = 0, step = 0, num = 0;
    char *ch = str;
    while (*ch != '\0') {
        num = (unsigned int) (*ch);

        num = num & 0xFF; // pulling the last byte from num 

        if (num > ASCII_LIMIT) {
                // is NonAscii > 128
            step = 0;
            if (num < TWO) {
                step = 2;
            } else if (num < THREE) {
                step = 3;
            } else if (num < FOUR) {
                step = 4;
            } else if (num < FIVE) {
                step = 5;
            } else if (num < SIX) {
                step = 6;
            }
          
            nonAsciiCount++;
            // pointer has to be incremented according to bytes traversed.
            ch += step;
        }
        // do nothing if ASCII
        ch++;
    }
    return nonAsciiCount;
}

int main(void) {
    FILE* fdesc = stdin;
    char buff[BUFFER_SIZE + 2]; /* 2 Extra for \0 & \n */
    memset(buff, 0, sizeof (buff));

    while (NULL != fgets(buff, BUFFER_SIZE + 1, fdesc))
        printf("%d\n", getNonAsciiCount(buff));
    return 0;
}

