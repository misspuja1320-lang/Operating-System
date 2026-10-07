#include<stdio.h>
#include<conio.h>
#define max 30
int main()
{
int i,j,n,t,p[max],bt[max],wt[max],tat[max],at[max]; 
float awt=0,atat=0;
printf("\nEnter the number of processes -- ");
scanf("%d", &n);
printf("\nEnter the process number -- ");
for(i=0;i<n;i++)
{
	scanf("%d",&p[i]);
}
printf("\nEnter the burst time of the processes --");
for(i=0;i<n;i++)
{
	scanf("%d",&bt[i]);
}
printf("\nEnter the arrival time of the processes --");
for(i=0;i<n;i++)
{
	scanf("%d",&at[i]);
}
//applying bubble sort technique
for(i=0;i<n;i++)
{
	for(j=0;j<n-i-1;j++)
	{
		if(bt[j]>bt[j+1])
		{
			t=bt[j];
			bt[j]=bt[j+1];
			bt[j+1]=t;
			
			t=p[j];
			p[j]=p[j+1];
			p[j+1]=t;
		}
	}
}
temp[0]=0;
printf("\nPROCESS \tARIVAL TIME \tBURST TIME \tWAITING TIME\t TURNAROUND TIME\n");
for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("\n%d\t\t %d\t\t %d\t\t %d\t\t %d\t\t",i+1,at[i],bt[i],wt[i],tat[i]);
    }
awt=awt/n;
atat=atat/n;
printf("\nAverage waiting time=%f\n", awt);
printf("Average turnaround time=%f\n", atat);
getch();
}
