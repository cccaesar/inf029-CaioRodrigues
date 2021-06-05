#include <stdio.h>
#include <stdlib.h>

int sequenciaDeFibonacci(int t)
{
    if( t < 2)
        return t;
    else
        return sequenciaDeFibonacci(t - 1) + sequenciaDeFibonacci(t - 2);
}


int main()
{
    int x;
    scanf("%d", &x);
    x = sequenciaDeFibonacci(x);
    printf("%d\n", x);
}