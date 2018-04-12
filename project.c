#include<stdio.h>
#include<conio.h>
struct processs{							
	int arrivaltime,p_id,status,bursttime,priority;
}pro[35];
void compare(int x,int y);
void display(int temp);
int main()
{
	int num,i;
	printf("Please enter the number of processes do u want:\n");
	scanf("%d",&num);
	int order_execution;
	printf("Please enter the arrival time of each process:\n");
	for(i=0;i<num;i++)
	{
		printf("Enter the arrival time of P : %d\n",i+1);
		scanf("%d",&pro[i].arrivaltime);
		pro[i].p_id = i+1;
	}
	printf("please enter the burst time of each process:\n");
	for(i=0;i<num;i++)
	{
		printf("Enter the burst time of P: %d\n",i+1);
		scanf("%d",&pro[i].bursttime);
	}
	printf(" Please Enter the priority of each process:\n");
	for(i=0;i<num;i++)
	{
		printf("Enter the priority of P %d\n",i+1);
		scanf("%d",&pro[i].priority);
	}
	for(i=0;i<num;i++)										
		pro[i].status = 0;																		
	int time1 = 0;			
	int count1 = 0, count2 = 0;
	i=0;
	while(count1!=num)
	{
		if(pro[i].status!=1 && pro[i].status!=2)
		{	
			printf("\nProcessing %d",pro[i].p_id);
			int j;
			for(j=i+1;j<num;j++)
			{
				if(pro[j].status != 1 && pro[j].status!=2 && (pro[j].priority < pro[i].priority) && (pro[j].arrivaltime <= time1))
				{
					printf("\nProcess %d",pro[i].p_id," is interupt by another %d",pro[j].p_id,".Pushed  into queue");
					printf("\nProcess %d",pro[j].p_id," it is proceesss");
					pro[i].status = 2;
					count2++;
					time1 += pro[j].bursttime;
					pro[j].status = 1;
					printf("Process %d is completely processed",pro[j].p_id);
					count1 += 2;
					break;
				}
			}
			if(pro[i].status != 2)
			{
				time1 += pro[i].bursttime;
				pro[i].status = 1;
				printf("\nProcess %d  is completely processed",pro[i].p_id);
				count1++;
			}
		}
		i = (i+1)%num;
	}
	int tq = 2;
	time1 = 0;
	count1 = 0;
	printf("\nThe second queue using the round robin scheduling algo");
	i=0;
	while(count1 != count2)
	{
		if(pro[i].status == 2)
		{
			if(pro[i].bursttime<2)
			{
				pro[i].bursttime -= 1;
				time1 += 1;
				pro[i].status = 1;
				printf("Completed executing  %d",pro[i].p_id," at %d",time1," time-units");
				count1++; 
			}
			else
			{
				pro[i].bursttime -= 2;
				time1 += tq;
				printf("\nProcessing  %d for 2 time-units",pro[i].p_id);
			}
		}
		i = (i+1)%num;
	}
	printf("\nThe order of the execution\n");		
	return 0;
}
void compare(int a, int b)											
{
	return 0;
}
display(int l)												
{
	int p = l;
	while(p!=l)
	{
      printf("P-> ");
	}
	printf("\n");
}
