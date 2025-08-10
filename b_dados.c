#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void registro(){

    setlocale(LC_ALL, "Portuguese");

    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    FILE *file; //cria um arquivo
    file = fopen(arquivo, "w"); //cria o arquivo com o nome do CPF
    fprintf(file, cpf); //sava o valor da variavel
    fclose(file); //fecha o arquivo

    file = fopen(arquivo, "a"); //abre o arquivo para adicionar mais informações
    fprintf(file, ", Nome: ");
    fclose(file); 

    printf("\nDigite o nome a ser cadastrado: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ", Sobrenome: ");
    fclose(file); 

    printf("\nDigite o sobrenome a ser cadastrado: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ", Cargo: ");
    fclose(file);

    printf("\nDigite o cargo a ser cadastrado: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, cargo);
    fclose(file);

    printf("\nCADASTRADO COM SUCESSO!!");
    system("pause");
}

void consulta(){

    setlocale(LC_ALL, "Portuguese");

    char cpf[40];
    char conteudo[200];

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL){
        printf("\nNão foi possivel abrir o arquivo, não localizado!\n");
        return;
    }

    while(fgets(conteudo, 200, file) != NULL){
        printf("\nEssas são as informações do usuario: ");
        printf("CPF: %s", conteudo);
        printf("\n\n");
    }

    system("pause");
}

void deletar(){
    char cpf[40];

    printf("Informe o CPF do usuário a ser deletado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(remove(cpf) == 0){
        printf("\nUsuario deletado com sucesso!!\n");
        system("pause");
    }
    else if(remove(cpf) != 0){
        printf("\nUsuario não encontrado ou não pode ser deletado.\n");
        system("pause");
    }
    fclose(file);
}

int main (){
    setlocale(LC_ALL, "Portuguese");

    int x = 0;

   do{
     
    system("cls");

    printf("\n\n**** CARTÓRIO EBAC ****\n\n");
    printf("Menu de opções: \n\n");
    printf("\t1 - CADASTRAR ALUNO.\n");
    printf("\t2 - CONSULTAR ALUNO.\n");
    printf("\t3 - DELETAR ALUNO.\n");
    printf("\t0 - SAIR!");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &x);

    system("cls");

    switch (x){
        case 1: 
        registro();
        break;

        case 2:	
        consulta();
        break;

        case 3:
        deletar();
        break;

        case 0:
          printf("\nSaindo do sistema...\n");

        break;

        default:
        printf("\nOPÇÃO INVALIDA!\n");
        system("pause");
    }

   }while(x != 0);

}
