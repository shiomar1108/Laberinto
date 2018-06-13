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

    switch(jugador.dir)
    {
        case Norte:
            printf("\n Norte... \n");
            /* Seguir Norte */
            /*if (jugador.pos_act[0]+1 >)
            {
             
            }*/

        break;

        case Oeste:
            printf("\n Oeste... \n");
            /* Seguir Oeste */
             if ( ( jugador.pos_act[1]-1 < 0 || lab[jugador.pos_act[0]][jugador.pos_act[1]-1] == 'M' ) && lab[jugador.pos_act[0]-1][jugador.pos_act[1]] != 'M' )
            {
                jugador.pos_act[0] -= 1;
                printf("\n Adelante \n");
            }
            else
            {
                /* Girar al sur */
                if ( ( lab[jugador.pos_act[0]-1][jugador.pos_act[1]] == 'M' || jugador.pos_act[0]-1 < 0 ) && ( jugador.pos_act[1]-1 < 0 || lab[jugador.pos_act[0]][jugador.pos_act[1]-1] == 'M' ) )
                {
                    jugador.pos_act[1] += 1;
                    jugador.dir = Sur;
                    printf("\n Izquierda \n");
                }
                /* Girar Norte */
                else
                {   
                    jugador.pos_act[1] -= 1;
                    jugador.dir = Norte;
                    printf("\n Derecha \n");
                }
            }
        break;

        case Sur:
            printf("\n Sur... \n");
            /* Seguir Sur */
            if ( (jugador.pos_act[1]+1 < LAB_SIZE ) && (lab[jugador.pos_act[0]][jugador.pos_act[1]+1] != 'M') )
            {
               jugador.pos_act[1] += 1;
                printf("\n Adelante \n");
            }
            else
            {   
                /* Girar Este */
                if(( jugador.pos_act[1]+1 < LAB_SIZE ||  lab[jugador.pos_act[0]][jugador.pos_act[1]+1] == 'M') && ( lab[jugador.pos_act[0]+1][jugador.pos_act[1]] != 'M' ) )
                {
                    jugador.pos_act[0] += 1;
                    jugador.dir = Este;
                    printf("\n Derecha \n");
                }
                /* Girar Oeste */
                else
                {
                    jugador.pos_act[0] -= 1;
                    jugador.dir = Oeste;
                    printf("\n Izquierda \n");
                }
            }
        break;

        case Este:
            printf("\n Este... \n");
        break;

        default:
            printf("\n Error... \n");
        break; 
    }
    jugador.mov++;
    return jugador;
}

