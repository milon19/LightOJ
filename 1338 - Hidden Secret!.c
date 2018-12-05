#include<stdio.h>

int main()
{
    int i, t;
    scanf("%d", &t);
    char str1[100], str2[100];
    for(i = 1; i <= t; i++)
    {
        scanf(" %[^\n]s", str1);
        scanf(" %[^\n]s", str2);

        int j, s1[26] = {0}, s2[26] = {0};

        for(j = 0; str1[j] != '\0'; j++)
        {
            if(str1[j] >= 'A' && str1[j] <= 'Z')
                s1[str1[j] - 'A']++;
            else if(str1[j] >= 'a' && str1[j] <= 'z')
                s1[str1[j] - 'a']++;

        }
        for(j = 0; str2[j] != '\0'; j++)
        {
            if(str2[j] >= 'A' && str2[j] <= 'Z')
                s2[str2[j] - 'A']++;
            else if(str2[j] >= 'a' && str2[j] <= 'z')
                s2[str2[j] - 'a']++;
        }
        int flag = 0;

        for(j = 0; j < 26; j++)
        {
            if(s1[j] != s2[j])
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            printf("Case %d: Yes\n", i);
        else
            printf("Case %d: No\n", i);
    }

    return 0;
}
