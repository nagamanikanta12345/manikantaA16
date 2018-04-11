#include<stdio.h>
#include<conio.h>
struct processs{							
	int arrivaltime,p_id,status,bursttime,priority;
}pro[20];
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
	//cout<<"Processing first queue using priority scheduling"<<endl<<endl<<endl;					
	int time = 0;			
	int count = 0, count2 = 0;
	i=0;
	while(count!=num)
	{
		if(pro[i].status!=1 && pro[i].status!=2)
		{	
			printf("Processing %d",pro[i].p_id);
			int j;
			for(j=i+1;j<num;j++)
			{
				if(pro[j].status != 1 && pro[j].status!=2 && (pro[j].priority < pro[i].priority) && (pro[j].arrivaltime <= time))
				{
					printf("Process P %d",pro[i].p_id," is interupt by another %d",pro[j].p_id,".Pushed  into queue");
					printf("Process P %d",pro[j].p_id," it is proceesss");
					pro[i].status = 2;
					count2++;
					time += pro[j].bursttime;
					pro[j].status = 1;
					printf("Process P %d ",pro[j].p_id," is completely processed");
					//order_execution.push(p[j].p_id);
					count += 2;
					break;
				}
			}
			if(pro[i].status != 2)
			{
				time += pro[i].bursttime;
				pro[i].status = 1;
				printf("Process P %d ",pro[i].p_id," is completely processed");
			//	order_execution.push(p[i].p_id);
				count++;
			}
		}
		i = (i+1)%num;
	}
	int tq = 2;
	time = 0;
	count = 0;
	printf("\nProcessing second queue using round robin scheduling");
	i=0;
	while(count != count2)
	{
		if(pro[i].status == 2)
		{
			if(pro[i].bursttime<2)
			{
				pro[i].bursttime -= 1;
				time += 1;
				pro[i].status = 1;
				printf("Completed executing P %d",pro[i].p_id," at %d",time," time-units");
				//order_execution.push(p[i].p_id);
				count++; 
			}
			else
			{
				pro[i].bursttime -= 2;
				time += tq;
				printf("Processing P %d",pro[i].p_id," for 2 time-units");
			}
		}
		i = (i+1)%num;
	}
	printf("Displaying the order of execution\n");		
	display(order_execution);
	return 0;
}
