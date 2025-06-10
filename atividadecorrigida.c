#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define uma variável constante, com o número máximo de clientes que podem ser armazenados no array
#define MAX_CLIENTES 50

// Estrutura para armazenar os dados do cliente
typedef struct
{
    int codigo;
    char nome[100];
    char email[100];
    int idade;
} Cliente;

// Array global para armazenar os clientes e contador
Cliente clientes[MAX_CLIENTES];
int totalClientes = 0;

// Protótipos das funções
void exibirMenu();
void adicionarCliente();
void listarClientes();
void buscarCliente();

int main()
{
    int opcao;

    do
    {
        exibirMenu();
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer do teclado

        switch (opcao)
        {
        case 1:
            adicionarCliente();
            break;
        case 2:
            listarClientes();
            break;
        case 3:
            buscarCliente();
            break;
        case 0:
            printf("Saindo do sistema...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
        }
        printf("\nPressione Enter para continuar...");
        getchar();

    } while (opcao != 0);

    return 0;
}

void exibirMenu()
{
    system("clear || cls"); // Limpa a tela no Linux/Mac (clear) ou Windows (cls)
    printf("==================================\n");
    printf("      SISTEMA DE CADASTRO\n");
    printf("==================================\n");
    printf("1 - Adicionar Cliente\n");
    printf("2 - Listar Clientes\n");
    printf("3 - Buscar Cliente\n");
    printf("0 - Sair\n");
    printf("==================================\n");
    printf("Escolha uma opcao: ");
}

void adicionarCliente()
{
    if (totalClientes >= MAX_CLIENTES)
    {
        printf("Limite máximo de clientes atingido!\n");
        return;
    }

    Cliente novoCliente;

    printf("Digite o código do cliente: ");
    scanf("%d", &novoCliente.codigo);
    getchar();

    printf("Digite o nome do cliente: ");
    fgets(novoCliente.nome, sizeof(novoCliente.nome), stdin);
    novoCliente.nome[strcspn(novoCliente.nome, "\n")] = '\0'; // remove '\n'

    printf("Digite o email do cliente: ");
    fgets(novoCliente.email, sizeof(novoCliente.email), stdin);
    novoCliente.email[strcspn(novoCliente.email, "\n")] = '\0';

    printf("Digite a idade do cliente: ");
    scanf("%d", &novoCliente.idade);
    getchar();

    clientes[totalClientes++] = novoCliente;

    printf("Cliente adicionado com sucesso!\n");
}

void listarClientes()
{
    if (totalClientes == 0)
    {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("==== Lista de Clientes ====\n");
    for (int i = 0; i < totalClientes; i++)
    {
        printf("Código: %d\n", clientes[i].codigo);
        printf("Nome: %s\n", clientes[i].nome);
        printf("Email: %s\n", clientes[i].email);
        printf("Idade: %d\n", clientes[i].idade);
        printf("--------------------------\n");
    }
}

void buscarCliente()
{
    int codigo;
    printf("Digite o código do cliente para buscar: ");
    scanf("%d", &codigo);
    getchar();

    for (int i = 0; i < totalClientes; i++)
    {
        if (clientes[i].codigo == codigo)
        {
            printf("Cliente encontrado:\n");
            printf("Código: %d\n", clientes[i].codigo);
            printf("Nome: %s\n", clientes[i].nome);
            printf("Email: %s\n", clientes[i].email);
            printf("Idade: %d\n", clientes[i].idade);
            return;
        }
    }
    printf("Cliente com código %d não encontrado.\n", codigo);
}
