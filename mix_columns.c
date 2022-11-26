#include "aes.h"

unsigned char FFmul(unsigned char a, unsigned char b)
{
	unsigned char bw[4];
	unsigned char res = 0;
	int i;
	bw[0] = b;
	for (i = 1; i < 4; i++)
	{
		bw[i] = bw[i - 1] << 1;
		if (bw[i - 1] & 0x80)
		{
			bw[i] ^= 0x1b;
		}
	}
	for (i = 0; i < 4; i++)
	{
		if ((a >> i) & 0x01)
		{
			res ^= bw[i];
		}
	}
	return res;
}

void mix_columns(unsigned char state[][4])
{
	unsigned char t[4];
	int r, c;
	for (c = 0; c < 4; c++)
	{
		for (r = 0; r < 4; r++)
		{
			t[r] = state[r][c];
		}
		for (r = 0; r < 4; r++)
		{
			state[r][c] = FFmul(0x02, t[r])
				^ FFmul(0x03, t[(r + 1) % 4])
				^ FFmul(0x01, t[(r + 2) % 4])
				^ FFmul(0x01, t[(r + 3) % 4]);
		}
	}
}

void inv_mix_columns(unsigned char state[][4])
{
	unsigned char t[4];
	int r, c;
	for (c = 0; c < 4; c++)
	{
		for (r = 0; r < 4; r++)
		{
			t[r] = state[r][c];
		}
		for (r = 0; r < 4; r++)
		{
			state[r][c] = FFmul(0x0e, t[r])
				^ FFmul(0x0b, t[(r + 1) % 4])
				^ FFmul(0x0d, t[(r + 2) % 4])
				^ FFmul(0x09, t[(r + 3) % 4]);
		}
	}
}

