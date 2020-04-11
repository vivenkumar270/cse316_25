#include<stdio.h>
struct process
{
    char name;
    int AT,BT,WT,TAT,RT,CT;
}A1[10],A2[10],A3[10];          

int n;
void sortByArrival()
{
struct process temp;
int i,j;
for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
            {
                if(A1[i].AT>A1[j].AT)
                    {
                          temp=A1[i];
                          A1[i]=A1[j];
                          A1[j]=temp;
                    }
            }
    }
}

int main()
{
     int i,j,k=0,r=0,time=0,tq1=5,tq2=8,flag=0;
     char c;
     printf("Enter no of processes:");
     scanf("%d",&n);
     for(i=0,c='A';i<n;i++,c++)
     {
         A1[i].name=c;
         printf("\nEnter the arrival time and burst time of process %c: ",A1[i].name);
         scanf("%d%d",&A1[i].AT,&A1[i].BT);
         A1[i].RT=A1[i].BT;/*save burst time in remaining time for each process*/

    }
sortByArrival();
time=A1[0].AT;
printf("Process in first queue following RR with qt=5");
printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
for(i=0;i<n;i++)
{

  if(A1[i].RT<=tq1)
  {

       time+=A1[i].RT;              /*from arrival time of first process to completion of second process*/
       A1[i].RT=0;
       A1[i].WT=time-A1[i].AT-A1[i].BT;/*amount of time process has been waiting in the first queue*/
       A1[i].TAT=time-A1[i].AT;/*amount of time to execute the process*/
       printf("\n%c\t\t%d\t\t%d\t\t%d",A1[i].name,A1[i].BT,A1[i].WT,A1[i].TAT);

  }
  else                    /*process moves to queue 2 with qt=8*/
  {
      A2[k].WT=time;
      time+=tq1;
      A1[i].RT-=tq1;
      A2[k].BT=A1[i].RT;
      A2[k].RT=A2[k].BT;
      A2[k].name=A1[i].name;
      k=k+1;
      flag=1;
   }
}
if(flag==1)
 {printf("\nProcess in second queue following RR with qt=8");
  printf("\nProcess\t\tRT\t\tWT\t\tTAT\t\t");
}for(i=0;i<k;i++)
   {
    if(A2[i].RT<=tq2)
     {
       time+=A2[i].RT;/*from arrival time of first process +BT of this process*/
       A2[i].RT=0;
       A2[i].WT=time-tq1-A2[i].BT;/*amount of time process has been waiting in the ready queue*/
       A2[i].TAT=time-A2[i].AT;/*amount of time to execute the process*/
       printf("\n%c\t\t%d\t\t%d\t\t%d",A2[i].name,A2[i].BT,A2[i].WT,A2[i].TAT);

    }
    else                          /*process moves to queue 3 with FCFS*/
    {
      A3[r].AT=time;
      time+=tq2;
      A2[i].RT-=tq2;
      A3[r].BT=A2[i].RT;
      A3[r].RT=A3[r].BT;
      A3[r].name=A2[i].name;
      r=r+1;
      flag=2;
    }
  }

{if(flag==2)
printf("\nProcess in 3 queue following FCFS ");
}
for(i=0;i<r;i++)
{
    if(i==0)
            A3[i].CT=A3[i].BT+time-tq1-tq2;
        else
            A3[i].CT=A3[i-1].CT+A3[i].BT;

}

for(i=0;i<r;i++)
    {
        A3[i].TAT=A3[i].CT;
        A3[i].WT=A3[i].TAT-A3[i].BT;
        printf("\n%c\t\t%d\t\t%d\t\t%d\t\t",A3[i].name,A3[i].BT,A3[i].WT,A3[i].TAT);

    }

}

