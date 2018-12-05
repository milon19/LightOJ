#include<stdio.h>
#include<string.h>



int main()
{
    int i, t, j;
    scanf("%d", &t);
    char str[100][50], test[50];
    strcpy(str[0], "http://www.lightoj.com/");
    for(i = 1; i <= t; i++)
    {
        for(j = 1; j < 100; j++)
            strcpy(str[j], "Ignored");
        char cmd[6];
        int ind = 0;
        printf("Case %d:\n", i);
        while(scanf("%s", &cmd) == 1)
        {
            if(strcmp(cmd, "QUIT") == 0)
                break;
            if(strcmp(cmd, "VISIT") == 0)
            {
                ind++;
                //printf("----Ind: %d\n", ind);
                scanf("%s", &test);
                strcpy(str[ind], test);
                printf("%s\n", str[ind]);
                for(j = ind + 1; j < 100; j++)
                    strcpy(str[j], "Ignored");
            }
            else if(strcmp(cmd, "BACK") == 0)
            {
                ind--;
                //printf("----Ind: %d\n", ind);
                if(ind < 0)
                {
                    printf("Ignored\n");
                    ind = 0;
                }
                else
                    printf("%s\n", str[ind]);
            }
            else if(strcmp(cmd, "FORWARD") == 0)
            {
                if(ind < 0)
                    ind = 0;
                ind++;
                //printf("----Ind: %d\n", ind);
                printf("%s\n", str[ind]);
                if(strcmp(str[ind], "Ignored") == 0)
                    ind--;
            }
        }
    }

    return 0;
}
