# Sistema de Gerenciamento de Consultas Médicas

## Desenvolvido por: Gabriel Carvalho e Victor Aires

### 📌 Descrição
Este projeto implementa um sistema de gerenciamento de consultas médicas, permitindo o cadastro, alteração, exclusão e consulta de médicos, pacientes e consultas. Além disso, o sistema garante a integridade dos dados ao excluir automaticamente as consultas vinculadas a médicos e pacientes removidos.

---

## 🛠 Funcionalidades

✔ **Cadastro de médicos, pacientes e consultas**
✔ **Alteração de dados** (nome, especialidade, horários, etc.)
✔ **Exclusão de registros**, removendo automaticamente as consultas associadas
✔ **Busca de médicos, pacientes e consultas**
✔ **Listagem geral e filtrada**
✔ **Alocação dinâmica** para manipulação eficiente dos dados

---

## 🏗 Estrutura do Código
O código é baseado nas seguintes **structs**:

```c
typedef struct {
    int cpf;
    char name[50];
    char rg[25];
    char endereco[100];
    char telefone[20];
    char sexo[20];
} paciente;

typedef struct {
    int num_consulta;
    int id_paciente;
    int id_medico;
    char horario[6];
    char duracao[20];
    char data[10];
} consulta;

typedef struct {
    int crm;
    char name[50];
    char especialidade[50];
} medico;
```

### 📌 Principais Funções Implementadas

#### ➤ Cadastro de Médicos
```c
void addMedico(medico **m, int *num_medicos);
```
Permite inserir um novo médico no sistema.

#### ➤ Exclusão de Médicos (Remove Consultas Vinculadas)
```c
void excluirMedico(medico **m, int *num_medicos, consulta **c, int *num_consultas);
```
Se um médico for excluído, todas as suas consultas também são removidas.

#### ➤ Cadastro de Pacientes
```c
void addPaciente(paciente **p, int *num_pacientes);
```
Adiciona um novo paciente à base de dados.

#### ➤ Gerenciamento de Consultas
```c
void addConsulta(consulta **c, int *num_consultas);
```
Permite agendar consultas e vincular pacientes a médicos.

#### ➤ Relatórios
```c
void gerarRelatorios();
```
Gera um relatório com todas as informações cadastradas.

---

## 🚀 Como Executar

### 1️⃣ Compilar o código
```bash
gcc main.c -o hospital_system
```

### 2️⃣ Executar o programa
```bash
./hospital_system
```

---

## 📋 Exemplo de Uso

📌 **Fluxo básico do sistema**
```bash
Bem-vindo ao sistema de gerenciamento de consultas médicas!
1 - Médicos
2 - Pacientes
3 - Consultas
4 - Relatório
5 - Sair
Escolha uma opção: 1

--- Menu de Médicos ---
1 - Incluir Médico
2 - Pesquisar Médico
3 - Excluir Médico
4 - Voltar
Escolha uma opção: 1
Digite o CRM do médico: 1234
Digite o nome do médico: Dr. Pedro
Digite a especialidade do médico: Cardiologista
Médico cadastrado com sucesso!
```

---

## ⚠ Possíveis Melhorias Futuras
✅ **Persistência dos dados com arquivos binários**
✅ **Interface gráfica para melhor usabilidade**
✅ **Integração com banco de dados para escalabilidade**

---

## 📌 Conclusão
Este sistema permite um gerenciamento eficiente de médicos, pacientes e consultas, garantindo integridade ao excluir automaticamente consultas vinculadas. Ele utiliza **alocação dinâmica**, evitando desperdício de memória. É um projeto modular e extensível para futuras melhorias.

📌 **Desenvolvido com dedicação por Gabriel Carvalho e Victor Aires!** 🚀

