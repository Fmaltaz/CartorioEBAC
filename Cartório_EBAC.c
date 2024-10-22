#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() //Fun��o respons�vel por registrar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio da cria��o de vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char opcao;
	//Fim da cria��o de vari�veis
	
	do 
	{

		printf("Digite o CPF do usu�rio a ser cadastrado: "); //Coleta informa��o do usu�rio
		scanf("%s", cpf); //Armazena a string com o "%s"
		
		strcpy(arquivo, cpf); //respons�vel por copiar o valor das strings
		
		FILE *file; //cria o arquivo 
		file = fopen(arquivo, "w"); //cria o arquivo 
		fprintf(file, "CPF: %s\n", cpf); //salva o valor da vari�vel
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file, "Nome: "); //Adiciona o r�tulo "nome" ao arquivo
		fclose(file);//Fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: "); //Coleta informa��o do usu�rio
		scanf("%s", nome); //Armazena essa informa��o
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file, "%s\n", nome); //Adiciona o "nome" no arquivo
		fclose(file); //Fecha o arquivo
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adiconar mais dados
		fprintf(file, "Sobrenome: "); //Adiciona o r�tulo "sobrenome" ao arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coleta informa��o do usu�rio
		scanf("%s", sobrenome); //Armazena essa informa��o
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file,"%s\n", sobrenome); //Adiciona o "sobrenome" ao arquivo
		fclose(file); //Fecha o arquivo
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file, "Cargo: "); //Adiciona o r�tulo "cargo" ao arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coleta informa��o do usu�rio
		scanf("%s", cargo); //Armazena essa informa��o
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais informa��o
		fprintf(file,"%s\n", cargo); //Adiciona o "cargo" ao arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Usu�rio cadastrado com sucesso!\n"); //Exibe uma valida��o da a�a� de registro para o usu�rio
		
		printf("\nDeseja cadastrar outro usu�rio? (s/n): ");
		scanf(" %c", &opcao);
		system("cls");
	
	}
	while (opcao == 's');
	return 0;
	
		
		
}

int consultar() //Fun��o respons�vel por consultar os usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio da cria��o de vari�veis
	char cpf[40];
	char conteudo[200];
	char opcao;
	//Fim da cria��o de vari�veis
	
	do {
		
		
		printf("Digite o CPF a ser consultado: "); //Coleta informa��o do usu�rio
		scanf("%s", cpf); //Armazena essa informa��o
		
		FILE *file;
		file = fopen(cpf, "r"); //Abre o arquivo corresponde ao CPF digitado no modo de leitura (read)
		
		if (file == NULL) //Verifica se o arquivo existe, se n�o, exibe mensagem de erro
		{
			printf ("CPF n�o encontrado\n"); //Mensagem de erro exibida para o usu�rio
			system("pause"); //Pausa o programa at� o usu�rio pressionar uma tecla
			return 1; //Sai da fun��o com um valor que indica erro
		}
		
		printf("\nInforma��es do usu�rio:\n"); //Exibe as informa��es do usu�rio se forem encontradas
		
		while (fgets(conteudo, 200,file) != NULL) //L� cada linha do arquivo e exibe o conte�do at� chegar ao fim do arquivo
		{
			printf("%s", conteudo); //Exibe o conteudo do arquivo
		}
		
		fclose(file);
		
		printf("\nDeseja consultar outro usu�rio? (s/n): ");
		scanf(" %c", &opcao);
		system("cls");
	}
	while (opcao == 's');
	return 0;
}

int apagar() //Fun��o respons�vel por apagar os usu�rios do sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio da cria��o de vari�veis
	char cpf[40];
	char opcao;
	//Fim da cria��o de vari�veis
	
	do
	{
		
		printf("Digite o CPF do usu�rio a ser apagado: "); //Coleta informa��o do usu�rio
		scanf("%s", cpf); //Armazena essa informa��o
		
		FILE *file;
		file = fopen(cpf, "r"); //Abre o arquivo no modo de leitura para verificar se o mesmo existe
		
		if(file == NULL) //Se n�o existe exibe mensagem de erro ao usu�rio
		{
			printf("Usu�rio n�o encontrado\n"); //Mensagem de erro exibida para o usu�rio
			system("pause"); //Pausa o programa at� o usu�rio pressionar uma tecla
			return 0;
		}
		
		else //Caso o arquivo exista, deleta o mesmo
			{
				fclose(file); //Fecha o arquivo para que seja deletado
				remove(cpf); //Deleta o arquivo
				printf("Usu�rio apagado com sucesso!\n"); //Exibe mensagem de valida��o da a��o para o usu�rio
				
				printf("\nDeseja apagar outro usu�rio? (s/n): ");
				scanf(" %c", &opcao);
				system("cls");
			}
	}
	while (opcao == 's');
	return 0;			
	
}

int main() //Fun��o do menu inicial do programa
{
	int opcao=0; //definindo vari�veis
	int laco=1; //Vari�vel do loop do menu
		
	for (laco=1;laco=1;) //Mant�m o programa rodando at� o usu�rio decidir sair
	
	{
	
		system("cls"); //Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //define idioma para portugu�s
	
		//in�cio do menu
		printf("    CART�RIO DA EBAC    \n\n"); 
		printf("Escolha a op��o no menu:\n\n");	
		printf("\t1 - Cadastrar usu�rios\n");
		printf("\t2 - Consultar usu�rios\n");
		printf("\t3 - Apagar usu�rios\n");
		printf("\t4 - Sair\n\n");
		printf("Op��o:"); 
		//fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usu�rio
	
		system("cls"); //limpar tela
		
		switch(opcao) //Verifica qual op��o o sus�rio escolheu e exibe a fun��o desejada
		{
			case 1:
				registrar(); //Exibe a fun��o para registrar um usu�rio
				break;
				
			case 2:
				consultar(); //Exibe a fun��o para consultar um usu�rio
				break;
			
			case 3:
				apagar(); //Exibe a fun��o para apagar um usu�rio
				break;
			
			case 4:
				return 0; //Sai do programa
				
			default:
				printf("Op��o inv�lida\n"); //Exibe mensagem de erro caso a op��o escolhida seja inv�lida
				system("pause"); //Pausa o programa at� o usu�rio pressionar uma tecla
				break;	
							
			
		}	 
	}
}
