#include <stdio.h>

void figures(int column_number, int row_number, int tab[][row_number], char c, int spawn)
{
    int i;
    i = 0;

    if(c=='K')
    {
        while(tab[spawn][i+1]==0 && tab[spawn+1][i+1] == 0 && i+1 < row_number)
        {
            i++;
        }

        tab[spawn][i] = 1;
        tab[spawn+1][i] = 1;
        tab[spawn][i-1] = 1;
        tab[spawn+1][i-1] = 1;

    } else if(c=='T')
    {
        while(tab[spawn+1][i+1]==0 && tab[spawn][i] == 0 && tab[spawn+2][i] == 0 && i+1 < row_number)
        {
            i++;
        }

        tab[spawn][i-1] = 1;
        tab[spawn+1][i-1] = 1;
        tab[spawn+1][i] = 1;
        tab[spawn+2][i-1] = 1;

    } else if(c=='I')
    {
        while(tab[spawn][i+1]==0 && i+1 < row_number)
        {
            i++;
        }

        tab[spawn][i]=1;
        tab[spawn][i-1]=1;
        tab[spawn][i-2]=1;
        tab[spawn][i-3]=1;

    } else if(c=='F')
    {
        i++;
        while(tab[spawn][i+1] == 0 && tab[spawn+1][i-1] == 0 && i+1<row_number)
        {
            i++;
        }

        tab[spawn][i] = 1;
        tab[spawn][i-1] = 1;
        tab[spawn][i-2] = 1;
        tab[spawn+1][i-2] = 1;

    } else if(c=='W')
    {
        //while(tab[spawn][i+1] == 0 && tab[spawn+1][i+1] == 0 && tab[spawn+2][i+1] == 0 i+1<row_number)
        while(tab[spawn][i+1] == 0 && tab[spawn+1][i+1] == 0 && tab[spawn+2][i+1] == 0 && tab[spawn+3][i+1] == 0 && tab[spawn+4][i+1] == 0 && i+1 < row_number)
        {
            i++;
        }

        tab[spawn][i] = 1;
        tab[spawn+1][i] = 1;
        tab[spawn+2][i] = 1;
        tab[spawn+3][i] = 1;
        tab[spawn+4][i] = 1;
        tab[spawn][i-1] = 1;
        tab[spawn][i-2] = 1;
        tab[spawn+2][i-1] = 1;
        tab[spawn+2][i-2] = 1;
        tab[spawn+4][i-1] = 1;
        tab[spawn+4][i-2] = 1;
    }

    i = 0;
}


void lower(int column, int row, int tab[][row], int position)
{
    //to lower the whole board above position

    int limit = 0;
    limit = position; //position is the number of the full row

    //zero'ing the position row
    for(int i=0; i<column; i++)
    {
        tab[i][position] = 0;
    }

    while(limit > 0)
    {
        for(int i=0; i<column; i++)
        {
            tab[i][limit] = tab[i][limit - 1];
        }
        limit--;
    }

    for(int i=0; i<column; i++)
    {
        tab[i][0] = 0;
    }
}


void clear_full_lines(int column, int row, int tab[][row])
{
    int flag;
    flag = 1;

    for(int i=0; i<row; i++)
    {
        flag = 1;
        for(int j=0; j<column; j++)
        {
            if(tab[j][i] == 0)
            {
                flag = 0;
            }
        }
        if(flag == 1)
        {
            lower(column, row, tab, i);
        }
    }

}


int main()
{
    int column;
    int row;
    int x;
    char c;

    int k=0;

    scanf("%d %d %d", &column, &row, &k);
    int tab[column][row];
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            tab[j][i] = 0;
        }
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", tab[j][i]);
        }
        printf("\n");
    }

    //scanf("%d", &x);
    for(int i=0; i<k; i++)
    {
        c = getchar();
        scanf("%c %d", &c, &x);
        figures(column, row, tab, c, x);
    }

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", tab[j][i]);
        }
        printf("\n");
    }
/*
    tab[3][4] = 1;
    lower(column, row, tab, 5);

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            printf("%d ", tab[j][i]);
        }
        printf("\n");
    }
*/

    return 0;
}
