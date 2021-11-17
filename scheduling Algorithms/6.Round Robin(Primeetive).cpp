#include <bits/stdc++.h>
using namespace std;
/*****************************************/
void SortProcesses(int start,int end,int AT[],int BT[],string p[],int CBT[]){
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

					p[j-1].swap(p[j]);
					}
				}
				k++;
			}
		}
/******************************************/
int main(){
		int n,QT;
		cout<<"Enter Number of Processes and QauntumT : "<<endl;
		cin>>n>>QT;
		string p[n];
		int AT[n],BT[n],CT[n],WT[n],TAT[n],j,CBT[n],RQ[n];
		float sumTAT=0,sumWT=0;
		int i=0;
		while(i<n){
			cout<<i+1<<".Enter Process Name, AT, BT : "; 
			cin>>p[i]>>AT[i]>>BT[i];
			cout<<endl;
			CBT[i]=BT[i];
			RQ[i]=-1;//not in ready queue
			i++;
		}
		SortProcesses(0,n,AT,BT,p,CBT);
		i=0;
		int flag=0,curr_time=0,count=0,k=1,diff,z,max;
		i=0;
		RQ[i]=1;
		k=1;
		max=k;
		while(true){
			if(count==n){
				break;
			}
			if(k!=RQ[i]){
				i++;
				continue;
			}
			diff=QT;//this to be subtracted
			if(BT[i]-QT<0){
				diff=QT-(QT-BT[i]);
			}
			curr_time=curr_time+diff;
			BT[i]=BT[i]-diff;
			k++;
			//moved to next item in queue
			if(BT[i]==0){
				CT[i]=curr_time;
				TAT[i]=CT[i]-AT[i];
				WT[i]=TAT[i]-CBT[i];
				count+=1;
				RQ[i]=-2;//removed from ready queue
			}
			j=0;
			z=0;
			while(AT[j]<=curr_time&&j<n){
				if(RQ[j]==-1){
				RQ[j]=++max;
				max=RQ[j];
				}
				j++;
			}
			flag=0;
			if(RQ[i]!=-2){//in ready queue
				RQ[i]=++max;
				max=RQ[i];
			}
			i=0;
	}
	cout<<endl<<"Processes Name"<<'\t'<<"AT"<<'\t'<<"BT"<<'\t'<<"CT"<<'\t'<<"TAT"<<'\t'<<"WT"<<endl;
	for(int i=0;i<n;i++){
			sumTAT+=TAT[i];
			sumWT+=WT[i];
			cout<<p[i]<<"              "<<AT[i]<<'\t'<<CBT[i]<<'\t'<<CT[i]<<'\t'<<TAT[i]<<'\t'<<WT[i]<<endl;
	}
	cout<<"Average TAT = "<<sumTAT/n<<" units"<<endl;
	cout<<"Average WT  = "<<sumWT/n<<" units";
}
	
/*5 3
p1 0 8
p2 5 2
p3 1 7 
p4 6 3
p5 8 5
Average TAT = 15 units
Average WT  = 10 units
*/
/*
6 2
p1 0 4
p2 2 3
p3 3 5
p4 4 3
p5 6 4
p6 8 3
Average TAT = 12.5 units
Average WT  = 8.83333 units
*/
/*
7 2
p1 0 6
p2 1 3
p3 2 4
p4 4 5
p5 5 2
p6 6 3
p7 8 4
Average TAT = 16.1429 units
Average WT  = 12.2857 units
*/
