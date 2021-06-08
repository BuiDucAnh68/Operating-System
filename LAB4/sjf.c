#include<stdio.h>
int main()
{
//non-preemtive
	int pn[10];
	int arr[10],bur[10],star[10],finish[10], tat[10], wt[10],res[10],i,n,temp1,temp2,j,pos;
	int totwt = 0,tottat=0;
	
	printf("Enter the number processes:");
	scanf("%d",&n);
	for(i =0 ; i<n;i++){
		printf("Enter the Processer,Arrival Time,Burst Time:");
		scanf("%d%d%d",&pn[i],&arr[i],&bur[i]);
		
	}
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
		 
		 if(i >=1 && bur[i] > bur[j])
		 {
		 	temp1= bur[i];
		 	temp2= arr[i];
		 	bur[i] = bur[j];
		 	arr[i] = arr[j];
		 	bur[j] = temp1;
		 	arr[j] = temp2;
		 }
		 
		}
	if(i==0)
	{
		star[i]=arr[i];
		wt[i]=star[i]-arr[i];
		finish[i]=star[i]+bur[i];
		tat[i]=finish[i]-arr[i];
		res[i] =star[i];
	}
	else{
		star[i]=finish[i-1];
		wt[i]=star[i]-arr[i];
		finish[i]=star[i]+bur[i];
		tat[i]=finish[i]-arr[i];
		res[i] = star[i] -arr[i];
	}
	}

	
	printf("\nPName\tResponse Waitime  Turnaround Time");
	for(i=0;i<n;i++) {
	printf("\n%d\t%4d\t%6d\t%6d\n",pn[i],res[i],wt[i],tat[i]);
	totwt+=wt[i];
	tottat+=tat[i];
	}
	float avgwait = (totwt*1.0)/n;
	float avgtat = (tottat*1.0)/n;
	printf("\nAverage Waiting Time:%f",avgwait);
	printf("\nAverage Turnaround Time:%f",avgtat);
	printf("\n");
}
