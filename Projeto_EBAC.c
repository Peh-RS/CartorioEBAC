#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registrar() //Página do "Registrar"
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[14];
	char cpf[14];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("### REGISTRO DE DADOS ###\n\n");
	printf("ATENÇÃO!\n");
	printf("Não colocar acentos e caracteres especiais.\n");
	printf("Não utilizar 'espaço' entre as palavras, ao invés disso, utilizar o underline (_).\n\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //Salva a informação na variável
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings (o nome do arquivo será igual ao CPF)
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file, "CPF: "); //Identifica a informação que virá
	fprintf(file, cpf); //Coloca a informação salva na string dentro do arquivo
	fclose(file); //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\n\nCadastro realizado com sucesso.");
	printf("\n\n\n\n\n");
	
	system("pause");
}

int consultar() //Página do "Consultar"
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[14];
	char conteudo[500];
	
	printf("### CONSULTA DE DADOS ###\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Procura o arquivo com o CPF digitado e lê
	
	if(file)
	{
		printf("\n\nEssas são as informações do cadastro:\n");
	}
	else
	{
		printf("\n\nCadastro não localizado.");
	}
	
	while(fgets(conteudo, 500, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	
	printf("\n\n\n\n\n");
	
	system("pause");
}

int deletar() //Página do "Deletar"
{
	char cpf[14];
	
	printf("### EXCLUSÃO DE DADOS ###\n\n");
	printf("Digite o CPF do cadastro a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file)
	{
		fclose(file);
		remove(cpf); //Deleta a pasta com o nome do CPF
		printf("\n\nO cadastro foi excluído com sucesso.\n\n\n\n\n");
	}
	else
	{
		printf("\n\nO cadastro não se encontra no sistema. Verifique se o CPF foi escrito corretamente.\n\n\n\n\n");
	}
	
	system("pause");
}

int main() //Página do "Menu"
{
	int opcao=0; //Definindo variáveis
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		system("cls"); //Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Cadastrar\n");
		printf("\t2 - Consultar\n");
		printf("\t3 - Excluir\n\n");
		printf("Opção: "); //Final do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls");
	
		switch(opcao) //Início da seleção
		{
			case 1: //Se o usuário digitar "1", irá para a página indicada na linha abaixo
			registrar();
			break;
		
			case 2: //Se o usuário digitar "2", irá para a página indicada na linha abaixo
			consultar();
			break;
		
			case 3: //Se o usuário digitar "3", irá para a página indicada na linha abaixo
			deletar();
			break;
		
			default:
			printf("Esta opção não está disponível.\n\n");
			system("pause"); //Final da seleção
			
		}
	}
}
