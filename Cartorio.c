#include <stdio.h>  //biblioteca de comunica��o com o usu�rio -- em textos
#include <stdlib.h> //biblioteca de aloca�ao de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o (acentua��o)
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //fun��o respons�vel pela cria��o do usu�rio
{
	//inicio cria��o das variaveis/strings
	char arquivo [40]; //variavel para cria�ao do arquivo
	char cpf [40]; //variavel com at� 40 caracteres (poderia ser +/-)
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim da cria��o das variaveis
	
	printf ("Digite o CPF: "); //coletando informa��o do usu�rio
	scanf ("%s", cpf); //comando para armazenamento na vari�vel
	
	strcpy (arquivo, cpf); //respons�vel por copiar os valores das strings ---- do cpf pro arquivo neste caso
	
	FILE *file; //FILE - cmd definido. vai procurar nas bibliotecas uma estrutura file, pois criaremos um arquivo (*file) 
	file = fopen (arquivo, "w"); //vai abrir o arquivo (fopen) e escrever nele (W - write)
	fprintf (file, cpf); //escreve o cpf no arquivo
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo e atualizando-o 
	fprintf (file, "\nNome: "); //inserindo o texto ap�s cada inser��o
	fclose (file);
	
	printf ("Digite o nome a ser cadastrado: ");
	scanf ("%s", nome);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, nome);
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, "\nSobrenome: ");
	fclose (file);
	
	printf ("Digite o sobrenome a ser cadastrado: ");
	scanf ("%s", sobrenome);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, sobrenome);
	fclose (file);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, "\nCargo: ", "\n");
	fclose (file);
	
	printf ("Digite o cargo a ser cadastrado: ");
	scanf ("%s", cargo);
	
	file = fopen (arquivo, "a"); 
	fprintf (file, cargo);
	fprintf (file, "\n\n");
	fclose (file);		
	
}
int consulta() //fun��o respons�vel pela consulta ao usu�rio
{
	char cpf [40];
	char conteudo [200];
		
	setlocale (LC_ALL, "Portuguese");
	
	printf ("Digite o CPF a ser consultado: ");
	scanf ("%s", cpf);
	
	FILE *file;
	file = fopen (cpf, "r"); //abre o arquivo e consulta o cpf
		
	if (file == NULL) //caso arquivo seja nulo, traz a msg de erro
	{
		printf ("N�o foi poss�vel abrir o arquivo, n�o localizado. ");
		printf ("\n");
	}
		printf ("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf ("CPF: ");
		
	while (fgets (conteudo, 200, file) != NULL) //fgets � p/ buscar no arquivo o conteudo o tamanho maximo (200), vai parar quando for nulo.
	{
		printf ("%s", conteudo);		
	}
		system ("pause");
		
		fclose (file);
}
int deletar() //fun��o para deletar usu�rios
{
	char cpf [40];
	
	printf ("Digite o CPF do usu�rio a ser deletado: ");
	scanf ("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("O usu�rio n�o se encontra no sistema! \n");
		system ("pause");
 	}
 	
 	if (file != NULL)
	{
		printf ("Usu�rio deletado com sucesso! \n");
		fclose (file);
		system ("pause");
	}	
 	
}
int main() //fun��o principal
{
	int opcao = 0;
	int laco = 1;
	
	for (laco =1; laco = 1;) //la�o de repeti�ao. criada variavel = 1, sem incremento (++), pro programa sempre voltar no inicio, sair so se o usuario quiser 
	{
		system ("cls");
	
		setlocale (LC_ALL, "Portuguese"); //linguagens da categoria all ser�o em portugu�s
	
		printf ("\t ### Cart�rio da EBAC ### \n \n"); //inicio do menu
		printf ("Escolha a op��o desejada do menu: \n\n");
		printf ("\t 1 - Registrar os usu�rios \n");
		printf ("\t 2 - Consultar os usu�rios \n");
		printf ("\t 3 - Deletar os usu�rios \n\n"); // fim do menu ----------  \t = espa�o, \n = quebra de linha
	
		printf ("Digite a op��o desejada: ");
		scanf ("%d", &opcao); //scanf usado para definir onde alocar o vlr digitado; %d indica que � um vlr do tipo numero; & traz a variavel
	
		system ("cls"); //usado para "limpar" a tela ap�s inser��o do comando na tela
	
		switch (opcao) //switch case: processamento mais rapido
		{
			case 1: //caso a op��o for 1 fa�a
			registro ();
			break;
			
			case 2:
			consulta ();
			break;
					
			case 3:
			deletar ();
			break;
			
			default: //caso a op��o seja diferente (n�o definida)
			printf ("Esta op��o n�o est� dispon�vel! \n");
			system ("pause");
			break;			
		}
	}	
}

