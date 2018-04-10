#include<stdio.h>
#include<conio.h>
struct processs{							
	int arrivaltime,p_id,status,bursttime,priority;
}pro[20];
int main()
{
	int n,i;
	printf("Please enter the number of processes do u want:\n");
	scanf("%d",&num);
	printf("Please enter the arrival time of each process:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the arrival time of P : %d\n",i+1);
		scanf("%d",pro[i].arrivaltime);
		pro[i].p_id = i+1;
	}
	printf("please enter the burst time of each process:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the burst time of P: %d\n",i+1);
		scanf("%d",&pro[i].bursttime);
	}
	printf(" Please Enter the priority of each process:\n");
	for(i=0;i<n;i++)
	{
		printf("Enter the priority of P %d\n",i+1);
		scanf("%d",pro[i].priority);
	}
