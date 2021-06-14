#include <stdio.h>


int ehPrimo(int n)
{
    int i, ehPrimo = -2;
    for(i=n - 1; i > 1 && ehPrimo == -2; i--)
    {
        if(n % i == 0)
            ehPrimo = 0;
    }
    return ehPrimo;
}

int proximoPrimo(int n)
{
    /*if( ehPrimo(n + 1) == -2 )
    {
        return n+1;
    }
    else
    {
        return proximoPrimo(n + 1);
    }*/
    int i, primo = 0;
    for(i=n + 1; primo == 0; i++)
    {
        if( ehPrimo(i) == -2 )
        {
            primo = 1;
            break;
        }
    }
    return i;
}

int calcularMDC(int x, int y, int divisor)
{
    int novoDivisor = divisor, novoX = 0, novoY = 0; 
    if(x == 1 && y == 1)
    {   
        return 1;
    }
    if((y % divisor) == 0)
    {
        novoY = 1;
        y = y / divisor;
    }
    if((x % divisor) == 0)
    {
        novoX = 1;
        x = x / divisor;
    }
    if((novoX == 1) && (novoY == 1))
    {   
        novoDivisor = 2;
        return divisor * calcularMDC(x, y, novoDivisor);
    }
    else
    {   
        if((novoX == 0) && novoY == 0)
            novoDivisor = proximoPrimo(divisor);
        return 1 * calcularMDC(x, y, novoDivisor);
    }
}

int main()
{
    int x, y, mdc = 0;
    scanf("%d%d", &x,&y);
    mdc =  calcularMDC(x, y, 2);
    printf("%d\n", mdc);
}