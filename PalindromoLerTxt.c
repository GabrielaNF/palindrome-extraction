#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

// Funcao para gerar todos as string que sao palindromos potenciais.
void gerarPalindromo(char *s, int n, bool pal[n][n]) {
    // Inicializa o palindromo na matriz
    for (int i = 0; i < n; i++) {
        pal[i][i] = true;
    }

    // iteracoes para diferentes tamanhos de substrings
    for (int tam = 2; tam <= n; tam++) {
        for (int i = 0; i <= n - tam; i++) {
            // Calcula a posicao final da substring
            int j = i + tam - 1;

            // Verifica se os caracteres nas posicoes de inicio e fim sao iguais e se a substring entre eles e um palindromo ou um unico caractere.
            if (s[i] == s[j] && (tam == 2 || pal[i + 1][j - 1])) {
                // Marca a substring de i a j como um palindromo
                pal[i][j] = true;
            }
        }
    }
}

// Funcao para mostrar a string com os cortes
void imprimirStringCortada(char *s, int indicesCortes[], int n) {
    printf("String Cortada: ");
    // Usa uma pilha para armazenar a string cortada
    char pilha[n * 2]; // Tamanho em dobro para armazenar os '|'
    int top = -1;
    int idx = n - 1;
    while (idx >= 0) {
        if (indicesCortes[idx] != -1) {
            for (int i = indicesCortes[idx] + 1; i <= idx; i++) {
                pilha[++top] = s[i];
            }
            pilha[++top] = '|';
            idx = indicesCortes[idx];
        } else {
            for (int i = 0; i <= idx; i++) {
                pilha[++top] = s[i];
            }
            break;
        }
    }
    // Imprime o que tem na pilha desempilhando
    while (top >= 0) {
        printf("%c", pilha[top--]);
    }
    printf("\n");
}

// Funcao para calcular o numero minimo de cortes necessarios para tornar todas as substrings de 's' palindromicas
int minCortes(char *s) {
    if (s == NULL || *s == '\0')
        return 0;
    int n = strlen(s);

    // Matriz 2D para armazenar se a substring [i, j] e um palindromo
    bool pal[n][n];
    memset(pal, 0, sizeof(pal));

    gerarPalindromo(s, n, pal);

    // Matriz para armazenar os cortes minimos necessarios para tornar a substring [0, i] um palindromo
    int minCortesMatriz[n];
    for (int i = 0; i < n; i++) {
        minCortesMatriz[i] = INT_MAX;
    }

    // Nao e necessario cortar para um unico caractere, pois ele sempre e um palindromo
    minCortesMatriz[0] = 0;

    // Array para armazenar os indices dos cortes
    int indicesCortes[n];
    memset(indicesCortes, -1, sizeof(indicesCortes));

    // Iterar sobre a string fornecida
    for (int i = 1; i < n; i++) {
       // Verificar se a string de 0 a i e um palindromo. Entao o numero minimo de cortes sera 0.
        if (pal[0][i]) {
            minCortesMatriz[i] = 0;
        } else {
            for (int j = i; j >= 1; j--) {
                // Se s[i] e s[j] forem iguais e a substring interna [i+1, j-1] for um palindromo ou tiver um tamanho de 1
                if (pal[j][i]) {
                    // Atualizar o numero minimo de cortes necessarios se cortar na posicao 'j+1' resultar em um valor menor
                    if (minCortesMatriz[j - 1] + 1 < minCortesMatriz[i]) {
                        minCortesMatriz[i] = minCortesMatriz[j - 1] + 1;
                        indicesCortes[i] = j - 1;
                    }
                }
            }
        }
    }

    // Imprimir a string particionada com cortes
    imprimirStringCortada(s, indicesCortes, n);

    // Retornar o numero minimo de cortes necessarios para toda a string 's'
    return minCortesMatriz[n - 1];
}

int main() {
    clock_t inicio = clock();

    
    // Abre o txt de texto
    FILE *txt;
    txt = fopen("exemplos_strings.txt", "r");
    
    // Verifica se o txt foi aberto corretamente
    if (txt == NULL) {
        fprintf(stderr, "Erro ao abrir o txt.\n");
        return 1;
    }
    
    // Loop para ler cada linha do txt
    char linha[100];
    while (fgets(linha, sizeof(linha), txt) != NULL) {
        // Remove o caractere de nova linha, se houver
        linha[strcspn(linha, "\n")] = 0;
        
        // Calcula e imprime os cortes para a string atual
        int cortes = minCortes(linha);
        printf("String: %s\n", linha);
        printf("Minimo de cortes: %d\n\n", cortes);
    }
    
    // Fecha o txt
    fclose(txt);

    double tempoFinal = (double)(clock() - inicio) / CLOCKS_PER_SEC;
    printf("Tempo total: %f segundos\n", tempoFinal);

    system("Pause");
    return 0;
}
