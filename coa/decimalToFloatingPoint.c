//   Decimal to Floating point.
//   Floating point are of two types..
//     1) Single Precision.
//     2) Double Precision.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *floatBinary(float f)
{
    float res;
    int f1;
    int t = 4;
    static int ans[4];
    int z = 0;
    while (t--)
    {
        res = f * 2;
        f1 = (int)res;
        ans[z++] = f1;
        f = res - f1;
    }
    for(int i = 0; i < 4; i++)
        printf("%d", ans[i]);
}

int decimalToBinary(int n)
{

    int bin[32], i = 0;
    while (n > 0)
    {
        bin[i] = n % 2;
        n = n / 2;
        i++;
    }
    int result = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        result = result * 10 + bin[j];
    }
    return result;
}

void show(int a[], int n, int special)
{
    if (special == 1)
    {
        n = n - 1;
    }
    for (int i = n; i >= 0; i--)
    {
        printf("%d", a[i]);
    }
}

int main()
{

    float num;
    int integral;
    printf("enter a decimal number: ");
    scanf("%f", &num);

    integral = (int)num;
    num = num - integral;
    printf("%d %f\n", integral, num);

    int a[1000];
    int z = 0;
    while (integral > 0)
    {
        a[z++] = integral % 2;
        integral = integral / 2;
    }
    show(a, z - 1, 0);
    printf("\n");

    int count = z - 1;
    printf("count = %d\n", count);
    int exponentSingle = 127 + (count);
    int exponentDouble = 1023 + (count);
    printf("%d %d\n", exponentSingle, exponentDouble);

    printf("This is in Single Precision..\n");
    int E = decimalToBinary(exponentSingle);
    printf(" 0 | %d | ", E);
    show(a, z - 1, 1);
    floatBinary(num);

    printf("\n\nThis is in double precision..");
    int b[1000];
    z = 0;
    while (exponentDouble > 0)
    {
        b[z++] = exponentDouble % 2;
        exponentDouble /= 2;
    }
    printf("\n 0 | ");
    show(b, z - 1, 0);
    printf(" | ");
    show(a, z - 1, 1);
    floatBinary(num);
}
