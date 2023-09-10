//Carson Gedeus

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXSIZE 8

typedef struct
{
 char cell [4];
 int standard;
} aut;

void convchar(int size, char arr[], int array[]);
void firstgen(int size, int array[]);
void cellstruct(int size, int array[],aut detail[]);
int conv(int a, int b, int c,aut detail[]);
int  main()
{
    int automata, count, stimulate, newstate, left,middle,right;
    int i, j, k, l;
    char started[250]; 
    int num[250];
    char goes[250];
    int normal_num[8];
    int N_Cells[250];
    aut detail[MAXSIZE];

    strcpy(detail[0].cell,"111");
    strcpy(detail[1].cell,"110");
    strcpy(detail[2].cell,"101");
    strcpy(detail[3].cell,"100");
    strcpy(detail[4].cell,"011");
    strcpy(detail[5].cell,"010");
    strcpy(detail[6].cell,"001");
    strcpy(detail[7].cell,"000");


    scanf("%d",&automata);


    for(i=0;i<automata;i++)
    {
        scanf("%d %d", &stimulate, &count); //input
        scanf("%s", started);

        convchar(count,started,num);
        printf("Automata #%d:\n", i+1);

        firstgen(count,num);
            scanf("%s", goes);

            convchar(8, goes,normal_num);

        cellstruct(MAXSIZE, normal_num,detail);

        if(stimulate>0)
        {
            for(j=0;j<stimulate;j++)
            {
                for(k=0;k<count;k++)
                {
                    if(k==0)
                    {
                        left   = num[count-1];
                        middle = num[k];
                        right  = num[k+1];
                        newstate = conv(left,middle,right,detail);
                        N_Cells[k] = newstate;
                    }
                     if(k == count-1)
                    {
                        left   = num[k-1];
                        middle = num[k];
                        right  = num[k-k];
                        newstate = conv(left,middle,right,detail);
                        N_Cells[k] = newstate;
                    }
                    if(k>0 && k!=count-1)
                    {
                            left   = num[k-1];
                            middle = num[k];
                            right  = num[k+1];
                            newstate = conv(left,middle,right,detail);
                            N_Cells[k] = newstate;
                    }
                }
                firstgen(count, N_Cells);
                for(l=0; l<count; l++)
                        {
                            num[l]=N_Cells[l];
                        }
            }
        }
        printf("\n");
    }
}
void convchar(int size, char arr[], int array[])
{
    int i;
    for(i=0;i<size;i++)
    {
        array[i] = arr[i] - '0';
    }
}
void firstgen(int size, int array[])
{
    int i;
    for(i=0;i<size;i++)
    {
        if(array[i]==0)
            printf(".");
        if(array[i]==1)
            printf("#");
    }
    printf("\n");
}
void cellstruct(int size, int array[],aut detail[])
{
    int i;
    for(i=0;i<size;i++)
    {
        detail[i].standard=array[i];
    }
}
  int conv(int a, int b, int c,aut detail[]) {  //All necessary cases
    if      (a == 1 && b == 1 && c == 1)
    {
        return detail[0].standard;
    }
    else if (a == 1 && b == 1 && c == 0)
    {
        return detail[1].standard;
    }
    else if (a == 1 && b == 0 && c == 1)
    {
        return detail[2].standard;
    }
    else if (a == 1 && b == 0 && c == 0)
    {
        return detail[3].standard;
    }
    else if (a == 0 && b == 1 && c == 1)
    {
        return detail[4].standard;
    }
    else if (a == 0 && b == 1 && c == 0)
    {
        return detail[5].standard;
    }
    else if (a == 0 && b == 0 && c == 1)
    {
        return detail[6].standard;
    }
    else if (a == 0 && b == 0 && c == 0)
    {
        return detail[7].standard;
    }
    return 0;
  }
