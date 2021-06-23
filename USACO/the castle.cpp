#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: castle
*/
using namespace std;

struct walls{
	bool west=false;
	bool east=false;
	bool south=false;
	bool north=false;
};

int arr1[52][52],sizes[52],n,m;
walls arr[52][52];

walls whichwalls(int n){
	walls res;
	if(n%2==1){
		res.west=true;
		n--;
	}
	if(n>=8){
		res.south=true;
		n-=8;
	}
	if(n>=4){
		res.east=true;
		n-=4;
	}
	if(n>=2){
		res.north=true;
		n-=2;
	}
	return res;
}
void bfscan(int num){
	int neww,roomsize=0,i,j,in=0;
	do{
		neww=0;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(arr1[i][j]==-1){
					arr1[i][j]=num;
					roomsize++;
					if(arr[i][j].east==false && arr1[i][j+1]==0){
						neww++;
						arr1[i][j+1]=-1;
					}
					if(arr[i][j].north==false && arr1[i-1][j]==0){
						neww++;
						arr1[i-1][j]=-1;
					}
					if(arr[i][j].west==false && arr1[i][j-1]==0){
						neww++;
						arr1[i][j-1]=-1;
					}
					if(arr[i][j].south==false && arr1[i+1][j]==0){
						neww++;
						arr1[i+1][j]=-1;
					}
				}
			}
		}
	}while(neww!=0);
	sizes[num]=roomsize;
}
main(){
	ifstream fin("castle.in");
	ofstream fout("castle.out");
	int i,j,p,num_comp=1,in,max=INT_MIN,max1=INT_MIN,max1x,max1y;
	bool truefornorth;
	fin>>n>>m;
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			fin>>p;
			arr[i][j]=whichwalls(p);                                                                                                                                                
		}
	}
	while(1){
		in=0;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(arr1[i][j]==0){
					arr1[i][j]=-1;
					in=1;
					break;
				}
			}
			if(in==1){
				break;
			}
		}
		if(in==0){
			break;
		}else if(in==1){
			bfscan(num_comp);
			num_comp++;
		}
	}
	for(i=1;i<num_comp;i++){
		if(sizes[i]>max){
			max=sizes[i];
		}
	}
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(arr[i][j].north==true && i-1>-1){
				if(arr1[i][j]!=arr1[i-1][j]){
					if(max1<(sizes[arr1[i][j]])+(sizes[arr1[i-1][j]])){
						max1=(sizes[arr1[i][j]])+(sizes[arr1[i-1][j]]);
						max1x=i;max1y=j;
						truefornorth=true;
					}else if(max1==(sizes[arr1[i][j]])+(sizes[arr1[i-1][j]])){
						if(j<max1y){
							max1x=i;max1y=j;
						    truefornorth=true;
						}else if(j==max1y){
							if(i>max1x){
								max1x=i;max1y=j;
						        truefornorth=true;
							}else if(truefornorth==false){
								max1x=i;max1y=j;
						        truefornorth=true;
							}
						}
					}
				}
			}
			if(arr[i][j].south==true && i+1<=m){
				if(arr1[i][j]!=arr1[i+1][j]){
					if(max1<(sizes[arr1[i][j]])+(sizes[arr1[i+1][j]])){
						max1=(sizes[arr1[i][j]])+(sizes[arr1[i+1][j]]);
						max1x=i+1;max1y=j;
						truefornorth=true;
					}else if(max1==(sizes[arr1[i][j]])+(sizes[arr1[i+1][j]])){
						if(j<max1y){
							max1x=i+1;max1y=j;
						    truefornorth=true;
						}else if(j==max1y){
							if(i+1>max1x){
								max1x=i+1;max1y=j;
						        truefornorth=true;
							}else if(truefornorth==false){
								max1x=i+1;max1y=j;
						        truefornorth=true;
							}
						}
					}
				}
			}
			if(arr[i][j].west==true && j-1>-1){
				if(arr1[i][j]!=arr1[i][j-1]){
					if(max1<(sizes[arr1[i][j]])+(sizes[arr1[i][j-1]])){
						max1=(sizes[arr1[i][j]])+(sizes[arr1[i][j-1]]);
						max1x=i;max1y=j-1;
						truefornorth=false;
					}else if(max1<(sizes[arr1[i][j]])+(sizes[arr1[i][j-1]])){
						if(j-1<max1y){
							max1x=i;max1y=j-1;
						    truefornorth=false;
						}else if(j-1==max1y){
							if(i>max1x){
								max1x=i;max1y=j-1;
						        truefornorth=false;
							}
						}
					}
				}
			}
			if(arr[i][j].east==true && j+1>-1){
				if(arr1[i][j]!=arr1[i][j+1]){
					if(max1<(sizes[arr1[i][j]])+(sizes[arr1[i][j+1]])){
						max1=(sizes[arr1[i][j]])+(sizes[arr1[i][j+1]]);
						max1x=i;max1y=j;
						truefornorth=false;
					}else if(max1==(sizes[arr1[i][j]])+(sizes[arr1[i][j+1]])){
						if(j<max1y){
							max1x=i;max1y=j;
						    truefornorth=false;
						}else if(j==max1y){
							if(i>max1x){
								max1x=i;max1y=j;
						        truefornorth=false;
							}
						}
					}
				}
			}
		}
	}
	fout<<num_comp-1<<endl<<max<<endl<<max1<<endl<<max1x<<" "<<max1y<<" ";
	if(truefornorth){
		fout<<"N"<<endl;
	}else{
		fout<<"E"<<endl;
	}
}
