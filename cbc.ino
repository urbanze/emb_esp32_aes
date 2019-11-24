#include <mbedtls\aes.h>

mbedtls_aes_context aes;

unsigned char key[] = "1234567890123456";
unsigned char  iv[] = "1234567890123456";


String bla = "Embarcados";
unsigned char out[16];
unsigned char inp[16]; 

void setup()
{
	Serial.begin(115200);

	int size = sizeof(bla);

	for (int i = 0; i < size; i++)
	{
		inp[i] = bla[i];
	}

	for (int i = size; i < 16; i++)
	{
		inp[i] = 0;
	}
	
	mbedtls_aes_init(&aes);
	mbedtls_aes_setkey_enc(&aes, key, 128);
}

void loop()
{
	Serial.print("\n\nIV: ");
	for (int i = 0; i < 16; i++)
	{
		Serial.print(iv[i], HEX);
		Serial.print(" ");
	}

	mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, 16, iv, inp, out);

	Serial.printf("\nChipertext: ");
	for (int i = 0; i < 16; i++)
	{
		Serial.print(out[i], HEX);
		Serial.print(" ");
	}

	delay(5000);
}
