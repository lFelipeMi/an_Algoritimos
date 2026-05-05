void q12(int n)
{
    int i = 1, count = 0;

    while (i < n)
    {
        i *= 3;
        count++;
    }
}

void q12_expandida(int n)
{
    int i = 1, count = 0;         // c1

    while (i < n)                 // c2 (teste: log3(n) + 1 vezes)
    {
        i *= 3;                   // c3 (corpo: log3(n) vezes)
        count++;                  // c4 (corpo: log3(n) vezes)
    }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
A variável iteradora 'i' inicia como 1 e é multiplicada por 3 a cada
iteração do laço while, que só para quando 'i' alcança (ou passa) o
valor 'n'. Isso significa que a quantidade de execuções do laço é o 
número x tal que 3^x = n, ou seja, x ≈ log base 3 de n.

T(n) = c1 + (log3(n) + 1)c2 + log3(n)c3 + log3(n)c4

T(n) = a*log3(n) + b

ANÁLISE ASSINTÓTICA
=========================================================================
Como bases de logaritmo não importam no Big O devido à mudança de base
por fator constante constante t (log3(n) = log2(n) / log2(3)):
- Pior caso: T(n) = a*log(n) + b → O(log n)
- Melhor caso: T(n) = a*log(n) + b → Ω(log n)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(log n)
- Big Ω: Ω(log n)
- Big Θ: Θ(log n)

Portanto, o algoritmo possui crescimento logarítmico.
========================================================================= 
*/
