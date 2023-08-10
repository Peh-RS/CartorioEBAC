#include <stdio.h> //Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registrar() //P�gina do "Registrar"
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[14];
	char cpf[14];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	
	printf("### REGISTRO DE DADOS ###\n\n");
	printf("ATEN��O!\n");
	printf("N�o colocar acentos e caracteres especiais.\n");
	printf("N�o utilizar 'espa�o' entre as palavras, ao inv�s disso, utilizar o underline (_).\n\n\n");
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf); //Salva a informa��o na vari�vel
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings (o nome do arquivo ser� igual ao CPF)
	
	FILE *file; //Cria o arquivo
	file = fopen(arquivo, "w"); 
	fprintf(file, "CPF: "); //Identifica a informa��o que vir�
	fprintf(file, cpf); //Coloca a informa��o salva na string dentro do arquivo
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

int consultar() //P�gina do "Consultar"
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[14];
	char conteudo[500];
	
	printf("### CONSULTA DE DADOS ###\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); //Procura o arquivo com o CPF digitado e l�
	
	if(file)
	{
		printf("\n\nEssas s�o as informa��es do cadastro:\n");
	}
	else
	{
		printf("\n\nCadastro n�o localizado.");
	}
	
	while(fgets(conteudo, 500, file) != NULL)
	{
		printf("%s", conteudo);
	}
	
	fclose(file);
	
	printf("\n\n\n\n\n");
	
	system("pause");
}

int deletar() //P�gina do "Deletar"
{
	char cpf[14];
	
	printf("### EXCLUS�O DE DADOS ###\n\n");
	printf("Digite o CPF do cadastro a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file)
	{
		fclose(file);
		remove(cpf); //Deleta a pasta com o nome do CPF
		printf("\n\nO cadastro foi exclu�do com sucesso.\n\n\n\n\n");
	}
	else
	{
		printf("\n\nO cadastro n�o se encontra no sistema. Verifique se o CPF foi escrito corretamente.\n\n\n\n\n");
	}
	
	system("pause");
}

int main() //P�gina do "Menu"
{
	int opcao=0; //Definindo vari�veis
	int loop=1;
	
	for(loop=1;loop=1;)
	{
		system("cls"); //Respons�vel por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
		printf("### Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejada do menu:\n\n");
		printf("\t1 - Cadastrar\n");
		printf("\t2 - Consultar\n");
		printf("\t3 - Excluir\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Final do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls");
	
		switch(opcao) //In�cio da sele��o
		{
			case 1: //Se o usu�rio digitar "1", ir� para a p�gina indicada na linha abaixo
			registrar();
			break;
		
			case 2: //Se o usu�rio digitar "2", ir� para a p�gina indicada na linha abaixo
			consultar();
			break;
		
			case 3: //Se o usu�rio digitar "3", ir� para a p�gina indicada na linha abaixo
			deletar();
			break;
			
			case 4: //Se o usu�rio digitar "4", o sistema fechar�
			printf("Obrigado por utilizar o sistema.\n\n");
			return 0;
			break;
		
			default:
			printf("Esta op��o n�o est� dispon�vel.\n\n");
			system("pause"); //Final da sele��o
			
		}
	}
}
