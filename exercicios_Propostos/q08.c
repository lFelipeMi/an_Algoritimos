void q08(int n) {
  int i, j;

  for (i = 0; i < n; i++) {
    for (j = 0; j < i * i; j++) {
    }
  }
}

void q08_expandida(int n) {
  int i, j; // c1

  for (i = 0; i < n; i++) // c2 (inicialização: 1 vez)
                          // c3 (teste: n + 1 vezes)
                          // c4 (passo: n vezes)
  {
    for (j = 0; j < i * i; j++) // c5 (inicialização: n vezes)
                                // c6 (teste: no máximo n^3/3 + n vezes)
                                // c7 (passo: aproximadamente n^3/3 vezes)
    {
      // c8 (corpo: aproximadamente n^3/3 vezes)
    }
  }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando que o loop externo roda n vezes (de 0 a n-1).
O loop interno roda de 0 a i^2 - 1 a cada iteração de i.
A quantidade total de vezes que o loop interno executa é a
soma de i^2 para i = 0 até n-1.
Essa soma quadrática é igual a (n-1)*n*(2n-1)/6.
Descartando os termos de menor grau, ela é dominada por n^3 / 3.

T(n) = c1 + c2 + (n + 1)c3 + nc4 + nc5 + (n^3/3 + n)c6 + (n^3/3)c7 + (n^3/3)c8

T(n) = a*n^3 + b*n^2 + c*n + d

Este valor é fixo para um dado tamanho de n. Não há melhor/pior
caso baseando-se no conteúdo da entrada.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*n^3 + b*n^2 + c*n + d → O(n^3)
- Melhor caso: T(n) = a*n^3 + b*n^2 + c*n + d → Ω(n^3)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(n^3)
- Big Ω: Ω(n^3)
- Big Θ: Θ(n^3)

Portanto, o algoritmo possui crescimento polinomial cúbico.
=========================================================================
*/
