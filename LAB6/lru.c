#include<stdio.h>
//Kiem tra xem thoi gian co la nho nhat hay khong
int lru(int time[] ,int n)
{
	int i ,minium = time[0],loc= 0;
	for(i = 1; i<n;++i){
		if(time[i] < minium){
			minium = time[i];
			loc=i;
		}
	}
	return loc;
}

int main(){
int no_frame,no_pages,frame[25],pages[50],count = 0,time[10],flag1,flag2,i,faults,loc,j;
printf("Enter number of frames:");
scanf("%d",&no_frame);
printf("Enter number of pages: ");
scanf("%d",&no_pages);
printf("Enter reference string: ");
for(i = 0 ; i<no_pages;++i)
{
	scanf("%d",&pages[i]);
}
//Khoi tao gan ban dau gia tri la -1
for(i = 0 ;i<no_frame;++i)
{
	frame[i] = -1;	
}

for(i = 0;i<no_pages;++i)
{
	flag1=flag2=0;
	for(j = 0;j<no_frame;++j)
	{
	if(frame[j] == pages[i]){
		count++;
		time[j] = count;
			flag1=flag2=1;
			break;}
	}
//kiem tra flag1
if(flag1 == 0){
	for(j =0;j<no_frame;++j){
	if(frame[j] == -1){
		count++;
		faults++;
		frame[j] = pages[i];
		time[j] = count;
		flag2 = 1;
		break;
	}
	}
}
//KIem tra flag2
if(flag2 == 0){
	loc =lru(time,no_frame);
	count++;
	faults++;
	frame[loc] = pages[i];
	time[loc] =count;
}
printf("\n");
for(j=0;j<no_frame;++j)
{
	printf("%d\t",frame[j]);
}

}
printf("\n\nTotal Page Faults =%d\n",faults);
}
