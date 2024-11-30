#include <stdio.h>
#include <stdlib.h>

#include "agendamento.h"
p_paciente v[MAX];
p_consulta consultas[MAX];

int main(void) {
    inicializa();
    int pos = 0; //posicao inicial do vetor
    int posConsulta = 0;
    int opc = 0; //escolha do usuario
    int idDesejado = 0;
    int operacao = 0;
    char codDesejado[4];

    //Login de usuário
    int login_sucesso = 0;

    while(!login_sucesso){
        int opc_login;

        printf("\n--- Login ---\n");
        printf("1) Registrar novo usuario\n");
        printf("2) Fazer login\n");
        printf("3) Sair\n");
        printf("Escolha: ");
        scanf("%d", &opc_login);




        switch (opc_login) {
            case 1:
                Registrar_usuario();
                break;
            case 2:
                login_sucesso = Login();
                break;
            case 3:
                printf("Encerrando o Sistema...");
                exit(0);
            default:
                printf("Opcao invalida.\n");
                break;
        }

    }

    while (operacao != 11){
        printf("\n                 ________________     \n");
        printf("                 || BEM VINDO! ||\n");
        printf("                 ||  CLINICA   ||\n");
        Linha();
        printf("1) CADASTRAR PACIENTE \n");
        printf("2) BUSCAR PACIENTE \n");
        printf("3) EDITAR PACIENTE \n");
        printf("4) REMOVER PACIENTE \n");
        printf("5) LISTAR OS PACIENTES DA CLINICA \n");
        printf("6) AGENDAR CONSULTA \n");
        printf("7) EDITAR CONSULTA \n");
        printf("8) CANCELAR CONSULTA \n");
        printf("9) LISTAR TODAS AS CONSULTAS \n");
        printf("10) BUSCAR CONSULTA \n");
        printf("11) SAIR \n");
        Linha();
        printf("Escolha: \n");
        scanf("%d", &operacao);

        switch (operacao){
            case 1:
                printf("CADASTRAR PACIENTE \n");
                Cadastrar_paciente(pos);
                pos++;
                break;

            case 2:
                printf("BUSCAR PACIENTE\n");
                printf("Digite o ID do paciente desejado para visualizar os seus dados: \n");
                scanf("%d", &idDesejado);
                Buscar_paciente_por_id(idDesejado);
                break;

            case 3:
                printf("EDITAR PACIENTE\n");
                printf("Digite o ID do paciente desejado para editar os seus dados: \n");
                scanf("%d", &idDesejado);
                Editar_paciente(idDesejado);
                break;

            case 4:
                printf("REMOVER PACIENTE\n");
                printf("Digite o ID do paciente para remove-lo: \n");
                scanf("%d", &idDesejado);
                Remover_paciente(idDesejado);
                break;

            case 5:
                printf("LISTAR OS PACIENTES DA CLINICA\n");
                Listar_pacientes();
                break;

            case 6:
                printf("AGENDAR CONSULTA\n");
                Agendar_consulta(posConsulta);
                posConsulta++;
                break;

            case 7:
                printf("EDITAR CONSULTA\n");
                printf("Digite o codigo da consulta para edita-la: \n");
                scanf("%s", codDesejado);
                Editar_consulta(codDesejado);
                break;

            case 8:
                printf("CANCELAR CONSULTA\n");
                printf("Digite o codigo da consulta para remove-la: \n");
                scanf("%s", codDesejado);
                Cancelar_consulta(codDesejado);
                break;

            case 9:
                printf("LISTAR TODAS AS CONSULTAS\n");
                Listar_consultas();
                break;

            case 10:
                printf("BUSCAR CONSULTA\n");
                printf("Digite o ID do paciente para buscar suas consultas: ");
                scanf("%d", &idDesejado);
                Buscar_consulta(idDesejado);

            case 11:
                printf("Fim da execucao\n");
                break;

            default:
                printf("Opcao invalida. \n");
        }
    }

    return 0;
}
