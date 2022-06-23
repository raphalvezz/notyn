#include <stdio.h>
#include <stdlib.h>

#define MAX_QUANTIDADE 20

//função para imprimir as opções do menu 

void menu()
{
	
	printf("\t\t _______\n");
	printf("\t\t|   |   |.-----..-----..--.--.\n");
	printf("\t\t|       ||  -__||     ||  |  |\n");
	printf("\t\t|__|_|__||_____||__|__||_____|\n");
	printf("\n\n\t  |[1] Para ver eventos\n");
	printf("\t  |[2] Para ver todas as pessoas\n");
	printf("\t  |[3] Para ver as pessoas de acordo com sua orientacao sex.\n");
	printf("\t  |[4] Para adicionar um evento\n");
	printf("\t  |[5] Ver eventos acontecendo agora\n");
	printf("\t  |[6] Para cadastrar uma nova pessoa\n");
	printf("\t  |[7] Para cadastrar uma pessoa em um Evento\n");
	printf("\t  |[0] Para sair\n\n");
	printf("\t  |Insira um valor de 0 a 7: ");

}

void telaInicio()
{
	printf(" ______                                  __            __                           _______         __\n");
	printf("|   __ \\.-----..--------. ______ .--.--.|__|.-----..--|  |.-----.  .---.-..-----.  |    |  |.-----.|  |_ .--.--..-----.\n");
	printf("|   __ <|  -__||        ||______||  |  ||  ||     ||  _  ||  _  |  |  _  ||  _  |  |       ||  _  ||   _||  |  ||     |\n");
	printf("|______/|_____||__|__|__|         \\___/ |__||__|__||_____||_____|  |___._||_____|  |__|____||_____||____||___  ||__|__|\n");
	printf("                                                                                                         |_____|\n");

	printf("\t\t                 __                __\n");
	printf("\t\t.----..---.-..--|  |.---.-..-----.|  |_ .----..-----. ______ .-----..-----.\n");
	printf("\t\t|  __||  _  ||  _  ||  _  ||__ --||   _||   _||  -__||______||__ --||  -__|\n");
	printf("\t\t|____||___._||_____||___._||_____||____||__|  |_____|        |_____||_____|\n\n");
}

//definindo as structs

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
	
//inicializando as structs	
	
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
	
	tamanho_pessoas = 6;
	
//cadastro do usuário

	telaInicio();
	printf("\n\t  |Digite seu nome: ");
	fgets(usuario_nome, 25, stdin);

	do{
		printf("\n\t  |Digite sua idade: ");
		scanf("%d",&usuario_idade);
		if (usuario_idade<18)
			printf("\n\t  [voce deve ser maior de idade]\n\n");
		else if (usuario_idade>120)
			printf("\n\t  [IDADE INVALIDA]\n\n");

	}while(usuario_idade<18 || usuario_idade>120);
	
	do{

		printf("\n\t  |Masculino - 'm'");
		printf("\n\t  |Feminino - 'f'");
		printf("\n\t  |Digite seu sexo (m/f): ");
		_flushall();
		scanf("%c", &usuario_sexo);
		if (usuario_sexo != 'm' && usuario_sexo != 'f')
			printf("\n\t  [sexo invalido! digite 'm' para masculino e 'f' para feminino]\n");
	}while(usuario_sexo != 'm' && usuario_sexo != 'f');

	do{
		printf("\n\t  |Heterossexual - 'e'");
		printf("\n\t  |Bissexual - 'b'");
		printf("\n\t  |Homossexual - 'o'");
		printf("\n\t  |Digite sua orientacao sexual (e/b/o): ");	
		_flushall();
		scanf("%c",&usuario_orientacao_sexual);
		if (usuario_orientacao_sexual != 'e' && usuario_orientacao_sexual != 'b' && usuario_orientacao_sexual != 'o' )
			printf("\n\t  [orientacao sexual invalida!]");
	}while(usuario_orientacao_sexual != 'e' && usuario_orientacao_sexual != 'b' && usuario_orientacao_sexual != 'o' );
	
	printf("\n\t  [cadastro finalizado!]\n\n");
	printf("\t  |seus dados:\n");
	printf("\t  |nome: %s",usuario_nome);
	printf("\t  |idade: %d\n",usuario_idade);
	printf("\t  |sexo: %c\n",usuario_sexo);
	printf("\t  |orientacao sexual: %c\n\n\n",usuario_orientacao_sexual);
	
	struct PESSOAS *ptrPessoas = NULL;
	ptrPessoas = p;
	
	
	do{
		do{
			menu();
			scanf("%d",&opcao);
			if (opcao<0 || opcao>8)
				printf("\n\t  [valor invalido insira um valor de 1 a 7]");
			if (opcao == 0)
				break;
				
			switch (opcao)
			{
				
			//vizualização dos eventos	
				
			case 1:
				for(i=0; i < tamanho_eventos; i++)
					printf("\n\t  |Nome: %s\n\t  |descricao: %s\n\t  |endereco: %s\n\t  |horario: %dh\n\t  |data: %d/%d\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				break;
				
			//vizualização de todas as pessoas	
				
			case 2:
				for (i=0; i < tamanho_pessoas; i++)
					{
						printf("\n\t  |Nome: %s\n\t  |Idade: %d\n\t  |Sexo: %c\n\t  |Orientacao Sexual: %c\n", ptrPessoas->nome, ptrPessoas->idade, ptrPessoas->sexo, ptrPessoas->orientacao_sexual);
						ptrPessoas++;
					}
				break;
				
			//vizualização das pessoas de acordo com a orientação sexual	
				
			case 3:	
				if (usuario_sexo == 'm')
				{	
					if (usuario_orientacao_sexual == 'e')
					{
						for(i=0; i < tamanho_pessoas; i++)
							{
								if (p[i].sexo  == 'f' && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
									printf("\n\t  |Nome: %s\n\t  |Idade: %d\n\t  |Sexo: %c\n\t  |Orientacao Sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
							}
					}
							
					else if (usuario_orientacao_sexual == 'b')
					{
						for(i=0; i < tamanho_pessoas; i++)
						{
							if (p[i].sexo == 'm' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') || p[i].sexo == 'f'  && (p[i].orientacao_sexual == 'e' || p[i].orientacao_sexual == 'b'))
								printf("\n\t  |Nome: %s\n\t  |Idade: %d\n\t  |Sexo: %c\n\t  |Orientacao Sexual: %c\n\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
						}
					}
					else
					{
						for(i=0; i < tamanho_pessoas; i++)
						{
							if (p[i].sexo  == 'm' && (p[i].orientacao_sexual == 'o' || p[i].orientacao_sexual == 'b') )
								printf("\n\t  |Nome: %s\n\t  |Idade: %d\n\t  |Sexo: %c\n\t  Orientacao Sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
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
								printf("\n\t  |Nome: %s\nIdade: %d\nSexo: %c\n\t Orientacao Sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
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
				
			//cadastrar eventos		
				
			case 4:
				for (i= tamanho_eventos; i<MAX_QUANTIDADE; i++)
				{
					fflush(stdin);
					printf("\n\t  |Nome do evento: ");
					fgets(e[i].nome, 25, stdin);
					printf("\n\t  |Descricao do evento: ");
					fgets(e[i].descricao, 75, stdin);
					printf("\n\t  |Endereco do evento: ");
					fgets(e[i].endereco, 50, stdin);
					do{
						printf("\n\t  |Horario do evento (formato 24h)\n");
						scanf("%d",&e[i].horario);
						if (e[i].horario<0 || e[i].horario>24)
							printf("\n\t  [horario invalido!]");
					}while(e[i].horario<0 || e[i].horario>24);
								
					do{
						printf("\n\t  |Dia do evento (1 a 31): ");
						scanf("%d",&e[i].dia);
						if (e[i].dia<1 || e[i].dia>31)
							printf("\n\t  [dia invalido!]\n");
					}while(e[i].dia<1 || e[i].dia>31);
							
					do{
						printf("\n\t  |Mes do evento (1 a 12): ");
						scanf("%d",&e[i].mes);
						if(e[i].mes<1 || e[i].mes>12)
							printf("\n\t  [Mes invalido!]\n");
					}while(e[i].mes<1 || e[i].mes>12);
					cont++;
					tamanho_eventos++;
					
					do{
						printf("\n\t  |Quer cadastrar mais um evento?(s/n): ");
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
					printf("\n\t  |Nome: %s\n\t  |Descricao: %s\n\t  |Endereco: %s\n\t  |Horario: %dh\n\n\t  |Data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				
				break;
				
			//vizualizar eventos acontecendo hoje	
				
			case 5:
				do{
					printf("\n\t  |Que dia e hoje? ");
					scanf("%d",&dia_atual);
					if (dia_atual<1 || dia_atual>31)
						printf("\n\t  [dia invalido!]\n");
				}while(dia_atual<1 || dia_atual>31);
				
				do{
				printf("\n\t  |Em que mes estamos? ");
				scanf("%d",&mes_atual);
				if (mes_atual<1 || mes_atual>12)
					printf("mes invalido!\n");
				}while(mes_atual<1 || mes_atual>12);
		
				for(i=0; i < tamanho_eventos; i++)
					if (e[i].dia == dia_atual && e[i].mes == mes_atual)
						printf("\n\t  |Nome: %s\n\t  |Descricao: %s\n\t  |Endereco: %s\n\t  |Horario: %dh\n\n\t  |Data: %d/%d\n\n\n", e[i].nome, e[i].descricao, e[i].endereco, e[i].horario, e[i].dia, e[i].mes);
				break;
				
			//cadastrar pessoas	
				
			case 6:
				for (i=tamanho_pessoas; i<MAX_QUANTIDADE; i++)
				{
					fflush(stdin);
					printf("\n\t  |Digite seu nome: ");
					fgets(p[i].nome, 25, stdin);
				
					do{
						printf("\n\t  |Digite sua idade: ");
						scanf("%d",&p[i].idade);
						if (p[i].idade<18)
							printf("\n\t  [voce deve ser maior de idade]\n\n");
						else if (p[i].idade>120)
							printf("\n\t  [idade invalida!]\n\n");
					}while(p[i].idade<18 || p[i].idade>120);
					
					do{
						printf("\n\t  |Digite seu sexo (m/f)\n");
						printf("\n\t  |Masculino - m");
						printf("\n\t  |Feminino - f\n\t   ");
						_flushall();
						scanf("%c", &p[i].sexo);
						if (p[i].sexo != 'm' && p[i].sexo != 'f')
							printf("\n\t  [sexo invalido! digite 'm' para masculino e 'f' para feminino]\n");
					}while(p[i].sexo != 'm' && p[i].sexo != 'f');
				
					do{
						printf("\n\t  |Digite sua orientacao sexual (e/b/o)\n");
						printf("\n\t  |Heterossexual - 'e'\n");
						printf("\n\t  |Bissexual - 'b'\n");
						printf("\n\t  |Homossexual- 'o'\n\t   ");
						_flushall();
						scanf("%c",&p[i].orientacao_sexual);
						if (p[i].orientacao_sexual != 'e' && p[i].orientacao_sexual != 'b' && p[i].orientacao_sexual != 'o' )
							printf("[orientacao sexual invalida!]\n");
					}while(p[i].orientacao_sexual != 'e' && p[i].orientacao_sexual != 'b' && p[i].orientacao_sexual != 'o' );
					contador++;
					tamanho_pessoas++;	
					
					do{
						printf("\n\t  |Quer cadastrar mais uma pessoa?(s/n): ");
						_flushall();
						scanf("%c",&resposta_pessoa);
						if (resposta_pessoa != 'n' && resposta_pessoa != 's')
							printf("[resposta invalida]\n\n");
					}while(resposta_pessoa != 'n' && resposta_pessoa != 's');
					if (resposta_pessoa == 'n')
						break;
				}
			
				total_pessoas = 6 + contador;
				for (i=0; i < total_pessoas; i++)
					printf("\n\t  |Nome: %s\n\t  |Idade: %d\n\t  |Sexo: %c\n\t  |Orientacao sexual: %c\n", p[i].nome, p[i].idade, p[i].sexo, p[i].orientacao_sexual);
			break;
			
			//cadastrar uma pessoa a um evento
			
			case 7:
				printf("\n\t  ------\n");
				printf("\n\t  Eventos\n");
				printf("\n\t  ------\n\n");
				for(i=0; i < tamanho_eventos; i++)
					printf("\n\t  |Codigo: %d\nnome: %s\n", i, e[i].nome);
				printf("\n\t  ------\n");
				printf("\n\t  Pessoas\n");
				printf("\n\t  ------\n\n");
				for (i=0; i<tamanho_pessoas; i++)
				{
					printf("%s\n", p[i].nome);
					printf("\n\t  ------\n");
				}
				
				for (i=0; i < MAX_QUANTIDADE; i++)
				{
					do{
					
						printf("\n\t  |Qual cod do Evento?\n\t  ");
						scanf("%d",&pe[i].codigo);
						
						fflush(stdin);
						printf("\n\t  |Qual seu nome?\n\t  ");
						fgets(pe[i].pessoa, 25, stdin);
						tamanho_ep++;
						
						printf("\n\t  |Quer cadastrar mais uma pessoa a um evento?(s/n)\n\t  ");
						_flushall();
						scanf("%c",&resposta_pe);
						if (resposta_pe != 'n' && resposta_pe != 's')
							printf("\n\t  [resposta invalida]\n\n");
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



