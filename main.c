#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define TAM 10

//declarando a struct:
struct stReserva {
    char nome[50];
    int cpf;
    int dia;
    int qtdadePessoas;
};

// typedef transformando "struct stReserva" em apenas "reserva":
typedef struct stReserva reserva;

// sub-rotinas:
int fazerReserva(reserva listaReservas[], int cont);
void listarReservas(reserva listaReservas[], int cont);
void totalPessoasPorDia(reserva listaReservas[], int cont);

int main() {
    setlocale(LC_ALL, "");

    reserva listaReservas[TAM];
    int cont = 0;
    int opcao;
    int i;

    do {
        system("cls");
        printf("Bem-vindo ao sistema de reservas do restaurante Nuestra Casa\n");
        printf("Escolha uma opção:\n");
        printf("1 - Fazer Reserva\n");
        printf("2 - Listar Reservas\n");
        printf("3 - Total de Pessoas Por Dia\n");
        printf("4 - Sair\n");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1: {
                cont = fazerReserva(listaReservas, cont);
                break;
            }
            case 2: {
                listarReservas(listaReservas, cont);
                break;
            }
            case 3: {
                totalPessoasPorDia(listaReservas, cont);
                break;
            }
            case 4: {
                printf("Saindo...\n");
                break;
            }
            default: {
                printf("Opção inválida! Tente novamente.\n");
                system("pause");
                break;
            }
        }
    } while (opcao != 4);
    return 0;
}

// Função Fazer Reserva:
int fazerReserva(reserva listaReservas[], int cont) {
    int i;
    printf("================================\n");
    printf("Fazer Reserva\n");
    printf("Digite o Nome da Reserva:\n");
    fflush(stdin);
    gets(listaReservas[cont].nome);
    printf("Digite o CPF do cliente (apenas os números):\n");
    scanf("%d", &listaReservas[cont].cpf);
    printf("Digite o dia da reserva (1 - Quinta, 2 - Sexta, 3 - Sábado, 4 - Domingo):\n");
    scanf("%d", &listaReservas[cont].dia);
    printf("Digite a quantidade de Pessoas:\n");
    scanf("%d", &listaReservas[cont].qtdadePessoas);
    cont++;
    system("pause");
    return cont; 
}

// Procedimento Listar Reservas:
void listarReservas(reserva listaReservas[], int cont) {
    int i;

    if (cont == 0) {
        printf("Nenhuma reserva cadastrada.\n");
    } else {
        printf("Reservas cadastradas:\n");
        for (i = 0; i < cont; i++) {
            printf("================================\n");
            printf("Nome: %s\n", listaReservas[i].nome);
            printf("CPF: %d\n", listaReservas[i].cpf);
            printf("Dia: %d\n", listaReservas[i].dia);
            printf("Número de Pessoas: %d\n", listaReservas[i].qtdadePessoas);
        }
        printf("================================\n");
    }
    system("pause");
}

// Procedimento Total de pessoas por dia:
void totalPessoasPorDia(reserva listaReservas[], int cont) {
    int opcaodia, total = 0;
	int i;

    do {
        system("cls");
        printf("Escolha uma opção de dia para ver quantidade de pessoas:\n");
        printf("1 - Quinta\n");
        printf("2 - Sexta\n");
        printf("3 - Sábado\n");
        printf("4 - Domingo\n");
        printf("5 - Voltar\n");
        printf("Opção: ");
        scanf("%d", &opcaodia);
        total = 0;
        for (i = 0; i < cont; i++) {
            if (listaReservas[i].dia == opcaodia) {
                total += listaReservas[i].qtdadePessoas;
            }
        }
        switch (opcaodia) {
            case 1: {
                printf("Total de pessoas na quinta: %d\n", total);
                break;
            }
            case 2: {
                printf("Total de pessoas na sexta: %d\n", total);
                break;
            }
            case 3: {
                printf("Total de pessoas no sábado: %d\n", total);
                break;
            }
            case 4: {
                printf("Total de pessoas no domingo: %d\n", total);
                break;
            }
            case 5: {
                printf("Saindo...\n");
                break;
            }
            default: {
                printf("Opção inválida! Digite um número de 1 a 4 ou 5 para sair do menu.\n");
                break;
            }
        }
		system("pause");
    } while (opcaodia != 5);
}

