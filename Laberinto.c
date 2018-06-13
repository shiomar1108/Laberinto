#include "Laberinto.h"
/* Global variable definition */

/*  Local function prototyping  */

void fill_lab ( unsigned char lab[LAB_SIZE][LAB_SIZE] );
bool found_row ( int x, uint64_t number[], int size );

/*  Function Declaration    */

bool found_row ( int x, uint64_t number[], int size )
{
    for(uint8_t i = 0; i < size; i++)
    {
        if(number[i] == x)
        {
            return true;
        }
    }
    return false;
}

void fill_lab( unsigned char lab[LAB_SIZE][LAB_SIZE] )
{
    uint8_t i;
	uint8_t j;
	for (i = 0; i < LAB_SIZE; i++)
	{
		for (j = 0; j < LAB_SIZE; j++)
		{
			lab[j][i] = '.';
		}
	}
	/* TODO: Usar User Inputs */
    uint64_t elements_row0[20] = {0,1,2,3,4,5,6,7,8,9,10,11};
    uint64_t elements_row1[20] = {0,1,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19};
    uint64_t elements_row2[20] = {0,2,3,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19};
    uint64_t elements_row3[20] = {0,4,5,6,7,8,9,10,11,13,14,15,16,17,18,19};
    uint64_t elements_row4[20] = {0,2,3,4,5,6,7,8,9,10,11,18,19};
    uint64_t elements_row5[20] = {0,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19};
    uint64_t elements_row6[20] = {0,2,3,4,5,6,7,8,9,10,11,12,14,15,16,17,18,19};
    uint64_t elements_row7[20] = {0,14,15,16,17,18,19};
    uint64_t elements_row8[20] = {0,2,3,4,5,6,7,8,10,11,12,14,15,16,17,18,19};
    uint64_t elements_row9[20] = {0,2,3,4,5,6,7,8,10,11,12,14,15,16,17,18,19};
    uint64_t elements_row10[20] = {0,2,3,4,5,6,7,8,10,11,12,13,14,15,16,17,18,19};
    uint64_t elements_row11[20] = {0,10,11,12,13,14,15,16,17,18,19};
    uint64_t elements_row12[20] = {0,2,3,4,5,6,8,9,10,11,12,13,14,15,16,17,18,19};
    uint64_t elements_row13[20] = {0,2,3,4,5,6,8,9,10,11,12,13,19};
    uint64_t elements_row14[20] = {0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19};
    uint64_t elements_row15[20] = {0,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19};
    uint64_t elements_row16[20] = {0,17,18,19};
    uint64_t elements_row17[20] = {0,1,2,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19};
    uint64_t elements_row18[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,17,18,19};
    uint64_t elements_row19[20] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

    for (uint8_t i = 0; i < LAB_SIZE; i++)
    {
        if(found_row(i,elements_row0,18))
        {
            lab[i][0] = 77;
        }
        if(found_row(i,elements_row1,18))
        {
            lab[i][1] = 77;
        }
        if(found_row(i,elements_row2,18))
        {
            lab[i][2] = 77;
        }
        if(found_row(i,elements_row3,18))
        {
            lab[i][3] = 77;
        }
        if(found_row(i,elements_row4,18))
        {
            lab[i][4] = 77;
        }
        if(found_row(i,elements_row5,18))
        {
            lab[i][5] = 77;
        }
        if(found_row(i,elements_row6,18))
        {
            lab[i][6] = 77;
        }
        if(found_row(i,elements_row7,18))
        {
            lab[i][7] = 77;
        }
        if(found_row(i,elements_row8,18))
        {
            lab[i][8] = 77;
        }
        if(found_row(i,elements_row9,18))
        {
            lab[i][9] = 77;
        }
        if(found_row(i,elements_row10,18))
        {
            lab[i][10] = 77;
        }
        if(found_row(i,elements_row11,18))
        {
            lab[i][11] = 77;
        }
        if(found_row(i,elements_row12,18))
        {
            lab[i][12] = 77;
        }
        if(found_row(i,elements_row13,18))
        {
            lab[i][13] = 77;
        }
        if(found_row(i,elements_row14,18))
        {
            lab[i][14] = 77;
        }
        if(found_row(i,elements_row15,18))
        {
            lab[i][15] = 77;
        }
        if(found_row(i,elements_row16,18))
        {
            lab[i][16] = 77;
        }
        if(found_row(i,elements_row17,18))
        {
            lab[i][17] = 77;
        }
        if(found_row(i,elements_row18,18))
        {
            lab[i][18] = 77;
        }
        if(found_row(i,elements_row19,18))
        {
            lab[i][19] = 77;
        }
    }
}

void init_lab ( unsigned char lab[LAB_SIZE][LAB_SIZE], uint8_t entrada[2], uint8_t salida [2] )
{
    fill_lab(lab);
    /* Definicion de la Entrada */
    lab[entrada[0]][entrada[1]] = 69;

    /* Definicion de la Salida */
    lab[salida[0]][salida[1]] = 83;
}


