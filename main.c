#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Funções para o médico
typedef struct {
    int crm;
    char nome[50];
    char especialidade[50];
} Medico;

Medico *medicos = NULL;
int totalMedicos = 0;


void incluirMedico(){
    medicos = (Medico *)realloc(medicos,(totalMedicos+1) * sizeof(Medico));
    if (medicos == NULL){
        printf("Eita, deu erro na hora de alocar a memoria doidho!\n");
        return;
    }

    printf("\n --- Cadastro de Medico ---");
    printf("Digite o CRM: ");
    scanf(" %d", &medicos[totalMedicos].crm);
    getchar();

    printf("Digite o nome: ");
    fgets(medicos[totalMedicos].nome, 50, stdin);
    medicos[totalMedicos].nome[strcspn(medicos[totalMedicos].nome, "\n")] = 0;

    printf("Digite a especialização: ");
    fgets(medicos[totalMedicos].especialidade, 50, stdin);
    medicos[totalMedicos].especialidade[strcspn(medicos[totalMedicos].especialidade, "\n")] = 0;

    totalMedicos++;
    printf("Medico cadastrado com sucesso!\n");

    }
    
    printf("\n --- Cadastro de Medico ---\n");
    printf("Digite o CRM: ");
    scanf(" %d", &medicos[totalMedicos].crm);
    getchar();//Usado para limpar o buffer do teclado

    printf("Digite o nome: ");
    fgets(medicos[totalMedicos].name, 50, stdin);
    medicos[totalMedicos].name[strcspn(medicos[totalMedicos].name, "\n")] = 0; //Função para remover o \n do fgets

    printf("Digite a especializacao do candango:");
    fgets(medicos[totalMedicos].especialidade, 50, stdin);
    medicos[totalMedicos].especialidade[strcspn(medicos[totalMedicos].especialidade, "\n")] = 0; //Novamente, removendo o \n do fgets

    medicos[totalMedicos].ativo = 1;
    totalMedicos++;

    printf("Medico cadastrado com sucesso no sistema!\n");
}



//Listing existing doctors for you my brother
void listDoctors(){
    printf("\n --- Lista de Medicos ---\n");
    for (int i = 0; i <totalMedicos; i++){
        if(medicos[i].ativo) {
            printf("CRM %d | Nome: %s | Especializacao: %s\n", medicos[i].crm, medicos[i].name, medicos[i].especialidade);
        }
    }
}


//Deleting doctors candangos, os baum stay os candango go away
void deleteDoctor(){
    int crm;
    printf("\n Digite o CRM do medico ao qual voce deseja remover do sistema: ");
    scanf(" %d", &crm);

    for (int i = 0; i<totalMedicos; i++){
        if (medicos[i].crm == crm && medicos[i].ativo){
            medicos[i].ativo = 0; // Tornando assim o candango demitido
            printf("Medico deletado com sucesso!\n");
            return;
        }
    }
    printf("Medico não encontrado!\n");
}

//Menu, atualmente apenas para médicos
void menuMedico(){
    int option;
    do{
        printf("\n-------Menu-------\n");
        printf("1 - Incluir Medico\n");
        printf("2 - Listar Medicos\n");
        printf("3 - Atualizar Medico\n");
        printf("3 - Excluir Medico\n");
        printf("4 - Sair\n");
        printf("O que voce quer pra hoje meu pratao?: ");
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
            addDoctor();
            break;

            case 2:
            listDoctors();
            break;

            case 3:
            deleteDoctor();
            break;

            case 4:
            printf("Saindo...\n");
            break;

            default:
            printf("Desculpe, voce poderia escolher outra opcao?\n");
        
        }
    }while (option!=4);
}

//Fim das funções dos médicos


// Inicio das funções para os pacientes

Paciente pacientes[MAX_PACIENTES];
int totalPacients = 0;

typedef struct {
    int cpf;
    char name[50];
    int rg;
    char adress[100]; //Bro's adress
    int telefone;
    char sexo[50];
} Paciente;

void addPaciente() {
    int tamanho = 0;


}


void menuPacientes() {

    int option;
    do {

        switch(option){
            case 1:
                addPaciente();
                break;
        }
    }
}
//Fim das funções dos pacientes


//Inicio das funções para consulta

typedef struct {

    int consulta;
    int horario;
    int data;
    int duration;
    int idCrm; //Variável para chamar o CRM do médico
    int idCpf; //Variável para chamar o Cpf do paciente
    //Preciso entender se coloco novamente o crm do médico e o cpf do paciente, afinal eles irão se encontrar aqui na consulta, mas talvez não é necessário indicar isso na struct
} Consulta;

void menuConsultas(){
    //Escrever aqui o menu de consultas
}

//Fim das funções de consulta



//Inicio Função menuRelatorio
void menuRelatorio(){

    //Dentro da opção relatórios o usuário poderá escolher entre:
    //Lista de consultas agendadas para o paciente.
    //Lista de consultas agendadas para o médico.
    //Lista de pacientes por especialidade.

}
//Fim Função menuRelatorio

int main () {

    int opcoes;
    printf("Ola, seja bem vindo(a) ao sistema de gerenciamnento de consultas medicas!\n");
    printf("Developed by cttbiel and aires.\n");
    printf("Por favor, escolha uma das opcoes abaixo: \n");

    do
    {
        printf("\n-------Menu-------\n");
        printf("1 - Medicos\n");
        printf("2 - Pacientes\n");
        printf("3 - Consultas\n");
        printf("4 - Sair\n");
        scanf(" %d", &opcoes);    
    
    switch (opcoes) {
    case 1:
        menuMedico();
        break;

    case 2:
        menuPacientes();
        break;

    case 3:
        menuConsultas();
        break;

    case 4:
        menuRelatorio();
        break;

    case 5:
        printf("Fechando aplicacao...\n");
        break;
    
    default:
        printf("Opcao invalida patrao, joga ota ai pa nois\n");
        break;
    }
    } while (opcoes != 5);
    return 0;
}
