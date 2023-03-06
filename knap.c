#include<stdio.h>
int wt[20],value[20],ratio[20],n,w,weight=0,id[20],profit=0;
void main()
{
    int i,j,temp;
    printf("enter the no. of entries");
    scanf("%d",&n);
    printf("Enter the values in format: wt value \n");
    for(i=0;i<n;i++)
    {
        id[i]=i+1;
        scanf("%d %d",&wt[i],&value[i]);
        ratio[i]=value[i]/wt[i];
    }
    printf("enter weight of scak");
    scanf("%d",&w);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {

            if(ratio[j]<ratio[j+1])
            {
                temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp;
                temp=value[j];
                value[j]=value[j+1];
                value[j+1]=temp;
                temp=wt[j];
                wt[j]=wt[j+1];
                wt[j+1]=temp;
                temp=id[j];
                id[j]=id[j+1];
                id[j+1]=temp;
            }
        }
    }
    i=-1;
    while(w>weight)
    {
        i++;
        if(weight+wt[i]<w)
        {
            weight=weight+wt[i];
            profit=profit+value[i];
        }
        else
        {
            profit=profit+(value[i]/wt[i])*(w-weight);
            weight=w;
        }
    }
    printf("id\twt\tvalue\tratio\n");
    for(j=0;j<n;j++)
    {
        printf("%d\t%d\t%d\t%d\n",id[j],wt[j],value[j],ratio[j]);
    }
    printf("\n\nSack-{");
    for(j=0;j<=i;j++)
    {
        printf("%d,",id[j]);
    }
    printf("}");
    printf("\nprofit=%d",profit);
}
