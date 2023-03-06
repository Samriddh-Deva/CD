
#include<stdio.h>
#include<string.h>
int a[100][3],ns,fs;

int input()
{   int c=0,n=1,n1,n2;
    printf("Enter the number of states");
    scanf("%d",&ns);
    printf("Enter the final state ");
    scanf("%d",&fs);
    printf(": -1 Ends the input \n\nEnter the transitions in format:\ncurrent_state input next_state\n");
    while(n!=-1)
    {
        scanf("%d %d %d",&n1,&n,&n2);
        if(n==-1)
            break;
        a[c][0]=n1;
        a[c][1]=n;
        a[c++][2]=n2;
    }
        return c;
}

int tt[20][3];
int f[20][3];
int ts[50];

void Mark_zero()
{
    int i;
    for(i=0;i<20;i++)
    {
        tt[i][0]=-1;
        tt[i][1]=-1;
        tt[i][2]=-1;
        f[i][0]=-1;
        f[i][1]=-1;
        f[i][2]=-1;
    }
    for(i=0;i<50;i++)
    {
        ts[i]==-1;
    }
}

int add_state(int a,int b)
{
    int ret,r,f;


    if(a==-1&&b==-1)
    {
        return -1;
    }
    else if(a==-1&&b!=-1)
        {return b;}
    else if(a!=-1&&b==-1)
        {return a;}
    else
    {
        ret=a;
        do
        {
        ret=(ret*10)+(b%10);
        b=b/10;
    }while(b!=0);

    return ret;
    }
}

void traverse(int c)
{
    int i;
    for(i=0;i<c;i++)
    {
        if(a[i][1]==0||a[i][1]==1)
        {
            if(tt[a[i][0]][a[i][1]]==-1)
            {
                tt[a[i][0]][a[i][1]]=a[i][2];
            }
            else
            tt[a[i][0]][a[i][1]]=add_state(tt[a[i][0]][a[i][1]],a[i][2]);
        }
    }
}

void display()
{
    int i;
    printf("CS\t0\t1\n");
    for(i=0;i<ns;i++)
    {
        //printf("%d",ns);
        printf("q%d\t",i);
        if(tt[i][0]==-1)
            printf("-\t");
        else
        printf("{%d}\t",tt[i][0]);
        if(tt[i][1]==-1)
            printf("-\n");
        else
        printf("{%d}\n",tt[i][1]);
    }
}

int simplify(int x)
{
    int a[20],n,r,c=0,i,j,temp,f=0,c2,size;
    char str[50];

    n=x;
    sprintf(str,"%d",n);
    size=strlen(str);
    do{
            r=n%10;
            a[c++]=r;
            size--;
            n=n/10;

    }while(n!=0);

    if(size!=0)
    {
        a[c++]=0;
        c2=c+1;
    }
    else
     c2=c;
    for(i=0;i<c;i++)
    {
        for(j=i+1;j<c;j++)
        {
            if(a[i]==a[j])
            {
                a[j]=-1;
                c2-=1;
            }
        }
    }
    for(i=0;i<c;i++)
    {
        for(j=0;j<c-i-1;j++)
        {
            if(a[j]<a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
        }
    }
    for(i=0;i<c2;i++)
    {
        f=(f*10)+a[i];
    }
    if(x==-1)
        return -1;
    else
        return f;

}

int convert()
{
    int c=0,fv=-1,i,r,n,w,j,size;
    char str[20];
    f[0][0]=0;
    f[0][1]=simplify(tt[0][0]);
    f[0][2]=simplify(tt[0][1]);

    if(f[0][1]!=0)
    {
        ts[c++]=f[0][1];
    }
    if(f[0][2]!=0)
    {
        ts[c++]=f[0][2];
    }

    for(i=0;i<c;i++)
    {

        n=ts[i];
        f[i+1][0]=n;
        sprintf(str,"%d",n);
        size=strlen(str);
        do
        {
            r=n%10;
            size--;
            if(f[i+1][1]==0)
                f[i+1][1]=add_state(tt[r][0],f[i+1][1]);
            else
                f[i+1][1]=add_state(f[i+1][1],tt[r][0]);
            if(f[i+1][2]==0)
                f[i+1][2]=add_state(tt[r][1],f[i+1][2]);
            else
                f[i+1][2]=add_state(f[i+1][2],tt[r][1]);
            n=n/10;
        }while(n!=0);


        if(size!=0)
        {
            if(tt[0][0]!=-1)
                f[i+1][1]=add_state(f[i+1][1],tt[0][0]);
            if(tt[0][1]!=-1)
                f[i+1][2]=add_state(f[i+1][2],tt[0][1]);
        }
        if(f[i+1][1]!=-1)
            f[i+1][1]=simplify(f[i+1][1]);
        if(f[i+1][2]!=-1)
            f[i+1][2]=simplify(f[i+1][2]);

        fv=-1;
        for(j=0;j<c;j++)
        {
            if(f[i+1][1]!=0)
            {
                if(f[i+1][1]==ts[j])
                {
                    fv=0;
                    break;
                }
            }
        }

        if(fv==-1&&f[i+1][1]!=-1&&f[i+1][1]!=0)
        {
            ts[c++]=f[i+1][1];
        }

        fv=-1;
        for(j=0;j<c;j++)
        {
            if(f[i+1][2]!=0)
            {
                if(f[i+1][2]==ts[j])
                {
                    fv=0;
                    break;
                }
            }
        }
        if(fv==-1&&f[i+1][2]!=-1&&f[i+1][2]!=0)
        {
            ts[c++]=f[i+1][2];
        }
    }
    return c;

}


void display2(int c)
{
    int i,flag,n;
    printf("CS\t0\t1\n");
    for(i=0;i<=c;i++)
    {
        flag=0;
        n=f[i][0];
        do
        {
            if(n%10==fs)
                flag=1;
            n=n/10;
        }while(n!=0);
        if(flag==0)
            printf("q");
        if(flag==1)
            printf("*q");
        if(f[i][0]==-1)
            printf("[D]\t");
        else
        printf("{%d}\t",f[i][0]);
        if(f[i][1]==-1)
            printf("[D]\t");
        else
        printf("{%d}\t",f[i][1]);
        if(f[i][2]==-1)
            printf("[D]\n");
        else
        printf("{%d}\n",f[i][2]);
        //printf("q%d\t{%d}\t{%d}\n",i,f[i][0],f[i][1]);
    }
}
void display3(int c)
{
    int i,flag,n;
    printf("CS\t\t0\t1\n");
    for(i=0;i<=c;i++)
    {
        flag=0;
        n=f[i][0];
        do
        {
            if(n%10==fs)
                flag=1;
            n=n/10;
        }while(n!=0);
        if(flag==0)
            printf("q");
        if(flag==1)
            printf("*q");


        if(f[i][0]==-1)
            printf("[D]\t");
        else
        {
            n=f[i][0];
            printf("[");
            do
            {
                printf("q%d,",n%10);
                n=n/10;
            }while(n!=0);
            // Edit for space
            printf("]\t\t");
        }
        if(f[i][1]==-1)
            printf("[D]\t");
        else
        {n=f[i][1];
            printf("[");
            do
            {
                printf("q%d,",n%10);
                n=n/10;
            }while(n!=0);
            // Edit for space
            printf("]\t\t");}
        if(f[i][2]==-1)
            printf("[D]\n");
        else
        {n=f[i][2];
            printf("[");
            do
            {
                printf("q%d,",n%10);
                n=n/10;
            }while(n!=0);
            // Edit for space
            printf("]\n");}

    }
}

void main()
{
    int c,f;
    c=input();
    Mark_zero();
    traverse(c);
    display();
    printf("\n\n");
    f=convert();
    display2(f);
}
