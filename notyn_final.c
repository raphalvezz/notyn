#include <stdio.h>
#include <stdlib.h>
#define MAX_EVENTOS 20
#define MAX_PESSOAS 20
#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
 
struct EVENTOS{
    char nome[25];
	char descricao[50];
	char endereco[50];
	int horario,dia,mes;
};
struct PESSOAS{
    char nome[30];
    int idade;
    char sexo;
    char orientacao_sexual;
    char eventos[30]; 
};

	int idade_usuario,i,j,opcao,horario_cadastrado,dia_cadastrado,mes_cadastrado,dia_atual,mes_atual,cont = 0, total_eventos = 0, contador = 0, total_pessoas = 0, tamanho;
	char nome_usuario[25],evento_cadastrado[25],descricao_cadastrado[50],endereco_cadastrado[50];
	char sexo_usuario,orientacao_sexual_usuario,resposta, resp;

int main(){
	
	struct EVENTOS e[MAX_EVENTOS] = {{"balada","evento open bar com musicas pop",
	"avenida abobrinha 165 jardim america",20,17,06},
	
	{"rodeio","rodeio com diversos shows de sertanejo e atracoes",
	"rua riacho 399 jardim didinha",19,18,06},
	
	{"bar","bar com karaoke sala de jogos e excelentes comidas",
	"rua arco iris 846 jardim florida",18,19,06},	
	
	{"rave","evento de musica eletronica com otimos djs em um sitio maravilhoso",
	"estrada joaquim 137 jardim olimpia",17,17,06},
	
	{"show de rock","show com diversas bandas e muito rock",
	"estadio do bandeirão",21,18,06},
	
	{"festa junina","arraia divertido e com muita comida boa",
	"avenida juscelino 789",15,19,06}};
	
	struct PESSOAS p[MAX_PESSOAS] = {{"ana",19,'f','e',"balada,rodeio,bar"}, 
	{"julia",27,'f','b',"rodeio,rave,show de rock"},
	{"bia",20,'f','o',"rave"},
	{"joao",18,'m','e',"bar,rave,show de rock"},
	{"gui",24,'m','b',"bar"},	
	{"luiz",28,'m','o',"rodeio"}};
	
	
	printf("digite seu nome\n");
	fgets(p[7].nome, 25, stdin);

	do{
		printf("digite sua idade\n");
		scanf("%d",&p[7].idade);
		if (p[7].idade<18)
			printf("voce deve ser maior de idade\n\n");
		else if (p[7].idade>120)
			printf("idade invalida\n\n");
	}while(p[7].idade<18 || p[7].idade>120);
	
	do{
		printf("digite seu sexo (m/f)\n");
		printf("masculino-m\n");
		printf("feminino-f\n");
		_flushall();
		scanf("%c", &p[7].sexo);
		if (p[7].sexo != 'm' && p[7].sexo != 'f')
			printf("sexo invalido! digite 'm' para masculino e 'f' para feminino \n");
	}while(p[7].sexo != 'm' && p[7].sexo != 'f');

	do{
		printf("digite sua orientacao sexual (e/b/o)\n");
		printf("heterossexual - 'e'\n");
		printf("bissexual - 'b'\n");
		printf("homossexual- 'o'\n");
		_flushall();
		scanf("%c",&p[7].orientacao_sexual);
		if (p[7].orientacao_sexual != 'e' && p[7].orientacao_sexual != 'b' && p[7].orientacao_sexual != 'o' )
			printf("orientacao sexual invalida!\n");
	}while(p[7].orientacao_sexual != 'e' && p[7].orientacao_sexual != 'b' && p[7].orientacao_sexual != 'o' );
	
	printf("\n\ncadastro finalizado!\n");
	printf("seus dados:\n");
	printf("nome: %s\n",p[7].nome);
	printf("idade: %d\n",p[7].idade);
	printf("sexo: %c\n",p[7].sexo);
	printf("orientacao sexual: %c\n\n\n",p[7].orientacao_sexual);
	
	struct PESSOAS *ptrPessoas = NULL;
	ptrPessoas = p;
	
	do{
		do{
			printf("\n\n-----MENU DE OPCOES-----\n");
			printf("[1] para ver eventos\n");
			printf("[2] para ver pessoas\n");
			printf("[3] para adicionar um evento\n");
			printf("[4] ver eventos acontecendo agora\n");
			printf("[5] para sair\n");
			scanf("%d",&opcao);
			if (opcao<1 || opcao>5)
				printf("insira um valor de 1 a 5");
			if (opcao == 5)
				break;
				
				
			switch (opcao)
			{
			case 1:
				for(i=0; i < 6; i++)
					printf("nome: %s\ndescricao: %s\nendereco: %s\nhorario: %dh\n data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				break;
				
			case 2:
				
				if (p[7].sexo == 'm')
				{	
					if (p[7].orientacao_sexual == 'e')
					{
						for(i=0; i < 6; i++)
							{
								if (p[i].sexo == 'f' && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
								{
									printf("Nome: %s\nIdade: %d\nSexo: %c\nEventos: %s\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->eventos);
									ptrPessoas++;
								}
									
									
							}
					}
							
					else if (p[7].orientacao_sexual == 'b')
					{
						for(i=0; i < 6; i++)
						{
							if (p[i].sexo == 'm' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') || p[i].sexo == 'f'  && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
							{
								printf("Nome: %s\nIdade: %d\nSexo: %c\nEventos: %s\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->eventos);
								ptrPessoas++;
							}
						}
					}
					else
					{
						for(i=0; i < 6; i++)
						{
							if (p[i].sexo == 'm' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') )
							{
								printf("Nome: %s\nIdade: %d\nSexo: %c\nEventos: %s\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->eventos);
								ptrPessoas++;
							}
						}
					}
				}
				
				else
				{	
					if (p[7].orientacao_sexual == 'e')
					{
						for(i=0; i < 6; i++)
						{
							if (p[i].sexo == 'm' && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
							{
								printf("Nome: %s\nIdade: %d\nSexo: %c\nEventos: %s\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->eventos);
								ptrPessoas++;
							}
						}
					}
						
					else if (p[7].orientacao_sexual == 'b')
					{
						for(i=0; i < 6; i++)
						{
							if (p[i].sexo == 'f' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') || p[i].sexo == 'm' && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
							{
								printf("Nome: %s\nIdade: %d\nSexo: %c\nEventos: %s\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->eventos);
								ptrPessoas++;
							}
						}
					}
					else
					{
						for(i=0; i < 6; i++)
						{
							if (p[i].sexo == 'f' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b'))
							{
								printf("Nome: %s\nIdade: %d\nSexo: %c\nEventos: %s\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->eventos);
								ptrPessoas++;
							}
						}
					}
				}
				break;		
				
			case 3:
				for (i= 6; i<MAX_EVENTOS; i++)
				{
					printf("Nome do evento\n");
					fgets(e[i].nome, 25, stdin);
					printf("\n");
					printf("Descricao do evento\n");
					fgets(e[i].descricao, 50, stdin);
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
					
					do{
						printf("quer cadastrar mais um evento?(s/n)\n");
						_flushall();
						scanf("%c",&resposta);
						if (resposta != 'n' && resposta != 's')
							printf("resposta invalida\n\n");
					}while(resposta != 'n' && resposta != 's');
					if (resposta == 'n')
						break;
				}
				total_eventos = 7 + cont;
				for (i=0; i < total_eventos; i++)
					printf("nome: %s\ndescricao: %s\nendereco: %s\nhorario: %dh\n data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				
				break;
				
				
			case 4:
			
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
		
				for(i=0; i < 6; i++)
					if (e[i].dia == dia_atual && e[i].mes == mes_atual)
						printf("nome: %s\ndescricao: %s\nendereco: %s\nhorario: %dh\n data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				break;
			case 5:
				for (i=6; i<MAX_PESSOAS; i++)
				{
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
						
					do{
						printf("quer cadastrar mais uma pessoa?(s/n)\n");
						_flushall();
						scanf("%c",&resp);
						if (resp != 'n' && resp != 's')
							printf("resposta invalida\n\n");
					}while(resp != 'n' && resp != 's');
					if (resp == 'n')
						break;
				}
			
				total_pessoas = 7 + contador;
				for (i=0; i < total_pessoas; i++)
					printf("nome: %s\nidade: %d\nsexo: %c\norientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
			
			default:
				break;
			}
		}while(opcao>1 || opcao<4);
	}while(opcao != 5);
	
	return 0;	
	}	


//int menu(int opcao)
//{

//	return opcao;
//}

