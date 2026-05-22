#include <stdio.h>
#include <string.h>

int main() {

    FILE *arquivo;

    int curso, aluno, materia;
    int totalAulas, faltas;
    int faltasPermitidas, frequencia, podeFaltar;

    int faltasArquivo;
    int novasFaltas;

    char nomeAluno[50];
    char nomeMateria[50];

    char linha[200];
    char alunoArquivo[50];
    char materiaArquivo[50];

    int encontrado = 0;

    printf("===== CURSOS =====\n");
    printf("1 - Ciencia da Computacao\n");
    printf("2 - Sistemas de Informacao\n");

    printf("\nEscolha um curso: ");
    scanf("%d", &curso);

    if(curso == 1) {

        printf("\nAlunos:\n");
        printf("1 - Eloah\n");
        printf("2 - Yasmin\n");
        printf("3 - Outro aluno\n");

        printf("\nEscolha o aluno: ");
        scanf("%d", &aluno);

        if(aluno == 1)
            strcpy(nomeAluno, "Eloah");

        else if(aluno == 2)
            strcpy(nomeAluno, "Yasmin");

        else if(aluno == 3) {

            printf("Digite o nome do aluno: ");
            scanf(" %[^\n]", nomeAluno);
        }

        else {

            printf("Opcao invalida!\n");
            return 0;
        }
    }

    else if(curso == 2) {

        printf("\nAlunos:\n");
        printf("1 - Lucas\n");
        printf("2 - Leonardo\n");
        printf("3 - Matheus\n");
        printf("4 - Outro aluno\n");

        printf("\nEscolha o aluno: ");
        scanf("%d", &aluno);

        if(aluno == 1)
            strcpy(nomeAluno, "Lucas");

        else if(aluno == 2)
            strcpy(nomeAluno, "Leonardo");

        else if(aluno == 3)
            strcpy(nomeAluno, "Matheus");

        else if(aluno == 4) {

            printf("Digite o nome do aluno: ");
            scanf(" %[^\n]", nomeAluno);
        }

        else {

            printf("Opcao invalida!\n");
            return 0;
        }
    }

    else {

        printf("Opcao invalida!\n");
        return 0;
    }


    printf("\nMaterias:\n");
    printf("1 - Fundamentos\n");
    printf("2 - Humanismo\n");
    printf("3 - Calculo\n");
    printf("4 - Programacao\n");
    printf("5 - Algoritmos\n");

    printf("\nEscolha a materia: ");
    scanf("%d", &materia);

    if(materia == 1) {

        totalAulas = 80;
        strcpy(nomeMateria, "Fundamentos");
    }

    else if(materia == 2) {

        totalAulas = 40;
        strcpy(nomeMateria, "Humanismo");
    }

    else if(materia == 3) {

        totalAulas = 80;
        strcpy(nomeMateria, "Calculo");
    }

    else if(materia == 4) {

        totalAulas = 80;
        strcpy(nomeMateria, "Programacao");
    }

    else if(materia == 5) {

        totalAulas = 80;
        strcpy(nomeMateria, "Algoritmos");
    }

    else {

        printf("Materia invalida!\n");
        return 0;
    }


    arquivo = fopen("relatorio.txt", "r");

    faltas = 0;

    if(arquivo != NULL) {

        while(fgets(linha, sizeof(linha), arquivo) != NULL) {

            if(sscanf(linha, "Aluno: %49[^\n]", alunoArquivo) == 1) {

                fgets(linha, sizeof(linha), arquivo);
                sscanf(linha, "Materia: %49[^\n]", materiaArquivo);

                fgets(linha, sizeof(linha), arquivo);

                fgets(linha, sizeof(linha), arquivo);
                sscanf(linha, "Faltas: %d", &faltasArquivo);

                if(strcmp(alunoArquivo, nomeAluno) == 0 &&
                   strcmp(materiaArquivo, nomeMateria) == 0) {

                    faltas = faltasArquivo;
                    encontrado = 1;
                }
            }
        }

        fclose(arquivo);
    }


    if(encontrado) {

        printf("\nAluno ja possui registro nesta materia.\n");
        printf("Faltas atuais: %d\n", faltas);

        printf("Quantas faltas deseja adicionar? ");
        scanf("%d", &novasFaltas);

        faltas += novasFaltas;
    }

    else {

        printf("\nDigite o numero de faltas: ");
        scanf("%d", &faltas);
    }


    faltasPermitidas = totalAulas * 25 / 100;

    frequencia = ((totalAulas - faltas) * 100) / totalAulas;

    podeFaltar = faltasPermitidas - faltas;

    
    printf("\n===== RELATORIO =====\n");

    printf("Aluno: %s\n", nomeAluno);
    printf("Materia: %s\n", nomeMateria);
    printf("Total de aulas: %d\n", totalAulas);
    printf("Faltas: %d\n", faltas);
    printf("Frequencia: %d%%\n", frequencia);

    if(podeFaltar > 0)
        printf("Ainda pode faltar %d aulas.\n", podeFaltar);

    else
        printf("Nao pode faltar mais!\n");


    arquivo = fopen("relatorio.txt", "a");

    if(arquivo == NULL) {

        printf("Erro ao abrir arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "\n---------------------------------\n");

    fprintf(arquivo, "Aluno: %s\n", nomeAluno);
    fprintf(arquivo, "Materia: %s\n", nomeMateria);
    fprintf(arquivo, "Total de aulas: %d\n", totalAulas);
    fprintf(arquivo, "Faltas: %d\n", faltas);
    fprintf(arquivo, "Frequencia: %d%%\n", frequencia);

    if(podeFaltar > 0)
        fprintf(arquivo, "Ainda pode faltar %d aulas.\n", podeFaltar);

    else
        fprintf(arquivo, "Nao pode faltar mais!\n");

    fclose(arquivo);

    printf("\nRelatorio salvo em relatorio.txt\n");

    return 0;
}
