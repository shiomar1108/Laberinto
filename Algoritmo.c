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
            printf("\n Norte... ");
            /* Girar Derecha: Este*/
            if ( jugador.pos_act[0]+1 < LAB_SIZE && lab[jugador.pos_act[0]+1][jugador.pos_act[1]] != 'M' )
            {
               jugador.pos_act[0] += 1;
                jugador.dir = Este;
                printf("Derecha \n");
            }
            else
            {
                /* Seguir Recto: Norte */
                if ( jugador.pos_act[1]-1 >= 0  && lab[jugador.pos_act[0]][jugador.pos_act[1]-1] != 'M' )
                {
                    jugador.pos_act[1] -= 1;
                    printf("Adelante \n");
                }
                else
                {
                    /*Girar Izquierda: Oeste */
                    if ( jugador.pos_act[0]-1 >= 0 && lab[jugador.pos_act[0]-1][jugador.pos_act[1]] != 'M' )
                    {
                        jugador.pos_act[0] -= 1;
                        jugador.dir = Oeste;
                        printf("Izquierda \n");
                    }
                    else
                    {
                        /* Regresarse: Sur*/
                        jugador.pos_act[1] += 1;
                        jugador.dir = Sur;
                        printf("Atras \n");
                    }
                }
            }
        break;

        case Oeste:
            printf("\n Oeste... ");
            /* Girar Derecha: Norte*/
            if ( jugador.pos_act[1]-1 >= 0 && lab[jugador.pos_act[0]][jugador.pos_act[1]-1] != 'M' )
            {
               jugador.pos_act[1] -= 1;
                jugador.dir = Norte;
                printf("Derecha \n");
            }
            else
            {
                /* Seguir Recto: Oeste */
                if ( jugador.pos_act[0]-1 >= 0 && lab[jugador.pos_act[0]-1][jugador.pos_act[1]] != 'M' )
                {
                    jugador.pos_act[0] -= 1;
                    printf("Adelante \n");
                }
                else
                {
                    /*Girar Izquierda: Sur */
                    if ( jugador.pos_act[1]+1 < LAB_SIZE && lab[jugador.pos_act[0]][jugador.pos_act[1]+1] != 'M' )
                    {
                        jugador.pos_act[1] += 1;
                        jugador.dir = Sur;
                        printf("Izquierda \n");
                    }
                    else
                    {
                        /* Regresarse: Este*/
                        jugador.pos_act[0] += 1;
                        jugador.dir = Sur;
                        printf("Atras \n");
                    }
                }
            }
        break;

        case Sur:
            printf("\n Sur... ");
            /* Girar Derecha: Oeste*/
            if ( jugador.pos_act[0]-1 >= 0 && lab[jugador.pos_act[0]-1][jugador.pos_act[1]] != 'M' )
            {
               jugador.pos_act[0] -= 1;
                jugador.dir = Oeste;
                printf("Derecha \n");
            }
            else
            {
                /* Seguir Recto: Sur */
                if ( jugador.pos_act[1]+1 < LAB_SIZE && lab[jugador.pos_act[0]][jugador.pos_act[1]+1] != 'M' )
                {
                    jugador.pos_act[1] += 1;
                    printf("Adelante \n");
                }
                else
                {
                    /*Girar Izquierda: Este */
                    if ( jugador.pos_act[0]+1 < LAB_SIZE && lab[jugador.pos_act[0]+1][jugador.pos_act[1]] != 'M' )
                    {
                        jugador.pos_act[0] += 1;
                        jugador.dir = Este;
                        printf("Izquierda \n");
                    }
                    else
                    {
                        /* Regresarse: Sur*/
                        jugador.pos_act[1] -= 1;
                        jugador.dir = Norte;
                        printf("Atras \n");
                    }
                }
            }
        break;

        case Este:
            printf("\n Este... ");
            /* Girar Derecha: Sur*/
            if ( jugador.pos_act[1]+1 < LAB_SIZE && lab[jugador.pos_act[0]][jugador.pos_act[1]+1] != 'M' )
            {
               jugador.pos_act[1] += 1;
                jugador.dir = Sur;
                printf("Derecha \n");
            }
            else
            {
                /* Seguir Recto: Este */
                if ( jugador.pos_act[0]+1 < LAB_SIZE && lab[jugador.pos_act[0]+1][jugador.pos_act[1]] != 'M' )
                {
                    jugador.pos_act[0] += 1;
                    printf("Adelante \n");
                }
                else
                {
                    /*Girar Izquierda: Norte */
                    if ( jugador.pos_act[1]-1 >= 0 && lab[jugador.pos_act[0]][jugador.pos_act[1]-1] != 'M' )
                    {
                        jugador.pos_act[1] -= 1;
                        jugador.dir = Norte;
                        printf("Izquierda \n");
                    }
                    else
                    {
                        /* Regresarse: Oeste*/
                        jugador.pos_act[0] -= 1;
                        jugador.dir = Oeste;
                        printf("Atras \n");
                    }
                }
            }
        break;

        default:
            printf("\n Error... ");
        break;
    }
    jugador.mov++;
    jugador.done =check_Done(lab,jugador);
    return jugador;
}

bool check_Done ( unsigned char lab[LAB_SIZE][LAB_SIZE], persona_t jugador )
{
    if ( lab[jugador.pos_act[0]][jugador.pos_act[0]] == 'S')
    {
        return true;
    }
    return false;
}


