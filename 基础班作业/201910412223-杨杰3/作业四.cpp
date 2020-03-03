#include<stdio.h>
#include<string.h>

#define N 100

int main()
{
    while (1)
    {
        char num[N];
        fgets(num, sizeof(num), stdin);
        int len = strlen(num);
        int point = 0;
        for (int i = 0; i < len; i++)
        {
            if (num[i] == '.')
            {
                point = i;
                break;
            }
            point = len - 1;
        }
        int first = 0;
        for (int j = 0; j < len; j++)
        {
            if (num[j] != '0' && num[j] != '.')
            {
                first = j;
                break;
            }
        }
        if (point < first)//小于1
        {
            if (first == (len - 2)) printf("%ce%d\n", num[first], 1 - first);
            else {
                num[first - 1] = num[first];
                num[first] = '.';
                for (int i = first - 1; i < len - 1; i++)
                {
                    printf("%c", num[i]);
                }
                printf("e%d\n", 1 - first);
            }
        }
        else {//大于1
            if (point == 1)
            {
                for (int i = 0; i < len - 1; i++)
                {
                    printf("%c", num[i]);
                }
                printf("e0\n");
            }
            else {
                for (int j = 0; j < len - 1; j++)
                {
                    if (j == 0) printf("%c.", num[j]);
                    else if (j == point) continue;
                    else printf("%c", num[j]);
                }
                printf("e%d\n", point - 1);
            }
        }
    }
    return 0;
}