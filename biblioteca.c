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
#define MAX_EMPRESTIMOS 100
#define TAM_STRING 100


// -- Definições da Estrutura --
struct Livro{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel;
};

struct Emprestimo {
    int indiceLivro; //Para saber qual livro de array 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// -- Protótipos de Funções --
void limparBufferEntrada();
void menuPrincipal();
void cadastrarLivro();
void listarLivros();
void realizarEmprestimo();
void listarEmprestimos();

// structs e variaveis usadas globalmente
struct Livro *biblioteca;
struct Emprestimo *emprestimos;




int totalLivros = 0;
int totalEmprestimos = 0;
int opcao;


// ====================== Função Principal ======================
int main() {
    // Usamos calloc para o array de livros
    biblioteca = (struct Livro *) calloc(MAX_LIVROS, sizeof(struct Livro));

    // Usamos calloc para o array de empréstimos
    emprestimos = (struct Emprestimo *) malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // VERIFICAÇÃO! VERIFICAR SE A ALOCAÇÃO DE MEMÓRIA DEU CERTO!
    if (biblioteca == NULL || emprestimos == NULL) {
        printf("ERRO: FALHA AO ALOCAR MEMÓRIA.\n");
        return 1; // Retorna 1 para indica o erro
    }
    
    // Chamando Menu Principal
    menuPrincipal();

    free(biblioteca);
    free(emprestimos);
    printf("Memória liberada com sucesso!\n");
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

    // -- Laço Principal do Menu Principal --
    
    do {
        printf("\n================================\n");
        printf("======== MENU PRINCIPAL ========\n");
        printf("================================\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Listar todos os livros\n");
        printf("3. Emprestar livros\n");
        printf("4. Listar emprestimos\n");
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
            realizarEmprestimo();
            break;

        case 4:
            listarEmprestimos();
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

        biblioteca[totalLivros].disponivel = 1;
        totalLivros++;
        
        printf("Livro cadastrado com sucesso!\n");
        printf("Aperte Enter para continuar.\n");
        getchar();

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
        printf("------------------------------\n");
        printf("Aperte Enter para continuar.\n");
        getchar();
    }
}

// -- Função Realizar Empréstimo --
void realizarEmprestimo() {
    printf("---------------------------------\n");
    printf("------ REALIZAR EMPRÉSTIMO ------\n");
    
    if (totalEmprestimos >= MAX_EMPRESTIMOS)
    {
        printf("Limite de emprestimos atingido!\n");
    } else {
        printf("Livros disponíveis:\n");
        int disponiveis = 0;
        for (int i = 0; i < totalLivros; i++)
        {
            if (biblioteca[i].disponivel)
            {
                printf("%d - %s\n", i + 1, biblioteca[i].nome);
                disponiveis++;
            }
        }
        
        if (disponiveis == 0) {
            printf("Nenhum livro disponivel para emprestimo!\n");
        } else
        {
            printf("\nDigite o numero do livro que deseja emprestar\n");
            int numLivro;
            scanf("%d", &numLivro);
            limparBufferEntrada();

            int indice = numLivro - 1; // Converte  para o indeice do array (0 a N - 1)

            // Validação da escolha do usuário
            if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel){
                printf("digite o nome do usuario que esta pegando o livro: ");
                fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '\0';
            
                // Registra emprestimo
                emprestimos[totalEmprestimos].indiceLivro = indice;

                // Atualiza o status do livro para indisponivel
                biblioteca[indice].disponivel = 0;

                totalEmprestimos++;
                printf("\nEmprestimo realizado com sucesso!\n");
            } else {
                printf("\nNúmero de livro inválido ou livro indisponivel.\n");
            }
        }
    }
}

// -- Função Listar Empréstimo --
void listarEmprestimos() {
    printf("------------------------------\n");
    printf("----- LISTA DE EMPRÉSTIMOS -----\n");
    if (totalEmprestimos == 0)
    {
        printf("Nenhum empréstimo realizado.\n");
    } else {
        for (int i = 0; i < totalEmprestimos; i++)
        {
            int indiceLivro = emprestimos[i].indiceLivro;
            printf("------------------------------\n");
            printf("EMPRESTIMO %d\n", i + 1);
            printf("Livro: %s\n", biblioteca[indiceLivro].nome);
            printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
        }
        printf("------------------------------\n");
    }
    printf("Aperte Enter para continuar.");
    getchar();
 }
    
    
    