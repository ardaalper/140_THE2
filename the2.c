#include <stdio.h>
#include <stdlib.h>
void fillstar(char *input,int col, int r,int c);
void filldot(char *input,int col, int r,int c);
void filler(char *input, int row, int col, int r, int c);
void dottostar(char *input, int row, int col);


int main(void)
{    
    char *input;
    char temp='\0';
    char **map;
    int i,j,k,col,row,total,x,y;
    int incol,inrow;

    scanf("%d %d\n",&x,&y);
    incol=x;
    inrow=y;
                            /*tek satırlık input alımı*/
    input = (char*)malloc(1 * sizeof(char));
    i=0;
    while (1)
    {   
        temp=getchar();
        if (!(temp==' '||temp=='X'||temp=='\n'))
            break;
        else
        {
            input[i]=temp;
            input = (char*) realloc(input,sizeof(char)*(i+2));
        }
        i++;
    }
    total=i;


        /*mapin sizelarını kontrol etme*/
    i=0;
    while (1)
    {
        if (input[i]=='X' || input[i]==' ')
            i++;
        else
            break;
    }
    col=i+1;
    row=total/col;
    
        /*doldurma*/
    filler(input,row,col,inrow,incol);
    dottostar(input,row,col);
    for (i=0;i<row;i++)
    {
        for (j=0;j<col-1;j++)
        {

            printf("%c",input[i*col+j]);
        }
        printf("\n");
    }
    
    return 0;
}

void fillstar(char *input,int col, int r,int c)
{
    input[r*col+c]='*';
}
void filldot(char *input,int col, int r,int c)
{
    input[r*col+c]='.';
}
/*****/
void filler(char *input, int row, int col, int r, int c) 
{
    int i=1;
    if (input[r * col + c] == ' ')
        filldot(input, col, r, c);
    else
        i=0;
    
    while (i)
    {
        if (r-1 >= 0)
            filler(input, row, col, r - 1, c);

        if (r+1 < row) 
            filler(input, row, col, r + 1, c);

        if(c-1 >= 0) 
            filler(input, row, col, r, c - 1);

        if(c+1 < col-1)
            filler(input, row, col, r, c + 1);  
        i=0;
    }
}

void dottostar(char *input, int row, int col)
{
    int flag=0;
    int i,j;

    for (i=0;i<row;i++)
    {
        if (input[i*col+0]=='.')
        {
            flag=1;
            break;
        }
    }

    for (i=0;i<row;i++)
    {
        if (input[i*col+(col-2)]=='.')
        {
            flag=1;
            break;
        }
    }

    for (i=0;i<col-1;i++)
    {
        if (input[0*col+i]=='.')
        {
            flag=1;
            break;
        }
    }

    for (i=0;i<col-1;i++)
    {
        if (input[(row-1)*col+i]=='.')
        {
            flag=1;
            break;
        }
    }

    if (flag)
    {
        for (i=0;i<row;i++)
        {
            for (j=0;j<col-1;j++)
            {
                if(input[i*col+j]=='.')
                    input[i*col+j]='*';
            }
        }
    }
}
