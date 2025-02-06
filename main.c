#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <time.h>

typedef struct
{
    int identificador;
    char nome[40];
    char especialidade[40];
} medico;

typedef struct
{
    int indentificador;
    char nome[40];
    int identidade;
    char endereco[40];
    int telefone;
    char sexo;
} paciente;

typedef struct
{
    int numero;
    int medicoID;
    int pacienteID;
    int horario;
    int duracao;
    int data;
} consulta;

int main(void)
{
    while (1)
    {
        
    }
    return 0;
}
