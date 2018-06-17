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

    char op = 'd';
    char more = 'Y';
    uint8_t temp[2] = {0,0};

    /*Inizializacion de variables de entrada y salida del laberinto */
    uint8_t sal[2] = {0,0};
    uint8_t ent[2] = {0,0};

    /* Usuario Ingresa las coodenadas de entrada */
    printf("\n Diga la entrada al laberinto ? (x): ");
    scanf("%u", &ent[0]);
    printf("\n Diga la entrada al laberinto ? (y): ");
    scanf("%u", &ent[1]);

    /*Usuario Ingresa corrdenadas de salida*/
    printf("\n Diga la salida al laberinto ? (x): ");
    scanf("%u", &sal[0]);
    printf("\n Diga la salida al laberinto ? (y): ");
    scanf("%u", &sal[1]);
    /* Linea para evitar que la siguiente lectura que se quede con el ENTER anterior */
    getchar();

    /* Inizializacion  de juador */
    jug = init_jugador(jug,ent);

    /* Inizializacion del laberinto */
    printf("\n Quiere usar el laberinto por default (d) o crear uno nuevo (n): ");
    scanf("%c", &op);

    if(op == 'd')
    {
        printf("\n Laberinto Default... \n");
        init_lab(lab,ent, sal);
    }
    else
    {
        printf("\n Laberinto de Usuario... \n");
        lab[sal[0]][sal[1]] = 'S';
        lab[ent[0]][ent[1]] = 'E';
        while (more != 'n')
        {
            /* Obtener la posicion del muro del usuario */
            printf("\n Diga la posicion del muro ? (x): ");
            scanf("%u", &temp[0]);
            printf("\n Diga la posicion del muro ? (y): ");
            scanf("%u", &temp[1]);

            /* Linea para evitar que la siguiente lectura que se quede con el ENTER anterior */
            getchar();
            lab[temp[0]][temp[1]] = 'M';

            /* Validacion de querer otro muro */
            printf("\n Quiere otro muro (y/n): ");
            scanf("%c", &more);
        }
    }
    /* Impresion del tablero previa a la solucion */
    print_board(lab,jug);

    /* Pausa previa solucion */
    getchar();
    printf("\n Pulse ENTER para iniciar solucion: ");
    getchar();

    /* Loop de solucion */
    while( !jug.done )
    {
        /* Rutina de Solucion del Laberinto*/
        jug = Solucion(lab,jug);
        /* Impresion del laberinto para debug */
        //print_board(lab,jug);
    }
    /*Impresion final para ver al jugador en la salida */
    print_board(lab,jug);
}



