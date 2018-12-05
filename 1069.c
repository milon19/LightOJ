#include<stdio.h>

int main()
{
    int i, t, mypos, liftpos, door = 3, enterexit = 5, comemypos, ground, totaltime, temp;
    scanf("%d", &t);

    for(i = 1; i <= t; i++)
    {
        scanf("%d %d", &mypos, &liftpos);
        if(liftpos > mypos)
            comemypos = (liftpos - mypos)*4;
        else
            comemypos = (mypos - liftpos)*4;
        ground = mypos*4;
        totaltime = comemypos + (3*door) + (2*enterexit) + ground;
        printf("Case %d: %d\n", i, totaltime);
    }
    return 0;
}
