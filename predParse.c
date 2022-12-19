#include<stdio.h>
#include<string.h>
char prod[20][20],c[20][20],fol[20][20],NT[10];
int n,x=0,ntc=0,f=0;
int pt[20][20];

void first(char a,int z)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(prod[i][0]==a)
        {
            if(!isupper(prod[i][2])||prod[i][2]=='`')
            {
                c[z][x++]=prod[i][2];
            }
            if(isupper(prod[i][2]))
            {
                first(prod[i][2],z);
            }
        }
    }
}

void firstfol(char a,int z)
{
    int i;

    for(i=0;i<n;i++)
    {
        if(prod[i][0]==a)
        {
            if(prod[i][2]=='`')
            {
                f=1;
            }
            if(!isupper(prod[i][2])&&prod[i][2]!='`')
            {
                fol[z][x++]=prod[i][2];
            }
            if(isupper(prod[i][2])&&prod[i][2]!='`')
            {
                firstfol(prod[i][2],z);
            }
        }
    }
}
void follow(char a,int z)
{
    int i,j,wc=0;

    if(z==0)
    fol[z][x++]='$';
    for(i=0;i<n;i++)
    {
         for(j=2;j<strlen(prod[i]);j++)
        {
            if(prod[i][j]==a)
            {
                f=0;
                if(!isupper(prod[i][j+1]))
                    fol[z][x++]=prod[i][j+1];
                if(j+1<strlen(prod[i]))
                {
                    firstfol(prod[i][j+1],z);
                    wc=1;
                    while(f==1)
                    {
                        f=0;
                        if(!isupper(prod[i][j+1+wc]))
                            fol[z][x++]=prod[i][j+2];
                        else
                            firstfol(prod[i][j+1+wc],z);
                    }
                    }
                else
                {
                    follow(prod[i][0],z);
                    }
            }
        }
    }
}

void main()
{
    int i,j,k,tc=0;
    char T[10];

    printf("Enter the number of productions");
    scanf("%d",&n);
    for (i=0;i<n;i++)
    {
        printf("Enter production %d : ",i+1);
        scanf("%s",&prod[i]);
    }

    printf("Enter Terminal Symbol %d : ",i+1);
    scanf("%s",&T);
    tc=strlen(T);
    for(i=0;i<n;i++)
    {
        for(j=0;j<ntc;j++)
        {
            if(prod[i][0]==NT[j])
            {
                break;
            }
        }
        if(ntc==j)
        {
            NT[ntc++]=prod[i][0];
        }
    }


    for(i=0;i<ntc;i++)
    {
        first(NT[i],i);
        x=0;
        follow(NT[i],i);
        x=0;

    }

    for(i=0;i<tc;i++)
    {
        printf("\t%c",T[i]);
    }
    printf("\n",T[i]);
    for(i=0;i<n;i++)
    {
        for (j=0;j<tc;j++)
        {

        }
    }
}
