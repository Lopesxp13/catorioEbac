#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região          
#include <string.h> //biblioteca responsável por cuida dos string

int registro() //Função responsavel pro cadastrar os usuários no sistema
 {
 	//inicio criação de variáveis/string
 	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fnal da criação de variáveis/string
	
	printf("digite o cpf a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%srefere-se a string
	
	strcpy(arquivo, cpf); // Responsável por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo
	fprintf(file,cpf); //salvo o valoda variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado : ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,"a");
	fclose(file);
	
	printf("digiteo cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
 }
int consulta()
{
	
     char cpf[40];
     char conteudo[200];
     
     printf("Digite o cpf a ser consultado: ");
     scanf("%s",cpf);
     
     FILE *file;
     file = fopen(cpf,"r");
     
     if(file == NULL)
     {
     	printf("não foi possivel abrir o arquivo, não localizado!.\n");
	 }
      while(fgets(conteudo, 200, file) != NULL)
      {
      	printf("\nEssas são as informacões do usuário: ");
      	printf("%s", conteudo);
      	printf("\n\n");
	  }
 
        system("pause");
}
	      
int deletar() 
{
    char cpf[40];
    
	printf("Digite o cpf do usuário a ser deletado");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		system("pause");
	}
}
int main()
{
    int opcao=0; //definido variaveis  
	int laco=1;
	
    for(laco=1;laco=1;)
	{
	
	system("cls");
	
    setlocale(LC_ALL, "Portuguese"); //DEfinido o linguagem
    
    
	printf("### Cartório da EBAC ###\n\n"); //inicio do menu   
	printf("Escolha a Opção desejada do menu:\n\n");
	printf("\t1 - Regitrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n");
	printf("opcao: "); //fim do menu
	 
	
	scanf("%d", &opcao); //armazenando a escolha do usuario
	
	system("cls"); //responsavelpor limpar a tela 
	
	switch(opcao) //inicio da seleção
	{
		case 1:
		registro(); //chamada de funções
	    break;
	
  	     case 2:
  	     consulta();
  	     break;
	    
	    case 3:
	    deletar();
	    break;
	    
	    
	    default:printf("Esse opcao não está disponivel\n");
	    system("pause");
	    break;
	}  //fim da seleção
	
	
	
}
}
