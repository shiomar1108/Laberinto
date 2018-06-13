#ifndef ALGORITMO_H_INCLUDED
#define ALGORITMO_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "Laberinto.h"

enum direccion
{
    Norte,
    Oeste,
    Sur,
    Este
};

typedef struct
{
    uint8_t pos_act[2];
    uint8_t mov;
    bool done;
    enum direccion dir;
} persona_t;

/* Protyping of public functions */

persona_t init_jugador( persona_t jugador, uint8_t pos[2]);

persona_t Solucion( unsigned char lab[LAB_SIZE][LAB_SIZE], persona_t jugador);

bool check_Done ( unsigned char lab[LAB_SIZE][LAB_SIZE], persona_t jugador );

#endif // ALGORITMO_H_INCLUDED
