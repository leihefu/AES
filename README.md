基于c语言的AES加密算法，目录中有visual stdio 工程，可直接下载测试

#include <stdio.h>
#include "aes.h"

uint8_t key[16] = { 
	0x2b, 0x7e, 0x15, 0x16,
	0x28, 0xae, 0xd2, 0xa6,
	0xab, 0xf7, 0x15, 0x88,
	0x09, 0xcf, 0x4f, 0x3c 
};

uint8_t data[16] = { 
	0x32,0x88,0x31,0xe0,
	0x43,0x5a,0x31,0x37,
	0xf6,0x30,0x98,0x07,
	0xa8,0x8d,0xa2,0x34 
};

int main(void)
{
	aes_init(key);

	printf("密钥是:\r\n");
	for (int i = 0; i < 16; i++) 
	{
		printf("%x ", key[i]);
		if ((i + 1) % 4 == 0)
			printf("\r\n");
	}
	printf("\r\n");

	printf("明文是:\r\n");
	for (int i = 0; i < 16; i++) 
	{
		printf("%x ", data[i]);
		if ((i + 1) % 4 == 0)
			printf("\r\n");
	}
	printf("\r\n");

	//输出密文
	aes_encrypt(data, 16);
	printf("密文是:\r\n");
	for (int i = 0; i < 16; i++) 
	{
		printf("%x ", data[i]);
		if ((i + 1) % 4 == 0)
			printf("\r\n");
	}
	printf("\r\n");

	//再次进行解密
	printf("密文解密是:\r\n");
	aes_decrypt(data, 16);
	for (int i = 0; i < 16; i++) 
	{
		printf("%x ", data[i]);
		if ((i + 1) % 4 == 0)
			printf("\r\n");
	}
}
