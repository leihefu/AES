#include "aes.h"


void sub_bytes(unsigned char state[][4])
{
	int r, c;
	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			state[r][c] = Sbox[state[r][c]];
		}
	}
}

void inv_sub_bytes(unsigned char state[][4])
{
	int r, c;
	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			state[r][c] = InvSbox[state[r][c]];
		}
	}
}
