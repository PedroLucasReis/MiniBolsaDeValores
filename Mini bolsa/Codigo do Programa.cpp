//Nome: Pedro Lucas Correia dos Reis
//Código: 834539
//Link para o video: https://youtu.be/DCOAIiGFxGo

//bibliotecas padrão
#include <stdio.h>
#include <stdlib.h>

//Funções necessarias: (getche(), strlen(), toupper()...)
#include <ctype.h>
#include <conio.h>
#include <string.h>

/*Biblioteca criada e feita de maneira personalizada
e de uso exclusivo desse programa*/
#include "Biblioteca.h"


//Essa struct armazena as informaçoes de cada cliente, quantidade de ativos e saldo em conta
typedef struct{
	char prefer, nome[51], senha[11], cidade[51];
	int idade, wege2, itau2, taesa2, ambev2;;
	float money; 
}dados;

dados log;
//Para que todas as funçoes tenham acesso aos valores de cada ação, elas foram declaradas globalmente
float wege=74.94, itau=24.12, taesa=28.08, ambev=13.64;


//Ambas as structs foram usadas respeitando as ordens de preferencia de filas!
//Alem da diferenciação de fila preferencial e fila normal, a idade tambem tem um peso na sequencia!
//pessoas com mais idade passam na frente, tanto na fila preferencial quanto na fila normal!



//Faz os cadastros dos clientes
void cadastro();

//Faz o login
int log_ope();

//Mostra as ofertas do book
void book_ofer(char ativo);

//Compra e venda de ações.
//void operacao(char ope, char ativ, info *temp2/*info do cliente*/);

//Exclui as operações de compra e venda que estao no book de ofertas e nao foram executadas ainda
//void exclu_oper(info *temp7, int num);

//Corpo do programa
main()
{
	int cliente, i;
	char infinit, infinit3, infinit5, infinit7;
	//O while faz com que o programa se repita inumeras vezes sem encerrar
	//Assim o programa só se encera se a teclla de fechar for pressionada
	while(infinit!='4')
	{
		//MENU PRINCIPAL
		menus(1);
		infinit=getche();
		system("cls");
		
		switch(infinit)
		{
			case '1':
				{
					//Este if é para evitar que tenha a tentativa de login sem um cadastro antecipado
					FILE *cadastro;
					cadastro=fopen("Cadastros.txt", "rb");
					if(cadastro==NULL)
					{
						menus(6);
					}
					else
					{
						
						fclose(cadastro);
						
						
						infinit5='0';
						while(infinit5!='4')
						{
							
							menus(7);
							infinit5=getche();
							system("cls");
							/*novamente o while é declarado apenas para que o proximo menu seja
							encerrado quando a tecla "retornar" for pressionada*/
							switch(infinit5)
							{
								case '1':
									{
										infinit='0';
										while(infinit!='3')
										{
											
											menus(9);
											infinit=getche();
											system("cls");
											/*Nesse switch parece que as opções 1 e 2 sao iguais estruturalmente,
											porem um é para saque e outro para deposito. A função é a mesma, a mudança 
											esta no numero passado como parametro.
											Para ter um controle maior de tudo, o programa só vai retornar ao menu anterior
											caso a tecla certa seja pressionada, por isso o "default" nao foi usado como retorno*/
											switch(infinit)
											{
												case '1':
													{
														
														break;
													}
												case '2':
													{
														
														break;
													}
												case '3':
													{
														system("cls");
														printf("----------RETORNANDO!----------\n");
														break;
													}
												default:
													{
														/*Os menus são apenas uma sequencia de printf's que dão uma certa
														formatação paras as partes do programa. Logo, todos eles foram feitos na
														biblioteca feita apenas poara esse programa.
														Isso foi feito para diminuir o tamanho do codigo no corpo do programa*/
														system("cls");
														menus(8);
														break;
													}
											}
										}
										
										
										system("cls");
										break;
									}
								case '2':
									{	
										infinit3='0';
										while(infinit3!='5')
										{
											
											menus(10);
											infinit3=getche();
											system("cls");
											/*Esse switch faz a quebra entre operações entre cada ação diferente.
											Como cada case usa em media 50 linhas, para reduzir o tamanho do programa
											foram listadas apenas 4 ações diferentes. Na bolsa de valores real existem
											dezenas delas e isso tornaria o programa muito grande para ser avaliado,
											apenas dificultando a correção do codigo.
											obs: após fazer a primeira ação, só precisei copiar e editar para que
											atendesse as 4 açoes corretamente. Logo, a maioria tem quase a mesma 
											quantidade de linhas.
											Cada case tem seu respectivo book de ofertas, separando as ordens de compra
											e venda de diferentes ações visualmente.
											Vale lebrar que as açoes estão tecnicamente na mesma fila, mas este switch faz
											parte da separação entre elas durante a exibição*/
											switch(infinit3)
											{
												case '1':
													{
														system("cls");
														char infinit2;
														infinit2='0';
														while(infinit2!='3')
														{
															
															printf("----------WEG----------\n");
															printf("| PRECO ATUAL: R$%.2f |\n", wege);
															/*Este if é apenas para a estetica do programa.
															Caso tenha alguma ordem aberta nobbok ele ira exibir. Senão,
															para nao ficar totalmente vazio ele mostrara BOOK VAZIO*/
															
														
															menus(11);
															infinit2=getche();
															system("cls");
															/*Outra parte da separação de informções dos ativos é
															se as ordens são de compra ou venda. Quando as ordens forem exibidas,
															primeiramente serão exibidas as ordens de compra e depois as de venda.
															Isto tambem facilitou na construção da inseção de orens na função correspondente*/
															switch(infinit2)
															{
																case '1':
																	{
																		//operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '2':
																	{
																		//operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '3':
																	{
																		system("cls");
																		printf("----------RETORNANDO----------\n");
																		break;
																	}
																default:
																	{
																		system("cls");
																		//Menus(8): menu de tecla desconhecida.
																		//Feito para melhorar estetica e reduzir o tamanho do programa.
																		//É utilizada varias vezes.
																		menus(8);
																		break;
																	}
										
															}
														}
														break;
													}
												case '2':
													{
														system("cls");
														char infinit2;
														infinit2='0';
														/*Como eu disse em um comentario anterior, os cases são quase identicos 
														entre eles, o que muda são os ativos(WEGE, ITAU, TAESA E AMBEV).*/
														while(infinit2!='3')
														{
															printf("----------ITAU----------\n");
															printf("| PRECO ATUAL: R$%.2f |\n", itau);
														
															
															//exib_dados(3, 0, temp);
															menus(11);
															infinit2=getche();
															system("cls");
															switch(infinit2)
															{
																case '1':
																	{
																		//operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '2':
																	{
																		//operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '3':
																	{
																		system("cls");
																		printf("----------RETORNANDO----------\n");
																		break;
																	}
																default:
																	{
																		system("cls");
																		menus(8);
																		break;
																	}
										
															}
														}
														break;
													}
												case '3':
													{
														system("cls");
														char infinit2;
														infinit2='0';
														while(infinit2!='3')
														{	
															printf("----------TAESA----------\n");
															printf("| PRECO ATUAL: R$%.2f |\n", taesa);
															
															
															;
															menus(11);
															infinit2=getche();
															system("cls");
															switch(infinit2)
															{
																case '1':
																	{
																	//	operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '2':
																	{
																	//	operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '3':
																	{
																		system("cls");
																		printf("----------RETORNANDO----------\n");
																		break;
																	}
																default:
																	{
																		system("cls");
																		menus(8);
																		break;
																	}
										
															}
														}
														break;
													}
												case '4':
													{
														system("cls");
														char infinit2;
														infinit2='0';
														while(infinit2!='3')
														{
															printf("----------AMBEV----------\n");
															printf("| PRECO ATUAL: R$%.2f |\n", ambev);
																		
															
															menus(11);
															infinit2=getche();
															system("cls");
															switch(infinit2)
															{
																case '1':
																	{
																		//faz uma nova operação de compra
																	//	operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '2':
																	{
																		//Operação de venda
																	//	operacao(infinit2 , infinit3, temp);
																		break;
																	}
																case '3':
																	{
																		system("cls");
																		printf("----------RETORNANDO----------\n");
																		break;
																	}
																default:
																	{
																		system("cls");
																		menus(8);
																		break;
																	}
										
															}
														}
														break;
													}
												case '5':
													{
														system("cls");
														printf("----------RETORNANDO----------\n");
														break;
													}
												default:
													{
														system("cls");
														menus(8);
														break;
													}
														
											}
										}
										break;
									}
								case '3':
									{
										/*Este if é para evitar a tentativa de exclusao sem que nenhuma operação tenha
										sido feita no book de ofertas da "MINI BOLSA"*/
									/*	if(inicio2->prox!=NULL)
										{
											//Faz a exlusão de todas as operações em aberto do perfil que esta logado
											exclu_oper(temp, 1);
										}
										else
										{
											system("cls");
											printf("----------------ALERTA!----------------\n");
											printf("|    NENHUMA COMPRA/VENDA EM ABERTO   |\n");
											printf("|          RETORNANDO AO MENU         |\n");
											printf("---------------------------------------\n\n");
										}*/
										break;
									}
								case '4':
									{
										system("cls");
										printf("----------RETORNANDO----------\n");
										break;
									}
								default:
									{
										system("cls");
										menus(8);
										break;
									}
							}
						}
					}
					
					break;
				}
			case '2':
				{
					infinit7='0';
					while(infinit7!='4')
					{
						//MENU CLIENTES
						menus(2);
						infinit7=getche();
						switch(infinit7)
						{
							case '1':
								{
									//Faz o cadstro de novos clientes
									cadastro();
									system("cls");
									printf("-----------ALERTA!----------\n");
									printf("|  CADASTRO REALIZADO COM  |\n");
									printf("|         SUCESSO!         |\n");
									printf("----------------------------\n");
									break;
								}
							case '2':
								{
									system("cls");
									printf("\nObs 1: User e senha nao sao mostrados pois eles \nsao de conhecimento exclusivo e privado de cada usuario!\n\n");
									printf("Obs 2: Pessoas com maior idade passam na frente, tanto \nna fila preferencial quanto na fila normal!\n\n");
									//Exibe informações publicas dos clientes
									
									break;
								}
							case '3':
								{
									//Exclui os cadastros feiros
								//	excluir();
									break;
								}
							case '4':
								{
									system("cls");
									printf("RETORNANDO AO MENU PRINCIPAL...\n");
									break;
								}
							default:
								{
									system("cls");
									menus(8);
									break;
								}
						}
						
					}
					
					break;
				}
			case '3':
				{
					/*Como o menu ajuda são varios printf's, ele foi feito totalmenta na iblioteca,
					redizir o tamanho do arquivo principal do programa*/
					ajuda();
					break;	
				}
			case '4':
				{
					system("cls");
					printf("----------FECHANDO!----------\n");
					break;
				}
			default:
				{
					system("cls");
					menus(8);
					break;
				}
		}
	}
	system("pause");
}


void cadastro()
{
	FILE *cadastro;
	/*------------------*/
	system("cls");
	dados novo[2];
	int carac;
	char user[30];
	
	printf("\nDigite seu nome: ");
	fflush(stdin);
	scanf("%[^\n]", novo[0].nome);
	
	printf("\nDigite o nome da sua cidade: ");
	fflush(stdin);
	scanf("%[^\n]", novo[0].cidade);
	
	printf("\nDigite sua idade: ");
	scanf("%i", &novo[0].idade);
	
	/*Para deixar a "MINI BOLA DE VALORES" minimamente mais proxima da real,
	eu acrescentei um sistema de Usuari e senha.
	Dessa forma o programa ganha uma autenticidade melhor e mais apreciavel*/
	printf("DIGITE UM NOVO NOME DE USUARIO:");
	printf("Obs: O nome de usuario deve possuir \nno maximo 20 caracteres\n");
	do
	{
		fflush(stdin);
		scanf("%[^\n]", user);
		carac=strlen(user);
		
		if(carac>20)
		menus(3);
	}
	while(carac>20);
	
	strcat(user,".txt");
	cadastro=fopen(user,"rb");
	while(cadastro!=NULL)
	{
		fclose(cadastro);
		printf("--------------ALERTA!------------\n");
		printf("| NOME DE USUARIO INDISPONIVEL! |\n");
		printf("|         TENTE OUTRO!          |\n");
		printf("---------------------------------\n");
		fflush(stdin);
		scanf("%[^\n]", user);
		strcat(user,".txt");
		cadastro=fopen(user,"rb");
		
	}
	

	/*Para facilitar a identificação e manipulação dos Usuarios e senhas futuramente,
	o limite de 20 caracteres foi definido para ambos*/
	
	
	printf("DIGITE UMA NOVA SENHA:");
	printf("Obs: A senha deve possuir \nno maximo 20 caracteres\n");
	do
	{
		fflush(stdin);
		scanf("%[^\n]", novo[0].senha);
		carac=strlen(novo[0].senha);
		
		if(carac>20)
		menus(3);
	}
	while(carac>20);
	
	cadastro=fopen("Cadastros.txt", "ab");
	fwrite(&user, sizeof(user), 1, cadastro);
	fclose(cadastro);
	cadastro=fopen(user, "ab");
	fwrite(&novo[0], sizeof(novo[0]), 1, cadastro);
	fclose(cadastro);
	system("cls");
}


/*Esta função serve apenas para poder encontrar o cliente com o 
usuario correspondente ao fornecido.
dessa forma, reduz o processo dentro do main(corpo do programa)
Dessa forma, ele retorna para o men o numero da posição do cliente na fila,
tornando o processo no main muito mais curto.*/

