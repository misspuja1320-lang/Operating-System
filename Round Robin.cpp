#include<stdio.h>
int main()
{
	int i,j,n,bt[10],wt[10],tat[10],ts,ct[10],max;
	float awt=0,atat=0,temp=0;
	printf("enter the no of the process--");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nenter the burst time for process %d--",i+1);
		scanf("%d",&bt[i]);
		ct[i]=bt[i];
	}
	printf("\nenter the size of the time silce--");
	scanf("%d",&ts);
	max=bt[0];
	for(i=1;i<n;i++)
	{
		if(max<bt[i])
		max=bt[i];
	}
	for(j=0;j<(max/ts)+1;j++)
	for(i=0;i<n;i++)
	
		if(bt[i]!=0)
		if(bt[i]<=ts)
	{
		tat[i]=temp+bt[i];
		temp=temp+bt[i];
		bt[i]=0;
	}
	else
	{
		bt[i]=bt[i]-ts;
		temp=temp+ts;
	}
	for(i=0;i<n;i++)
	{
		wt[i]=tat[i]-ct[i];
		atat+=tat[i];
		awt+=wt[i];
	}
	printf("\n The average tat time is-- %f",atat/n);
	printf("\n The average wt time is--%f",awt/n);
	printf("\n\tPROCESS\t BURST TIME\t WAITING TIME\t TURNAROUND TIME\n");
	for(i=0;i<n;i++)
	printf("\t%d \t\t%d \t\t %d \t\t%d \n",i+1,ct[i],wt[i],tat[i]);
	return 0;	
}
