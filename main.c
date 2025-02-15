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



typedef struct {
    int cpf;
    char name[50];
    int rg;
    char adress[100]; //Bro's adress
    int telefone;
    char sexo[50];
    int taVivo; // 1 - Vivo; 0 - Morto;
} Paciente;


typedef struct {
    int consulta;
    int horario;
    int data;
    int duration;
    //Preciso entender se coloco novamente o crm do médico e o cpf do paciente, afinal eles irão se encontrar aqui na consulta, mas talvez não é necessário indicar isso na struct
} Consulta;


Medico medicos[MAX_MEDICOS];
int totalMedicos = 0;

void addDoctor(){
    if(totalMedicos >=MAX_MEDICOS){
        printf("Numero maximo de médicos atingidos, se você quiser adicionar outro, demita alguém para adicionar este novo.\n");
        return;
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
void menu(){
    int option;
    do{
        printf("\n-------Menu-------\n");
        printf("1 - Incluir Medico\n");
        printf("2 - Listar Medicos\n");
        printf("3 - Excluir Medico\n");
        printf("4 - Sair\n");
        printf("O que você quer pra hoje meu pratao?: ");
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
            printf("Desculpe, você poderia escolher outra opcao?\n");
        
        }
    }while (option!=4);
}


int main () {
    menu();
    return 0;
}