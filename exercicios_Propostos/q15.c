void q15(int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            continue;
        }
        else
        {
            break;
        }
    }
}

void q15_expandida(int n)
{
    int i;                        // c1

    for (i = 0; i < n; i++)       // c2 (inicialização: 1 vez)
                                  // c3 (teste: no máximo 2 vezes)
                                  // c4 (passo: no máximo 1 vez)
    {
        if (i % 2 == 0)           // c5 (teste: no máximo 2 vezes)
        {
            continue;             // c6 (quando i=0, 1 vez)
        }
        else
        {
            break;                // c7 (quando i=1, executado e sai)
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
Qualquer que seja o N > 1, o laço de iteração ocorre da seguinte forma:
Para i = 0: entra no if (0 % 2 == 0), executa continue e vai pra próxima.
Para i = 1: entra no else (1 % 2 != 0), executa break e sai da repetição.
Para qualquer N <= 0, o laço nem inicia.
Portanto, a estrutura de controle RODA NO MÁXIMO 2 VEZES 
independentemente do valor de N.

T(n) = c1 + c2 + c3+ c4 + c5 + c6 + c7
T(n) = C (uma constante)

A complexidade é sempre constante.

ANÁLISE ASSINTÓTICA
=========================================================================
- Pior caso: T(n) = c → O(1)
- Melhor caso: T(n) = c → Ω(1)

CONCLUSÃO
=========================================================================
A complexidade do algoritmo é:
- Big O: O(1)
- Big Ω: Ω(1)
- Big Θ: Θ(1)

Portanto, o algoritmo possui crescimento constante.
========================================================================= 
*/
