#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>  //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registrar() // Fun��o para registrar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	char arquivo[40]; // In�cio da defini��o das vari�veis/ strings
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // Fim da defini��o de vari�veis/ strings 
	
	printf("Digite o CPF do usu�rio a ser cadastrado: "); // Comando para usu�rio inserir informa��es
	scanf("%s", cpf); // salvar a informa��o: %s refere-se a string a ser armazenada 
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string (nome do arquivo = cpf)
	
	FILE *file; // Chama a fun��o FILE para criar um arquivo
	file = fopen(arquivo, "w"); // cria o arquivo: w � para escrever
	fprintf(file,"CPF: "); // definindo o dado a ser inserido
	fprintf(file,cpf); // salva o valor da variavel
	fprintf(file,"\n"); // pula uma linha para inserir a vari�vel seguinte
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); // adiciona nova informa��o no arquivo
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

int consultar() // Fun��o para consultar as informa��es do usu�rio cadastrado
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40]; // Definindo vari�veis
	char conteudo[100];
	
	printf("\tDigite o CPF do usu�rio a ser consultado: ");
	scanf("%s",cpf);
  	
FILE *file; // Chama a fun��o para abrir o arquivo
file = fopen(cpf,"r"); // ler o arquivo
  	
if(file == NULL) // caso n�o haja o arquivo referente ao cpf informado / usu�rio n�o cadastrado
{
	printf("N�o foi possivel abrir o arquivo - CPF n�o localizado!\n");
}
	
if(fgets) // quando o arquivo � encontrado
{
fgets(conteudo,100,file);
printf("\n\tEssas s�o as informa��es do usu�rio:\n");
}

while(fgets(conteudo, 100, file) != NULL) // repeti��o usada para apresentar todas as informa��es do usu�rio
{
	printf("%s", conteudo);
}
  	
system ("pause");
}

int deletar() // Fun��o para deletar o arquivo de um usu�rio 
{
	char cpf[40]; // Definindo a vari�vel 
	
	printf("\tDigite o CPF do usu�rio que deseja deletar do sistema: " );
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // ler o arquivo
		
if(file == NULL) // caso n�o haja o arquivo referente ao cpf informado
{
	printf("\n\t O CPF informado n�o se encontra no sistema\n");	
	system("pause");
}
else // quando o arquivo � encontrado
{
	fclose(file);
	remove(cpf);
	printf("\t\nUsu�rio deletado!\n");
	system("pause");
}
}

int main() // Fun��o inicial para apresentar o menu 
{
	int opcao=0; // Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;) // Definindo a repeti��o
  {
 	system("cls"); // comando para limpar a tela (op��o est�tica)
 	
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem 
	
	// In�cio do Menu
	printf("\n\t### Cart�rio da EBAC ###\n\n"); 
	printf("   Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar usu�rios\n");
	printf("\t2 - Consultar usu�rios\n");
	printf("\t3 - Deletar usu�rios\n\n"); 
	printf("   Digite 1,2 ou 3 e tecle enter\n"); // Acrescentei a instru��o para facilitar a compreens�o do usu�rio
	//Fim do Menu
	
	scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
	system("cls"); // comando para limpar a tela (op��o est�tica)
	
	switch(opcao) // In�cio da sele��o do menu (chamar fun��es para cada op��o) 
	{
		case 1:
		registrar(); // chamada das fun��es
	 	break; 
	 	
	 	case 2:
	 	consultar();
	 	break;
	 	
	 	case 3:
	 	deletar();
	 	break; 
	 	
	 	default:
	 	printf("\t Essa op��o n�o est� dispon�vel -> Escolha 1,2 ou 3 no menu \n"); // Acrescentei a seta com instru��o para corre��o do usu�rio
	 	system("pause");
	 	break;
	}  // Fim da sele��o
  }
}

// Acrescentar no final do projeto: 
// printf("   Esse Software � de livre uso dos alunos da EBAC e foi criado\n  durante a aula 5 (Primeiro C�digo) do curso TI do Zero ao Pro");
