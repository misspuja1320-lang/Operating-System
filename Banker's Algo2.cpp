// Deadlock Prevention
#include<stdio.h>
#include<conio.h>
void main()
{
     int job[10][10],time[10],avail,temp[10],tem[10],safe[10],ind=1,i,j,q,n,t;
     clrscr();
     printf("Enter the number of jobs:");
     scanf("%d",&n);
     for(i=0;i<n;i++)
     {
      printf("Enter name :");
      scanf("%d",&job[i]);
      printf("Enter the time:");
      scanf("%d",&time[i]);
      }
      printf("Enter the available resources:");
      scanf("%d",&avail);
      for(i=0;i<n;i++)
      {
        temp[i]=time[i];
        tem[i]=i;
        }
        for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
        {
          if(temp[i]>temp[j])
          {
           t=temp[i];
           temp[i]=temp[j];
           temp[j]=t;
           t=tem[i];
           tem[i]=tem[j];
           tem[j]=t;
           }
           }
           for(i=0;i<n;i++)
           {
             q=tem[i];
             if(time[q]<=avail)
             {
                safe[ind]=tem[i];
                avail-=tem[q];
                printf("%s",job{safe[ind]]);
                ind++;
                }
                else
                {
                    printf("No safe sequence\n");
                    }
                    }
                    printf("Safe sequence is:");
                    for(i=1;i<ind;i++)
                    printf("%s %d\n",job[safe[i]],time[safe[i]]);
                    getch();
                    }
      
     
