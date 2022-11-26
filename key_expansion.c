#include "aes.h"
#include <stdio.h>

void key_expansion(unsigned char* key, unsigned char w[][4][4])
{
	int i, j, r, c;
	unsigned char rc[] = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36 };
	for (r = 0; r < 4; r++)
	{
		for (c = 0; c < 4; c++)
		{
			w[0][r][c] = key[r + c * 4];
		}
	}
	for (i = 1; i <= 10; i++)
	{
		for (j = 0; j < 4; j++)
		{
			unsigned char t[4];
			for (r = 0; r < 4; r++)
			{
				t[r] = j ? w[i][r][j - 1] : w[i - 1][r][3];
			}
			if (j == 0)
			{
				unsigned char temp = t[0];
				for (r = 0; r < 3; r++)
				{
					t[r] = Sbox[t[(r + 1) % 4]];
				}
				t[3] = Sbox[temp];
				t[0] ^= rc[i - 1];
			}
			for (r = 0; r < 4; r++)
			{
				w[i][r][j] = w[i - 1][r][j] ^ t[r];
			}
		}
	}
}

