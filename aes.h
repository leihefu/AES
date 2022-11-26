#ifndef __AES_H
#define __AES_H

typedef		unsigned __int32	uint32_t;
typedef		unsigned __int16	uint16_t;
typedef		unsigned char		uint8_t;

extern unsigned char Sbox[256];
extern unsigned char InvSbox[256];
extern unsigned char w[11][4][4];

void key_expansion(unsigned char* key, unsigned char w[][4][4]);

void sub_bytes(unsigned char state[][4]);
void shift_rows(unsigned char state[][4]);
void mix_columns(unsigned char state[][4]);
void add_round_key(unsigned char state[][4], unsigned char k[][4]);

void inv_sub_bytes(unsigned char state[][4]);
void inv_shift_rows(unsigned char state[][4]);
void inv_mix_columns(unsigned char state[][4]);

void aes_init(unsigned char* key);
unsigned char* encrypt(unsigned char* input);
unsigned char* decrypt(unsigned char* input);
void* aes_encrypt(void* input, int length);
void* decrypt(void* input, int length)

#endif

