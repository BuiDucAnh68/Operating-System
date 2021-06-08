#include<stdio.h>
void main()
{
        int i,n,quantum,temp,arr=0,count=0;
        float awt =0 , attat =0;
        int pn[10] ,bur[10],wt[10],tat[10],tot_bur[10];
        printf("Enter the number process:");
        scanf("%d",&n);
        for(i = 0;i<n;i++)
        {
        printf("Enter the process name,Burst Time:");
        scanf("%d%d",&pn[i],&bur[i]);
        tot_bur[i] = bur[i];
        }
        printf("Quantum Time = ");
        scanf("%d",&quantum);
        while(1)
        {
                for(i=0;i<n;i++)
                {
                        temp = quantum;
                        if(tot_bur[i] == 0)
                        {
                                count++;
                                continue;
                        }
                        if(tot_bur[i] > quantum)
                                tot_bur[i] -= quantum;
                        else
                                if(tot_bur >=0)
                                {
                                        temp = tot_bur[i];
                                        tot_bur[i] =0;
                                }
                        arr += temp;
                        tat[i] = arr;
                }
                if(n==count)
                        break;
        }
        printf("\nProcess\tStart\tStop\tBurst Time");
        for(i=0;i<n;i++)
        {
                wt[i] = tat[i] - bur[i];
                awt += wt[i];
                attat +=tat[i];
                printf("\n%d\t%3d\t%3d\t%3d\n",pn[i],wt[i],tat[i],bur[i]);
        }
        awt /=n;
        attat /=n;
        printf("\nAverage Waiting Time: %f",awt);
        printf("\nAverage Turnaround Time: %f",attat);
        printf("\n");

}

