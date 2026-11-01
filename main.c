
#include <stdio.h>
#include <string.h>

int main() {

    FILE *arquivo;

    int curso, aluno, materia;
    int totalAulas, faltas;
    int faltasPermitidas, frequencia, podeFaltar;

    int faltasArquivo;
    int novasFaltas;
    int encontrado = 0;

    char nomeAluno[50];
    char nomeMateria[50];

    char linha[200];
    char alunoArquivo[50] = "";
    char materiaArquivo[50] = "";

    printf("===== CURSOS =====\n");
    printf("1 - Ciencia da Computacao\n");
    printf("2 - Sistemas de Informacao\n");

    printf("\nEscolha um curso: ");

    if (scanf("%d", &curso) != 1) {
        printf("Entrada invalida!\n");
        return 1;
    }

    if (curso == 1) {

        printf("\nAlunos:\n");
        printf("1 - Eloah\n");
        printf("2 - Yasmin\n");
        printf("3 - Outro aluno\n");

        printf("\nEscolha o aluno: ");

        if (scanf("%d", &aluno) != 1) {
            printf("Entrada invalida!\n");
            return 1;
        }

        if (aluno == 1)
            strcpy(nomeAluno, "Eloah");

        else if (aluno == 2)
            strcpy(nomeAluno, "Yasmin");

        else if (aluno == 3) {

            printf("Digite o nome do aluno: ");
            scanf(" %49[^\n]", nomeAluno);
        }

        else {
            printf("Opcao invalida!\n");
            return 1;
        }
    }

    else if (curso == 2) {

        printf("\nAlunos:\n");
        printf("1 - Lucas\n");
        printf("2 - Leonardo\n");
        printf("3 - Matheus\n");
        printf("4 - Outro aluno\n");

        printf("\nEscolha o aluno: ");

        if (scanf("%d", &aluno) != 1) {
            printf("Entrada invalida!\n");
            return 1;
        }

        if (aluno == 1)
            strcpy(nomeAluno, "Lucas");

        else if (aluno == 2)
            strcpy(nomeAluno, "Leonardo");

        else if (aluno == 3)
            strcpy(nomeAluno, "Matheus");

        else if (aluno == 4) {

            printf("Digite o nome do aluno: ");
            scanf(" %49[^\n]", nomeAluno);
        }

        else {
            printf("Opcao invalida!\n");
            return 1;
        }
    }

    else {
        printf("Opcao invalida!\n");
        return 1;
    }

    printf("\n===== MATERIAS =====\n");
    printf("1 - Fundamentos\n");
    printf("2 - Humanismo\n");
    printf("3 - Calculo\n");
    printf("4 - Programacao\n");
    printf("5 - Algoritmos\n");

    printf("\nEscolha a materia: ");

    if (scanf("%d", &materia) != 1) {
        printf("Entrada invalida!\n");
        return 1;
    }

    if (materia == 1) {
        totalAulas = 80;
        strcpy(nomeMateria, "Fundamentos");
    }

    else if (materia == 2) {
        totalAulas = 40;
        strcpy(nomeMateria, "Humanismo");
    }

    else if (materia == 3) {
        totalAulas = 80;
        strcpy(nomeMateria, "Calculo");
    }

    else if (materia == 4) {
        totalAulas = 80;
        strcpy(nomeMateria, "Programacao");
    }

    else if (materia == 5) {
        totalAulas = 80;
        strcpy(nomeMateria, "Algoritmos");
    }

    else {
        printf("Materia invalida!\n");
        return 1;
    }

    // Consulta os registros anteriores

    arquivo = fopen("relatorio.txt", "r");

    if (arquivo != NULL) {

        while (fgets(linha, sizeof(linha), arquivo) != NULL) {

            if (sscanf(linha, "Aluno: %49[^\n]", alunoArquivo) == 1) {
                continue;
            }

            if (sscanf(linha, "Materia: %49[^\n]", materiaArquivo) == 1) {
                continue;
            }

            if (sscanf(linha, "Faltas: %d", &faltasArquivo) == 1) {

                if (strcmp(alunoArquivo, nomeAluno) == 0 &&
                    strcmp(materiaArquivo, nomeMateria) == 0) {

                    faltas = faltasArquivo;
                    encontrado = 1;
                }
            }
        }

        fclose(arquivo);
    }

    // Verifica se o aluno ja possui registro

    if (encontrado) {

        printf("\nAluno ja possui registro nesta materia.\n");
        printf("Faltas atuais: %d\n", faltas);

        printf("Quantas faltas deseja adicionar? ");

        if (scanf("%d", &novasFaltas) != 1 || novasFaltas < 0) {
            printf("Quantidade invalida!\n");
            return 1;
        }

        faltas += novasFaltas;
    }

    else {

        printf("\nDigite o numero de faltas: ");

        if (scanf("%d", &faltas) != 1 || faltas < 0) {
            printf("Quantidade invalida!\n");
            return 1;
        }
    }

    // Calcula a frequencia e as faltas permitidas

    faltasPermitidas = totalAulas * 25 / 100;

    frequencia = ((totalAulas - faltas) * 100) / totalAulas;

    if (frequencia < 0)
        frequencia = 0;

    podeFaltar = faltasPermitidas - faltas;

    if (podeFaltar < 0)
        podeFaltar = 0;

    // Exibe o relatorio

    printf("\n===== RELATORIO =====\n");

    printf("Aluno: %s\n", nomeAluno);
    printf("Materia: %s\n", nomeMateria);
    printf("Total de aulas: %d\n", totalAulas);
    printf("Faltas: %d\n", faltas);
    printf("Frequencia: %d%%\n", frequencia);
    printf("Limite de faltas: %d\n", faltasPermitidas);

    if (podeFaltar > 0)
        printf("Ainda pode faltar %d aulas.\n", podeFaltar);

    else if (faltas == faltasPermitidas)
        printf("Voce atingiu o limite de faltas!\n");

    else
        printf("Voce ultrapassou o limite de faltas!\n");

    // Salva o relatorio no arquivo

    arquivo = fopen("relatorio.txt", "a");

    if (arquivo == NULL) {
        printf("\nErro ao abrir arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "\n---------------------------------\n");
    fprintf(arquivo, "===== RELATORIO DE FALTAS =====\n");
    fprintf(arquivo, "Aluno: %s\n", nomeAluno);
    fprintf(arquivo, "Materia: %s\n", nomeMateria);
    fprintf(arquivo, "Total de aulas: %d\n", totalAulas);
    fprintf(arquivo, "Faltas: %d\n", faltas);
    fprintf(arquivo, "Frequencia: %d%%\n", frequencia);
    fprintf(arquivo, "Limite de faltas: %d\n", faltasPermitidas);

    if (podeFaltar > 0)
        fprintf(arquivo, "Ainda pode faltar %d aulas.\n", podeFaltar);

    else if (faltas == faltasPermitidas)
        fprintf(arquivo, "Voce atingiu o limite de faltas!\n");

    else
        fprintf(arquivo, "Voce ultrapassou o limite de faltas!\n");

    fclose(arquivo);

    printf("\nRelatorio salvo em relatorio.txt\n");

    return 0;
}
