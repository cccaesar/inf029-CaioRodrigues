#include <stdio.h>

int Multip_Rec(int n1, int n2)
{   
    if(n2 == 0)
        return 0;
    else if( n2 > 0 )
        return n1 + Multip_Rec(n1, n2 - 1);
    else
        return n1 + Multip_Rec(n1, n2 + 1);
}

int mudarValor(int n1, int n2)
{
    if( (n1 * n2) < 0)
    {
        return -1 * Multip_Rec(n1, n2);
    }
    else
        return Multip_Rec(n1, n2);
}


int main()
{
    int op1, op2, produto;
    scanf("%d%d",&op1, &op2);
    produto = mudarValor(op1, op2);
    printf("%d\n", produto);
}