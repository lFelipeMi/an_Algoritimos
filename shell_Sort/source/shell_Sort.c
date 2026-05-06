void shell_sort(int *v, int n) {
  int i;    // c1
  int j;    // c2
  int gap;  // c3
  int temp; // c4

  for (gap = n / 2; gap > 0; gap /= 2) // c5 (inicialização)
                                       // c6 (teste)
                                       // c7 (passo)
  {
    for (i = gap; i < n; i++) // c8 (inicialização)
                              // c9 (teste)
                              // c10 (passo)
    {
      temp = v[i]; // c11
      for (j = i; j >= gap && v[j - gap] > temp;
           j -= gap) // c12 (inicialização)
                     // c13 (teste)
                     // c14 (passo)
      {
        v[j] = v[j - gap]; // c15
      }
      v[j] = temp; // c16
    }
  }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando que a análise exata depende da sequência de incrementos (gaps).
Para a sequência clássica de Shell (n/2, n/4, ..., 1), temos que o laço externo
executa aproximadamente log2(n) vezes.
O laço do meio executa (n - gap) vezes para cada gap. Chamaremos a soma
dessas execuções de S, onde S ≈ n * log2(n).

- Inicializações: c1 + c2 + c3 + c4
- For (gap):
    - Inicialização: c5
    - Teste: (log n + 1) * c6
    - Passo: (log n) * c7
- For (i):
    - Inicialização: (log n) * c8
    - Teste: (S + log n) * c9
    - Passo: S * c10
    - Corpo (temp = v[i] e v[j] = temp): S * c11 + S * c16
- For (j):
    - Inicialização: S * c12
    - Teste: depende da condição (chamaremos de X * c13)
    - Passo: depende da condição (chamaremos de Y * c14)
    - Corpo: depende da condição (chamaremos de Y * c15)

PIOR CASO (Vetor configurado de forma adversa):
--------------------------------------------------
Ocorre quando os elementos não se misturam nos gaps pares (ex: maiores nas
posições pares e menores nas ímpares), forçando um número massivo de trocas
apenas no último gap (gap = 1), comportando-se como um Insertion Sort O(n^2).
Neste cenário, as variáveis X e Y de repetição do laço mais interno
crescem proporcionalmente a n^2.

T_pior(n) =
    c1 + c2 + c3 + c4 + c5
    + (log n + 1)c6 + (log n)c7 + (log n)c8
    + (S + log n)c9 + S(c10 + c11 + c12 + c16)
    + (n^2)c13 + (n^2)c14 + (n^2)c15

T_pior(n) = a*n^2 + b*n*log(n) + c*log(n) + d

MELHOR CASO (Vetor já ordenado):
--------------------------------------------------
Quando o vetor está ordenado, a condição `v[j - gap] > temp` falha
logo na primeira verificação do laço mais interno.
Portanto, o laço `j` executa seu teste exatamente S vezes, mas nunca
executa seu passo nem seu corpo (Y = 0 e X = S).

T_melhor(n) =
    c1 + c2 + c3 + c4 + c5
    + (log n + 1)c6 + (log n)c7 + (log n)c8
    + (S + log n)c9 + S(c10 + c11 + c12 + c16)
    + S*c13

T_melhor(n) = a*n*log(n) + b*log(n) + c

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*n^2 + ...  → O(n^2)
- Melhor caso: T(n) = a*n*log(n) + ... → Ω(n log n)

(Obs: Devido ao último gap = 1, frequentemente a base teórica de
limite inferior em definições mais generalistas é tratada como Ω(n)).

CONCLUSÃO
=========================================================================
A complexidade do algoritmo Shell Sort (com gaps divididos por 2) é:
- Big O: O(n^2)
- Big Ω: Ω(n log n)

Portanto, o algoritmo possui crescimento quadrático no pior caso e
crescimento linearítmico no melhor caso para a sequência clássica de Shell.
=========================================================================
*/
