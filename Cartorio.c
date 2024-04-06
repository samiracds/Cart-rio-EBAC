#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de spaço de memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro ()  //função rrdponsável por cadastras os usuários no sistema
{
    //inicio da crianção de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome [40];
    char cargo [40];
    //final da criação de variáveis/string
    
    printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
    scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsável por copiar os valores da String
    
    FILE *file; //cria o arquivo 
    file = fopen(arquivo,"w"); //cria o arquivo e o "w" significa escrever
    fprintf(file, cpf); //salvo o valor da variavel
    fclose(file); //fecha o arquivo
    
    file = fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);  
    
    printf("Digite o cargo a ser cadastrado: ");
    scanf("%s", cargo);  
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    system("pause");
}

int consulta ()
{
    setlocale(LC_ALL,"Portuguese");
    
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);
    
    FILE *file;
    file = fopen(cpf, "r"); //cria o arquivo e o "w" significa ler
    
    if(file == NULL) //se for inserida uma informação inexistente, retornará com a mensagem de que o usuário não foi localizado
    {
        printf("Não foi possível abrir o arquivo, não localizado!.\n");
    }
    
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuário: ");
        printf("%s", conteudo);
        printf("\n\n");
    }
    
    system("pause");
  
}

int deletar ()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf); //remove os dados dentro do banco
    
    FILE *file;
    file = fopen(cpf, "r"); // cria o arquivo e o "r" significa read/ler
    
    if(file == NULL);
    {
        printf("O usuário não se encontra no sistema!.\n");
        system("pause");
    }
}


int main ()
{
    int opcao=0; //definindo as variáveis
    int laco=1;
    
    for(laco=1;laco=1;)
    {
    
       system("cls");
    
       setlocale(LC_ALL,"Portuguese"); //definindo a linguagem
    
       printf("###Cartório da EBAC###\n\n"); //inicio do menu
       printf("Escolha a opção desejada do Menu\n\n");
       printf("\t1 - Registrar nome\n");
       printf("\t2 - Consultar nome\n");
       printf("\t3 - Deletar nome\n"); 
       printf("\t4 - Sair do sistema\n");
       printf("Opção: "); //fim do menu
 
    
       scanf("%d", &opcao); //armazenando a escolha do usuário
    
       system ("cls"); //respnsável por limpar a tela
    
       switch(opcao) //inicio da seleção do meu
       {
           case 1:
           registro(); //chamada de função
           break;
           
           case 2:
          consulta();
           break;
           
           case 3:
           deletar();
           break;
           
           case 4:
           printf("Obrigado por utilizar o sistema!\n");
           return 0; // serve para quebra de laço, saindo do sistema
           break;
           
           default: 
           printf ("Essa opção não está disponível\n");
           system("pause");
           break;              
       }
    }
}



