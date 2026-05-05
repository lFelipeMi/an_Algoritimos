void q2()
{
    int i, n = 100;
    int v[100];

    for (i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            break;
        }
    }
}



void q2_expandida()
{
    int i;            // c1
    int n = 100;      // c2
    int v[100];       // c3

    for (i = 0; i < n; i++)   // c4 (inicialização) 
                              // + c5 (teste k+1 vezes) 
                              // + c6 (passo k vezes)
    {
        if (v[i] == 0)        // c7
        {
            break;            // c8
        }
    }
}

/*
FUNÇÃO DE CUSTO T(n)

FUNÇÃO DE CUSTO T(n)
T(n) = c1 + c2 + c3 + c4 + (k + 1)c5 + kc6 + kc7 + c8

onde k é o número de iterações executadas (1 ≤ k ≤ n)

PIOR CASO
Ocorre quando o break nunca é executado (nenhum elemento é 0), 
então k = n

T_pior(n) = c1 + c2 + c3 + c4 + (n + 1)c5 + nc6 + nc7

Simplificando:
T_pior(n) = an + b

MELHOR CASO
Ocorre quando v[0] == 0 (break na primeira iteração), então k = 1

T_melhor(n) = c1 + c2 + c3 + c4 + c5 + c6 + c7 + c8

Simplificando:
T_melhor(n) = b

ANÁLISE ASSINTÓTICA
Pior caso: T(n) ∈ O(n)
Melhor caso: T(n) ∈ Ω(1)

CONCLUSÃO

O algoritmo possui complexidade linear no pior caso 
e constante no melhor caso:
*/
