void q02(int n) {
  for (int i = 2 * n; i > 0; i--) {
    for (int j = 0; j < i; j++) {
    }
  }
}

void q02_expandida(int n) {
  for (int i = 2 * n; i > 0; i--) // c1  (inicialização: 1 vez)
                                  // c2 (teste: 2n + 1 vezes)
                                  // c3 (passo: 2n vezes)
  {
    for (int j = 0; j < i; j++) // c4 (inicialização: 2n vezes)
                                // c5 (teste: 2n^2 + 3n vezes)
                                // c7 (passo: 2n^2 + n vezes)
    {
      // c8 (corpo interno: 2n^2 + n vezes)
    }
  }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando iteradores e laços:
- For externo (i):
    - Inicialização: c2
    - Teste: (2n + 1) * c3
    - Passo: 2n * c4
    - Corpo:
        - For interno (j): Loop executado i vezes para cada iteração do externo.
            Total de execuções do corpo é a soma de i=1 até 2n de i, que
            é (2n * (2n + 1)) / 2 = 2n^2 + n.
            - Inicialização: 2n * c5
            - Teste: (2n^2 + 3n) * c6
            - Passo: (2n^2 + n) * c7
            - Corpo: (2n^2 + n) * c8

T(n) = c1 + c2 + (2n + 1)c3 + 2nc4 + 2nc5 + (2n^2 + 3n)c6 + (2n^2 + n)c7 + (2n^2
+ n)c8

T(n) = a*n^2 + b*n + c

Neste caso, não há variação condicional dentro dos loops que altere a
quantidade de execuções. O melhor e o pior caso são o mesmo.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*n^2 + b*n + c  → O(n^2)
- Melhor caso: T(n) = a*n^2 + b*n + c → Ω(n^2)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n^2)
- Big Ω: Ω(n^2)
- Big Θ: Θ(n^2)

Portanto, o algoritmo possui crescimento polinomial quadrático.
=========================================================================
*/
