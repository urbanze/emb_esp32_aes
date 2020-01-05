#include <mbedtls\aes.h>


mbedtls_aes_context aes;

unsigned char key[] = "1234567890123456";
unsigned char  iv[] = "1234567890123456";

char bla[] = "0123456789012345678901234567890123456789012345678901234567890123456789";
unsigned char out[16];
unsigned char inp[16];



void setup()
{
	Serial.begin(115200);

	mbedtls_aes_init(&aes);
	mbedtls_aes_setkey_enc(&aes, key, 128);
}

void loop()
{
    Serial.printf("\r\n\r\nPlaintext: ");
    Serial.printf("%s\n", bla);

    Serial.printf("Chipertext: ");
    for (int i = 0; i < strlen(bla); i += 16)
    {
        if (bla[i] == 0)
            {break;}
        
        memset(inp, 0, sizeof(inp));
        memset(out, 0, sizeof(out));

        for (int j = (0 + i); j < (16 + i); j++)
        {
            if (bla[j] != 0)
                {inp[j-i] = bla[j];}
            else
                {break;}
        }

        mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, 16, iv, inp, out);
        
        for (int j = 0; j < 16; j++)
        {
           Serial.printf("%02x ", out[j]);
        }
    }

    delay(5000);
}
