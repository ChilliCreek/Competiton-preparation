#include<bits/stdc++.h>

using namespace std;

main(){
	int n,m,i,j,lim,b,indi,indi1=0;
	bool arr[125001]={0};
	cin>>n>>m;
	lim=2*m*m;
	vector <int> save;
	
	for(i=0;i<=m;i++){
		for(j=i;j<=m;j++){
			save.push_back(i*i+j*j);
			arr[i*i+j*j]=1;
		}
    }
    sort(save.begin(),save.end());
	for(j=1;j<=int(lim/(n-1));j+=1){
		for(i=0;i<save.size();i++){
			if(save[i]>lim-(n-1)*j){
				break;
			}
			indi=0;
			for(b=save[i]+j*(n-1);b>save[i];b-=j){
				if(arr[b]==0){
					indi=1;break;
				}
			}
			if(indi==0){
				indi1 = 1;
				cout<<save[i]<<" "<<j<<endl;
			}
		}             
	}
	if(indi1==0){
		cout<<"NONE"<<endl;
	}
}
