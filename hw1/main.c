#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdlib.h>

int min(int a, int b)
{
    return a < b ? a : b;
}

int is_palindrome(char *s, int l, int r)
{
    while (l < r)
        if (s[l++] != s[r--])
            return 0;
    return 1;
}

int divide_and_conquer(char *s, int i, int j)
{
    if (*s == '\0')
        return 0;

    if (i == j || is_palindrome(s, i, j))
        return 1;

    int m = INT_MAX;
    for (int k = i; k < j; k++)
        m = min(m, divide_and_conquer(s, i, k) + divide_and_conquer(s, k + 1, j));

    return m;
}

int dynamic_programming(char *s)
{
    int len = strlen(s);
    int **mem = calloc(sizeof(int *), len);
    for (int i = 0; i < len; i++)
        mem[i] = calloc(sizeof(int), len);

    for (int i = 0; i < len; i++)
        mem[i][i] = 1;

    for (int l = 2; l <= len; l++)
    {
        for (int i = 0; i <= len - l; i++)
        {
            int j = i + l - 1;
            mem[i][j] = INT_MAX;
            if (is_palindrome(s, i, j))
                mem[i][j] = 1;
            else
                for (int k = i; k < j; k++)
                    mem[i][j] = min(mem[i][j], mem[i][k] + mem[k + 1][j]);
        }
    }

    int ans = mem[0][len - 1];
    for (int i = 0; i < len; i++)
        free(mem[i]);
    free(mem);

    return ans;
}

int main(int argc, char **argv)
{
    assert(argc == 2);

    printf("%d\n", dynamic_programming(argv[1]));

    return 0;
}
