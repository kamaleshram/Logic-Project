#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**Premise FB*/
int premise(char sl[][4][30], int n)
{
    if (sl[n][1][0] == 'P' || sl[n][1][0] == 'p')
        return 1;
    else
        return 0;
}

/**And Introduction FB*/
int andintro(char sl[][4][30], int n)
{
    int x = atoi(sl[n][2]) - 1;
    int y = atoi(sl[n][3]) - 1;

    if ((x<n) && (y<n))
    {
        printf("Inside main block");
        char s[30] = "";
        if (((n > x) && (n > y)) == 1)
        {
            strcpy(s, sl[x][0]);
            strcat(s, "^");
            strcat(s, sl[y][0]);
            if ((strcmp(sl[n][0], s)) == 0)
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }

    else
        return 0;
    
}

/**And elim 1*/
int andelim1(char sl[][4][30], int n)
{
    int y = atoi(sl[n][2]) - 1;
    if ((y<n))
    {
        char m[15]; /**a^b should be given this way (a^b)*/
        int a = strlen(sl[y][0]);
        int c = -1;
        int k = 0;
        int flag = 0;
        for (int j = 0; j < a; j++)
        {
            if ((sl[y][0][j]) == '(')
                k++;
            if ((sl[y][0][j]) == ')')
                k--;
            if ((sl[y][0][j]) == '^')
            {
                if (k == 1)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                c++;

                m[c] = sl[y][0][j + 1];
            }
        }
        m[c] = '\0';
        if (strcmp(m, sl[n][0]) == 0)
            return 1;
        else
        {
            return 0;
        }
    }

    else
        return 0;
}

/**And elim 2*/
int andelim2(char sl[][4][30], int n)
{
    int y = atoi(sl[n][2]) - 1;
    if ((y<n))
    {
        char p[15]; /**a^b should be given this way (a^b)*/
        int a = strlen(sl[y][0]);
        int d = -1;
        int k = 0;
        int flag = 0;
        for (int j = 0; j < a; j++)
        {
            if ((sl[y][0][j]) == '(')
                k++;
            if ((sl[y][0][j]) == ')')
                k--;
            if ((sl[y][0][j]) == '^')
            {
                if (k == 1)
                {
                    flag = 1;
                }
            }
            if (flag == 1)
            {
                d++;
                p[d] = sl[y][0][j + 1];
            }
        }
        p[d - 1] = '\0';
        printf("%s", p);
        if (strcmp(p, sl[n][0]) == 0)
            return 1;
        else
        {
            return 0;
        }
    }

    else
        return 0;
}
/**Or 1 Introduction*/
int orin1(char sl[][4][30], int n)
{
    int x = atoi(sl[n][2]) - 1;
    if ((x<n))
    {
        char s1[30];
        strcpy(s1, sl[x][0]);
        strcat(s1, "v");
        char *p = (strstr(sl[n][0], s1));
        if (p)
            return 1;
        else
            return 0;
    }

    else
        return 0;
}
/**Or 2 Introduction*/
int orin2(char sl[][4][30], int n)
{
    int x = atoi(sl[n][2]) - 1;
    if ((x<n))
    {
        char s2[30];
        strcpy(s2, "v");
        strcat(s2, sl[x][0]);
        char *p = (strstr(sl[n][0], s2));
        if (p)
            return 1;
        else
            return 0;
    }

    else
        return 0;
}
/**Implies Elimination*/
int impel(char sl[][4][30], int n)
{
    int x = atoi(sl[n][2]) - 1;
    int y = atoi(sl[n][3]) - 1;

    if ((x<n) && (y<n))
    {
        char z[30] = "(";
        strcat(z, sl[y][0]);
        strcat(z, ">");
        strcat(z, sl[n][0]);
        strcat(z, ")");

        if ((strcmp(z, sl[x][0])) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else
        return 0;
}

/**Modus Tollens*/
int mt(char sl[][4][30], int n)
{
    int x = atoi(sl[n][2]) - 1;
    int y = atoi(sl[n][3]) - 1;
    if ((x<n) && (y<n))
    {
        int k = 0;

        char p[30];
        char q[30];

        for (int i = 0;; i++)
        {
            p[i] = sl[y][0][i + 1];

            if (sl[y][0][i + 1] == '\0')
                break;
        }

        for (int i = 0;; i++)
        {
            q[i] = sl[n][0][i + 1];

            if (sl[n][0][i + 1] == '\0')
            {
                break;
            }
        }

        char z[30] = "(";
        strcat(z, q);
        strcat(z, ">");
        strcat(z, p);
        strcat(z, ")");

        if ((strcmp(z, sl[x][0])) == 0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    else
        return 0;
}

/**Rulefinder*/
int rulefinder(char sl[][4][30], int n)
{
    if (strcmp(sl[n][1],"P")==0){
        return 1;
    }

    else if (strcmp(sl[n][1],"^i")==0){
        return 2;
    }

    else if (strcmp(sl[n][1],"^e1")==0){
        return 3;
    }

    else if (strcmp(sl[n][1],"^e2")==0){
        return 4;
    }

    else if (strcmp(sl[n][1],"vi1")==0){
        return 5;
    }

    else if (strcmp(sl[n][1],"vi2")==0){
        return 6;
    }

    else if (strcmp(sl[n][1],">e")==0){
        return 7;
    }

    else if (strcmp(sl[n][1],"mt")==0){
        return 8;
    }

    else
    {
        return 0;
    }   
}
