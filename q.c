#include<stdio.h>
#include<string.h>
int a[100][3],ns;

int input()
{   int c=0,n=1,n1,n2;
    printf("Enter the number of states");
    scanf("%d",&ns);
    printf(": State 2 is E \n: -1 Ends the input \n\nEnter the transitions in format:\ncurrent_state input next_state\n");
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
int ec[20];
int f[20][2];

void Mark_zero()
{
    int i;
    for(i=0;i<20;i++)
    {

        ec[i]=-1;
        tt[i][0]=-1;
        tt[i][1]=-1;
        tt[i][2]=-1;
        f[i][0]=-1;
        f[i][1]=-1;
    }
}

int add_state(int a,int b)
{
    return (a*10)+b;
}

void traverse(int c)
{
    int i;
    for(i=0;i<c;i++)
    {
        if(a[i][1]==2)
        {
            if(ec[a[i][0]]==-1)
            {
                ec[a[i][0]]=a[i][2];
            }
            else
            ec[a[i][0]]=add_state(ec[i],a[i][2]);
        }
        else
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
    printf("CS\t0\t1\tE\n");
    for(i=0;i<ns;i++)
    {
        //printf("%d",ns);
        printf("q%d\t",i);
        if(tt[i][0]==-1)
            printf("-\t");
        else
        printf("{%d}\t",tt[i][0]);
        if(tt[i][1]==-1)
            printf("-\t");
        else
        printf("{%d}\t",tt[i][1]);
        if(ec[i]==-1)
            printf("-\n");
        else
        printf("{%d}\n",ec[i]);
        //printf("%d\t %d\t %d\n",tt[i][0],tt[i][1],ec[i]);
    }
}

void Update_E_closure()
{
    int i;

    for(i=0;i<ns;i++)
    {
        if(ec[i]+1==ec[i+1])
        {
            ec[i]=add_state(ec[i],ec[i+1]);
        }
    }

    for(i=0;i<ns;i++)
    {
        if(ec[i]!=-1)
        {
            ec[i]=add_state(ec[i],i);
        }
        else
            ec[i]=i;
    }
}



void E_closure()
{
    int i,n,r;
    for(i=0;i<ns;i++)
    {
        n=ec[i];

        do
        {
            //printf("hi");
            r=n%10;
            if(f[i][0]==-1)
            {
                if(ec[tt[r][0]]==0)
                {
                    f[i][0]==-1;
                }
                else
                f[i][0]=ec[tt[r][0]];
                //printf("hihi%d",ec[tt[r][0]]);
            }
            else
                f[i][0]=add_state(f[i][0],ec[tt[r][0]]);
            if(f[i][1]==-1)
            {

                if(ec[tt[r][1]]==0)
                {
                    f[i][1]=-1;
                }
                else
                f[i][1]=ec[tt[r][1]];
            }
            else
                f[i][1]=add_state(f[i][1],ec[tt[r][1]]);
            n=n/10;
        }while(n!=0);
    }
}

void display2()
{
    int i;
    printf("CS\t0\t1\n");
    for(i=0;i<ns;i++)
    {
        printf("q%d\t",i);
        if(f[i][0]==-1)
            printf("-\t");
        else
        printf("{%d}\t",f[i][0]);
        if(f[i][1]==-1)
            printf("-\n");
        else
        printf("{%d}\n",f[i][1]);
        //printf("q%d\t{%d}\t{%d}\n",i,f[i][0],f[i][1]);
    }
}

void main()
{
    int c;
    c=input();
    Mark_zero();
    traverse(c);
    Update_E_closure();
    display();
    printf("\n\n");
    E_closure();
    display2();
}
