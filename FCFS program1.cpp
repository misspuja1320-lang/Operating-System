#include <stdio.h>
#define max 20
int main() {
    int n,p[max],bt[max],wt[max],tat[max];
    float awt=0,atat=0;
    printf("Enter the number of process:\n");
    scanf("%d",&n);
    printf("Enter the burst time of process:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",bt[i]);
    }
    printf("\n Process\t Burst Time\t Waiting Time\t Turn Around Time\t\n");
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(int j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("\n%d\t\t %d\t\t %d\t\t %d\t\t",i+1,bt[i],wt[i],tat[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("\nAverage waiting time=%f",awt);
    printf("\nAverage turn around time=%f",atat);
    return 0;
}
