#include<stdio.h>
int main()
{
//SRTF preemtive
	int time,pn[10],arr[10],bur[10],finish[10],n,i,star[10],small,wt[10],tat[10];
	int avgwait = 0 , avgtat=0,sum_bur= 0;
	printf("Enter the number process: " );
	scanf("%d",&n);
	for(i = 0 ;i<n;i++)
	{
		printf("Enter the Process Name,Arrival Time,Burst TIme:");
		scanf("%d%d%d",&pn[i],&arr[i],&bur[i]);
		sum_bur += bur[i];
	}
	
	bur[9] = 1000;
	printf("\nPName\tArrival\tBurst\tResponse Waiting  Turnaround");
	for(time = 0 ;time < sum_bur;)
	{
		small = 9;
		for(i= 0 ;i<n;i++)
		{
			if(arr[i] <= time && bur[i]>0 && bur[i]<bur[small])
				small = i;
		
		}
		if(small == 9)
		{
			time++;
			continue;
		}
		
		printf("\n%d\t%4d\t%4d\t%4d\t%5d\t%5d\n",pn[small],arr[small],bur[small],time-arr[small],time-arr[small],time+bur[small] - arr[small]);
		avgwait += (time-arr[small]);
		avgtat += (time+bur[small] - arr[small]);
		time += bur[small];
		bur[small] = 0;
	}
printf("\nAverage Waiting Time = %f",avgwait*1.0/n);
printf("\nAverage Turnaround Time = %f",avgtat*1.0/n);
printf("\n");
return 0;		
}
