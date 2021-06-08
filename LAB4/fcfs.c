#include<stdio.h>
void main(){
int pn[10];
int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], i, n;
int totwt=0, tottat=0;
printf("Enter the number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++) {
printf("Enter the Process Name, Arrival Time & Burst Time:");
scanf("%d%d%d",&pn[i],&arr[i],&bur[i]);
}
for(i=0;i<n;i++) {
if(i==0) {
star[i]=arr[i];
wt[i]=star[i]-arr[i];
finish[i]=star[i]+bur[i];
tat[i]=finish[i]-arr[i];
} else{star[i]=finish[i-1];
wt[i]=star[i]-arr[i];
finish[i]=star[i]+bur[i];
tat[i]=finish[i]-arr[i];
}  
}
printf("\nPName\tArrtime\tBurtime\tStart\tTAT\tFinish\n");
for(i=0;i<n;i++) {
printf("\n%d\t%6d\t%6d\t%6d\t%6d\t%6d\n",pn[i],arr[i],bur[i],star[i],tat[i],finish[i]);
totwt+=wt[i];
tottat+=tat[i];
}
float avgwait = (totwt*1.0)/n;
float avgtat = (tottat*1.0)/n;
printf("\nAverage Waiting Time:%f",avgwait);
printf("\nAverage Turnaround Time:%f",avgtat);
printf("\n");
}
