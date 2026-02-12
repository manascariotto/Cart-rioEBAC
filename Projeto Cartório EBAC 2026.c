#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bibliotec de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar()
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome [40];
	char cargo[40];
	
	printf("\n!! REGISTRO DE USUÁRIO !!\n\n\n\nDigite os dados a serem redistrados\n\n\nCPF (sem caracteres como . , - e etc.): ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo no banco de dados, nesse caso no computador
	file = fopen(arquivo, "w"); //cria o arquivo
	fprintf(file,cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo

	file = fopen(arquivo,"a");
	fprintf(file," | NOME E SOBRENOME: ");
	fclose(file);
	
	printf("\n\n\nNOME (somente o primeiro nome): ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," ");
	fclose(file);
	
	printf("\n\n\nSOBRENOME (somente o último sobrenome): ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," | CARGO: ");
	fclose(file);
	
	printf("\n\n\nCARGO: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("\n\!! CONSULTA DE USUÁRIO !! \n\n\n\n");
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nCPF não localizado!\n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nInformações do USUÁRIO: \n\n\nCPF: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("\n!! DELETAR USUÁRIO !!\n\n\n\nDigite CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\n\nUsuário não encontrado!\n\n\n\n");
	}
	
	if(file != NULL)
	{
		printf("\n\n\n\nUsuário DELETADO!\n\n\n\n");
	}

system("pause");

}


int main ()
{
	int opcao=0; //Definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf ("\n ### Cartório da EBAC ###\n\n"); //Início o menu
		printf ("Escolha a opção desejada no menu de Cadastros:\n\n");
		printf("\t1 - Registrar\n\n");
		printf("\t2 - Consultar\n\n");
		printf("\t3 - Deletar\n\n"); 
		printf("\n\n\t4 - Sair do Sistema\n\n\n\n");
		printf("Digite uma opção: "); //Final do menu
	
		scanf("%d", &opcao); //Amrzenando informações
	
		system("cls");
	

	switch (opcao) //Início da seleção
	{
		case 1:
		registrar();
		break;
	
		case 2:
		consultar();
		break;
	
		case 3:
		deletar();
		break;
		
		case 4:
		printf("\n\nObrigado(a) por utilizar o sistema!\n\n");
		return 0;
		break;
	
		default:
			printf("\n\n\n\nVocê escolheu uma opção INVÁLIDA!\n\n\n\n");
			system("pause");
		break;
	
	} //Final da seleção
	}
	
	printf("\n\nEsse software é de livre uso de Maria Eduarda Scariotto");
}
