#include <stdio.h>   // Biblioteca padrão de entrada e saída (printf, scanf, fopen, etc.)
#include <stdlib.h>  // Biblioteca padrão com funções utilitárias (system, remove, etc.)
#include <string.h>  // Biblioteca para manipulação de strings (strcpy, strcmp, etc.)
#include <locale.h>  // Biblioteca para configurar localização (acentos, caracteres especiais, etc.)

// ---------------------- FUNÇÃO PARA CADASTRAR NOVO USUÁRIO ----------------------
void cadastro_usuario() {
    char arquivosenha[20]; // Nome do arquivo (baseado na senha do usuário)
    char senha[10];        // Senha digitada pelo usuário
    char usuario[40];      // Nome do usuário
    FILE *file;            // Ponteiro para manipulação de arquivos

    do {
        printf("\n\n**** CADASTRO DE USUARIO ****\n\n");

        // Solicita senha para cadastro
        printf("\nDigite a senha a ser cadastrada: ");
        scanf("%s", senha);

        // Copia a senha para a variável que será usada como nome do arquivo
        strcpy(arquivosenha, senha);

        // Verifica se já existe arquivo com esse nome (ou seja, senha já cadastrada)
        file = fopen(arquivosenha, "r");
        if (file != NULL) { // Se arquivo existir
            fclose(file); // Fecha o arquivo
            printf("\nUsuario já existente!\n");
            system("pause");
            continue; // Volta ao início do loop para tentar novamente
        }

        // Cria o arquivo com a senha como nome e salva a senha dentro
        file = fopen(arquivosenha, "w");
        fprintf(file, "Senha: %s", senha); // Grava no arquivo
        fclose(file);

        // Solicita o nome do usuário
        printf("\nInforme o nome do Usuario: ");
        scanf("%s", usuario);

        // Abre o arquivo novamente no modo de adição e salva o nome
        file = fopen(arquivosenha, "a");
        fprintf(file, "\nNome: %s", usuario);
        fclose(file);

        // Mensagem de sucesso
        printf("\nUSUARIO CADASTRADO COM SUCESSO!\n");
        system("pause");
        break; // Sai do loop

    } while (1); // Loop infinito até o cadastro ser feito com sucesso
}

// ---------------------- FUNÇÃO DE LOGIN ----------------------
int login() {
    char senha[20];     // Senha digitada pelo usuário
    char arquivo[40];   // Nome do arquivo baseado na senha
    char conteudo[200]; // Para leitura do conteúdo do arquivo
    FILE *file;

    // Solicita senha para login
    printf("\nInforme a senha do usuario: ");
    scanf("%s", senha);

    // Copia a senha para a variável que será usada como nome do arquivo
    strcpy(arquivo, senha);

    // Tenta abrir o arquivo correspondente à senha
    file = fopen(arquivo, "r");
    if (file == NULL) { // Se não encontrar o arquivo
        printf("\nSenha incorreta ou usuario não cadastrado.\n");
        system("pause");
        return 0; // Retorna 0 para indicar falha no login
    }

    // Exibe o conteúdo do arquivo (dados do usuário)
    printf("\nDADOS DO USUARIO:\n");
    while (fgets(conteudo, 200, file) != NULL) { // Lê linha por linha
        printf("%s\n", conteudo);
    }
    fclose(file);

    // Mensagem de sucesso
    printf("\nLOGIN EFETUADO COM SUCESSO!\n");
    system("pause");
    return 1; // Retorna 1 para indicar sucesso no login
}

// ---------------------- FUNÇÃO PARA REGISTRAR ALUNO ----------------------
void registro() {
    char arquivo[40], cpf[40], nome[40], sobrenome[40], cargo[40];
    FILE *file;

    // Solicita CPF (será o nome do arquivo)
    printf("Digite o CPF a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);

    // Cria o arquivo e grava o CPF
    file = fopen(arquivo, "w");
    fprintf(file, "CPF: %s", cpf);
    fclose(file);

    // Adiciona campo Nome
    file = fopen(arquivo, "a");
    fprintf(file, ", Nome: ");
    fclose(file);

    printf("\nDigite o nome: ");
    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", nome);
    fclose(file);

    // Adiciona campo Sobrenome
    file = fopen(arquivo, "a");
    fprintf(file, ", Sobrenome: ");
    fclose(file);

    printf("\nDigite o sobrenome: ");
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", sobrenome);
    fclose(file);

    // Adiciona campo Cargo
    file = fopen(arquivo, "a");
    fprintf(file, ", Cargo: ");
    fclose(file);

    printf("\nDigite o cargo: ");
    scanf("%s", cargo);

    file = fopen(arquivo, "a");
    fprintf(file, "%s", cargo);
    fclose(file);

    printf("\nCADASTRADO COM SUCESSO!\n");
    system("pause");
}

// ---------------------- FUNÇÃO PARA CONSULTAR ALUNO ----------------------
void consulta() {
    char cpf[40], conteudo[200];
    FILE *file;

    // Solicita CPF para consulta
    printf("Digite o CPF a ser consultado: ");
    scanf("%s", cpf);

    // Tenta abrir o arquivo correspondente
    file = fopen(cpf, "r");
    if (file == NULL) { // Se não encontrar
        printf("\nCadastro não encontrado!\n");
    } else {
        // Lê e exibe todo o conteúdo
        while (fgets(conteudo, 200, file) != NULL) {
            printf("%s\n", conteudo);
        }
        fclose(file);
    }
    system("pause");
}

// ---------------------- FUNÇÃO PARA DELETAR ALUNO ----------------------
void deletar() {
    char cpf[40];

    // Solicita CPF para exclusão
    printf("Informe o CPF para exclusão: ");
    scanf("%s", cpf);

    // remove() apaga o arquivo com o nome igual ao CPF informado
    if (remove(cpf) == 0) {
        printf("\nDados deletados com sucesso!\n");
    } else {
        printf("\nDados não encontrados.\n");
    }
    system("pause");
}

// ---------------------- FUNÇÃO PRINCIPAL ----------------------
int main() {
    setlocale(LC_ALL, "Portuguese"); // Configura a localização para permitir acentos no console

    int opcao_auth = 0; // Opção escolhida no menu de autenticação
    int logado = 0;     // Flag para indicar se o usuário fez login com sucesso

    // MENU DE LOGIN / CADASTRO
    do {
        system("cls"); // Limpa a tela
        printf("\n**** SISTEMA DE AUTENTICACAO ****\n");
        printf("1 - Cadastrar Usuario\n");
        printf("2 - Login\n");
        printf("0 - Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao_auth);

        switch (opcao_auth) {
            case 1:
                cadastro_usuario(); // Chama função de cadastro de usuário
                break;
            case 2:
                logado = login(); // Chama função de login
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                return 0; // Encerra o programa
            default:
                printf("\nOpção inválida!\n");
                system("pause");
        }

        // Só avança para o menu de alunos se o login for bem-sucedido
        if (logado == 1) break;

    } while (1); // Loop infinito até login válido ou saída

    // MENU DE ALUNOS
    int opcao_alunos = 0;
    do {
        system("cls"); // Limpa a tela
        printf("\n**** MENU DE CADASTRO EBAC ****\n");
        printf("1 - Cadastrar.\n");
        printf("2 - Consultar.\n");
        printf("3 - Deletar.\n");
        printf("0 - Sair\n");
        printf("\nEscolha: ");
        scanf("%d", &opcao_alunos);

        switch (opcao_alunos) {
            case 1:
                registro(); // Cadastra novo aluno
                break;
            case 2:
                consulta(); // Consulta aluno
                break;
            case 3:
                deletar(); // Deleta aluno
                break;
            case 0:
                printf("\nSaindo do sistema...\n");
                break;
            default:
                printf("\nOpção inválida!\n");
                system("pause");
        }

    } while (opcao_alunos != 0); // Repete até escolher "Sair"

    return 0; // Fim do programa
}