typedef struct pessoa {
   char nome;
   int idade;
} PESSOA;

typedef struct pessoas{
  PESSOA pessoa[2];
} PESSOAS;
int main()
{
	PESSOAS pessoas;
	pessoas.pessoa[0].idade = 1;
	pessoas.pessoa[0].nome = 'a';
	pessoas.pessoa[1].idade = 2;
	pessoas.pessoa[1].nome = 'b';
	
	int i;
	for (i = 0; i < 2; i++) {
	  printf("nome %c idade %d \n", pessoas.pessoa[i].nome,
	  pessoas.pessoa[i].idade);
	}
}

