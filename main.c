#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar informações de um médico
typedef struct Medico {
    int identificador;
    char nome[40];
    char especialidade[40];
    struct Medico *proximo;
} Medico;

// Lista encadeada para armazenar médicos
typedef struct {
    Medico *medicos;
    int tam;
} ListaMedico;

void inicializarListaMedico(ListaMedico *lista) {
    lista->medicos = NULL;
    lista->tam = 0;
}

void incluirMedico(ListaMedico *lista, Medico *m) {
    m->proximo = NULL;
    if (lista->medicos == NULL) {
        lista->medicos = m;
    } else {
        Medico *aux = lista->medicos;
        while (aux->proximo != NULL) {
            aux = aux->proximo;
        }
        aux->proximo = m;
    }
    lista->tam++;
}

void listarMedicos(ListaMedico *lista) {
    Medico *aux = lista->medicos;
    while (aux != NULL) {
        printf("ID: %d\n", aux->identificador);
        printf("Nome: %s\n", aux->nome);
        printf("Especialidade: %s\n", aux->especialidade);
        aux = aux->proximo;
    }
}

// Estrutura para armazenar informações de um paciente
typedef struct {
    int identificador;
    char nome[40];
    int identidade;
    char endereco[40];
    int telefone;
    char sexo;
} Paciente;

// Estrutura para armazenar informações de uma consulta
typedef struct {
    int numero;
    int medicoID;
    int pacienteID;
    char horario[10];
    int duracao;
    char data[10];
} Consulta;

int main(void) {
    int opcao;
    do {
        printf("\n==== MENU ====\n");
        printf("1 - Agendar Consulta\n");
        printf("2 - Cadastrar Paciente\n");
        printf("3 - Cadastrar Medico\n");
        printf("4 - Relatorio\n");
        printf("5 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Funcionalidade de agendamento ainda nao implementada.\n");
                break;
            case 2:
                printf("Funcionalidade de cadastro de paciente ainda nao implementada.\n");
                break;
            case 3:
                printf("Funcionalidade de cadastro de medico ainda nao implementada.\n");
                break;
            case 4:
                printf("Funcionalidade de relatorio ainda nao implementada.\n");
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 5);
    
    return 0;
}
