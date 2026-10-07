#include<stdio.h>
#define max 20
int main()
{
    int n,i,j,bt[max],p[max],wt[max],tat[max],total=0,totalT=0,pos,temp;
    float awt,atat;
    printf("Enter the number of process:");
    scanf("%d",&n);
    
    for(i=0;i<n;i++)
    {
        printf("p%d\n",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
            pos=j;
        }
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];
        total+=wt[i];
    }
    awt=(float)total/n;
    printf("\n Process\t BT\t WT\t TAT\n");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        totalT+=tat[i];
        printf("%d\t\t %d\t %d\t %d\n",p[i],bt[i],wt[i],tat[i]);
    }
    atat=(float)totalT/n;
    printf("\nAverage waiting time=%f",awt);
    printf("\nAverage turn around time=%f",atat);
    return 0;
}
