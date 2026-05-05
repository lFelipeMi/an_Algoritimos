void q16(int n)
{
    int i, sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += i;

        if (sum > 10)
        {
            break;
        }
    }
}

void q16_expandida(int n)
{
    int i, sum = 0;               // c1

    for (i = 0; i < n; i++)       // c2 (inicialização: 1 vez)
                                  // c3 (teste: <= 6 vezes)
                                  // c4 (passo: <= 5 vezes)
    {
        sum += i;                 // c5 (corpo: <= 6 vezes)

        if (sum > 10)             // c6 (teste: <= 6 vezes)
        {
            break;                // c7 (corpo: no máximo 1 vez)
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)
=========================================================================
O laço roda enquanto a soma sum for menor ou igual a 10.
Analisando iterativamente:
i=0: sum=0
i=1: sum=1
i=2: sum=3
i=3: sum=6
i=4: sum=10
i=5: sum=15 -> Condição de break acionada.

O laço sempre faz ATÉ 6 iterações, não importando quão 
grande seja N. Para N pequenos (como n=2), ele faz n iterações
e termina. De qualquer forma, ele é limitado superiormente por 6.

T(n) <= c1 + c2 + 6*c3 + 5*c4 + 6*c5 + 6*c6 + c7
T(n) <= C (constante superior estrita)

O tempo de execução não escala junto com n ao infinito.

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
