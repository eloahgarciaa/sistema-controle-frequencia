#include <stdio.h>

int main() {

    FILE *arquivo;

    int curso, aluno, materia;
    int totalAulas, faltas;
    int faltasPermitidas, frequencia, podeFaltar;

    char nomeAluno[50];
    char nomeMateria[50];

    printf("===== CURSOS =====\n");
    printf("1 - Ciencia da Computacao\n");
    printf("2 - Sistemas de Informacao\n");

    printf("\nEscolha um curso: ");
    scanf("%d", &curso);


    if(curso == 1) {

        printf("\nAlunos:\n");
        printf("1 - Eloah\n");
        printf("2 - Yasmin\n");

        printf("\nEscolha o aluno: ");
        scanf("%d", &aluno);

        if(aluno == 1) sprintf(nomeAluno, "Eloah");
        else sprintf(nomeAluno, "Yasmin");
    }

    else if(curso == 2) {

        printf("\nAlunos:\n");
        printf("1 - Lucas\n");
        printf("2 - Leonardo\n");
        printf("3 - Matheus\n");

        printf("\nEscolha o aluno: ");
        scanf("%d", &aluno);

        if(aluno == 1) sprintf(nomeAluno, "Lucas");
        else if(aluno == 2) sprintf(nomeAluno, "Leonardo");
        else sprintf(nomeAluno, "Matheus");
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
        sprintf(nomeMateria, "Fundamentos");
    }
    else if(materia == 2) {
        totalAulas = 40;
        sprintf(nomeMateria, "Humanismo");
    }
    else if(materia == 3) {
        totalAulas = 80;
        sprintf(nomeMateria, "Calculo");
    }
    else if(materia == 4) {
        totalAulas = 80;
        sprintf(nomeMateria, "Programacao");
    }
    else if(materia == 5) {
        totalAulas = 80;
        sprintf(nomeMateria, "Algoritmos");
    }
    else {
        printf("Materia invalida!\n");
        return 0;
    }

    printf("\nDigite o numero de faltas: ");
    scanf("%d", &faltas);

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

    fprintf(arquivo, "\n---------------------------------\n");

    fprintf(arquivo, "===== RELATORIO DE FALTAS =====\n");
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