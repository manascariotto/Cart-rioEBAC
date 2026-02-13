#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bibliotec de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar()
{	
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	int opcao_interna;
	
	do 
	{
		system("cls");	
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
	
		printf("\n\nUsuário registrado com sucesso!\n\n");
		
		//Menu de decisão
		printf("\n\nDeseja:\n");
		printf("\t1 - Registrar outro usuário\n");
		printf("\t2 - Voltar ao menu principal\n");
		printf("\t3 - Encerrar o programa\n");
		printf("\nEscolha uma opção: ");
		scanf("%d", &opcao_interna);
		
		if (opcao_interna == 3)
		exit(0);
		
		} 
		
	while (opcao_interna == 1);
	return 0;
		
	system("pause");
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	int opcao_consulta; //Variável para controlar o menu interno
	
	do 
	{
	
		system("cls"); //Limpa a tela a cada nova consulta
		char cpf[40];
		char conteudo[200];
	
		printf("\n!! CONSULTA DE USUÁRIO !! \n\n\n\n");
		printf("Digite o CPF a ser consultado: ");
		scanf("%s",cpf);
	
		FILE *file;
		file = fopen(cpf,"r");
	
		if(file == NULL)
		{
			printf("\nCPF não localizado!\n\n\n");
		}
		else
		{
			printf("\nInformações do USUÁRIO: \n\n\nCPF: ");
			while(fgets(conteudo, 200, file) != NULL)
			{
			
				printf("%s", conteudo);
			}
			printf("\n\n");
			fclose(file); //Fechando o arquivo
		}
	
		//Menu de decisão após a consulta
		printf("\n\nDeseja:\n");
		printf("\t1 - Consultar outro usuário\n");
		printf("\t2 - Voltar ao menu principal\n");
		printf("\t3 - Encerrar o programa\n");
		printf("\nEscolha uma opção: ");
		scanf("%d", &opcao_consulta);
	
		if (opcao_consulta == 3)
		{ 
			printf("\n\nEncerrando o sistema... Até logo!\n\n");
			exit(0); //Finaliza o programa completamente
		}
	}
	
	while (opcao_consulta == 1); //Se for 2, o laço quebra e volta para a main
	return 0;
	
	system("pause");

}

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	int opcao_interna;
	
	do 
	{
		system("cls");
		char cpf[40];
	
		printf("\n!! DELETAR USUÁRIO !!\n\n\n\nDigite CPF a ser deletado: ");
		scanf("%s", cpf);
	
		//remover o arquivo	
		if (remove(cpf) == 0)
		{
			printf("\n\nUsuário deletado com sucesso!\n\n");
		}
		
		else 
		{
			printf("\n\nErro: Usuário não encontrado ou não foi possível deletar.\nVerifique o CPF.\n\n");
		}

		printf("\n\nDeseja:\n\n");
		printf("\t1 - Deletar outro usuário\n");
		printf("\t2 - Voltar ao menu\n");
		printf("\t3 - Encerrar o programa\n");
		printf("\nEscolha uma opção: ");
		scanf("%d", &opcao_interna);
		
		if (opcao_interna == 3)
		exit (0);
	}
	
	while (opcao_interna == 1);
	return 0;

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
