// =====================
//
// Sistema de biblioteca
//
// =====================

// -- Bibliotecas --
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// -- Constantes Globais --
#define MAX_LIVROS 50
#define TAM_STRING 100


// -- Definições da Estrutura --
struct Livro{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
};

// -- Protótipos de Funções --
void limparBufferEntrada();
void menuPrincipal();
void cadastrarLivro();
void listarLivros();

// ====================== Função Principal ======================


struct Livro biblioteca[MAX_LIVROS];
int totalLivros = 0; 

int main() {

    menuPrincipal();

 return 0;
}





// ======================= Outras Funções =======================

// -- Função Limpar Buffer de Entrada --
void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// -- Função Menu Principal --
void menuPrincipal() {
    int opcao;

    // -- Laço Principal do Menu Principal --
    do {
        printf("\n================================\n");
        printf("======== MENU PRINCIPAL ========\n");
        printf("================================\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Listar todos os livros\n");
        printf("3. Emprestar livros\n");
        printf("4. Vizualizar livros emprestados\n");
        printf("0. Sair\n");
        printf("================================\n");
        printf("Digite uma opção\n");

        // -- Lê a opção do usuário --
        scanf("%d", &opcao);
        limparBufferEntrada(); // Limpa o \n deixado pelo scanf.
    
        // -- Processamento da Opção --
        switch (opcao)
        {
        case 1:
            cadastrarLivro();
            break;

        case 2:
            listarLivros();
            break;

        case 3:
            printf("Empréstimo de livro(Ainda não implementado)");
            break;

        case 4:
            printf("Visualizar Empréstimo de livro(Ainda não implementado)");
            break;

        case 0:
            printf("\nSaindo...\n");
            
            break;
        
        default:
            printf("Opção inválida.\n");
            printf("Pressione Enter para sair.\n");
            getchar();
            break;
        }
    } while (opcao != 0);
    {
        printf("Saindo!");
    }
    
}


// -- Função Cadastrar livro --
void cadastrarLivro(){

    printf("\n==== CADASTRO DE LIVRO ====\n");
    if (totalLivros < MAX_LIVROS) {
        printf("Digite o nome do livro: ");
        fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);

        printf("Digite o nome do autor: ");
        fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);

        printf("Digite a editora: ");
        fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

        biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
        biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
        biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';

        printf("Digite a edição: ");
        scanf("%d", &biblioteca[totalLivros].edicao);
        limparBufferEntrada();

        totalLivros++;
        printf("Livro cadastrado com sucesso!\n");

    } else
    {
        printf("Biblioteca Cheia!\nLimite de livros cadastrados alcançado!\n");
    }
}

// -- FUNÇÃO DE LISTAR LIVROS --
void listarLivros() {

    if (totalLivros == 0)
    {
        printf("Nenhum livro cadastrado ainda!\n");
    } else {
        for (int i = 0; i < totalLivros; i++)
        {
            printf("------------------------------\n");
            printf("---------- LIVRO %d ----------\n", i + 1);
            printf("Nome: %s\n", biblioteca[i].nome);
            printf("Autor: %s\n", biblioteca[i].autor);
            printf("Editora: %s\n", biblioteca[i].editora);
            printf("Edição: %d\n", biblioteca[i].edicao);
        }
        printf("------------------------------");
    }
    
    

}