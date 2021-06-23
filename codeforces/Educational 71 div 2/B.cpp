#include<iostream>
#include<queue>
#include<utility>
main(){
	int m,n,arr[51][51],t,t1,step_n;
	std::queue<std::pair <int,int> >steps;
	std::cin>>m>>n;
	for(t=0;t<m;t++){
		for(t1=0;t1<n;t1++){
			std::cin>>arr[t][t1];
		}
	}
	for(t=0;t<m-1;t++){
		for(t1=0;t1<n-1;t1++){
			if(arr[t][t1] !=0 &&arr[t][t1+1] !=0 &&arr[t+1][t1+1] !=0 &&arr[t+1][t1] !=0 ){
				arr[t][t1]=2;
				arr[t+1][t1]=2;
				arr[t+1][t1+1]=2;
				arr[t][t1+1]=2;
				step_n++;
				steps.push(std::make_pair(t,t1));
		    }
		}
	}
	for(t=0;t<m;t++){
		for(t1=0;t1<n;t1++){
			if(arr[t][t1]==1){
				std::cout<<"-1";
				return 0;
			}
		}
	}
	std::cout<<step_n<<std::endl;
	while(!steps.empty()){
		std::cout<<steps.front().first+1<<" "<<steps.front().second+1<<std::endl;
		steps.pop();
	}
	return 0;
}
