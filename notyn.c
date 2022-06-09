
/*#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int idade;
    char sexo;
    char nome[100];
}Pessoa_individual;

typedef struct{
    Pessoa_individual pessoa
}Pessoa_total;

// Procedimento para imprimir os dados de uma Pessoa

void imprimirPessoa(Pessoa_total pessoas){
    printf("\n\tNome: %s", pessoas.Pessoa_individual.nome);
    printf("\tIdade: %d\n", pessoas.Pessoa_individual.idade);
    printf("\tSexo: %c\n", pessoas.Pessoa_individual.sexo);
}

// função que lê os dados de uma pessoa e retorna para quem chamou
Pessoa lerPessoa(){
    Pessoa_total pessoas;
    printf("\nDigite seu nome: ");
    fgets(pessoas.Pessoa_individual.nome, 100, stdin);
    printf("Digite sua idade: ");
    scanf("%d", &pessoas.Pessoa_individual.idade);
    scanf("%c");
    printf("Digite f ou m para o sexo:");
    scanf("%c", &pessoas.Pessoa_individual.sexo);
    return pessoas;
}

int main()
 {
    int i;
    Pessoa_total pessoas[3];

    for(i = 0; i < 3; i++)
        Pessoa_total[i] = lerPessoa();

    for(i = 0; i < 3; i++)
        imprimirPessoa(pessoas[i]);

    return 0;
}*/

#include <stdio.h>
#include <stdlib.h>
struct Pessoa1{
    int idade;
    char sexo;
    char nome[100];
};

struct Pessoa2{
    int idade;
    char sexo;
    char nome[100];
};

struct Pessoa3{
    int idade;
    char sexo;
    char nome[100];
};

struct evento1{
    char nome[100];
	char descricao[100];
};

struct evento2{
    char nome[100];
    char descricao[100];
};

int main() {
	struct Pessoa1 p1;
	struct Pessoa2 p2;
    struct Pessoa3 p3;

	struct evento1 e1;
	struct evento2 e2;
	
    p1.idade = 35;
    p1.sexo = 'm';
    strcpy(p1.nome,"joao");

	p2.idade = 27;
    p2.sexo = 'f';
    strcpy(p2.nome,"maria");
    
    p3.idade = 20;
    p3.sexo = 'f';
    strcpy(p3.nome,"julia");
    
    printf("Nome: %s\nIdade: %d\nSexo: %c\n", p1.nome, p1.idade, p1.sexo);
    printf("Nome: %s\nIdade: %d\nSexo: %c\n", p2.nome, p2.idade, p2.sexo);
    printf("Nome: %s\nIdade: %d\nSexo: %c\n", p3.nome, p3.idade, p3.sexo);

    return 0;
}




