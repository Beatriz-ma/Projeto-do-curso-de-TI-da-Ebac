#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h>  //biblioteca de alocação de espaço em memória
#include <locale.h>  //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registrar() // Função para registrar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char arquivo[40]; // Início da definição das variáveis/ strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // Fim da definição de variáveis/ strings 
	
	printf("Digite o CPF do usuário a ser cadastrado: "); // Comando para usuário inserir informações
	scanf("%s", cpf); // salvar a informação: %s refere-se a string a ser armazenada 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string (nome do arquivo = cpf)
	
	FILE *file; // Chama a função FILE para criar um arquivo
	file = fopen(arquivo, "w"); // cria o arquivo: w é para escrever
	fprintf(file,"CPF: "); // definindo o dado a ser inserido
	fprintf(file,cpf); // salva o valor da variavel
	fprintf(file,"\n"); // pula uma linha para inserir a variável seguinte
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // adiciona nova informação no arquivo
	fprintf(file,"Nome: ");
	fprintf(file,nome);
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Sobrenome: ");
	fprintf(file,sobrenome);
	fprintf(file,"\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,"Cargo: ");
	fprintf(file,cargo);
	fprintf(file,"\n");
	fclose(file);	
	
    system("pause");

}

int consultar() // Função para consultar as informações do usuário cadastrado
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40]; // Definindo variáveis
	char conteudo[100];
	
	printf("\tDigite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
  	
FILE *file; // Chama a função para abrir o arquivo
file = fopen(cpf,"r"); // ler o arquivo
  	
if(file == NULL) // caso não haja o arquivo referente ao cpf informado / usuário não cadastrado
{
	printf("Não foi possivel abrir o arquivo - CPF não localizado!\n");
}
	
if(fgets) // quando o arquivo é encontrado
{
fgets(conteudo,100,file);
printf("\n\tEssas são as informações do usuário:\n");
}

while(fgets(conteudo, 100, file) != NULL) // repetição usada para apresentar todas as informações do usuário
{
	printf("%s", conteudo);
}
  	
system ("pause");
}

int deletar() // Função para deletar o arquivo de um usuário 
{
	char cpf[40]; // Definindo a variável 
	
	printf("\tDigite o CPF do usuário que deseja deletar do sistema: " );
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // ler o arquivo
		
if(file == NULL) // caso não haja o arquivo referente ao cpf informado
{
	printf("\n\t O CPF informado não se encontra no sistema\n");	
	system("pause");
}
else // quando o arquivo é encontrado
{
	fclose(file);
	remove(cpf);
	printf("\t\nUsuário deletado!\n");
	system("pause");
}
}

int main() // Função inicial para apresentar o menu 
{
	int opcao=0; // Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;) // Definindo a repetição
  {
 	system("cls"); // comando para limpar a tela (opção estética)
 	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	// Início do Menu
	printf("\n\t### Cartório da EBAC ###\n\n"); 
	printf("   Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar usuários\n");
	printf("\t2 - Consultar usuários\n");
	printf("\t3 - Deletar usuários\n"); 
	printf("\t4 - Sair do sistema\n\n"); 
	//Fim do Menu
	
	scanf("%d", &opcao); // Armazenando a escolha do usuário
	
	system("cls"); // comando para limpar a tela (opção estética)
	
	switch(opcao) // Início da seleção do menu (chamar funções para cada opção) 
	{
		case 1:
		registrar(); // chamada das funções
	 	break; 
	 	
	 	case 2:
	 	consultar();
	 	break;
	 	
	 	case 3:
	 	deletar();
	 	break; 
	 	
	 	case 4:
	 	printf("\nObrigada por utilizar o nosso sistema!\n");
	 	return 0;
	 	break; 
	 	
	 	default:
	 	printf("\t Essa opção não está disponível -> Escolha 1,2 ou 3 no menu \n"); // Acrescentei a seta com instrução para correção do usuário
	 	system("pause");
	 	break;
	}  // Fim da seleção
  }
}

// Acrescentar no final do projeto: 
// printf("   Esse Software é de livre uso dos alunos da EBAC e foi criado\n  durante a aula 5 (Primeiro Código) do curso TI do Zero ao Pro");
