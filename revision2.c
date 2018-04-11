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
					count += 2;
					break;
				}
			}
