#include <stdio.h>
#include <stdlib.h>


long long convert (int n)
{
    long long bin;
    int rem;
    int i;

    rem = 1;
    i = 1;
    bin = 0;

    while (n != 0)
    {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

int ft_strlen (char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
        i++;
    return (i);
}

long long int *str_to_bin (char *s)
{
    int k;
    int i;
    long long int *res;

    k = ft_strlen (s);
    i = 0;
    res = (long long int *)malloc(sizeof (long long int) * k);
    while (i < k)
    {
        res[i] = convert ((int) (s[i]));
        i++;
    }
    return (res);
}

int main ()
{
    char str[] = "Hello world!";
    long long *res;

    res = str_to_bin(str);
    

}

