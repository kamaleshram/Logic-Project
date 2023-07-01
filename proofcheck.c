#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.c" 

/**Main Function*/
int main()
{
    int n;
    printf("Enter the no. of lines in the proof to be given: ");
    scanf("%d", &n);
    char lines[n][30];
    for (int i = 0; i < n; i++)
    {
        scanf("%s", lines[i]);
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("Value at %dth line is %s\n", i+1, lines[i]);
    }

    char sl[n][4][30];

    for (int i = 0; i < n; i++)
    {
        int g = -1;
        for (int j = 0; j < 4; j++)
        {
            int x = -1;
            while (1)
            {
                g++;
                x++;
                if (lines[i][g] == '\0')
                {
                    sl[i][j][x] = '\0';
                    break;
                }
                else if (lines[i][g] == '/')
                {

                    sl[i][j][x] = '\0';
                    break;
                }
                else
                {
                    sl[i][j][x] = lines[i][g];
                }
            }
            if (lines[i][g] == '\0')
            {
                break;
            }
        }
    }

    printf("\n");
    for (int i=0; i<n; i++)
    {
        switch(rulefinder(sl, i))
        {
            case 1:
                if(premise(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;

            case 2:
                if(andintro(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;

            case 3:
                if(andelim1(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;

            case 4:
                if(andelim2(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;

            case 5:
                if(orin1(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;

            case 6:
                if(orin2(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;

            case 7:
                if(impel(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;

            case 8:
                if(mt(sl, i)){
                    continue;
                }
                else
                {
                    printf("Line number:  %d is not valid", i+1);
                    return 0;
                }
            break;
        }      
    }

    printf("Given proof of sequent is VALID");
}