#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_MEDICOS 20
#define MAX_PACIENTES 50

//Struct dos doctor
typedef struct {
    int crm;
    char nome[50];
    char especialidade[50];
} Medico;

Medico medicos[MAX_MEDICOS];
int totalMedicos = 0;

void incluirMedico(){
    if(totalMedicos >=MAX_MEDICOS){
        printf("Número máximo de médicos atingidos, se você quiser, recomendo exlcuir um já existente para adicionar este novo.\n");
        return;
    }
    
    printf("\n --- Cadastro de Médico ---\n");
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

        switch (opcao) {
            case 1:
            addDoctor();
            break;

            case 2:
            listDoctors();
            break;

            case 3:
            deleteDoctr();
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