//
// Created by Win10 on 04/11/2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendamento.h"

#define MAX_LINHA 200

void inicializa() {
    //varrer o vetor e colocar null em todas as posicoes
    for (int i = 0; i < MAX; i++) {
        v[i] = NULL;
        consultas[i] = NULL;
    }
}

void Cadastrar_paciente(int i) {
    if (v[i] != NULL) {
        printf("Posição já preenchida\n");
        return;
    }

    v[i] = (p_paciente) malloc(sizeof(struct Paciente));
    if (v[i] == NULL) {
        printf("Erro ao alocar memória para o paciente.\n");
        return;
    }

    fflush(stdin);

    // Coleta dos dados do paciente
    printf("Digite o id: \n");
    scanf("%d", &v[i]->id);
    fflush(stdin);
    printf("Digite o cpf: \n");
    scanf("%lld", &v[i]->cpf);
    fflush(stdin);
    printf("Digite o nome completo: \n");
    scanf(" %[^\n]", v[i]->nome);
    fflush(stdin);
    printf("Digite a idade: \n");
    scanf("%d", &v[i]->idade);
    fflush(stdin);
    printf("Digite o sexo (F/M): \n");
    scanf(" %c", &v[i]->sexo);
    fflush(stdin);
    printf("Digite a data de nascimento (DD/MM/AAAA): \n");
    scanf(" %[^\n]", v[i]->data_nascimento);
    fflush(stdin);
    printf("Digite o endereco: \n");
    scanf(" %[^\n]", v[i]->endereco);
    fflush(stdin);
    printf("Digite o telefone: \n");
    scanf("%lld", &v[i]->telefone);
    fflush(stdin);
    printf("Digite a naturalidade: \n");
    scanf(" %[^\n]", v[i]->naturalidade);
    fflush(stdin);
    printf("Digite o estado: \n");
    scanf(" %[^\n]", v[i]->estado);
    fflush(stdin);
    printf("Digite a nacionalidade: \n");
    scanf(" %[^\n]", v[i]->nacionalidade);
    fflush(stdin);
    printf("Digite o historico medico do paciente: \n");
    scanf(" %[^\n]", v[i]->historico_medico);
    fflush(stdin);

    // Abrir o arquivo e salvar os dados do paciente
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt", "a"); // Modo append para adicionar sem sobrescrever
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar o paciente.\n");
        free(v[i]);  // Libera a memória caso o arquivo não possa ser aberto
        v[i] = NULL;
        return;
    }

    // Escreve os dados no arquivo
    fprintf(arquivo, "Id: %d\n", v[i]->id);
    fprintf(arquivo, "Cpf: %lld\n", v[i]->cpf);
    fprintf(arquivo, "Nome completo: %s\n", v[i]->nome);
    fprintf(arquivo, "Idade: %d\n", v[i]->idade);
    fprintf(arquivo, "Sexo: %c\n", v[i]->sexo);
    fprintf(arquivo, "Data de nascimento: %s\n", v[i]->data_nascimento);
    fprintf(arquivo, "Endereco: %s\n", v[i]->endereco);
    fprintf(arquivo, "Telefone: %lld\n", v[i]->telefone);
    fprintf(arquivo, "Naturalidade: %s\n", v[i]->naturalidade);
    fprintf(arquivo, "Estado: %s\n", v[i]->estado);
    fprintf(arquivo, "Nacionalidade: %s\n", v[i]->nacionalidade);
    fprintf(arquivo, "Historico medico: %s\n", v[i]->historico_medico);
    fprintf(arquivo, "---------------------------\n");

    fclose(arquivo); // Fecha o arquivo após a gravação
    printf("Paciente cadastrado e salvo no arquivo com sucesso.\n");
}


// Função para buscar e exibir informações de um paciente por ID
void Buscar_paciente_por_id(int id_procurado) {
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt", "r"); // Arquivo no mesmo diretório
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    char linha[200];
    int id_encontrado = 0; // Flag para verificar se o paciente foi encontrado

    // Armazenar os dados temporariamente
    int id, idade;
    long long int cpf, telefone;
    char nome[90], sexo, data_nascimento[30], endereco[150], naturalidade[60], estado[30], nacionalidade[60], historico_medico[150];

    // Percorrer o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Procurar pela linha que contém o ID
        if (sscanf(linha, "Id: %d", &id) == 1) {
            // Verifica se o ID é o procurado
            if (id == id_procurado) {
                id_encontrado = 1;

                // Ler e armazenar os dados do paciente a partir do arquivo
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Cpf: %lld", &cpf);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Nome completo: %[^\n]", nome);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Idade: %d", &idade);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Sexo: %c", &sexo);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Data de nascimento: %[^\n]", data_nascimento);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Endereco: %[^\n]", endereco);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Telefone: %lld", &telefone);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Naturalidade: %[^\n]", naturalidade);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Estado: %[^\n]", estado);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Nacionalidade: %[^\n]", nacionalidade);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Historico medico: %[^\n]", historico_medico);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "---------------------------\n");

                // Exibir as informações do paciente
                printf("Id: %d\n", id);
                printf("Cpf: %lld\n", cpf);
                printf("Nome completo: %s\n", nome);
                printf("Idade: %d\n", idade);
                printf("Sexo: %c\n", sexo);
                printf("Data de nascimento: %s\n", data_nascimento);
                printf("Endereco: %s\n", endereco);
                printf("Telefone: %lld\n", telefone);
                printf("Naturalidade: %s\n", naturalidade);
                printf("Estado: %s\n", estado);
                printf("Nacionalidade: %s\n", nacionalidade);
                printf("Historico medico: %s\n", historico_medico);
                printf("---------------------------\n");

                break; // Sai do loop, pois o paciente foi encontrado
            }
        }
    }

    if (!id_encontrado) {
        printf("Paciente com ID %d não encontrado.\n", id_procurado);
    }

    fclose(arquivo); // Fecha o arquivo
}


void Editar_paciente(int id_procurado) {
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        return;
    }

    FILE *temp = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_pacientes.txt", "w");
    if (temp == NULL) {
        printf("Erro ao criar arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char linha[256];
    int id, idade, encontrado = 0;
    long long int cpf, telefone;
    char nome[90], sexo, data_nascimento[30], endereco[150], naturalidade[60], estado[30], nacionalidade[60], historico_medico[150];

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        if (sscanf(linha, "Id: %d", &id) == 1 && id == id_procurado) {
            encontrado = 1;

            // Ler os dados do paciente
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Cpf: %lld", &cpf);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Nome completo: %[^\n]", nome);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Idade: %d", &idade);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Sexo: %c", &sexo);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Data de nascimento: %[^\n]", data_nascimento);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Endereco: %[^\n]", endereco);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Telefone: %lld", &telefone);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Naturalidade: %[^\n]", naturalidade);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Estado: %[^\n]", estado);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Nacionalidade: %[^\n]", nacionalidade);
            fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Historico medico: %[^\n]", historico_medico);
            fgets(linha, sizeof(linha), arquivo); // Ignorar linha de separador

            // Menu para editar os dados
            int op = 0;
            while (op != 13) {
                printf("\nO que deseja editar?");
                printf("\n1. ID");
                printf("\n2. CPF");
                printf("\n3. Nome completo");
                printf("\n4. Idade");
                printf("\n5. Sexo");
                printf("\n6. Data de nascimento");
                printf("\n7. Endereco");
                printf("\n8. Telefone");
                printf("\n9. Naturalidade");
                printf("\n10. Estado");
                printf("\n11. Nacionalidade");
                printf("\n12. Historico medico");
                printf("\n13. Sair");
                printf("\n\nEscolha: ");
                scanf("%d", &op);

                switch (op) {
                    case 1:
                        printf("\nID atual: %d\nNovo ID: ", id);
                        scanf("%d", &id);
                        break;
                    case 2:
                        printf("\nCPF atual: %lld\nNovo CPF: ", cpf);
                        scanf("%lld", &cpf);
                        break;
                    case 3:
                        printf("\nNome atual: %s\nNovo nome: ", nome);
                        scanf(" %[^\n]", nome);
                        break;
                    case 4:
                        printf("\nIdade atual: %d\nNova idade: ", idade);
                        scanf("%d", &idade);
                        break;
                    case 5:
                        printf("\nSexo atual: %c\nNovo sexo (F/M): ", sexo);
                        scanf(" %c", &sexo);
                        break;
                    case 6:
                        printf("\nData de nascimento atual: %s\nNova data de nascimento: ", data_nascimento);
                        scanf(" %[^\n]", data_nascimento);
                        break;
                    case 7:
                        printf("\nEndereco atual: %s\nNovo endereco: ", endereco);
                        scanf(" %[^\n]", endereco);
                        break;
                    case 8:
                        printf("\nTelefone atual: %lld\nNovo telefone: ", telefone);
                        scanf("%lld", &telefone);
                        break;
                    case 9:
                        printf("\nNaturalidade atual: %s\nNova naturalidade: ", naturalidade);
                        scanf(" %[^\n]", naturalidade);
                        break;
                    case 10:
                        printf("\nEstado atual: %s\nNovo estado: ", estado);
                        scanf(" %[^\n]", estado);
                        break;
                    case 11:
                        printf("\nNacionalidade atual: %s\nNova nacionalidade: ", nacionalidade);
                        scanf(" %[^\n]", nacionalidade);
                        break;
                    case 12:
                        printf("\nHistórico médico atual: %s\nNovo histórico médico: ", historico_medico);
                        scanf(" %[^\n]", historico_medico);
                        break;
                    case 13:
                        printf("\nFim da edição.\n");
                        break;
                    default:
                        printf("Opção inválida.\n");
                        break;
                }
            }

            // Escrever os dados atualizados no arquivo temporário
            fprintf(temp, "Id: %d\n", id);
            fprintf(temp, "Cpf: %lld\n", cpf);
            fprintf(temp, "Nome completo: %s\n", nome);
            fprintf(temp, "Idade: %d\n", idade);
            fprintf(temp, "Sexo: %c\n", sexo);
            fprintf(temp, "Data de nascimento: %s\n", data_nascimento);
            fprintf(temp, "Endereco: %s\n", endereco);
            fprintf(temp, "Telefone: %lld\n", telefone);
            fprintf(temp, "Naturalidade: %s\n", naturalidade);
            fprintf(temp, "Estado: %s\n", estado);
            fprintf(temp, "Nacionalidade: %s\n", nacionalidade);
            fprintf(temp, "Historico medico: %s\n", historico_medico);
            fprintf(temp, "---------------------------\n");
        } else {
            // Copiar as outras linhas do arquivo original para o temporário
            fputs(linha, temp);
        }
    }

    fclose(arquivo);
    fclose(temp);

    if (encontrado) {
        remove("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt");
        rename("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_pacientes.txt", "C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt");
        printf("\nPaciente atualizado com sucesso!\n");
    } else {
        remove("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_pacientes.txt");
        printf("\nPaciente com ID %d não encontrado.\n", id_procurado);
    }
}

void Remover_paciente(int id_procurado) {
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    FILE *temp_arquivo = fopen("temp_pacientes.txt", "w");
    if (temp_arquivo == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo);
        return;
    }

    char linha[200];
    int ignorar_linhas = 0; // Controla se devemos ignorar linhas associadas ao paciente atual

    // Percorrer o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Verificar se a linha contém o ID do paciente
        int id;
        if (sscanf(linha, "Id: %d", &id) == 1 && id == id_procurado) {
            ignorar_linhas = 1; // Iniciar o processo de ignorar linhas
            continue;
        }

        // Ignorar as linhas até encontrar o próximo separador
        if (ignorar_linhas) {
            if (strcmp(linha, "---------------------------\n") == 0) {
                ignorar_linhas = 0; // Parar de ignorar após o separador
            }
            continue;
        }

        // Copiar a linha para o arquivo temporário
        fprintf(temp_arquivo, "%s", linha);
    }

    fclose(arquivo);
    fclose(temp_arquivo);

    // Substituir o arquivo original pelo temporário
    remove("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt");
    rename("temp_pacientes.txt", "C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt");

    printf("Paciente com ID %d removido com sucesso.\n", id_procurado);
}

void Listar_pacientes(){
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo de consultas");
    }

    char linha[200];
    printf("\n------LISTA DE PACIENTES DA CLINICA------\n");

    while(fgets(linha, sizeof(linha), arquivo)){
        printf("%s", linha);
    }

    fclose(arquivo);
    printf("\n------FIM DA LISTA------\n");
}

int Horario_disponivel(const char *data, const char *hora){
    FILE *arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt", "r");
    if (arquivo_consultas == NULL) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return 0; // Considerar como horário ocupado em caso de erro
    }

    char linha[200];
    char data_existente[11];
    char hora_existente[6];

    // Ler cada linha do arquivo e verificar data e horário
    while (fgets(linha, sizeof(linha), arquivo_consultas)) {
        if (sscanf(linha, "Data: %10s", data_existente) == 1 && strcmp(data_existente, data) == 0) {
            fgets(linha, sizeof(linha), arquivo_consultas); // Pular para a próxima linha
            if (sscanf(linha, "Horario: %5s", hora_existente) == 1 && strcmp(hora_existente, hora) == 0) {
                fclose(arquivo_consultas);
                return 0; // Horário já ocupado
            }
        }
    }

    fclose(arquivo_consultas);
    return 1; // Horário disponível
}

int Horario_valido(const char *hora){
    int hh, mm;
    if (sscanf(hora, "%d:%d", &hh, &mm) != 2) {
        return 0; // Formato inválido
    }
    if (mm != 0) {
        return 0; // Apenas horários em ponto são válidos
    }
    if (hh < 7 || hh > 18) {
        return 0; // Fora do intervalo permitido
    }
    return 1; // Horário válido
}


void Agendar_consulta(int i) {
    int id_paciente;
    printf("Digite o id do paciente para agendar a consulta: ");
    scanf("%d", &id_paciente);

    FILE *arquivo_pacientes = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt", "r");
    if (arquivo_pacientes == NULL) {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        return;  // Erro ao abrir arquivo
    }

    paciente paciente;
    char linha[200];
    int encontrado = 0;

    // Percorrer o arquivo para encontrar o paciente pelo ID
    while (fgets(linha, sizeof(linha), arquivo_pacientes)) {
        if (sscanf(linha, "Id: %d", &paciente.id) == 1 && paciente.id == id_paciente) {
            encontrado = 1;
            // Ler as próximas linhas com as informações do paciente
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Cpf: %lld", &paciente.cpf);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Nome completo: %[^\n]", paciente.nome);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Idade: %d", &paciente.idade);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Sexo: %c", &paciente.sexo);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Data de nascimento: %[^\n]", paciente.data_nascimento);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Endereco: %[^\n]", paciente.endereco);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Telefone: %lld", &paciente.telefone);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Naturalidade: %[^\n]", paciente.naturalidade);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Estado: %[^\n]", paciente.estado);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Nacionalidade: %[^\n]", paciente.nacionalidade);
            fgets(linha, sizeof(linha), arquivo_pacientes); sscanf(linha, "Historico medico: %[^\n]", paciente.historico_medico);
            break;
        }
    }

    fclose(arquivo_pacientes);

    if (!encontrado) {
        printf("Paciente com ID %d nao encontrado. Nao e possível agendar consulta.\n", id_paciente);
        return;
    }

    if (consultas[i] != NULL) {
        printf("Ja existe uma consulta agendada nesta posicao. Escolha outra.\n");
        return;
    }


    // Solicitar data e horário da consulta
    char data[11];
    char hora[6];

    printf("Digite a data da consulta (DD/MM/AAAA): \n");
    scanf(" %[^\n]", data);

    do {
        printf("Digite o horario da consulta (HH:00, entre 07:00 e 18:00): \n");
        scanf(" %[^\n]", hora);

        if (!Horario_valido(hora)) {
            printf("Horario invalido. Por favor, insira um horario no formato HH:00 e entre 07:00 e 18:00.\n");
        } else if (!Horario_disponivel(data, hora)) {
            printf("O horario %s na data %s ja esta ocupado. Escolha outro.\n", hora, data);
        }
    } while (!Horario_valido(hora) || !Horario_disponivel(data, hora));


    // Alocar memória para a nova consulta
    consultas[i] = (p_consulta) malloc(sizeof(struct Consulta));
    if (consultas[i] == NULL) {
        printf("Erro ao alocar memória para a consulta.\n");
        return;
    }

    strcpy(consultas[i]->data_consulta, data);
    strcpy(consultas[i]->hora_consulta, hora);

    // Declarando os profissionais existentes
    int n = 0;
    char profissionais[3][60] = {
        "Dr. Lucas Eduardo Facina",
        "Dra. Agata Rocha de Almeida",
        "Dr. Sergio Marreiro Filho"
    };
    char especialidades[3][60] = {
        "Demartologista",
        "Fisioterapeuta",
        "Cardiologista"
    };

    // Solicitar informações da consulta
    while (n < 1 || n > 3) {
        printf("Escolha um profissional:\n");
        printf("1. %s \n %s \n", profissionais[0], especialidades[0]);
        printf("2. %s \n %s \n", profissionais[1], especialidades[1]);
        printf("3. %s \n %s \n", profissionais[2], especialidades[2]);
        printf("\nDigite o numero do profissional desejado: ");
        scanf("%d", &n);
        if (n < 1 || n > 3) {
            printf("Numero invalido.\n");
        }
    }

    // Atribuindo o nome do profissional escolhido
    strcpy(consultas[i]->profissional, profissionais[n - 1]);

    // Atribuindo a especialidade escolhida
    strcpy(consultas[i]->especialidade, especialidades[n - 1]);

    printf("Digite o local: \n");
    scanf(" %[^\n]", consultas[i]->local);

    // Criando um codigo para cada consulta
    int codigo_valido = 0;  // Inicia como "falso" (código inválido)
    char codigo_tentativo[4];  // 3 caracteres + 1 para o '\0'

    // Laço de repetição para garantir que o código seja único e válido (3 caracteres)
    while (!codigo_valido) { // Enquanto código_valido for "falso" (0)
        printf("Crie um codigo para a consulta com 3 caracteres: \n");
        scanf(" %[^\n]", codigo_tentativo);
        fflush(stdin);

        // Verificar se o código tem exatamente 3 caracteres
        if (strlen(codigo_tentativo) != 3) {
            printf("O codigo deve ter exatamente 3 caracteres. Tente novamente.\n");
            continue;  // Solicitar novamente
        }

        // Verificar se o código já existe no arquivo de consultas
        FILE *arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt", "r");
        if (arquivo_consultas == NULL) {
            printf("Erro ao abrir o arquivo de consultas.\n");
            free(consultas[i]);
            consultas[i] = NULL;
            return;
        }

        char codigo_existente[4];  // Para armazenar códigos já existentes
        int codigo_existe = 0;

        while (fgets(linha, sizeof(linha), arquivo_consultas)) {
            if (sscanf(linha, "Codigo: %3s", codigo_existente) == 1) {
                if (strcmp(codigo_existente, codigo_tentativo) == 0) {
                    codigo_existe = 1;
                    break;  // Se o código já existe, sai do laço
                }
            }
        }

        fclose(arquivo_consultas);

        if (codigo_existe) {
            printf("Este codigo ja esta em uso. Escolha outro.\n");
        } else {
            codigo_valido = 1;  // Código válido, sai do laço
        }
    }

    // Salvar o código válido para a consulta
    strcpy(consultas[i]->codigo, codigo_tentativo);

    // Associar o ID do paciente à consulta
    consultas[i]->id_paciente = id_paciente;

    // Salvar a consulta em um arquivo
    FILE *arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt", "a");
    if (arquivo_consultas == NULL) {
        printf("Erro ao abrir o arquivo para salvar a consulta.\n");
        free(consultas[i]); // Liberar a memória em caso de erro
        consultas[i] = NULL;
        return;
    }

    fprintf(arquivo_consultas, "Codigo: %s\n", consultas[i]->codigo);
    fprintf(arquivo_consultas, "ID Paciente: %d\n", consultas[i]->id_paciente);
    fprintf(arquivo_consultas, "Data: %s\n", consultas[i]->data_consulta);
    fprintf(arquivo_consultas, "Horario: %s\n", consultas[i]->hora_consulta);
    fprintf(arquivo_consultas, "Nome do profissional: %s\n", consultas[i]->profissional);
    fprintf(arquivo_consultas, "Especialidade: %s\n", consultas[i]->especialidade);
    fprintf(arquivo_consultas, "Local da consulta: %s\n", consultas[i]->local);
    fprintf(arquivo_consultas, "---------------------------\n");
    fclose(arquivo_consultas);

    printf("Consulta agendada com sucesso para o paciente ID %d.\n", id_paciente);
}

void Listar_consultas(){
    FILE *arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt", "r");
    if(arquivo_consultas == NULL){
        printf("Erro ao abrir o arquivo de consultas");
    }

    char linha[200];
    printf("\n------LISTA DE CONSULTAS AGENDADAS------\n");

    while(fgets(linha, sizeof(linha), arquivo_consultas)){
        printf("%s", linha);
    }

    fclose(arquivo_consultas);
    printf("\n------FIM DA LISTA------\n");
}

void Buscar_consulta(int id_procurado) {
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    char linha[256];
    int id_paciente_encontrado = 0; // Flag para verificar se a consulta foi encontrada

    // Armazenar os dados temporariamente
    int id_paciente;
    char data[20], horario[10], profissional[60], especialidade[60], local[150];

    // Percorrer o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Procurar pela linha que contém o ID do paciente
        if (sscanf(linha, "ID Paciente: %d", &id_paciente) == 1) {
            // Verifica se o ID do paciente é o procurado
            if (id_paciente == id_procurado) {
                id_paciente_encontrado = 1;

                // Ler e armazenar os dados da consulta a partir do arquivo
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Data: %[^\n]", data);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Horario: %[^\n]", horario);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Nome do profissional: %[^\n]", profissional);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Especialidade: %[^\n]", especialidade);
                fgets(linha, sizeof(linha), arquivo); sscanf(linha, "Local da consulta: %[^\n]", local);

                // Exibir as informações da consulta
                printf("ID Paciente: %d\n", id_paciente);
                printf("Data: %s\n", data);
                printf("Horario: %s\n", horario);
                printf("Nome do profissional: %s\n", profissional);
                printf("Especialidade: %s\n", especialidade);
                printf("Local da consulta: %s\n", local);
                printf("---------------------------\n");
            }
        }
    }

    if (!id_paciente_encontrado) {
        printf("Consulta com ID do paciente %d nao encontrada.\n", id_procurado);
    }

    fclose(arquivo); // Fecha o arquivo
}

void Cancelar_consulta(char *cod_procurado) {
    FILE *arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt", "r");
    if (arquivo_consultas == NULL) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    FILE *temp_arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_consultas.txt", "w");
    if (temp_arquivo_consultas == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo_consultas);
        return;
    }

    char linha[200];
    char cod[50]; // Variável para armazenar o código da consulta
    int cod_encontrado = 0;

    // Percorrer o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo_consultas) != NULL) {
        // Procurar pela linha que contém o código
        if (sscanf(linha, "Codigo: %49s", cod) == 1) {
            if (strcmp(cod, cod_procurado) == 0) {
                cod_encontrado = 1;
                // Pular as próximas linhas da consulta e o separador
                fgets(linha, sizeof(linha), arquivo_consultas); // ID
                fgets(linha, sizeof(linha), arquivo_consultas); // Data
                fgets(linha, sizeof(linha), arquivo_consultas); // Horário
                fgets(linha, sizeof(linha), arquivo_consultas); // Profissional
                fgets(linha, sizeof(linha), arquivo_consultas); // Especialidade
                fgets(linha, sizeof(linha), arquivo_consultas); // Local
                fgets(linha, sizeof(linha), arquivo_consultas); // Separador
            } else {
                // Copiar as linhas para o arquivo temporário
                fprintf(temp_arquivo_consultas, "Codigo: %s\n", cod);
                fgets(linha, sizeof(linha), arquivo_consultas); fprintf(temp_arquivo_consultas, "%s", linha); // ID
                fgets(linha, sizeof(linha), arquivo_consultas); fprintf(temp_arquivo_consultas, "%s", linha); // Data
                fgets(linha, sizeof(linha), arquivo_consultas); fprintf(temp_arquivo_consultas, "%s", linha); // Horário
                fgets(linha, sizeof(linha), arquivo_consultas); fprintf(temp_arquivo_consultas, "%s", linha); // Profissional
                fgets(linha, sizeof(linha), arquivo_consultas); fprintf(temp_arquivo_consultas, "%s", linha); // Especialidade
                fgets(linha, sizeof(linha), arquivo_consultas); fprintf(temp_arquivo_consultas, "%s", linha); // Local
                fgets(linha, sizeof(linha), arquivo_consultas); fprintf(temp_arquivo_consultas, "%s", linha); // Separador
            }
        }
    }

    fclose(arquivo_consultas);
    fclose(temp_arquivo_consultas);

    // Verificar se o código foi encontrado
    if (cod_encontrado) {
        remove("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt");
        rename("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_consultas.txt", "C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt");
        printf("Consulta com código %s removida com sucesso!\n", cod_procurado);
    } else {
        remove("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_consultas.txt");
        printf("Consulta com código %s não encontrada.\n", cod_procurado);
    }
}

void Editar_consulta(char *cod_procurado) {
    FILE *arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt", "r");
    if (arquivo_consultas == NULL) {
        printf("Erro ao abrir o arquivo de consultas.\n");
        return;
    }

    FILE *temp_arquivo_consultas = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_consultas.txt", "w");
    if (temp_arquivo_consultas == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(arquivo_consultas);
        return;
    }

    char linha[256];
    int id, encontrado = 0;
    char data[20], horario[10], profissional[60], especialidade[60], local[150], codigo[4];

    // Percorrer o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo_consultas) != NULL) {
        // Procurar pela linha que contém o código
        if (sscanf(linha, "Codigo: %4s", codigo) == 1) {
            if (strcmp(codigo, cod_procurado) == 0) {
                encontrado = 1;

                // Ler os dados da consulta
                fgets(linha, sizeof(linha), arquivo_consultas); sscanf(linha, "ID Paciente: %d", &id);
                fgets(linha, sizeof(linha), arquivo_consultas); sscanf(linha, "Data: %[^\n]", data);
                fgets(linha, sizeof(linha), arquivo_consultas); sscanf(linha, "Horario: %[^\n]", horario);
                fgets(linha, sizeof(linha), arquivo_consultas); sscanf(linha, "Nome do profissional: %[^\n]", profissional);
                fgets(linha, sizeof(linha), arquivo_consultas); sscanf(linha, "Especialidade: %[^\n]", especialidade);
                fgets(linha, sizeof(linha), arquivo_consultas); sscanf(linha, "Local da consulta: %[^\n]", local);
                fgets(linha, sizeof(linha), arquivo_consultas); // Ignorar linha de separador

                // Menu para editar os dados
                int op = 0;
                while (op != 5) {
                    printf("O que deseja editar?");
                    printf("\n1. ID");
                    printf("\n2. Data e horário");
                    printf("\n3. Profissional");
                    printf("\n4. Local da consulta");
                    printf("\n5. Sair");
                    printf("\nObs: Nao e possivel alterar o codigo da consulta");
                    printf("\n\nEscolha: ");
                    scanf("%d", &op);

                    switch (op) {
                        case 1:
                            printf("\nID atual: %d\nNovo ID: ", id);
                            scanf("%d", &id);
                            FILE *arquivo_pacientes = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\pacientes.txt", "r");
                            if (arquivo_pacientes == NULL) {
                                printf("Erro ao abrir o arquivo de pacientes.\n");
                                return;  // Erro ao abrir arquivo
                            }

                            paciente paciente;
                            int id_encontrado = 0;
                            // Percorrer o arquivo para encontrar o paciente pelo ID
                            while (fgets(linha, sizeof(linha), arquivo_pacientes)) {
                                if (sscanf(linha, "Id: %d", &paciente.id) == 1 && paciente.id == id) {
                                    id_encontrado = 1;
                                    break;
                                }
                            }

                            fclose(arquivo_pacientes);

                            if (!id_encontrado) {
                                printf("Paciente com ID %d nao encontrado. Nao e possível editar esta consulta.\n", id);
                                return;
                            }
                            break;
                        case 2:
                            do {
                                printf("\nData atual: %s\nNova data: ", data);
                                scanf("%19s", data);
                                printf("\nHorario atual: %s\nNovo horario: ", horario);
                                scanf(" %[^\n]", horario);

                                if (!Horario_valido(horario)) {
                                    printf("Horario invalido. Por favor, insira um horario no formato HH:00 e entre 07:00 e 18:00.\n");
                                } else if (!Horario_disponivel(data, horario)) {
                                    printf("O horario %s na data %s ja esta ocupado. Escolha outro.\n", horario, data);
                                }
                            } while (!Horario_valido(horario) || !Horario_disponivel(data, horario));

                            break;
                        case 3:
                            printf("\nProfissional atual: %s\nProfissionais disponiveis: \n", profissional);
                            char profissionais[3][60] = {
                                "Dr. Lucas Eduardo Facina",
                                "Dra. Agata Rocha de Almeida",
                                "Dr. Sergio Marreiro Filho"
                            };
                            char especialidades[3][60] = {
                                "Demartologista",
                                "Fisioterapeuta",
                                "Cardiologista"
                            };
                            int n;
                            for (int i=0; i<3; i++) {
                                if (strcmp(profissional, profissionais[i]) == 0) {
                                    continue;
                                }
                                printf("%d. %s \n %s \n", i+1, profissionais[i], especialidades[i]);
                            }
                            printf ("Escolha: ");
                            scanf("%d", &n);
                            strcpy(profissional, profissionais[n-1]);
                            strcpy(especialidade, especialidades[n-1]);

                            break;
                        case 4:
                            printf("\nLocal atual: %s\nNovo local: ", local);
                            scanf(" %[^\n]", local);
                            break;
                        case 5:
                            printf("\nFim da edicao.\n");
                            break;
                        default:
                            printf("Opção invalida.\n");
                            break;
                    }
                }

                // Escrever os dados atualizados no arquivo temporário
                fprintf(temp_arquivo_consultas, "Codigo: %s\n", codigo);
                fprintf(temp_arquivo_consultas, "Id: %d\n", id);
                fprintf(temp_arquivo_consultas, "Data: %s\n", data);
                fprintf(temp_arquivo_consultas, "Horario: %s\n", horario);
                fprintf(temp_arquivo_consultas, "Nome do profissional: %s\n", profissional);
                fprintf(temp_arquivo_consultas, "Especialidade: %s\n", especialidade);
                fprintf(temp_arquivo_consultas, "Local: %s\n", local);
                fprintf(temp_arquivo_consultas, "---------------------------\n");
            } else {
                // Copiar as outras linhas do arquivo original para o temporário
                fputs(linha, temp_arquivo_consultas);
            }
        }
    }

    fclose(arquivo_consultas);
    fclose(temp_arquivo_consultas);

    if (encontrado) {
        remove("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt");
        rename("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_consultas.txt", "C:\\Users\\Win10\\CLionProjects\\agendamento2911\\consultas.txt");
        printf("\nConsulta atualizada com sucesso!\n");
    } else {
        remove("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\temp_consultas.txt");
        printf("\nConsulta com codigo %s não encontrada.\n", cod_procurado);
    }
}

void Registrar_usuario(){
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\usuarios.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return;
    }
    char usuario[50], senha[50];

    printf("Digite o nome de usuario: ");
    scanf(" %49[^\n]", usuario);
    printf("Digite a senha: ");
    scanf(" %49[^\n]", senha);

    fprintf(arquivo, "%s %s\n", usuario, senha);
    fclose(arquivo);
    printf("Novo usuario registrado com sucesso!\n");
}

int Login(){
    FILE *arquivo = fopen("C:\\Users\\Win10\\CLionProjects\\agendamento2911\\usuarios.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usuarios.\n");
        return 0;
    }
    char usuario[50], senha[50];
    char usuario_arquivo[50], senha_arquivo[50];
    int login_sucesso = 0;

    printf("Digite o nome de usuario: ");
    scanf(" %49[^\n]", usuario);
    printf("Digite a senha: ");
    scanf(" %49[^\n]", senha);

    // Remover espaços
    usuario[strcspn(usuario, "\n")] = '\0';
    senha[strcspn(senha, "\n")] = '\0';

    while (fscanf(arquivo, "%49s %49s", usuario_arquivo, senha_arquivo) != EOF) {
        if (strcmp(usuario, usuario_arquivo) == 0 && strcmp(senha, senha_arquivo) == 0) {
            login_sucesso = 1;
            break;
        }
    }

    fclose(arquivo);

    if (login_sucesso) {
        printf("Login bem-sucedido! Ola, %s!\n", usuario);
        return 1;
    } else {
        printf("Nome de usuario ou senha incorretos.\n");
        return 0;
    }

}
void Linha() {
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}




