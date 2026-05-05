void q6()
{
    int i, n = 100;

    for (i = n; i > 0; i = i / 2)
    {
    }
}

void q6_expandida()
{
    int i;            // c1
    int n;            // c2
    n = 100;          // c3

    for (i = n; i > 0; i = i / 2)   // c4 (inicialização 1 vez) 
                                     // + c5 (teste log2(n)+1 vezes) 
                                     // + c6 (passo log2(n) vezes)
    {
        // corpo vazio
    }
}

/*
______________________________________________
CONSTATAÇÃO

O algoritmo possui crescimento logarítmico 
devido à divisão por 2 a cada iteração.

Laço:
- Teste: i > 0 → 
    executa aproximadamente log2(n) + 1 vezes → (log2(n) + 1)*c4
- Passo (i = i / 2): 
    executa log2(n) vezes → log2(n)*c5
- Corpo: log2(n) vezes → log2(n)*c6

FUNÇÃO DE CUSTO T(n)
T(n) = c1 + c2 + c3 
     + c4 + (log2(n)+1)c5 + (log2(n))c6

PIOR CASO
O laço é executado até i ≤ 1:

T_pior(n) = c1 + c2 + c3 
          + c4 + (log2(n)+1)c5 + (log2(n))c6

MELHOR CASO
Não há condições que alterem o número de iterações, então:

T_melhor(n) = T_pior(n) = a log2(n) + b

ANÁLISE ASSINTÓTICA

T(n) ∈ O(log n)
T(n) ∈ Ω(log n)

CONCLUSÃO

O algoritmo possui complexidade logarítmica 
tanto no melhor quanto no pior caso
*/