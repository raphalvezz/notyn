
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




