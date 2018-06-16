/*
 ============================================================================
 Name        : Laberinto.c
 Author      : Shiomar Salazar
 Version     :
 Copyright   : Free to use.
 Description : Solution for Algorithm Project # 3
 ============================================================================
 */

#include <stdio.h>
#include <stdint.h>
#include "Laberinto.h"
#include "Algoritmo.h"

void print_board ( unsigned char lab[LAB_SIZE][LAB_SIZE], persona_t jugador )
{
	for (uint8_t i = 0; i < LAB_SIZE; i++)
	{
		for (uint8_t j = 0; j < LAB_SIZE; j++)
		{
			if(jugador.pos_act[0] == j && jugador.pos_act[1] == i)
            {
                printf ("|P|");

            }
			else
			{
                printf ("|%c|", lab[j][i]);
			}
		}
		printf ("\n");
	}

    printf("Posicion Actual: %i , %i \n",jugador.pos_act[0],jugador.pos_act[1]);
    printf("Cantidad de Movimientos: %i \n",jugador.mov);
    printf("Se resolvio el laberinto ?: %d \n", jugador.done);
}

unsigned char lab[LAB_SIZE][LAB_SIZE];
persona_t jug;

int main(void) {

    uint8_t sal[2] = {0,0};
    uint8_t ent[2] = {0,0};

    printf("\n Diga la entrada al laberinto ? (x,y):");
    //scanf("");
    printf("\n Diga la salida al laberinto ? (x,y):");
    //scanf("");

    init_lab(lab,ent, sal);
    jug = init_jugador(jug,ent);

    while( !jug.done )
    {
        jug = Solucion(lab,jug);
        //print_board(lab,jug);
    }
}



