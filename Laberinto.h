#ifndef LABERINTO_H_INCLUDED
#define LABERINTO_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/* Macro Definition */

#define LAB_SIZE 20

/* Public Function Prototyping */

void init_lab ( unsigned char lab[LAB_SIZE][LAB_SIZE], uint8_t entrada[2], uint8_t salida [2] );

void fill_lab ( unsigned char lab[LAB_SIZE][LAB_SIZE] );


#endif // LABERINTO_H_INCLUDED
