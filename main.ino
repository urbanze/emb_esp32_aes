#include <mbedtls\arc4.h>

mbedtls_arc4_context arc4;//Cria a estrutura do Arc4.

unsigned char key[] = "1234567890123456";//Chave usada no algoritmo. Esta chave deve ser aleatoria!!!
unsigned char input[] = "Seguranca da informacao. Embarcados";//Texto que sera criptografado.
unsigned char output[200];//Vetor de saida. 

void setup()
{
	Serial.begin(115200);//Inicia a comm. Serial.
	int size = sizeof(input)-1;//Atribui (size) ao tamanho da mensagem de input menos um (NULL TERMINATOR).

	mbedtls_arc4_init(&arc4);//Inicializa o Arc4.
	mbedtls_arc4_setup(&arc4, key, 16);//Configura a chave e seu tamanho em Bytes.
	mbedtls_arc4_crypt(&arc4, size, input, output);//Faz a criptografia do input e retorna os valores no output

	Serial.println("Criptograma: ");
	for (int i = 0; i < size; i++)
	{
		Serial.print(output[i], HEX);
		Serial.print(" ");
	}
}

void loop()
{

}
