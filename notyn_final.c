#include <stdio.h>
#include <stdlib.h>
#define MAX_QUANTIDADE 20

void menu()
{
	printf("\n\n-----MENU DE OPCOES-----\n");
	printf("[1] para ver eventos\n");
	printf("[2] para ver todas as pessoas\n");
	printf("[3] para ver as pessoas de acordo com sua orientacao sex.\n");
	printf("[4] para adicionar um evento\n");
	printf("[5] ver eventos acontecendo agora\n");
	printf("[6] para cadastrar uma nova pessoa\n");
	printf("[7] para cadastrar uma pessoa em um Evento\n");
	printf("[0] para sair\n");
}

struct EVENTOS{
    char nome[25];
	char descricao[75];
	char endereco[50];
	int horario,dia,mes;
};

struct PESSOAS_EVENTOS{
    int codigo;
	char pessoa[25];
};

struct PESSOAS{
    char nome[30];
    int idade;
    char sexo;
    char orientacao_sexual;
};

	int i, j, opcao, dia_atual,mes_atual,cont = 0, total_eventos = 0, contador = 0, total_pessoas = 0, tamanho_eventos, tamanho_pessoas, tamanho_ep=0, usuario_idade;
	char resposta_evento, resposta_pessoa, resposta_pe, usuario_nome[25], usuario_sexo, usuario_orientacao_sexual;

int main(){
	struct PESSOAS_EVENTOS pe[MAX_QUANTIDADE];

	struct EVENTOS e[MAX_QUANTIDADE] = {{"balada","evento open bar com musicas pop",
	"avenida abobrinha 165 jardim america",20,17,06},
	
	{"rodeio","rodeio com diversos shows de sertanejo e atracoes",
	"rua riacho 399 jardim didinha",19,18,06},
	
	{"bar","bar com karaoke sala de jogos e excelentes comidas",
	"rua arco iris 846 jardim florida",18,19,06},	
	
	{"rave","evento de musica eletronica com otimos djs em um sitio maravilhoso",
	"estrada joaquim 137 jardim olimpia",17,17,06},
	
	{"show de rock","show com diversas bandas e muito rock",
	"estadio do bandeirao",21,18,06},
	
	{"festa junina","arraia divertido e com muita comida boa",
	"avenida juscelino 789",15,19,06}};
	
	tamanho_eventos = 6;
		
	struct PESSOAS p[MAX_QUANTIDADE] = {{"ana",19,'f','e'}, 
	{"julia",27,'f','b'},
	{"bia",20,'f','o'},
	{"joao",18,'m','e'},
	{"gui",24,'m','b'},	
	{"luiz",28,'m','o'}};
	
	tamanho_pessoas = 7;
	

	printf("digite seu nome\n");
	fgets(usuario_nome, 25, stdin);

	do{
		printf("digite sua idade\n");
		scanf("%d",&usuario_idade);
		if (usuario_idade<18)
			printf("voce deve ser maior de idade\n\n");
		else if (usuario_idade>120)
			printf("idade invalida\n\n");
	}while(usuario_idade<18 || usuario_idade>120);
	
	do{
		printf("digite seu sexo (m/f)\n");
		printf("masculino-m\n");
		printf("feminino-f\n");
		_flushall();
		scanf("%c", &usuario_sexo);
		if (usuario_sexo != 'm' && usuario_sexo != 'f')
			printf("sexo invalido! digite 'm' para masculino e 'f' para feminino \n");
	}while(usuario_sexo != 'm' && usuario_sexo != 'f');

	do{
		printf("digite sua orientacao sexual (e/b/o)\n");
		printf("heterossexual - 'e'\n");
		printf("bissexual - 'b'\n");
		printf("homossexual- 'o'\n");
		_flushall();
		scanf("%c",&usuario_orientacao_sexual);
		if (usuario_orientacao_sexual != 'e' && usuario_orientacao_sexual != 'b' && usuario_orientacao_sexual != 'o' )
			printf("orientacao sexual invalida!\n");
	}while(usuario_orientacao_sexual != 'e' && usuario_orientacao_sexual != 'b' && usuario_orientacao_sexual != 'o' );
	
	printf("\n\ncadastro finalizado!\n");
	printf("seus dados:\n");
	printf("nome: %s\n",usuario_nome);
	printf("idade: %d\n",usuario_idade);
	printf("sexo: %c\n",usuario_sexo);
	printf("orientacao sexual: %c\n\n\n",usuario_orientacao_sexual);
	
	struct PESSOAS *ptrPessoas = NULL;
	ptrPessoas = p;
	
	
	do{
		do{
			menu();
			scanf("%d",&opcao);
			if (opcao<0 || opcao>8)
				printf("insira um valor de 1 a 7");
			if (opcao == 0)
				break;
				
			switch (opcao)
			{
			case 1:
				for(i=0; i < tamanho_eventos; i++)
					printf("nome: %s\ndescricao: %s\nendereco: %s\nhorario: %dh\n data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				break;
				
			case 2:
				for (i=0; i < tamanho_pessoas; i++)
					{
						printf("Nome: %s\nIdade: %d\nSexo: %c\n orientacao sexual: %c\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->orientacao_sexual);
						ptrPessoas++;
					}
				break;
			case 3:	
				if (usuario_sexo == 'm')
				{	
					if (usuario_orientacao_sexual == 'e')
					{
						for(i=0; i < tamanho_pessoas; i++)
							{
								if (p[i].sexo  == 'f' && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
									printf("Nome: %s\nIdade: %d\nSexo: %c\n orientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
							}
					}
							
					else if (usuario_orientacao_sexual == 'b')
					{
						for(i=0; i < tamanho_pessoas; i++)
						{
							if (p[i].sexo == 'm' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') || p[i].sexo == 'f'  && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
								printf("Nome: %s\nIdade: %d\nSexo: %c\n orientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
						}
					}
					else
					{
						for(i=0; i < tamanho_pessoas; i++)
						{
							if (p[i].sexo  == 'm' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') )
								printf("Nome: %s\nIdade: %d\nSexo: %c\n orientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
						}
					}
				}
				
				else
				{	
					if (usuario_orientacao_sexual == 'e')
					{
						for(i=0; i < tamanho_pessoas; i++)
						{
							if (p[i].sexo  == 'm' && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
								printf("Nome: %s\nIdade: %d\nSexo: %c\n orientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
						}
					}
						
					else if (usuario_orientacao_sexual == 'b')
					{
						for(i=0; i < tamanho_pessoas; i++)
						{
							if (p[i].sexo == 'f' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') || p[i].sexo == 'm' && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
								printf("Nome: %s\nIdade: %d\nSexo: %c\n orientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
						}
					}
					else
					{
						for(i=0; i < tamanho_pessoas; i++)
						{
							if (p[i].sexo == 'f' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b'))
								printf("Nome: %s\nIdade: %d\nSexo: %c\n orientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
						}
					}
				}
				break;		
				
			case 4:
				for (i= tamanho_eventos; i<MAX_QUANTIDADE; i++)
				{
					fflush(stdin);
					printf("Nome do evento\n");
					fgets(e[i].nome, 25, stdin);
					printf("Descricao do evento\n");
					fgets(e[i].descricao, 75, stdin);
					printf("Endereco do evento\n");
					fgets(e[i].endereco, 50, stdin);
					do{
						printf("horario do evento (formato 24h)\n");
						scanf("%d",&e[i].horario);
						if (e[i].horario<0 || e[i].horario>24)
							printf("horario invalido!");
					}while(e[i].horario<0 || e[i].horario>24);
								
					do{
						printf("dia do evento (1 a 31)\n");
						scanf("%d",&e[i].dia);
						if (e[i].dia<1 || e[i].dia>31)
							printf("dia invalido!\n");
					}while(e[i].dia<1 || e[i].dia>31);
							
					do{
						printf("mes do evento (1 a 12)\n");
						scanf("%d",&e[i].mes);
						if(e[i].mes<1 || e[i].mes>12)
							printf("mes invalido!\n");
					}while(e[i].mes<1 || e[i].mes>12);
					cont++;
					tamanho_eventos++;
					
					do{
						printf("quer cadastrar mais um evento?(s/n)\n");
						_flushall();
						scanf("%c",&resposta_evento);
						if (resposta_evento != 'n' && resposta_evento != 's')
							printf("resposta invalida\n\n");
					}while(resposta_evento != 'n' && resposta_evento != 's');
					if (resposta_evento == 'n')
						break;
				}
				total_eventos = 6 + cont;
				for (i=0; i < total_eventos; i++)
					printf("nome: %s\ndescricao: %s\nendereco: %s\nhorario: %dh\n data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				
				break;
				
				
			case 5:
				do{
					printf("que dia e hoje?\n");
					scanf("%d",&dia_atual);
					if (dia_atual<1 || dia_atual>31)
						printf("dia invalido!\n");
				}while(dia_atual<1 || dia_atual>31);
				
				do{
				printf("em que mes estamos?\n");
				scanf("%d",&mes_atual);
				if (mes_atual<1 || mes_atual>12)
					printf("mes invalido!\n");
				}while(mes_atual<1 || mes_atual>12);
		
				for(i=0; i < tamanho_eventos; i++)
					if (e[i].dia == dia_atual && e[i].mes == mes_atual)
						printf("nome: %s\ndescricao: %s\nendereco: %s\nhorario: %dh\n data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				break;
			case 6:
				for (i=tamanho_pessoas; i<MAX_QUANTIDADE; i++)
				{
					fflush(stdin);
					printf("digite seu nome\n");
					fgets(p[i].nome, 25, stdin);
				
					do{
						printf("digite sua idade\n");
						scanf("%d",&p[i].idade);
						if (p[i].idade<18)
							printf("voce deve ser maior de idade\n\n");
						else if (p[i].idade>120)
							printf("idade invalida\n\n");
					}while(p[i].idade<18 || p[i].idade>120);
					
					do{
						printf("digite seu sexo (m/f)\n");
						printf("masculino-m\n");
						printf("feminino-f\n");
						_flushall();
						scanf("%c", &p[i].sexo);
						if (p[i].sexo != 'm' && p[i].sexo != 'f')
							printf("sexo invalido! digite 'm' para masculino e 'f' para feminino \n");
					}while(p[i].sexo != 'm' && p[i].sexo != 'f');
				
					do{
						printf("digite sua orientacao sexual (e/b/o)\n");
						printf("heterossexual - 'e'\n");
						printf("bissexual - 'b'\n");
						printf("homossexual- 'o'\n");
						_flushall();
						scanf("%c",&p[i].orientacao_sexual);
						if (p[i].orientacao_sexual != 'e' && p[i].orientacao_sexual != 'b' && p[i].orientacao_sexual != 'o' )
							printf("orientacao sexual invalida!\n");
					}while(p[i].orientacao_sexual != 'e' && p[i].orientacao_sexual != 'b' && p[i].orientacao_sexual != 'o' );
					contador++;
					tamanho_pessoas++;	
					
					do{
						printf("quer cadastrar mais uma pessoa?(s/n)\n");
						_flushall();
						scanf("%c",&resposta_pessoa);
						if (resposta_pessoa != 'n' && resposta_pessoa != 's')
							printf("resposta invalida\n\n");
					}while(resposta_pessoa != 'n' && resposta_pessoa != 's');
					if (resposta_pessoa == 'n')
						break;
				}
			
				total_pessoas = 6 + contador;
				for (i=0; i < total_pessoas; i++)
					printf("\nnome: %s\nidade: %d\nsexo: %c\norientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
			break;
			
			case 7:
				printf("\n------\n");
				printf("eventos\n");
				printf("------\n\n");
				for(i=0; i < tamanho_eventos; i++)
					printf("codigo: %d\nnome: %s\n", i, e[i].nome);
				printf("\n------\n");
				printf("pessoas\n");
				printf("------\n\n");
				for (i=0; i<tamanho_pessoas; i++)
				{
					printf("%s\n", p[i].nome);
					printf("------\n");
				}
				
				for (i=0; i < MAX_QUANTIDADE; i++)
				{
					do{
					
						printf("Qual cod do Evento?\n");
						scanf("%d",&pe[i].codigo);
						
						fflush(stdin);
						printf("Qual seu nome?\n");
						fgets(pe[i].pessoa, 25, stdin);
						tamanho_ep++;
						
						printf("quer cadastrar mais uma pessoa a um evento?(s/n)\n");
						_flushall();
						scanf("%c",&resposta_pe);
						if (resposta_pe != 'n' && resposta_pe != 's')
							printf("resposta invalida\n\n");
					}while(resposta_pe != 'n' && resposta_pe != 's');
					if (resposta_pe == 'n')
						break;
				}
				
						
				for (i = 0; i < tamanho_ep; i++)
				{
					
					printf("\n%s", pe[i].pessoa);
					
					for (j = 0; j < tamanho_eventos; j++)
					{
						if (pe[i].codigo == j)
							printf("evento - %s", e[j].nome);
					}
								
				}
				break;
			
			default:
				break;
				
			}
		  }while(opcao>1 || opcao<8);
	}while(opcao != 0);
	
	return 0;	
}



