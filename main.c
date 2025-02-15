#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICOS 20
#define MAX_PACIENTES 50

//Struct dos doctor
typedef struct {
    int crm;
    char name[50];
    char especialidade[50];
    int ativo; // 1 - Ativo, 0 - Inativo
} Medico;

Medico medicos[MAX_MEDICOS];
int totalMedicos = 0;

void addDoctor(){
    if(totalMedicos >=MAX_MEDICOS){
        printf("Número máximo de médicos atingidos, se você quiser, recomendo exlcuir um já existente para adicionar este novo.\n");
        return;
    }
    
    printf("\n --- Cadastro de Médico ---\n");
    printf("Digite o CRM: ");
    scanf(" %d", &medicos[totalMedicos].crm);
    getchar();//Usado para limpar o buffer do teclado

    printf("Digite o nome: ");
    fgets(medicos[totalMedicos].name, 50, stdin);
    medicos[totalMedicos].name[strcspn(medicos[totalMedicos].name, "\n")] = 0; //Função para remover o \n do fgets

    printf("Digite a especialização do candango:");
    fgets(medicos[totalMedicos].especialidade, 50, stdin);
    medicos[totalMedicos].especialidade[strcspn(medicos[totalMedicos].especialidade, "\n")] = 0; //Novamente, removendo o \n do fgets

    medicos[totalMedicos].ativo = 1;
    totalMedicos++;

    printf("Médico cadastrado com sucesso no sistema!\n");
}

//Listing existing doctors for you my brother
void listDoctors(){
    printf("\n --- Lista de Médicos ---\n");
    for (int i = 0; i <totalMedicos; i++){
        if(medicos[i].ativo) {
            printf("CRM %d | Nome: %s | Especialização: %s\n", medicos[i].crm, medicos[i].name, medicos[i].especialidade);
        }
    }
}


//Deleting doctors candangos, os baum stay os candango go away
void deleteDoctor(){
    int crm;
    printf("\n Digite o CRM do médico ao qual você deseja remover do sistema: ");
    scanf(" %d", &crm);

    for (int i = 0; i<totalMedicos; i++){
        if (medicos[i].crm == crm && medicos[i].ativo){
            medicos[i].ativo = 0; // Tornando assim o candango demitido
            printf("Médico deletado com sucesso!\n");
            return;
        }
    }
    printf("Médico não encontrado!\n");
}

//Menu, atualmente apenas para médicos
void menu(){
    int option;
    do{
        printf("\n-------Menu-------\n");
        printf("1 - Incluir Médico\n");
        printf("2 - Listar Médicos\n");
        printf("3 - Excluir Médico\n");
        printf("4 - Sair\n");
        printf("Escolha uma opção: ");
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
            printf("Desculpe, você poderia escolher outra opção?\n");
        
        }
    }while (option!=4);
}


int main () {
    menu();
    return 0;
}