#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// ==========================================================================================AIRES && CTTBIEL================================================================================================

typedef struct
{
    int id;
    char name[50];
    int cpf;
    char endereco[100];
    int telefone;
    char sexo; // M para masculino e F para feminino
} paciente;

typedef struct
{
    int num_consulta;
    int id_paciente;
    int id_medico;
    char horario[6];
    int duracao;
    char data[10];
} consulta;

typedef struct
{
    int crm;
    char name[50];
    char especialidade[50];
} medico;

void addPaciente(paciente **p, int *num_paciente) // PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES==============
{
    *p = realloc(*p, (*num_paciente + 1) * sizeof(paciente));
    if (*p == NULL)
    {
        printf("Erro ao alocar memória para o paciente\n");
        return;
    }
    printf("\n --- Cadastro de Paciente ---\n");

    printf("ID: ");
    scanf("%d", &(*p)[*num_paciente].id);

    printf("Nome: ");
    fgets((*p)[*num_paciente].name, 50, stdin);
    (*p)[*num_paciente].name[strcspn((*p)[*num_paciente].name, "\n")] = 0;

    printf("CPF: ");
    scanf("%d", &(*p)[*num_paciente].cpf);

    printf("Endereço: ");
    fgets((*p)[*num_paciente].endereco, 100, stdin);
    (*p)[*num_paciente].endereco[strcspn((*p)[*num_paciente].endereco, "\n")] = 0;

    printf("Telefone: ");
    scanf("%d", &(*p)[*num_paciente].telefone);

    printf("Sexo: ");
    scanf(" %c", &(*p)[*num_paciente].sexo);

    (*num_paciente)++;

    printf("Paciente cadastrado com sucesso no sistema!\n");
    system("pause");
}

void alterarPaciente(paciente **p, int *num_paciente)
{
    int idPesquisar;
    printf("\nDigite o ID do paciente que deseja alterar: ");
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_paciente; i++)
    {
        if ((*p)[i].id == idPesquisar)
        {
            printf("\n --- Alterar Paciente ---\n");

            printf("Nome atual: %s\n", (*p)[i].name);
            printf("CPF atual: %d\n", (*p)[i].cpf);
            printf("Endereço atual: %s\n", (*p)[i].endereco);
            printf("Telefone atual: %d\n", (*p)[i].telefone);
            printf("Sexo atual: %c\n", (*p)[i].sexo);

            printf("Digite o novo Nome: ");
            fgets((*p)[i].name, 50, stdin);
            (*p)[i].name[strcspn((*p)[i].name, "\n")] = 0;

            printf("CPF: ");
            scanf("%d", &(*p)[i].cpf);

            printf(" Digite o Novo Endereço: ");
            fgets((*p)[i].endereco, 100, stdin);
            (*p)[i].endereco[strcspn((*p)[i].endereco, "\n")] = 0;

            printf("Digite o novo Telefone: ");
            scanf("%d", &(*p)[i].telefone);

            printf("Digite o novo Sexo: ");
            scanf(" %c", &(*p)[i].sexo);

            printf("Paciente alterado com sucesso!\n");
            break;
        }
    }
}

void excluirPaciente(paciente **p, int *num_paciente)
{
    if (*num_paciente == 0)
    {
        printf("Voce nao cadastrou paciente ainda o ze ruela\n");
        return;
    }
    int idPesquisar, encontrado = 0;
    printf("\nDigite o ID do paciente que deseja excluir: ");
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_paciente; i++)
    {
        if ((*p)[i].id == idPesquisar)
        {
            for (int j = i; j < *num_paciente - 1; j++)
            {
                (*p)[j] = (*p)[j + 1];
            }
            *p = realloc(*p, (*num_paciente - 1) * sizeof(paciente));
            (*num_paciente)--;
            printf("O paciente com o ID %d foi deletado com sucesso!\n", idPesquisar);
            encontrado = 1;
            break;
        }
    }

    if (encontrado == 1)
    {
        printf("Excluindo as consultas do paciente deletado...\n");
        // removerConsultasVinculadas(consultas, num_consultas, idPesquisar, 'P');
        system("pause");
    }
}

void pesquisarPaciente(paciente **p, int *num_paciente)
{
    printf("\nDigite o ID do paciente que deseja pesquisar: ");
    int idPesquisar;
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_paciente; i++)
    {
        if ((*p)[i].id == idPesquisar)
        {
            printf("\n --- Paciente Encontrado ---\n");
            printf("ID: %d\n", (*p)[i].id);
            printf("Nome: %s\n", (*p)[i].name);
            printf("CPF: %d\n", (*p)[i].cpf);
            printf("Endereço: %s\n", (*p)[i].endereco);
            printf("Telefone: %d\n", (*p)[i].telefone);
            printf("Sexo: %c\n", (*p)[i].sexo);
            break;
        }
    }
}
// FIM PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================
// CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS===============// CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS===============

void addConsulta(consulta **c, int *num_consultas) // - - - - - - - - - - - - -- - -- - -- ADICIONAR CONSULTA - - - - - - - - - - - - - -- -- -- -- - -- --- - -- - --  -- - - -- - - 
{
    *c = realloc(*c, (*num_consultas + 1) * sizeof(consulta));
    if (*c == NULL)
    {
        printf("Erro ao alocar memoria para a consulta\n");
        return;
    }
    printf("\n --- Cadastro de Consulta ---\n");

    printf("digite o numero da consulta: ");
    scanf("%d", &(*c)[*num_consultas].num_consulta);

    printf("ID do Paciente: ");
    scanf("%d", &(*c)[*num_consultas].id_paciente);

    printf("ID do Medico: ");
    scanf("%d", &(*c)[*num_consultas].id_medico);

    printf("Horario: ");
    fgets((*c)[*num_consultas].horario, 6, stdin);
    (*c)[*num_consultas].horario[strcspn((*c)[*num_consultas].horario, "\n")] = 0;

    printf("Duracao: ");
    scanf("%d", &(*c)[*num_consultas].duracao);

    printf("Data: ");
    fgets((*c)[*num_consultas].data, 10, stdin);
    (*c)[*num_consultas].data[strcspn((*c)[*num_consultas].data, "\n")] = 0;

    (*num_consultas)++;

    printf("Consulta cadastrada com sucesso no sistema!\n");
    system("pause");
}

void alterarConsulta(consulta **c, int *num_consultas) //- - -- - -- -- - -- -- -- -- -- - - ALTERAR CONSULTA- ----- - -- -- - -- -- - -- - -- - -- -- -- - - - -  - - 
{
    int idPesquisar;
    printf("\n Digite o numero da consulta que deseja alterar: ");
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_consultas; i++)
    {
        if ((*c)[i].num_consulta == idPesquisar)
        {
            printf("\n --- Alterar Consulta ---\n");

            printf("ID do Paciente atual: %d\n", (*c)[i].id_paciente);
            printf("ID do Medico atual: %d\n", (*c)[i].id_medico);
            printf("Horario atual: %s\n", (*c)[i].horario);
            printf("Duracao atual: %d\n", (*c)[i].duracao);
            printf("Data atual: %s\n", (*c)[i].data);

            printf("Digite o novo ID do Paciente: ");
            scanf("%d", &(*c)[i].id_paciente);
            getchar();

            printf("Digite o novo ID do Medico: ");
            scanf("%d", &(*c)[i].id_medico);
            getchar();

            printf("Digite o novo Horario: ");
            fgets((*c)[i].horario, 6, stdin);
            (*c)[i].horario[strcspn((*c)[i].horario, "\n")] = 0;

            printf("Digite a nova Duracao: ");
            scanf("%d", &(*c)[i].duracao);
            getchar();

            printf("Digite a nova Data: ");
            fgets((*c)[i].data, 10, stdin);
            (*c)[i].data[strcspn((*c)[i].data, "\n")] = 0;

            printf("Consulta alterada com sucesso!\n");
            system("pause");
            break;
        }
    }
}

void excluirConsulta(consulta **c, int *num_consultas)// - - - - - - - - - - - - - -  - -  - EXCLUIR CONSULTA - - - - - -- - ----- -- --- -- - -- - --- - -- - -- - -- -- - -- - -- - ---- - - - -- - - 
{
    int idPesquisar;
    printf("\nDigite o numero da consulta que deseja excluir: ");
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_consultas; i++)
    {
        if ((*c)[i].num_consulta == idPesquisar)
        {
            for (int j = i; j < *num_consultas - 1; j++)
            {
                (*c)[j] = (*c)[j + 1];
            }
            *c = realloc(*c, (*num_consultas - 1) * sizeof(consulta));
            (*num_consultas)--;
            printf("A consulta com o numero %d foi deletada com sucesso!\n", idPesquisar);
            break;
        }
    }
}

/*void exclurConsultaPaciente(consulta **c, int *num_consultas, int id_paciente)
{
    for (int i = 0; i < *num_consultas; i++)
    {
        if ((*c)[i].id_paciente == id_paciente)
        {
            for (int j = i; j < (*num_consultas - 1); j++)
            {
                (*c)[j] = (*c)[j + 1];
            }
            *c = realloc(*c, (*num_consultas - 1) * sizeof(consulta));
            (*num_consultas)--;
        }
    }
    printf("Todas as consultas deste paciente foram apagadas!\n");
}*/

void pesquisarConsulta(consulta **c, int *num_consultas)// - - - --- -- - -- --- -- - -- - -- -- - -EXCLUIR CONSULTA- - - -- - -- - -- - --- -- - -- - -- - -- - ---- -- -- - -- - - - -- - -- -- -- -
{
    int idPesquisar, encontrado = 0;
    printf("\nDigite o numero da consulta que deseja pesquisar: ");
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_consultas; i++)
    {
        if ((*c)[i].num_consulta == idPesquisar)
        {
            printf("\n --- Consulta Encontrada ---\n");
            printf("Numero da Consulta: %d\n", (*c)[i].num_consulta);
            printf("ID do Paciente: %d\n", (*c)[i].id_paciente);
            printf("ID do Medico: %d\n", (*c)[i].id_medico);
            printf("Horario: %s\n", (*c)[i].horario);
            printf("Duracao: %d\n", (*c)[i].duracao);
            printf("Data: %s\n", (*c)[i].data);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Consulta nao encontrada!\n");
    }
    system("pause");
}

void addMedico(medico **m, int *num_medicos)// - - - - - - - - - - -  MEDICOS - - - - - - - - - - -  MEDICOS - - - - - - - - - - - -M E D I C O S - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -  -
{
    *m = realloc(*m, (*num_medicos + 1) * sizeof(medico));
    if (*m == NULL)
    {
        printf("Erro na alocacao de memoria para o medico\n");
        return;
    }
    printf("\n --- Cadastro de Medicos ---\n");

    printf("Digite o CRM do medico: ");
    scanf("%d", &(*m)[*num_medicos].crm);

    printf("Digite o nome do medico: ");
    fgets((*m)[*num_medicos].name, 50, stdin);
    (*m)[*num_medicos].name[strcspn((*m)[*num_medicos].name, "\n")] = 0;

    printf("Digite a especialidade do medico: ");
    fgets((*m)[*num_medicos].especialidade, 50, stdin);
    (*m)[*num_medicos].especialidade[strcspn((*m)[*num_medicos].especialidade, "\n")] = 0;

    (*num_medicos)++;

    printf("Medico cadastrado com sucesso no sistema!\n");
    system("pause");
}

void alterarMedico(medico **m, int *num_medicos)
{
    int crmPesquisar;
    printf("\n --- Alterar Medico ---\n");
    printf("Digite o CRM do medico que deseja alterar: ");
    scanf("%d", &crmPesquisar);
    getchar();

    for (int i = 0; i < *num_medicos; i++)
    {
        if ((*m)[i].crm == crmPesquisar)
        {
            printf("Nome atual: %s\n", (*m)[i].name);
            printf("Especialidade atual: %s\n", (*m)[i].especialidade);

            printf("Digite o novo nome: ");
            fgets((*m)[i].name, 50, stdin);
            (*m)[i].name[strcspn((*m)[i].name, "\n")] = 0;

            printf("Digite a nova especialidade do medico: ");
            fgets((*m)[i].especialidade, 50, stdin);
            (*m)[i].especialidade[strcspn((*m)[i].name, "\n")] = 0;

            printf("Medico alterado com sucesso!\n");
            system("pause");
            break;
        }
    }
}

void excluirMedico(medico **m, int *num_medicos)
{
    if (*num_medicos == 0)
    {
        printf("Voce nao cadastrou medicos ainda o ze ruela\n");
        return;
    }

    int crm, encontrado = 0;
    printf("Digite o CRM do medico que deseja excluir: ");
    scanf(" %d", &crm);

    for (int i = 0; i < *num_medicos; i++)
    {
        if ((*m)[i].crm == crm)
        {
            encontrado = 1;

            for (int j = i; j < *num_medicos - 1; j++)
            {
                (*m)[j] = (*m)[j + 1];
            }
            *m = realloc(*m, (*num_medicos - 1) * sizeof(medico));
            (*num_medicos)--;

            if (*m == NULL && *num_medicos > 0)
            {
                printf("Erro ao realocar memoria!\n");
                return;
            }

            printf("Medico excluido com sucesso!\n");
            // removerConsultasVinculadas(consultas, num_consultas, crm, 'M');
            break;
        }
    }

    if (!encontrado)
    {
        printf("Medico com CRM %d nao encontrado ze!\n", crm);
    }


    
    
    
    printf("As consultas do medico foram excluidas!\n");
}


void menuConsultas(consulta *consultas, int *num_consultas) // MENUS====================MENUS====================MENUS====================MENUS====================MENUS==============
{
    int option; //- - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - -MENU CONSULTA- - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - -  - - -
    do
    {
        printf("\n-------Menu de Consultas:-------\n");
        printf("1 - Incluir Consulta\n");
        printf("2 - Alterar Consulta\n");
        printf("3 - Excluir Consulta\n");
        printf("4 - Pesquisar Consulta\n");
        printf("5 - Voltar\n");
        printf("6 - Sair\n");
        printf("O que voce quer pra hoje? Minha querida professora Cascine: \n");
        scanf("%d", &option);
        getchar();
        
        switch (option)
        {
        case 1:
        addConsulta(&consultas, &num_consultas);
            break;
            
        case 2:
        alterarConsulta(&consultas, &num_consultas);
            break;
            
        case 3:
        excluirConsulta(&consultas, &num_consultas);
            break;

        case 4:
            pesquisarConsulta(&consultas, &num_consultas);
            break;
            
        case 5:
            printf("Voltando...\n");
            break;
            
        default:
            printf("Desculpe, voce poderia escolher outra opcao?\n");
        }
    } while (option != 4);
}

void menuPaciente(paciente *pacientes, int *num_paciente) //- - - - - - - - - - - - - - - - - - - -  - - - -MENU PACIENTE- - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - -  - - -
{
    int option;
    do
    {
        printf("\n-------Menu.dos.Pacientes:-------\n");
        printf("1 - Incluir Paciente\n");
        printf("2 - Pesquisar Paciente\n");
        printf("3 - Excluir Paciente\n");
        printf("4 - Alterar Paciente\n");
        printf("5 - Voltar para o me\n");
        printf("6 - Sair\n");
        printf("O que voce quer pra hoje? Minha querida professora Cascine: \n");
        scanf("%d", &option);
        getchar();
        
        switch (option)
        {
        case 1:
        addPaciente(&pacientes, &num_paciente);
        break;
        
        case 2:
        pesquisarPaciente(&pacientes, &num_paciente);
        break;

        case 3:
        excluirPaciente(&pacientes, &num_paciente);
        break;
        
        case 4:
        alterarPaciente(&pacientes, &num_paciente);
        break;
        
        case 5:
        printf("Voltando...\n");
        break;

        default:
        printf("Desculpe, voce poderia escolher outra opcao?\n");
    }
    } while (option != 5);
}

void menuMedico(medico *medicos, int *num_medicos) //- - - - - - - - - - - - - - - - - - - -  - - - -MENU MEDICO- - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - -  - - -
{
    int option;
    do
    {
        printf("\n-------Menu dos Medicos:-------\n");
        printf("1 - Incluir Medico\n");
        printf("2 - Pesquisar Medico \n");
        printf("3 - Excluir Medico\n");
        printf("4 - Alterar Medico\n");
        printf("5 - Voltar para o menu anterior");
        printf("O que voce quer pra hoje? Minha querida professora Cascine: \n");
        scanf("%d", &option);
        getchar();
        switch (option)
        {
        case 1:
        addMedico(&medicos, &num_medicos);
        break;
        
        case 2:
        pesquisarMedico(&medicos, &num_medicos);
        break;
        
        case 3:
        excluirMedico(&medicos, &num_medicos);
        break;
        
        case 4:
            alterarMedico(&medicos, &num_medicos);
            break;
            
        case 5:
            printf("Voltando...\n");
            break;

        default:
            printf("Desculpe, voce poderia escolher outra opcao?\n");
        }
    } while (option != 5);
}


void menuRelatorio (consulta *consultas, int num_consultas, medico *medicos, int num_medicos, paciente *pacientes, int num_pacientes){

    int opcao, id;
    char especialidade[50];

    do{
        printf("\n -----Menu de Relatorios-----\n");
        printf("1 - Consultas por Paciente \n");
        printf("2 - Consultas por Medico\n");
        printf("3 - Pacientes por Especialidade\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao ");
        scanf(" %d", &opcao);
        getchar();
        
        switch (opcao){
        case
        }
        
    }
    
}



int main(void) // MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================
{
    
    paciente *pacientes = NULL;
    int num_pacientes = 0;
    
    consulta *consultas = NULL;
    int num_consultas = 0;
    
    medico *medicos = NULL;
    int num_medicos = 0;
    
    int opcoes;
    printf("Ola, seja bem vindo(a) ao sistema de gerenciamento de consultas medicas!\n");
    printf("Developed by Gabriel Carvalho and  Victor Aires.\n");
    printf("Por favor, escolha uma das opcoes abaixo: \n");
    
    do
    {
        printf("\n-------Menu-------\n");
        printf("1 - Medicos\n");
        printf("2 - Pacientes\n");
        printf("3 - Consultas\n");
        printf("4 - Relatorio");
        printf("5 - Sair do Programa...\n");
        scanf(" %d", &opcoes);
        
        switch (opcoes)
        {
        case 1:
            menuMedico(&medicos, &num_medicos);
            break;
        case 2:
            menuPacientes(&pacientes, &num_pacientes);
            break;
        
        case 3:
            menuConsultas(&consultas, &num_consultas);
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