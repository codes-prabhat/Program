#include <bits/stdc++.h>
using namespace std;
/*****************************************/
void SortProcesses(int start,int end,int AT[],int BT[],string p[],int flag[],int CBT[],int ST[]){
			int temp,k=0;
			for(int i=start;i<end;i++){
			for(int j=start+1;j<end-k;j++){
				if(AT[j-1]>AT[j]){
					temp=AT[j-1];
					AT[j-1]=AT[j];
					AT[j]=temp;

					temp=BT[j-1];
					BT[j-1]=BT[j];
					BT[j]=temp;

					temp=CBT[j-1];
					CBT[j-1]=CBT[j];
					CBT[j]=temp;

					temp=ST[j-1];
					ST[j-1]=ST[j];
					ST[j]=temp;

					temp=flag[j-1];
					flag[j-1]=flag[j];
					flag[j]=temp;

					p[j-1].swap(p[j]);
				}
				else if(AT[j-1]==AT[j]){
					if(BT[j-1]>BT[j]){
					temp=BT[j-1];
					BT[j-1]=BT[j];
					BT[j]=temp;

					temp=AT[j-1];
					AT[j-1]=AT[j];
					AT[j]=temp;

					temp=flag[j-1];
					flag[j-1]=flag[j];
					flag[j]=temp;


					p[j-1].swap(p[j]);
					}

					}
				}
				k++;
			}
		}
/******************************************/
int main(){
		int n;
		cout<<"Enter Number of Processes : "<<endl;
		cin>>n;
		string p[n];
		int AT[n],BT[n],CT[n],WT[n],TAT[n],j,flag[n],CBT[n],temp,ST[n];
		float sumTAT=0,sumWT=0,sumBT=0;
		int i=0,count=0,diff;
		while(i<n){
			cout<<i+1<<".Enter Process Name, AT, BT : "; 
			cin>>p[i]>>AT[i]>>BT[i];
			cout<<endl;
			sumBT+=BT[i];
			flag[i]=0;
			CBT[i]=BT[i];
			ST[i]=12345;
			i++;
		}
		SortProcesses(0,n,AT,BT,p,flag,CBT,ST);
		cout<<"Processes Name"<<'\t'<<"AT"<<'\t'<<"BT"<<'\t'<<"CT"<<'\t'<<"TAT"<<'\t'<<"WT"<<endl;
		int curr_time=0;
		i=0;
		while(count!=n){
			if(BT[i]==0){
				i++;
				continue;
			}
			if(ST[i]=12345){
				ST[i]=curr_time;
			}
			if(BT[i]!=0){
					curr_time=curr_time+1;
					BT[i]=BT[i]-1;
			}
			if(BT[i]==0&&flag[i]==0){
				count++;
				CT[i]=curr_time;
				TAT[i]=CT[i]-AT[i];
				WT[i]=TAT[i]-CBT[i];
				flag[i]=1;
			}
				j=i;
				while(AT[j]<=curr_time&&j<n){
					j++;
				}
				SortProcesses(i,j,BT,AT,p,flag,CBT,ST);
	}
				for(int i=0;i<n;i++){
				sumTAT+=TAT[i];
				sumWT+=WT[i];
				cout<<p[i]<<"              "<<AT[i]<<'\t'<<CBT[i]<<'\t'<<CT[i]<<'\t'<<TAT[i]<<'\t'<<WT[i]<<endl;
			}
			cout<<"Average TAT = "<<sumTAT/n<<" units"<<endl;
			cout<<"Average WT  = "<<sumWT/n<<" units";
}
/*
5
p1 5 4
p2 3 1
p3 1 3
p4 0 2
p5 8 2
Average TAT = 3.4 units
Average WT  = 1 units
*/	
/*5
p1 0 4
p2 0 2
p3 2 3
p4 4 2
p5 6 2*/
/*6
p1 1 2
p2 10 1
p3 10 1
p4 11 2
p5 11 4
p6 12 2*/
/*6
p1 0 4
p2 0 2
p3 0 1
p4 0 4
p5 0 2
p6 0 1*/
