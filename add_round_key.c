#include "aes.h"

void add_round_key(unsigned char state[][4], unsigned char k[][4])
{
	int r, c;
	for (c = 0; c < 4; c++)
	{
		for (r = 0; r < 4; r++)
		{
			state[r][c] ^= k[r][c];
		}
	}
}