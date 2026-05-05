void q07(int n)
{
    int i, j;

    for (i = n; i > 0; i /= 2)
    {
        for (j = i; j > 0; j /= 2)
        {
        }
    }
}

void q07_expandida(int n)
{
    int i, j;                     // c1

    for (i = n; i > 0; i /= 2)    // c2 (inicialização: 1 vez)
                                  // c3 (teste: log2(n) + 1 vezes)
                                  // c4 (passo: log2(n) vezes)
    {
        for (j = i; j > 0; j /= 2)  // c5 (inicialização: log2(n) vezes)
                                    // c6 (teste: log2(n)*(log2(n)+1)/2 vezes, aproximado)
                                    // c7 (passo: log2(n)*(log2(n)+1)/2 vezes)
        {
                                    // c8 (corpo: log2(n)*(log2(n)+1)/2 vezes)
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Considerando o loop de fora que reduz i dividindo por 2, de n até > 0, 
isso ocorre aproximadamente log2(n) vezes.
O loop interno divide j por 2 também, de i até > 0. A cada iteração 
do loop principal, a variável i vale n, depois n/2, n/4... 
Logo, o loop interno ocorre log2(i) vezes para cada i.
Uma soma de log2(n) + (log2(n)-1) + ... + 1 nos dá
(log2(n) * (log2(n)+1)) / 2 iterações completas do loop interno,
o que é aproximadamente log2(n)^2 / 2 = O((log n)^2).

T(n) = a*(log(n))^2 + b*log(n) + c

Esta quantidade de operações não altera para o mesmo n.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = a*(log(n))^2 + b*log(n) + c → O((log n)^2)
- Melhor caso: T(n) = a*(log(n))^2 + b*log(n) + c → Ω((log n)^2)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O((log n)^2)
- Big Ω: Ω((log n)^2)
- Big Θ: Θ((log n)^2)

Portanto, o algoritmo possui crescimento polilogarítmico de grau 2.
========================================================================= 
*/
