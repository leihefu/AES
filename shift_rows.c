#include "aes.h"

void shift_rows(unsigned char state[][4])
{
	unsigned char t[4];
	int r, c;
	for (r = 1; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			t[c] = state[r][(c + r) % 4];
		}
		for (c = 0; c < 4; c++)
		{
			state[r][c] = t[c];
		}
	}
}

void inv_shift_rows(unsigned char state[][4])
{
	unsigned char t[4];
	int r, c;
	for (r = 1; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			t[c] = state[r][(c - r + 4) % 4];
		}
		for (c = 0; c < 4; c++)
		{
			state[r][c] = t[c];
		}
	}
}


