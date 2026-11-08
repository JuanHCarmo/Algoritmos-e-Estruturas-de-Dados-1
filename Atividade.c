/*

Exercício 1

A)  A complexidade de tempo assintótica da função imprimirPadrao no pior caso é $O(N^2)$.   

B)No laço externo, a variável $i$ varia de $0$ até $N - 1$. Para cada valor fixo de $i$, o laço interno executa a instrução printf("*"); exatamente $i$ vezes (com $j$ variando de $0$ até $i - 1$).   
A quantidade total de vezes que printf("*"); é executada é a soma do número de iterações do laço interno para cada passo de $i$:
    Para $i = 0$: executa $0$ vezes
    Para $i = 1$: executa $1$ vez 
    Para $i = 2$: executa $2$ vezes 
    Para $i = N - 1$: executa $N - 1$ vezes

Exercício 2

int encontrarIndice(int vetor[], int tamanho, int elemento) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return i; // Retorna o índice da primeira ocorrência
        }
    }
    return -1; // Elemento não encontrado
}


a) Complexidade: $O(1)$ (tempo constante).
Cenário: Ocorre quando o elemento procurado está logo na primeira posição do array (vetor[0]). O laço executa apenas $1$ comparação e já retorna o resultado

b)Complexidade: $O(N)$ (tempo linear), onde $N$ é o tamanho do array.
Cenário e Justificativa: Ocorre quando o elemento não está presente no array ou está na última posição (vetor[N-1]). Nesse caso, a função precisa percorrer todo o vetor, realizando exatamente $N$ comparações dentro do laço for até determinar se retorna o índice ou $-1$. 

Exercício 3

a)A complexidade de tempo da função funcaoMisteriosa é $O(\log N)$. 

b)A variável $i$ é inicializada com o valor $N$ e, a cada iteração do laço, seu valor é dividido por $2$ (i = i / 2)
Se $N = 64:
1ª iteração: $i = 64 (contador = 1) 
2ª iteração: $i = 32 (contador = 2)   
3ª iteração: $i = 16 (contador = 3)
4ª iteração: $i = 8 (contador = 4)
5ª iteração: $i = 4 (contador = 5)
6ª iteração: $i = 2 (contador = 6)
7ª iteração: $i = 1 (contador = 7)
Próximo passo: $i = 1 / 2 = 0$ $\rightarrow$ sai do laço


Exercício 4

a)(Ingênua - Força Bruta)
bool possuiComum_v1(int vetorA[], int tamA, int vetorB[], int tamB) {
    for (int i = 0; i < tamA; i++) {
        for (int j = 0; j < tamB; j++) {
            if (vetorA[i] == vetorB[j]) {
                return true;
            }
        }
    }
    return false;
}

b)(Otimizada - Ordenação + Dois Ponteiros)

int comparar(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool possuiComum_v2(int vetorA[], int tamA, int vetorB[], int tamB) {
    // Ordena ambos os vetores em O(N log N) e O(M log M)
    qsort(vetorA, tamA, sizeof(int), comparar);
    qsort(vetorB, tamB, sizeof(int), comparar);

    int i = 0, j = 0;
    // Percorre ambos os vetores ordenados simultaneamente em O(N + M)
    while (i < tamA && j < tamB) {
        if (vetorA[i] == vetorB[j]) {
            return true;
        } else if (vetorA[i] < vetorB[j]) {
            i++;
        } else {
            j++;
        }
    }
    return false;
}

c)Versão 1: Possui dois laços aninhados. No pior caso, compara cada elemento de $A$ com todos os elementos de $B$, resultando em $N \times M$ comparações. A complexidade de tempo é $O(N \cdot M)$ (ou $O(N^2)$ caso $N \approx M$).

Versão 2: A ordenação dos vetores usando algoritmos eficientes (como Quicksort) custa $O(N \log N + M \log M)$. O percurso subsequente com dois ponteiros leva tempo linear $O(N + M)$. A complexidade total é $O(N \log N + M \log M)$.


Exercício 5

a)Analisando a função com três laços for sequenciais
O 1º laço executa $N$ vezes
O 2º bloco possui dois laços aninhados, executando $N \times N = N^2$ vezes
O 3º laço executa $N$ vezes.   
O número total de operações é dado por $T(N) = N + N^2 + N = N^2 + 2N$.
Na Notação Big O, consideramos apenas o termo de maior grau ($N^2$), logo a complexidade teórica é $O(N^2)$. 



b)

ong long contarOperacoes(int N) {
    long long contador = 0; // Variável acumuladora acumulando todas as operações

    // Passo 1: O(N)
    for (int i = 0; i < N; i++) {
        contador++;
    }

    // Passo 2: O(N^2)
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            contador++;
        }
    }

    // Passo 3: O(N)
    for (int i = 0; i < N; i++) {
        contador++;
    }

    return contador;
}

int main() {
    int testes[] = {10, 50, 100, 200};
    int numTestes = sizeof(testes) / sizeof(testes[0]);

    printf("N\t| Total de Operacoes Contadas (N^2 + 2N)\n");
    printf("----------------------------------------\n");

    for (int k = 0; k < numTestes; k++) {
        int N = testes[k];
        long long total = contarOperacoes(N);
        printf("%d\t| %lld\n", N, total);
    }

    return 0;
}

Para N = 10: 10^2 + 2(10) = 100 + 20 = 120

Para N = 50: 50^2 + 2(50) = 2500 + 100 = 2600

Para N = 100: 100^2 + 2(100) = 10000 + 200 = 10200

Para N = 200: 200^2 + 2(200) = 40000 + 400 = 40400

c)Sim, os resultados empíricos são totalmente consistentes com a análise teórica. O número de operações calculadas empiricamente segue a equação exata $N^2 + 2N$. Conforme $N$ aumenta (de 10 para 200), o termo $N^2$ passa a dominar quase completamente o valor final (por exemplo, em $N=200$, $N^2 = 40.000$ representa $99\%$ de todas as operações), confirmando assintoticamente o comportamento quadrático $O(N^2)$.
*/