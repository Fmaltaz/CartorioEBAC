#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() //Função responsável por registrar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio da criação de variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	char opcao;
	//Fim da criação de variáveis
	
	do 
	{

		printf("Digite o CPF do usuário a ser cadastrado: "); //Coleta informação do usuário
		scanf("%s", cpf); //Armazena a string com o "%s"
		
		strcpy(arquivo, cpf); //responsável por copiar o valor das strings
		
		FILE *file; //cria o arquivo 
		file = fopen(arquivo, "w"); //cria o arquivo 
		fprintf(file, "CPF: %s\n", cpf); //salva o valor da variável
		fclose(file); //fecha o arquivo
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file, "Nome: "); //Adiciona o rótulo "nome" ao arquivo
		fclose(file);//Fecha o arquivo
		
		printf("Digite o nome a ser cadastrado: "); //Coleta informação do usuário
		scanf("%s", nome); //Armazena essa informação
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file, "%s\n", nome); //Adiciona o "nome" no arquivo
		fclose(file); //Fecha o arquivo
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adiconar mais dados
		fprintf(file, "Sobrenome: "); //Adiciona o rótulo "sobrenome" ao arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Digite o sobrenome a ser cadastrado: "); //Coleta informação do usuário
		scanf("%s", sobrenome); //Armazena essa informação
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file,"%s\n", sobrenome); //Adiciona o "sobrenome" ao arquivo
		fclose(file); //Fecha o arquivo
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais dados
		fprintf(file, "Cargo: "); //Adiciona o rótulo "cargo" ao arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Digite o cargo a ser cadastrado: "); //Coleta informação do usuário
		scanf("%s", cargo); //Armazena essa informação
		
		file = fopen(arquivo, "a"); //Abre o arquivo para adicionar mais informação
		fprintf(file,"%s\n", cargo); //Adiciona o "cargo" ao arquivo
		fclose(file); //Fecha o arquivo
		
		printf("Usuário cadastrado com sucesso!\n"); //Exibe uma validação da açaõ de registro para o usuário
		
		printf("\nDeseja cadastrar outro usuário? (s/n): ");
		scanf(" %c", &opcao);
		system("cls");
	
	}
	while (opcao == 's');
	return 0;
	
		
		
}

int consultar() //Função responsável por consultar os usuários no sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio da criação de variáveis
	char cpf[40];
	char conteudo[200];
	char opcao;
	//Fim da criação de variáveis
	
	do {
		
		
		printf("Digite o CPF a ser consultado: "); //Coleta informação do usuário
		scanf("%s", cpf); //Armazena essa informação
		
		FILE *file;
		file = fopen(cpf, "r"); //Abre o arquivo corresponde ao CPF digitado no modo de leitura (read)
		
		if (file == NULL) //Verifica se o arquivo existe, se não, exibe mensagem de erro
		{
			printf ("CPF não encontrado\n"); //Mensagem de erro exibida para o usuário
			system("pause"); //Pausa o programa até o usuário pressionar uma tecla
			return 1; //Sai da função com um valor que indica erro
		}
		
		printf("\nInformações do usuário:\n"); //Exibe as informações do usuário se forem encontradas
		
		while (fgets(conteudo, 200,file) != NULL) //Lê cada linha do arquivo e exibe o conteúdo até chegar ao fim do arquivo
		{
			printf("%s", conteudo); //Exibe o conteudo do arquivo
		}
		
		fclose(file);
		
		printf("\nDeseja consultar outro usuário? (s/n): ");
		scanf(" %c", &opcao);
		system("cls");
	}
	while (opcao == 's');
	return 0;
}

int apagar() //Função responsável por apagar os usuários do sistema
{
	setlocale(LC_ALL, "Portuguese");
	
	//Inicio da criação de variáveis
	char cpf[40];
	char opcao;
	//Fim da criação de variáveis
	
	do
	{
		
		printf("Digite o CPF do usuário a ser apagado: "); //Coleta informação do usuário
		scanf("%s", cpf); //Armazena essa informação
		
		FILE *file;
		file = fopen(cpf, "r"); //Abre o arquivo no modo de leitura para verificar se o mesmo existe
		
		if(file == NULL) //Se não existe exibe mensagem de erro ao usuário
		{
			printf("Usuário não encontrado\n"); //Mensagem de erro exibida para o usuário
			system("pause"); //Pausa o programa até o usuário pressionar uma tecla
			return 0;
		}
		
		else //Caso o arquivo exista, deleta o mesmo
			{
				fclose(file); //Fecha o arquivo para que seja deletado
				remove(cpf); //Deleta o arquivo
				printf("Usuário apagado com sucesso!\n"); //Exibe mensagem de validação da ação para o usuário
				
				printf("\nDeseja apagar outro usuário? (s/n): ");
				scanf(" %c", &opcao);
				system("cls");
			}
	}
	while (opcao == 's');
	return 0;			
	
}

int main() //Função do menu inicial do programa
{
	int opcao=0; //definindo variáveis
	int laco=1; //Variável do loop do menu
		
	for (laco=1;laco=1;) //Mantém o programa rodando até o usuário decidir sair
	
	{
	
		system("cls"); //Limpa a tela
		
		setlocale(LC_ALL, "Portuguese"); //define idioma para português
	
		//início do menu
		printf("    CARTÓRIO DA EBAC    \n\n"); 
		printf("Escolha a opção no menu:\n\n");	
		printf("\t1 - Cadastrar usuários\n");
		printf("\t2 - Consultar usuários\n");
		printf("\t3 - Apagar usuários\n");
		printf("\t4 - Sair\n\n");
		printf("Opção:"); 
		//fim do menu
	
		scanf("%d", &opcao); //armazenando escolha do usuário
	
		system("cls"); //limpar tela
		
		switch(opcao) //Verifica qual opção o susário escolheu e exibe a função desejada
		{
			case 1:
				registrar(); //Exibe a função para registrar um usuário
				break;
				
			case 2:
				consultar(); //Exibe a função para consultar um usuário
				break;
			
			case 3:
				apagar(); //Exibe a função para apagar um usuário
				break;
			
			case 4:
				return 0; //Sai do programa
				
			default:
				printf("Opção inválida\n"); //Exibe mensagem de erro caso a opção escolhida seja inválida
				system("pause"); //Pausa o programa até o usuário pressionar uma tecla
				break;	
							
			
		}	 
	}
}
