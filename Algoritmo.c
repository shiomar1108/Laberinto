#include "Algoritmo.h"

persona_t init_jugador( persona_t jugador, uint8_t pos[2])
{
    jugador.pos_act[0] = pos[0];
    jugador.pos_act[1] = pos[1];
    jugador.mov = 0;
    jugador.done = false;
    jugador.dir = Oeste;
    return jugador;
}

persona_t Solucion (unsigned char lab[LAB_SIZE][LAB_SIZE], persona_t jugador)
{
    /* Move to the fornt if valid*/
    if ((jugador.pos_act[1]-1 < 0 || lab[jugador.pos_act[0]][jugador.pos_act[1]-1] == 'M' )&& lab[jugador.pos_act[0]-1][jugador.pos_act[1]] == '.')
    {
        jugador.pos_act[0] -= 1;
        printf("\n Forward \n");
    }
    else
    {
        if((lab[jugador.pos_act[0]-1][jugador.pos_act[1]] == 'M' || jugador.pos_act[0]-1 < 0)&&(jugador.pos_act[1]-1 < 0 || lab[jugador.pos_act[0]][jugador.pos_act[1]-1] == 'M'))
        {
            jugador.pos_act[1] += 1;
            printf("\n Left \n");
        }
        else
        {
            jugador.pos_act[1] -= 1;
            printf("\n Right \n");
        }

    }
    jugador.mov++;
    return jugador;
}

