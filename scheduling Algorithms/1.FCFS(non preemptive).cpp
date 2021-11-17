#include <bits/stdc++.h>
using namespace std;
int main(){
		int n;
		cout<<"Enter Number of Processes : "<<endl;
		cin>>n;
		string p[n],str;
		int AT[n],BT[n],CT[n],WT[n],TAT[n];
		float sumTAT=0,sumWT=0;
		int i=0,temp;
		while(i<n){
			cout<<i+1<<".Enter Process Name, AT, BT : "; 
			cin>>p[i]>>AT[i]>>BT[i];
			cout<<endl;
			i++;
		}
		for(int i=0;i<n;i++){
			for(int j=1;j<n-i;j++){
				if(AT[j-1]>AT[j]){
					temp=AT[j-1];
					AT[j-1]=AT[j];
					AT[j]=temp;

					temp=BT[j-1];
					BT[j-1]=BT[j];
					BT[j]=temp;

					p[j-1].swap(p[j]);
				}
			}
		}
			cout<<"Processes Name"<<'\t'<<"AT"<<'\t'<<"BT"<<'\t'<<"CT"<<'\t'<<"TAT"<<'\t'<<"WT"<<endl;
			CT[0]=AT[0]+BT[0];
			TAT[0]=CT[0]-AT[0];
			WT[0]=TAT[0]-BT[0];
			for(int i=1;i<n;i++){
				if(AT[i]>CT[i-1])
					CT[i]=AT[i]+BT[i];
				else
					CT[i]=CT[i-1]+BT[i];
				TAT[i]=CT[i]-AT[i];
				WT[i]=TAT[i]-BT[i];
			}

			for(int i=0;i<n;i++){
				sumTAT+=TAT[i];
				sumWT+=WT[i];
				cout<<p[i]<<"              "<<AT[i]<<'\t'<<BT[i]<<'\t'<<CT[i]<<'\t'<<TAT[i]<<'\t'<<WT[i]<<endl;
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
Average TAT = 3.6 units
Average WT  = 1.2 units
*/
