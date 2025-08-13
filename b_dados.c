#include <stdio.h>   // Biblioteca padrão de entrada e saída
#include <stdlib.h>  // Biblioteca para funções utilitárias (system, remove, etc.)
#include <string.h>  // Biblioteca para manipulação de strings (strcpy, etc.)
#include <locale.h>  // Biblioteca para configuração de idioma e acentuação

// Função para registrar um novo usuário
void registro(){

    setlocale(LC_ALL, "Portuguese"); // Define configuração regional para português

    int opcao = 0;

    do{
        char arquivo[40];    // Nome do arquivo (será o CPF)
        char cpf[40];        // CPF do usuário
        char nome[40];       // Nome do usuário
        char sobrenome[40];  // Sobrenome do usuário
        char cargo[40];      // Cargo do usuário

        system("cls");

        printf("Digite o CPF a ser cadastrado: ");
        scanf("%s", cpf); // Lê o CPF digitado

        strcpy(arquivo, cpf); // Copia o CPF para a variável arquivo

        FILE *file; // Declara ponteiro para arquivo
        file = fopen(arquivo, "w"); // Cria arquivo com o nome do CPF
        fprintf(file, cpf); // Grava o CPF no arquivo
        fclose(file); // Fecha o arquivo

        file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar mais informações
        fprintf(file, ", Nome: ");  // Escreve a etiqueta "Nome" no arquivo
        fclose(file); 

        printf("\nDigite o nome a ser cadastrado: ");
        scanf("%s", nome); // Lê o nome do usuário

        file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar
        fprintf(file, nome);        // Grava o nome no arquivo
        fclose(file);

        file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar
        fprintf(file, ", Sobrenome: "); // Escreve a etiqueta "Sobrenome" no arquivo
        fclose(file); 

        printf("\nDigite o sobrenome a ser cadastrado: ");
        scanf("%s", sobrenome); // Lê o sobrenome

        file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar
        fprintf(file, sobrenome);   // Grava o sobrenome no arquivo
        fclose(file);

        file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar
        fprintf(file, ", Cargo: "); // Escreve a etiqueta "Cargo" no arquivo
        fclose(file);

        printf("\nDigite o cargo a ser cadastrado: ");
        scanf("%s", cargo); // Lê o cargo

        file = fopen(arquivo, "a"); // Abre o arquivo para acrescentar
        fprintf(file, cargo);       // Grava o cargo no arquivo
        fclose(file);

        printf("\nCADASTRADO COM SUCESSO!!\n"); // Mensagem de sucesso
        system("pause"); // Pausa a execução até pressionar uma tecla

        // Pergunta se deseja fazer outro cadastro
        do {
            printf("\nDeseja realizar outro cadastro ou retornar ao menu?\n");
            printf("1 - Novo cadastro\n");
            printf("2 - Retornar ao menu\n");
            printf("Escolha: ");
            scanf("%d", &opcao);

            if (opcao != 1 && opcao != 2) {
                printf("\nOpção inválida! Tente novamente.\n");
                system("pause");
            }
        } while (opcao != 1 && opcao != 2);

    } while (opcao == 1); // Continua se o usuário quiser novo cadastro

}

// Função para consultar os dados de um usuário
void consulta(){

    setlocale(LC_ALL, "Portuguese"); // Define configuração regional para português

    char cpf[40];       // CPF para consulta
    char conteudo[200]; // Buffer para leitura do arquivo

    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf); // Lê o CPF

    FILE *file;
    file = fopen(cpf, "r"); // Abre o arquivo com o nome do CPF

    if(file == NULL){ // Verifica se o arquivo existe
        printf("\nNão foi possivel abrir o arquivo, não localizado!\n");
    }

    // Lê linha por linha do arquivo e exibe
    while(fgets(conteudo, 200, file) != NULL){
        printf("\nEssas são as informações do usuario: ");
        printf("CPF: %s", conteudo);
        printf("\n\n");
    }

    system("pause"); // Pausa a execução
}

// Função para deletar um usuário
void deletar(){
    char cpf[40]; // CPF do usuário a ser deletado

    printf("Informe o CPF do usuário a ser deletado: ");
    scanf("%s", cpf); // Lê o CPF

    FILE *file;
    file = fopen(cpf, "r"); // Abre o arquivo para leitura

    if(remove(cpf) == 0){ // Remove o arquivo
        printf("\nUsuario deletado com sucesso!!\n");
        system("pause"); // Pausa a execução
    }
    else if(remove(cpf) != 0){ // Se não conseguir remover
        printf("\nUsuario não encontrado ou não pode ser deletado.\n");
        system("pause");
    }
}

// Função principal
int main (){
    setlocale(LC_ALL, "Portuguese"); // Define configuração regional para português

    int x = 0; // Variável para armazenar a opção escolhida

   do{
    system("cls"); // Limpa a tela

    // Exibe o menu
    printf("\n\n**** CARTÓRIO EBAC ****\n\n");
    printf("Menu de opções: \n\n");
    printf("\t1 - CADASTRAR ALUNO.\n");
    printf("\t2 - CONSULTAR ALUNO.\n");
    printf("\t3 - DELETAR ALUNO.\n");
    printf("\t0 - SAIR!");
    printf("\n\nEscolha uma opção: ");
    scanf("%d", &x); // Lê a opção

    system("cls"); // Limpa a tela

    // Executa a função correspondente à opção
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
        system("pause"); // Pausa até pressionar tecla
    }

   }while(x != 0); // Repete enquanto a opção não for "0"

}
