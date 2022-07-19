#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "BMini Bolsa.h"

typedef struct{
	char name[100], city[100], pass[100];
	int yearsold;
	float cash;
}account;

char username[100], pass[100];

int login()
{
	FILE *doc;
	account inf;
	int veri;
	printf("Digite seu nome de usuario: ");
	fflush(stdin);
	scanf("%[^\n]", username);
	
	printf("\nAgora digite sua senha: ");
	fflush(stdin);
	scanf("%[^\n]", pass);
	
	strcat(username, ".txt");
	doc=fopen(username, "rb");
	if(doc==NULL)
	{
		system("cls");
		printf("-----------ALERTA!----------\n");
		printf("| NOME DE USUARIO OU SENHA |\n");
		printf("|    ESTAO INCORRETOS!     |\n");
		printf("----------------------------\n");
		return 0;
	}
	else
	{
		fread(&inf, sizeof(inf), 1, doc);
		veri=strcmp(inf.pass, pass);
		if(veri==1)
		{
			system("cls");
			printf("-----------ALERTA!----------\n");
			printf("| NOME DE USUARIO OU SENHA |\n");
			printf("|    ESTAO INCORRETOS!     |\n");
			printf("----------------------------\n");
			return 0;
		}
		else
		{
			return 1;
		}
	}
	
}

void regis()
{
	int num, num2=0;
	char user[100];
	FILE *doc;
	account regis;
	printf("Digite seu nome completo: ");
	fflush(stdin);
	scanf("%[^\n]", regis.name);
	
	printf("\nDigite sua idade: ");
	scanf("%i", &regis.yearsold);
	
	printf("\nDigite o nome da cidade em que reside: ");
	fflush(stdin);
	scanf("%[^\n]", regis.city);
	
	system("cls");
	printf("----------ALERTA!----------\n");
	printf("| O NOME DE USUARIO SERA  |\n");
	printf("| USADO PARA FAZER LOGIN  |\n");
	printf("|  JUNTO DE SUA SENHA     |\n");
	printf("---------------------------\n");
	printf("| O NOME DE USUARIO DEVE  |\n");
	printf("|   POSSUIR NO MINIMO 6   |\n");
	printf("|      CARACTERES         |\n");
	printf("---------------------------\n");
	
	
	printf("Digite um novo nome de Usuario: ");
	do
	{
		do
		{
			fflush(stdin);
			scanf("%[^\n]", user);
			
			num=strlen(user);
			if(num<=6)
			{
				printf("-------------ALERTA!------------\n");
				printf("| NOME DE USUARIO MUITO CURTO! |\n");
				printf("|        TENTE OUTRO!          |\n");
				printf("--------------------------------\n");
			}
		}
		while(num<=6);
		strcat(user, ".txt");
		doc=fopen(user, "rb");
		if(doc!=NULL)
		{
			printf("----------ALERTA!----------\n");
			printf("|    NOME DE USUARIO JA   |\n");
			printf("|       ESTA EM USO!      |\n");
			printf("|       TENTE OUTRO!      |\n");
			printf("---------------------------\n");
			fclose(doc);
		}
		else
		{
			num2++;
		}
		
	}while(num2!=1);
	
	system("cls");
	printf("---------------------------\n");
	printf("|     SUA SENHA DEVE      |\n");
	printf("|   POSSUIR NO MINIMO 6   |\n");
	printf("|      CARACTERES         |\n");
	printf("---------------------------\n");
	printf("Digite uma nova senha: ");
	do
	{
		fflush(stdin);
		scanf("%[^\n]", regis.pass);
		
		num=strlen(regis.pass);
		if(num<=6)
		{
			printf("-------------ALERTA!------------\n");
			printf("|     SENHA MUITO CURTA!       |\n");
			printf("|        TENTE OUTRO!          |\n");
			printf("--------------------------------\n");
		}
		
	}
	while(num<=6);
	doc=fopen(user, "ab");
	fwrite(&regis, sizeof(regis), 1, doc);
	fclose(doc);
	doc=fopen("Register.txt", "ab");
	fwrite(&user, sizeof(user), 1, doc);
	fclose(doc);
	
	system("cls");
	printf("----------PARABENS!---------");
	printf("|    CADASTRO REALIZADO    |");
	printf("|       COM SUCESSO!       |");
	printf("----------------------------");
}

main()
{
	char bt1, bt2, bt3;
	int val;
	do
	{
		text(1);
		bt1=getche();
		system("cls");
		switch(bt1)
		{
			case '1':
				{
					val=login();
					if(val==1);
					{
						do
						{
							FILE *doc;
							account log;
							doc=fopen(username, "rb");
							fread(&log, sizeof(log), 1, doc);
							system("cls");
							printf("\n---------------PERFIL--------------\n");
							printf("%s\n", log.name);
							printf("Cash: R$%.2f\n", log.cash);
							printf("-----------------------------------\n");
							printf("|   1       -->  DEPOSITAR/SACAR  |\n");
							printf("|   2       -->       ACOES       |\n");
							printf("|   3       -->  EXCLUIR OPERACAO |\n");
							printf("|   4       -->       SAIR        |\n");
							printf("-----------------------------------\n");
							bt2=getche();
							switch(bt2)
							{
								case '1':
									{
										do
										{
											printf("----------------------\n");
											printf("| 1  --->  DEPOSITAR |\n");
											printf("| 2  --->    SACAR   |\n");
											printf("| 3  --->   VOLTAR   |\n");
											printf("----------------------\n");
											switch(bt3)
											{
												
											}
										}
										while()
										break;
									}
								
							}
						}
						while()
					}
					
					break;
				}
			case '2':
				{
					regis();
					break;
				}
			case '3':
				{
					printf("----------ENCERRANDO!----------\n");
					printf("|        VOLTE SEMPRE!        |\n");
					printf("-------------------------------\n");
					break;
				}
			default:
				{
					system("cls");
					text(2);
					break;
				}
		}	
	}
	while(bt1!='3');
	
}
