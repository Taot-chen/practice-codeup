#include <cstdio>
int main()
{
    for (int a = 1; a <= 9; a++)
        {
        for (int b = 1; b <= 9; b++)
        {
            for (int c = 0; c <= 9; c++)
            {
                if (a * 100 + b * 10 + c + b * 100 + c * 10 + c == 532)
                {
                    printf("%d %d %d\n", a, b, c);
                }
            }
        }
    }
}
