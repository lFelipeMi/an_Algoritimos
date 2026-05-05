void q9()
{
    int i, j, n = 100;

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
        }
    }
}

void q9_expandida()
{
    int i;            // c1
    int j;            // c2
    int n;            // c3
    n = 100;          // c4

    for (i = 0; i < n; i++)       // c5 (inicialização 1 vez)
                                   // + c6 (teste n+1 vezes)
                                   // + c7 (passo n vezes)
    {
        for (j = i + 1; j < n; j++)   // c8 (inicialização 1 vez)
                                       // + c9 (teste n-i vezes)
                                       // + c10 (passo n-i-1 vezes)
        {
            // corpo vazio
        }
    }
}

/*

Observação:
O laço interno depende de i.

Para cada i:
j varia de (i+1) até (n-1)

Quantidade de execuções do laço interno:
(n - i - 1)

-------------------------
SOMATÓRIO DO LAÇO INTERNO
-------------------------

EXEMPLO de iterações do laço interno

for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++);

Exemplo n = 5:
i=0 → j=1,2,3,4  (4)
i=1 → j=2,3,4    (3)
i=2 → j=3,4      (2)
i=3 → j=4        (1)
i=4 → não entra  (0)

Total de execuções: 4+3+2+1+0 = 10

Generalização: n(n-1)/2

REPRESENTAÇÃO Triangular do laço interno (n = 5)

Tabela onde '*' representa execução do laço interno:

i\j | 0 | 1 | 2 | 3 | 4
----|---|---|---|---|---
0   |   | * | * | * | *
1   |   |   | * | * | *
2   |   |   |   | * | *
3   |   |   |   |   | *
4   |   |   |   |   |   

TOTAL de iterações:

∑(i=0 até n-1) (n - i - 1)

= (n-1) + (n-2) + ... + 1 + 0
= n(n-1)/2


FUNÇÃO DE CUSTO T(n)
T(n) = c1 + c2 + c3 + c4
     + c5 + (n+1)c6 + n c7
     + Σ_{i=0}^{n-1} [ c8 + (n-i)c9 + (n-i-1)c10 ]

PIOR CASO
Todos os laços percorridos completamente:

T_pior(n) = c1 + c2 + c3 + c4
          + c5 + (n+1)c6 + n c7
          + Σ_{i=0}^{n-1} [ c8 + (n-i)c9 + (n-i-1)c10 ]

MELHOR CASO
Não há condições que alterem iterações, então:

T_melhor(n) = T_pior(n) = n(n+1)/2 + c

ANÁLISE ASSINTÓTICA

Σ_{i=0}^{n-1} (n-i) ≈ n(n-1)/2 → O(n^2)

T(n) ∈ O(n^2)
T(n) ∈ Ω(n^2)

CONCLUSÃO

O algoritmo possui complexidade quadrática no pior e melhor caso
*/