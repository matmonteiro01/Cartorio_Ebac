#include <stdio.h>  //biblioteca de comunicação com o usuário -- em textos
#include <stdlib.h> //biblioteca de alocaçao de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região (acentuação)
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //função responsável pela criação do usuário
{
	//inicio criação das variaveis/strings
	char arquivo [40]; //variavel para criaçao do arquivo
	char cpf [40]; //variavel com até 40 caracteres (poderia ser +/-)
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//fim da criação das variaveis
	
	printf ("Digite o CPF: "); //coletando informação do usuário
	scanf ("%s", cpf); //comando para armazenamento na variável
	
	strcpy (arquivo, cpf); //responsável por copiar os valores das strings ---- do cpf pro arquivo neste caso
	
	FILE *file; //FILE - cmd definido. vai procurar nas bibliotecas uma estrutura file, pois criaremos um arquivo (*file) 
	file = fopen (arquivo, "w"); //vai abrir o arquivo (fopen) e escrever nele (W - write)
	fprintf (file, cpf); //escreve o cpf no arquivo
	fclose (file); //fecha o arquivo
	
	file = fopen (arquivo, "a"); //abrindo o arquivo e atualizando-o 
	fprintf (file, "\nNome: "); //inserindo o texto após cada inserção
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
int consulta() //função responsável pela consulta ao usuário
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
		printf ("Não foi possível abrir o arquivo, não localizado. ");
		printf ("\n");
	}
		printf ("\nEssas são as informações do usuário: \n\n");
		printf ("CPF: ");
		
	while (fgets (conteudo, 200, file) != NULL) //fgets é p/ buscar no arquivo o conteudo o tamanho maximo (200), vai parar quando for nulo.
	{
		printf ("%s", conteudo);		
	}
		system ("pause");
		
		fclose (file);
}
int deletar() //função para deletar usuários
{
	char cpf [40];
	
	printf ("Digite o CPF do usuário a ser deletado: ");
	scanf ("%s", cpf);
	
	remove (cpf);
	
	FILE *file;
	file = fopen (cpf, "r");
	
	if (file == NULL)
	{
		printf ("O usuário não se encontra no sistema! \n");
		system ("pause");
 	}
 	
 	if (file != NULL)
	{
		printf ("Usuário deletado com sucesso! \n");
		fclose (file);
		system ("pause");
	}	
 	
}
int main() //função principal
{
	int opcao = 0;
	int laco = 1;
	
	for (laco =1; laco = 1;) //laço de repetiçao. criada variavel = 1, sem incremento (++), pro programa sempre voltar no inicio, sair so se o usuario quiser 
	{
		system ("cls");
	
		setlocale (LC_ALL, "Portuguese"); //linguagens da categoria all serão em português
	
		printf ("\t ### Cartório da EBAC ### \n \n"); //inicio do menu
		printf ("Escolha a opção desejada do menu: \n\n");
		printf ("\t 1 - Registrar os usuários \n");
		printf ("\t 2 - Consultar os usuários \n");
		printf ("\t 3 - Deletar os usuários \n\n"); // fim do menu ----------  \t = espaço, \n = quebra de linha
	
		printf ("Digite a opção desejada: ");
		scanf ("%d", &opcao); //scanf usado para definir onde alocar o vlr digitado; %d indica que é um vlr do tipo numero; & traz a variavel
	
		system ("cls"); //usado para "limpar" a tela após inserção do comando na tela
	
		switch (opcao) //switch case: processamento mais rapido
		{
			case 1: //caso a opção for 1 faça
			registro ();
			break;
			
			case 2:
			consulta ();
			break;
					
			case 3:
			deletar ();
			break;
			
			default: //caso a opção seja diferente (não definida)
			printf ("Esta opção não está disponível! \n");
			system ("pause");
			break;			
		}
	}	
}

