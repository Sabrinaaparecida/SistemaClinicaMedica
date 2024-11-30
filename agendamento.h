//
// Created by Win10 on 04/11/2024.
//

#ifndef AGENDAMENTO_DE_CONSULTAS_AGENDAMENTO_H
#define AGENDAMENTO_DE_CONSULTAS_AGENDAMENTO_H

#define MAX 100

typedef struct Paciente{
    int id;
    long long int cpf;
    char nome[90];
    int idade;
    char sexo;
    char data_nascimento[30];
    char endereco[150];
    long long int telefone;
    char naturalidade[60];
    char estado[30];
    char nacionalidade[60];
    char historico_medico[150];
} paciente;

typedef paciente *p_paciente;

extern p_paciente v[MAX];

typedef struct Consulta{
    int id_paciente;
    char data_consulta[20];
    char hora_consulta[10];
    char profissional[60];
    char especialidade[60];
    char local[150];
    char codigo[4];

} consulta;

typedef consulta *p_consulta;

extern p_consulta consultas[MAX];


//Iniciar vetor de ponteiro com nulo
void inicializa();

//Cadastrar o paciente
void Cadastrar_paciente(int i);

//Remover paciente
void Remover_paciente(int id_procurado);

// Buscar paciente pelo ID e visualizar suas informações
void Buscar_paciente_por_id(int id_procurado);

void Listar_pacientes();

//Agendar consulta do paciente
void Agendar_consulta(int i);

int Horario_disponivel(const char *data, const char *hora);

int Horario_valido(const char *hora);

//Editar paciente
void Editar_paciente(int id_procurado);

void Buscar_consulta(int id_procurado);

void Listar_consultas();

void Cancelar_consulta(char *cod_procurado);

void Editar_consulta(char *cod_procurado);

void Registrar_usuario();

int Login();

void Linha();

#endif //AGENDAMENTO_DE_CONSULTAS_AGENDAMENTO_H
