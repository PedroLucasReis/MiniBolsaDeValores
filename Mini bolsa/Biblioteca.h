//Nome: Pedro Lucas Correia dos Reis
//Codigo: 834539
//Link para o video: https://youtu.be/DCOAIiGFxGo

//Comfirmação da ALTERnativa SIM ou NAO
char alter(char botao)
{
	while(toupper(botao)!='S' && toupper(botao)!='N')
	{
		system("cls");
		printf("----------ALERTA!----------\n");
		printf("   TECLA NAO RECONHECIDA!  \n");
		printf("      TENTE NOVAMENTE!     \n");
		printf("---------------------------\n");
		fflush(stdin);
		botao=getche();
	}
	return botao;
}

//Guarda a maioria dos printf's que formam os menus
void menus(int menu)
{
	switch(menu)
	{
		case 1:
			{
				printf("\n----------------------------------\n");
				printf("|      MINI BOLSA DE VALORES     |\n");
				printf("----------------------------------\n");
				printf("|   1     -->        LOGIN       |\n");
				printf("|   2     -->      CLIENTES      |\n");
				printf("|   3     -->        AJUDA       |\n");
				printf("|   4     -->   FECHAR PROGRAMA  |\n");
				printf("----------------------------------\n");
				break;
			}
		case 2:
			{
				printf("------------CLIENTES----------\n");
				printf("|   1     -->     CADASTRO   |\n");
				printf("|   2     -->      EXIBIR    |\n");
				printf("|   3     -->     EXCLUIR    |\n");
				printf("|   4     -->     RETORNAR   |\n");
				printf("------------------------------\n");
				break;
			}
		case 3:
			{
				system("cls");
				printf("\n----------------------\n");
				printf("|  TAMANHO INVALIDO!   |\n");
				printf("| LIMITE: 20 CARACTERES |\n");
				printf("|   TENTE NOVAMENTE    |\n");
				printf("------------------------\n");
				break;
			}
		case 4:
			{
				printf("----------ALERTA!----------\n");
				printf("|   O LOGIN JA FOI USADO  |\n");
				printf("|      TENTE OUTRO:       |\n");
				printf("---------------------------\n");
				break;
			}
		case 5:
			{
				printf("----------ALERTA!----------\n");
				printf("|   A SENHA JA FOI USADA  |\n");
				printf("|      TENTE OUTRA:       |\n");
				printf("---------------------------\n");
				break;
			}
		case 6:
			{
				printf("\n----------ALERTA!-----------\n");
				printf("|  NENHUM CLIENTE CADASTRADO |\n");
				printf("|     RETORNANDO AO MENU     |\n");
				printf("------------------------------\n");
				break;
			}
		case 7:
			{
				printf("\n---------------PERFIL--------------\n");
				printf("|   1       -->  DEPOSITAR/SACAR  |\n");
				printf("|   2       -->       ACOES       |\n");
				printf("|   3       -->  EXCLUIR OPERACAO |\n");
				printf("|   4       -->       SAIR        |\n");
				printf("-----------------------------------\n");
				break;
			}
		case 8:
			{
				printf("\n----------ALERTA!----------\n");
				printf("|    TECLA DESCONHECIDA!  |\n");
				printf("|     TENTE NOVAMENTE!    |\n");
				printf("---------------------------\n");
				break;
			}
		case 9:
			{
				printf("----------OPERACOES----------\n");
				printf("|    1    -->    DEPOSITAR  |\n");
				printf("|    2    -->      SACAR    |\n");
				printf("|    3    -->    RETORNAR   |\n");
				printf("-----------------------------\n");
				break;
			}
		case 10:
			{
				printf("----------ACOES------------\n");
				printf("|   1      -->    WEG     |\n");
				printf("|   2      -->    ITAU    |\n");
				printf("|   3      -->   TAESA    |\n");
				printf("|   4      -->   AMBEV    |\n");
				printf("---------------------------\n");
				printf("|   5      -->  RETORNAR  |\n");
				printf("---------------------------\n");
				break;
			}
		case 11:
			{
				printf("----------ACOES------------\n");
				printf("|   1      -->  COMPRAR   |\n");
				printf("|   2      -->  VENDER    |\n");
				printf("|   3      -->  RETORNAR  |\n");
				printf("---------------------------\n");
				break;
			}
		case 12:
			{
				system("cls");
				printf("----------ALERTA!----------\n");
				printf("|    SALDO INSUFICIENTE   |\n");
				printf("|    RETORNANDO AO MENU   |\n");
				printf("---------------------------\n");
			}
		case 13:
			{
				printf("----------ALERTA!----------\n");
				printf("|  SEM ACOES PARA VENDER  |\n");
				printf("|   RETORNANDO AO MENU    |\n");
				printf("---------------------------\n\n");
			}
		default:
			{
				break;
			}
	}	
}

//Verifica se uma string é igual a outra
int verifica(int letras,char pont[], char base[])
{
	int i=0;
	while(i<=letras-1)
	{
		if(toupper(pont[i])==toupper(base[i]))
		{
			i++;
			if(i==letras)
			{
				return 1;
			}	
		}
		else
		{
			return 0;
		}	
	}	
}

float money(int oper,char senha[11], float saldo)
{
	int control=0, carac;
	char senha2[11], menu;
	float valor, total;
	system("cls");
	
	printf("Digite o valor da operacao: ");
	scanf("%f", &valor);
	
	if(oper==2 && valor>saldo)
	{
		system("cls");
		printf("----------ALERTA!----------\n");
		printf("|    SALDO INSUFICIENTE!  |\n");
		printf("|    RETORNANDO AO MENU!  |\n");
		printf("---------------------------\n\n");
		return saldo;
	}
	
	printf("\n\nAgora informe sua senha para comfirmar: ");
	fflush(stdin);
	scanf("%[^\n]", senha2);
	
	while(control<2)
	{
		carac=strlen(senha2);
		while(carac<8 || carac>8)
		{ 
			printf("%i", carac);
			menus(3);
			fflush(stdin);
			scanf("%[^\n]", senha2);
			carac=strlen(senha2);
		}
		control++;
		while(control!=0)
		{
			carac=verifica(8, senha2, senha);
			if(carac==1)
			{
				system("cls");
				printf("----------SENHA VALIDA!----------\n\n");
				if(oper==1)
				{
					printf("----------DEPOSITO REALIZADO!----------\n\n");
					total=valor+saldo;
				}		
				else
				{
					printf("----------SAQUE REALIZADO!----------\n\n");
					total=saldo-valor;
				}
				return total;
			}
			else
			{
				system("cls");
				printf("----------SENHA INVALIDA!----------\n\n");
				printf("Tente novamente: ");
				fflush(stdin);
				scanf("%[^\n]", senha2);
				control=0;
			}
		}
	
	
		
	}
	
}


//verifica se uma strig é igual a outra mas com limite de caracteres
int veri_igualdade(char text[], char base[])
{
	int carac, control=0;
	carac=strlen(text);

	while(control<2)
	{
		carac=strlen(text);
		if(carac==8)
		{
			control++;
		}
		else
		{
			while(carac<8 || carac>8)
			{ 
				printf("%i", carac);
				menus(3);
				fflush(stdin);
				scanf("%[^\n]", text);
				carac=strlen(text);
			}
		}
		if(carac==8)	
		{
			carac=verifica(8, text, base);
			if(carac==1)
			{
				return 1;
			}
			else
			{
				return 0;
			}	
		}	
	}	
}

void ajuda()
{
	char descar, botao='0', botao1='0', botao2='0';
	while(botao!='4')
	{	
		printf("\n----------------------------------\n");
		printf("|            MODO AJUDA!         |\n");
		printf("----------------------------------\n");
		printf("|   1     -->       LOGIN        |\n");
		printf("|   2     -->      CLIENTES      |\n");
		printf("|   3     -->    AUTOR/CRIADOR   |\n");
		printf("|   4     -->      RETORNAR      |\n");
		printf("----------------------------------\n");
		botao=getche();
		system("cls");
		switch(botao)
		{
			case '1':
				{
					botao1='0';
					while(botao1!='4')
					{
						system("cls");
						printf("No menu \"LOGIN\" sao feitas todas as operacoes no perfil de cada cliente,\n");
						printf("desde depositos, saques de dinheiro da conta, compra e venda de acoes na\n");
						printf("\"MINI BOLSA DE VALORES\".\n\n");
						
						printf("Para acessar este menu, antes deve ser feito um cadastro no menu \"CLIENTES\"\n");
						printf("com nome, cidade em que reside, idade, \"USER\" e \"SENHA\".\n\n");
						
						printf("O User e senha e solicitado logo apos apertar o botao \nde \"LOGIN\" no menu principal.\n\n");
						printf("O User e senha devem ser anotados ou memorizados, pois estes sao de uso \n");
						printf("privado do dono de cada perfil. Logo essas informacoes nao sao mostradas \n");
						printf("em nenhuma parte do  programa!\n\n");
						
						printf("\n-----------AJUDA: PERFIL---------\n");
						printf("|   1       -->  DEPOSITAR/SACAR  |\n");
						printf("|   2       -->       ACOES       |\n");
						printf("|   3       -->  EXCLUIR OPERACAO |\n");
						printf("|   4       -->      RETORNAR     |\n");
						printf("-----------------------------------\n");
						botao1=getche();
						system("cls");
						switch(botao1)
						{
							case '1':
								{
									system("cls");
									printf("Nessa parte do programa, voce pode sacar e depositar dinheiro.\n");
									printf("Todo o dinheiro depositado ira diretamente para o perfil \ndo cliente que esta logado.\n");
									printf("Este dinheiro podera ser usado para a compra das acoes disponibilizadas \nno menu \"ACOES\".\n\n");
									printf("Caso  voce selecione a opcao \"SACAR\", voce podera retirar qualquer quantia \nde dinheiro que nao ");
									printf("ultrapasse o saldo total da conta logada.\n");
									printf("Dentro de cada opcao sera solicitado que informe o valor da \noperacao e sua senha.\n\n");
									
									printf("APERTE QUALQUER TECLA PARA RETORNAR APOS TERMINAR DE LER: ");
									descar=getche();
									system("cls");
									break;
								}
							case '2':
								{
									botao2='0';
									while(botao2!='3')
									{
										system("cls");
										printf("Aqui encontra-se a parte mais importante do programa: AS ACOES!\n");
										printf("Para reduzir o tamanho do codigo do programa, foram inseridas apenas 4 acoes.\n");
										printf("Curiosidade: Na bolsa de valores Brasileira real,existem varias \ndezenas de acoes.\n");
										printf("Como na bolsa de valores real, cada acao tem um preco diferente uma da outra.\n");
										printf("Ao abrir o programa,  por origem, os precos sao os mesmos da \nabertura do mercado ");
										printf("do dia 09/10/2020.\n\n");
										printf("Os precos sao WEGE:R$74,94  ITAU:R$24,12  TAESA:R$28,08  AMBEV:R$13,64\n\n");
										printf("Estes precos sao alterados quando uma compra e uma venda, \nambos no book de ofertas, ");
										printf("tiverem o mesmo preco. Quando isso acontecer\n, as ordens de compra e venda sao consideradas, ");
										printf("executadas, alterando o preco \natual do ativo(acao) e fazendo as devidas modificacoes \nnos perfis ");
										printf("dos operadores.\n\n");
										printf("Voce pode optar por fazer quantas compras quiser de cada acao, desde que \n");
										printf("tenha saldo suficiente para isso.\n");
										printf("As vendas tambem sao ilimitadas, mas antes precisa ter posse de \nalgum ativo para poder vende-lo.\n");
										printf("As operacoes de compra e venda podem ser divididas em dois tipos:\n\n");
										
										
										printf("-------------AJUDA: OPERACOES-----------\n");
										printf("|  1  -->     OPERACAO A MERCADO       |\n");
										printf("|  2  --> OPERACAO NO BOOK DE OFERTAS  |\n");
										printf("|  3  -->        RETORNAR              |\n");
										printf("----------------------------------------\n");
										botao2=getche();
										system("cls");
										switch(botao2)
										{
											case '1':
												{
													system("cls");
													printf("Todas as compras e vendas realizadas nessa opcao sao mediadas pelo computador!\n");
													printf("Quando voce compra por essa opcao, o vendedor e o sistema, e nao outro usuario.\n");
													printf("O mesmo acontece para as vendas, ou seja, voce estara \nvendendo para o computador.\n");
													printf("Vale lembrar que nao e possivel vender nenhum ativo se \nnao compra-lo de alguem antes.\n");
													printf("Esta opcao e ideal para quando o programa acaber de ser iniciado, \nja que o book estara vazio.\n");
													printf("Aqui sera solicitado apenas sua senha para comfirmacao.\n");
													printf("O preco que sera descontado se a operacao for de compra sera o valor \natual da acao.\n");
													printf("O mesmo acontece para as vendas, a acao sera vendida pelo preco atual da acao.\n\n");
													
													printf("APERTE QUALQUER TECLA PARA RETORNAR APOS TERMINAR DE LER: ");
													descar=getche();
													system("cls");
													break;
												}
											case '2':
												{
													system("cls");
													printf("Aqui, diferente da operacao a mercado, as operacoes de compra ou venda,\n");
													printf("vao parar no book de ofertas.\n");
													printf("Em caso de compra, aqui voce dita o preco que voce aceita pagar por determinado\n");
													printf("ativo. Para a venda acontece o mesmo, voce escolhe por qual preco quer \nvender a acao.\n");
													printf("Quando os precos de uma operacao de compra e uma de venda forem \niguais, as ordens ");
													printf("sao  executadas e o preco atual do ativo passa a ser a \nda ultima ordem executada.\n");
													printf("Atencao: apos fazer uma ordem no book, a movimentacao no seu perfil \nja sera realizada!\n");
													printf("Curiosidade: na bolsa de valores real, o book funciona quase da \nmesma forma. As pessoas ");
													printf("fazem suas ordens e como sao milhares de clientes \nos precos sao executados o tempo todo, ");
													printf("por isso existe a tal variacao de precos na bolsa. \nUma das formas de ganhar dinheiro e ");
													printf("comprar barato e vender caro. Para voce \npoder sentir como e, recomendo que compre ");
													printf("uma acao a mercado e faca \numa venda com um preco maior no book.\n\n");
													
													printf("APERTE QUALQUER TECLA PARA RETORNAR APOS TERMINAR DE LER: ");
													descar=getche();
													system("cls");
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
									printf("Esta opcao, exclui todas as operacaoes de compra e venda que \nestao abertas no book ");
									printf("de ofertas. As operacoes que ja foram \nexecutadas nao sao alteradas.\n");
									printf("Para as compras em aberto, apos a exclusao, o dinheiro e restituido \nna sua conta.\n");
									printf("Para as vendas, o diheiro da operacao voltara ao mercado(computador), \ne sua acao ");
									printf("voltara para seu respectivo perfil\n");
									printf("Aqui sera solicidado sua senha para confirmacao.\n\n");
									
									printf("APERTE QUALQUER TECLA PARA RETORNAR APOS TERMINAR DE LER: ");
									descar=getche();
									system("cls");
									break;
								}
							case '4':
								{
									system("cls");
									printf("----------RETORNANDO!----------\n");
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
			case '2':
				{
					system("cls");
					printf("Aqui voce pode cadastrar novos clientes(perfil/contas) que poderao ser usados\n");
					printf("nas operacoes dentro do menu login. Sera solicitado seu nome, cidade \nem que reside, idade, ");
					printf("um User e uma senha. Atencao: user e senha sao \ninformacoes privadas de cada cliente ");
					printf("e nao sera mostrada em nenhuma parte do \nprograma novamente, entao anote \nou memorize.\n");
					printf("Aqui tambem, precionando a opcao de \"EXIBIR\", voce podera ver as informacoes \npublicas ");
					printf("de cada cliente cadastrado, como nome, cidade residente, \nidade e se esta ");
					printf("em fila preferencial ou nao.\n");
					printf("Na opcao excluir, voce podera excluir um determinado perfil, informando o User\n");
					printf("e senha do mesmo.\n");
					printf("Atencao: e impossivel excluir uma conta que ainda possua ativos(acoes) \nou saldo bruto ");
					printf("maior do que R$0,00\n\n");
					
					printf("APERTE QUALQUER TECLA PARA RETORNAR APOS TERMINAR DE LER: ");
					descar=getche();
					system("cls");
					break;
				}
			case '3':
				{
					system("cls");
					printf("Criador: Pedro Lucas Correia dos Reis.\n");
					printf("\"Eu escolhi fazer um programa para esse segmento pois sempre fui interessado\n");
					printf("no mercado financeiro e bolsa de valores. Antes de iniciar o curso de\n");
					printf("Engenharia de computacao na UNAERP, meu interesse era passar em economia\n");
					printf("em alguma universidade publica. Porem, nao foi o caso, e tambem como eu\n");
					printf("sempre tive facilidade com tecnologia, foi minha segunda escolha. Hoje tenho\n");
					printf("um certo conhecimento sobre a bolsa de valores, o que facilitou a construcao\n");
					printf("estrutural do programa.\n\n");
					
					printf("APERTE QUALQUER TECLA PARA RETORNAR APOS TERMINAR DE LER: ");
					descar=getche();
					system("cls");
				}
			case '4':
				{
					system("cls");
					printf("----------RETORNANDO!----------\n");
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
