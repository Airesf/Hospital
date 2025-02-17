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

// PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES============PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES====================PACIENTES==============

void addPaciente(paciente **p, int *num_paciente) // - - - - - - - - - - - - - - - - - -ADICIONAR PACIENTE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
{
    if (*num_paciente <= 50)
    {
        *p = realloc(*p, (*num_paciente + 1) * sizeof(paciente));
        if (*p == NULL)
        {
            printf("Erro ao alocar memória para o paciente\n");
            return;
        }
        printf("\n --- Cadastro de Paciente ---\n");

        printf("ID: ");
        scanf(" %d", &(*p)[*num_paciente].id);
        getchar();

        printf("Nome: ");
        /*fgets((*p)[*num_paciente].name, 50, stdin);
        (*p)[*num_paciente].name[strcspn((*p)[*num_paciente].name, "\n")] = 0;*/
        scanf(" %[^\n]", (*p)[*num_paciente].name);

        printf("CPF: ");
        scanf(" %d", &(*p)[*num_paciente].cpf);

        printf("Endereco: ");
        // fgets((*p)[*num_paciente].endereco, 100, stdin);
        //(*p)[*num_paciente].endereco[strcspn((*p)[*num_paciente].endereco, "\n")] = 0;
        scanf(" %[^\n]", (*p)[*num_paciente].endereco);

        printf("Telefone: ");
        scanf(" %d", &(*p)[*num_paciente].telefone);

        printf("Sexo: ");
        scanf(" %c", &(*p)[*num_paciente].sexo);

        (*num_paciente)++;

        printf("Paciente cadastrado com sucesso no sistema!\n");
        system("pause");
    }
    else
    {
        printf("Numero maximo de pacientes atingido\n");
    }
}

void alterarPaciente(paciente **p, int *num_paciente) //  - - - - - - - - - - - - - - - - - -ALTERAR PACIENTE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
            scanf(" %[^\n]", (*p)[i].name);

            printf("CPF: ");
            scanf("%d", &(*p)[i].cpf);

            printf(" Digite o Novo Endereço: ");
            scanf(" %[^\n]", (*p)[i].endereco);

            printf("Digite o novo Telefone: ");
            scanf("%d", &(*p)[i].telefone);

            printf("Digite o novo Sexo: ");
            scanf(" %c", &(*p)[i].sexo);

            printf("Paciente alterado com sucesso!\n");
            break;
        }
    }
}

void excluirPaciente(paciente **p, int *num_paciente, consulta **c, int *num_consultas) // - - - - - - - - - - - - - - - - - -EXCLUIR PACIENTE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
{

    if (*num_paciente == 0)
    {
        printf("Voce nao cadastrou paciente ainda o ze ruela\n");
        return;
    }

    int idPesquisar, encontrado = 0;
    printf("\nDigite o RG do paciente que deseja excluir: ");
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_paciente; i++)
    {
        if ((*p)[i].id == idPesquisar)
        {

            printf("O paciente: %s foi excluido com sucesso!\n", (*p)[i].name);
            printf("ID: %d\n", (*p)[i].id);
            printf("CPF: %d\n", (*p)[i].cpf);
            printf("Endereco: %s\n", (*p)[i].endereco);
            printf("Telefone: %d\n", (*p)[i].telefone);
            printf("Sexo: %c\n", (*p)[i].sexo);

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

        for (int i = 0; i < *num_consultas; i++)
        {
            if ((*c)[i].id_paciente == idPesquisar)
            {
                for (int j = i; j < *num_consultas - 1; j++)
                {
                    (*c)[j] = (*c)[j + 1];
                }
                *c = realloc(*c, (*num_consultas - 1) * sizeof(consulta));
                (*num_consultas)--;
            }
        }
    }

    if (encontrado == 1)
    {
        printf("Excluindo as consultas do paciente deletado...\n");
        system("pause");
    }
}

void pesquisarPaciente(paciente **p, int *num_paciente) // - - - - - - - - - - - - - - - - - -PESQUISAR PACIENTE - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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

// CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS===============// CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS====================CONSULTAS===============

void addConsulta(consulta **c, int *num_consultas) // - - - - - - - - - - - - -- - -- - -- ADICIONAR CONSULTA - - - - - - - - - - - - - -- -- -- -- - -- --- - -- - --  -- - - -- - -
{
    if (*num_consultas <= 100)
    {
        *c = realloc(*c, (*num_consultas + 1) * sizeof(consulta));
        if (*c == NULL)
        {
            printf("Erro ao alocar memoria para a consulta\n");
            return;
        }

        printf("\n --- Cadastro de Consulta ---\n");

        printf("Digite o numero da consulta: ");
        scanf("%d", &(*c)[*num_consultas].num_consulta);

        printf("ID do Paciente: ");
        scanf("%d", &(*c)[*num_consultas].id_paciente);

        printf("ID do Medico: ");
        scanf("%d", &(*c)[*num_consultas].id_medico);

        printf("Horario: ");
        // fgets((*c)[*num_consultas].horario, 6, stdin);
        //(*c)[*num_consultas].horario[strcspn((*c)[*num_consultas].horario, "\n")] = 0;
        scanf(" %[^\n]", (*c)[*num_consultas].horario);

        printf("Duracao: ");
        scanf("%d", &(*c)[*num_consultas].duracao);

        printf("Data: ");
        // fgets((*c)[*num_consultas].data, 10, stdin);
        //(*c)[*num_consultas].data[strcspn((*c)[*num_consultas].data, "\n")] = 0;
        scanf(" %[^\n]", (*c)[*num_consultas].data);

        (*num_consultas)++;

        printf("Consulta cadastrada com sucesso no sistema!\n");
        system("pause");
    }
    else
    {
        printf("Numero maximo de consultas atingido zeeee\n");
    }
}

void alterarConsulta(consulta **c, int *num_consultas) //- - -- - -- -- - -- -- -- -- -- - - ALTERAR CONSULTA- ----- - -- -- - -- -- - -- - -- - -- -- -- - - - -  - - - -
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
            // fgets((*c)[i].horario, 6, stdin);
            //(*c)[i].horario[strcspn((*c)[i].horario, "\n")] = 0;
            scanf(" %[^\n]", (*c)[i].horario);

            printf("Digite a nova Duracao: ");
            scanf("%d", &(*c)[i].duracao);
            getchar();

            printf("Digite a nova Data: ");
            // fgets((*c)[i].data, 10, stdin);
            //(*c)[i].data[strcspn((*c)[i].data, "\n")] = 0;
            scanf(" %[^\n]", (*c)[i].data);

            printf("Consulta alterada com sucesso!\n");
            system("pause");
            break;
        }
    }
}

void excluirConsulta(consulta **c, int *num_consultas) // - - - - - - - - - - - - - -  - -  - EXCLUIR CONSULTA - - - - - -- - ----- -- --- -- - -- - --- - -- - -- - -- -- - -- - -- - ---- - - - -- - -
{
    int idPesquisar;
    printf("\nDigite o numero da consulta que deseja excluir: ");
    scanf("%d", &idPesquisar);
    getchar();

    for (int i = 0; i < *num_consultas; i++)
    {
        if ((*c)[i].num_consulta == idPesquisar)
        {
            printf("Numero da Consulta: %d\n", (*c)[i].num_consulta);
            printf("ID do Paciente: %d\n", (*c)[i].id_paciente);
            printf("CRM do Medico: %d\n", (*c)[i].id_medico);

            for (int j = i; j < (*num_consultas - 1); j++)
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

void pesquisarConsulta(consulta **c, int *num_consultas) // - - - --- -- - -- --- -- - -- - -- -- - -PESQUISAR CONSULTA- - - -- - -- - -- - --- -- - -- - -- - -- - ---- -- -- - -- - - - -- - -- -- -- -
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

//============================================================================================================================================================================================================================

void addMedico(medico **m, int *num_medicos) // - - - - - - - - - - - - - - - - - - - - - - - - - - - ADICIONAR MEDICO- - - - - - - - - - - - - - - - - - - - - - - - - - - - -
{
    if (*num_medicos <= 20)
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
        getchar();

        printf("Digite o nome do medico: ");
        // fgets((*m)[*num_medicos].name, 50, stdin);
        //(*m)[*num_medicos].name[strcspn((*m)[*num_medicos].name, "\n")] = 0;
        scanf(" %[^\n]", (*m)[*num_medicos].name);

        printf("Digite a especialidade do medico: ");
        // fgets((*m)[*num_medicos].especialidade, 50, stdin);
        //(*m)[*num_medicos].especialidade[strcspn((*m)[*num_medicos].especialidade, "\n")] = 0;
        scanf(" %[^\n]", (*m)[*num_medicos].especialidade);

        (*num_medicos)++;

        printf("Medico cadastrado com sucesso no sistema!\n");
        system("pause");
    }
    else
    {
        printf("Numero maximo de medicos atingido\n");
    }
}

void alterarMedico(medico **m, int *num_medicos) //- - - - - - - - - - - - - - - - - - - - - - - - - - - - -ALTERAR MEDICO- - - - - - - - - - - - - - - - - - - - - - - - - - - - -
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
            // fgets((*m)[i].name, 50, stdin);
            //(*m)[i].name[strcspn((*m)[i].name, "\n")] = 0;
            scanf(" %[^\n]", (*m)[i].name);

            printf("Digite a nova especialidade do medico: ");
            // fgets((*m)[i].especialidade, 50, stdin);
            //(*m)[i].especialidade[strcspn((*m)[i].name, "\n")] = 0;
            scanf(" %[^\n]", (*m)[i].especialidade);

            printf("Medico alterado com sucesso!\n");
            system("pause");
            break;
        }
    }
}

void excluirMedico(medico **m, int *num_medicos, consulta **c, int *num_consultas) ///- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -EXCLUIR MEDICO- - - - - - - - - - - - - - - - - - - - - - - - - - - - -
{
    if (*num_medicos == 0)
    {
        printf("Voce nao cadastrou medicos ainda o ze ruela\n");
        return;
    }

    int crm, encontrado = 0;
    printf("Digite o CRM do medico que deseja excluir: ");
    scanf("%d", &crm);
    getchar();

    for (int i = 0; i < *num_medicos; i++)
    {
        if ((*m)[i].crm == crm)
        {
            encontrado = 1;
            printf("O medico: %s foi excluido com sucesso!\n", (*m)[i].name);
            printf("CRM: %d\n", (*m)[i].crm);
            printf("Especialidade: %s\n", (*m)[i].especialidade);

            for (int j = i; j < *num_medicos - 1; j++)
            {
                (*m)[j] = (*m)[j + 1];
            }

            *m = realloc(*m, (*num_medicos - 1) * sizeof(medico));
            (*num_medicos)--;

            if (*m == NULL && *num_medicos > 0)
            {
                printf("Erro ao realocar memoria!\n");
                system("pause");
                return;
            }

            printf("Medico excluido com sucesso!\n");
            break;
        }
    }

    if (encontrado == 1) // Apaga todas as consultas do medico
    {
        for (int i = 0; i < *num_consultas; i++)
        {
            if ((*c)[i].id_medico == crm)
            {
                printf("Excluindo a consulta #%d do medico deletado...\n", (*c)[i].num_consulta);
                printf("ID do Paciente: %d\n", (*c)[i].id_paciente);
                printf("Horario: %s\n", (*c)[i].horario);
                printf("Duracao: %d\n", (*c)[i].duracao);
                printf("Data: %s\n", (*c)[i].data);
                printf("-----Consulta deleteda com sucesso!-----\n");
                for (int j = i; j < *num_consultas - 1; j++)
                {
                    (*c)[j] = (*c)[j + 1];
                }
                *c = realloc(*c, (*num_consultas - 1) * sizeof(consulta));
                (*num_consultas)--;
            }
        }
    }

    if (!encontrado)
    {
        printf("Medico com CRM %d nao encontrado ze!\n", crm);
    }
}

void pesquisarMedico(medico **m, int *num_medicos) // - - - - - - - - - - - - - - - - - - - - - - - - - - - - -PESQUISAR MEDICO- - - - - - - - - - - - - - - - - - - - - - - - - - - - -- - - - - - - - - - - - - - - - - - - - - - - - - - - - -
{
    int crmPesquisar, encontrado = 0;
    printf("\nDigite o CRM do medico que deseja pesquisar: ");
    scanf("%d", &crmPesquisar);
    getchar();

    for (int i = 0; i < *num_medicos; i++)
    {
        if ((*m)[i].crm == crmPesquisar)
        {
            printf("\n --- Medico Encontrado ---\n");
            printf("CRM: %d\n", (*m)[i].crm);
            printf("Nome: %s\n", (*m)[i].name);
            printf("Especialidade: %s\n", (*m)[i].especialidade);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("Medico nao encontrado!\n");
    }
    system("pause");
}

//===============================================================================================================================================================================================================================

void listarConsultasPorPaciente(consulta *consultas, int num_consultas, int idPaciente)
{
    int encontrado = 0;
    printf("\n=== Consultas do Paciente (ID %d) ===\n", idPaciente);

    for (int i = 0; i < num_consultas; i++)
    {
        if (consultas[i].id_paciente == idPaciente)
        {
            printf("Consulta #%d | Medico (CRM): %d | Data: %s | Horario: %s | Duração: %d min\n", consultas[i].num_consulta, consultas[i].id_medico, consultas[i].data, consultas[i].horario, consultas[i].duracao);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("Nenhuma consulta encontrada para este paciente.\n");
    }
}

void listarConsultasPorMedico(consulta *consultas, int num_consultas, int crmMedico)
{
    int encontrado = 0;
    printf("\n=== Consultas do Medico (CRM %d) ===\n", crmMedico);

    for (int i = 0; i < num_consultas; i++)
    {
        if (consultas[i].id_medico == crmMedico)
        {
            printf("Consulta #%d | Paciente (ID): %d | Data: %s | Horario: %s | Duracao: %d min\n",
                   consultas[i].num_consulta, consultas[i].id_paciente, consultas[i].data, consultas[i].horario, consultas[i].duracao);
            encontrado = 1;
        }
    }

    if (!encontrado)
    {
        printf("Nenhuma consulta encontrada para este medico.\n");
    }
}

void listarPacientesPorEspecialidade(consulta *consultas, int num_consultas, medico *medicos, int num_medicos, paciente *pacientes, int num_pacientes, char *especialidade)
{
    int encontrado = 0;
    printf("\n=== Pacientes atendidos por medicos da especialidade %s ===\n", especialidade);

    for (int i = 0; i < num_medicos; i++)
    {
        if (strcmp(medicos[i].especialidade, especialidade) == 0)
        {
            int crmMedico = medicos[i].crm;

            for (int j = 0; j < num_consultas; j++)
            {
                if (consultas[j].id_medico == crmMedico)
                {
                    for (int k = 0; k < num_pacientes; k++)
                    {
                        if (pacientes[k].id == consultas[j].id_paciente)
                        {
                            printf("Paciente: %s (ID %d)\n", pacientes[k].name, pacientes[k].id);
                            encontrado = 1;
                        }
                    }
                }
            }
        }
    }

    if (!encontrado)
    {
        printf("Nenhum paciente encontrado para esta especialidade.\n");
    }
}

void menuRelatorio(consulta *consultas, int num_consultas, medico *medicos, int num_medicos, paciente *pacientes, int num_pacientes)
{ // - - - - - - - - - - - - - - - - - -menuRelatorio - - - - - - - - - - - - - - - - - -
    int opcao, id;
    char especialidade[50];

    do
    {
        printf("\n -----Menu de Relatorios-----\n");
        printf("1 - Consultas por Paciente \n");
        printf("2 - Consultas por Medico\n");
        printf("3 - Pacientes por Especialidade\n");
        printf("4 - Voltar\n");
        printf("Escolha uma opcao ");
        scanf(" %d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            printf("Digite o ID do paciente: ");
            scanf("%d", &id);
            listarConsultasPorPaciente(consultas, num_consultas, id);
            break;

        case 2:
            printf("Digite o CRM do medico: ");
            scanf("%d", &id);
            listarConsultasPorMedico(consultas, num_consultas, id);
            break;

        case 3:
            printf("Digite a especialidade medica: ");
            // fgets(especialidade, 50, stdin);
            // especialidade[strcspn(especialidade, "\n")] = 0;
            scanf(" %[^\n]", especialidade);

            listarPacientesPorEspecialidade(consultas, num_consultas, medicos, num_medicos, pacientes, num_pacientes, especialidade);
            break;

        case 4:
            printf("Voltando...\n");
            break;

        default:
            printf("Opcao invalida, tente novamente\n");
        }
    } while (opcao != 4);
}

int main(void) // MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================MAIN====================
{
    paciente *pacientes = NULL;
    int num_pacientes = 0;

    consulta *consultas = NULL;
    int num_consultas = 0;

    medico *medicos = NULL;
    int num_medicos = 0;

    int opMAIN, opMedico, opPaciente, opConsulta;
    printf("Ola, seja bem vindo(a) ao sistema de gerenciamento de consultas medicas!\n");
    printf("Developed by Gabriel Carvalho and  Victor Aires.\n");
    printf("Por favor, escolha uma das opcoes abaixo: \n");

    do
    {
        printf("\n-------Menu-------\n");
        printf("1 - Medicos\n");
        printf("2 - Pacientes\n");
        printf("3 - Consultas\n");
        printf("4 - Relatorio\n");
        printf("5 - Sair do Programa...\n");
        scanf(" %d", &opMAIN);

        switch (opMAIN)
        {
        case 1:
            do
            {
                printf("\n-------Menu dos Medicos:-------\n");
                printf("1 - Incluir Medico\n");
                printf("2 - Pesquisar Medico \n");
                printf("3 - Excluir Medico\n");
                printf("4 - Alterar Medico\n");
                printf("5 - Voltar para o menu anterior\n");
                printf("O que voce quer pra hoje? Minha querida professora Cascine: \n");
                scanf("%d", &opMedico);
                getchar();
                switch (opMedico)
                {
                case 1:
                    addMedico(&medicos, &num_medicos);
                    break;

                case 2:
                    pesquisarMedico(&medicos, &num_medicos);
                    break;

                case 3:
                    excluirMedico(&medicos, &num_medicos, &consultas, &num_consultas);
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
            } while (opMedico != 5);
            break;

        case 2:

            do
            {
                printf("\n------- Menu dos Pacientes -------\n");
                printf("1 - Incluir Paciente\n");
                printf("2 - Pesquisar Paciente\n");
                printf("3 - Excluir Paciente\n");
                printf("4 - Alterar Paciente\n");
                printf("5 - Voltar para o menu principal\n");
                printf("O que voce quer pra hoje? Minha querida professora Cascine: \n");
                scanf("%d", &opPaciente);
                getchar();

                switch (opPaciente)
                {
                case 1:
                    addPaciente(&pacientes, &num_pacientes);
                    break;

                case 2:
                    pesquisarPaciente(&pacientes, &num_pacientes);
                    break;

                case 3:
                    excluirPaciente(&pacientes, &num_pacientes, &consultas, &num_consultas);
                    break;

                case 4:
                    alterarPaciente(&pacientes, &num_pacientes);
                    break;

                case 5:
                    printf("Voltando...\n");
                    break;

                default:
                    printf("Desculpe, voce poderia escolher outra opcao?\n");
                }
            } while (opPaciente != 5);
            break;

        case 3:
            //- - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - -MENU CONSULTA- - - - - - - - - - - - - - - - - - - -  - - - - - - - - - - - - - - - - - - - - - - -  - - -
            do
            {
                printf("\n------- Menu de Consultas -------\n");
                printf("1 - Incluir Consulta\n");
                printf("2 - Alterar Consulta\n");
                printf("3 - Excluir Consulta\n");
                printf("4 - Pesquisar Consulta\n");
                printf("5 - Voltar\n");
                printf("O que voce quer pra hoje? Minha querida professora Cascine: \n");
                scanf("%d", &opConsulta);
                getchar();

                switch (opConsulta)
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
            } while (opConsulta != 5);
            break;

        case 4:
            menuRelatorio(consultas, num_consultas, medicos, num_medicos, pacientes, num_pacientes);
            break;

        case 5:
            printf("Fechando aplicacao...\n");
            break;

        default:
            printf("Opcao invalida patrao, joga ota ai pa nois\n");
            break;
        }
    } while (opMAIN != 5);

    free(pacientes);
    free(consultas);
    free(medicos);

    return 0;
}