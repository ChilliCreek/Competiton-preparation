#include<iostream>
#define int long long
int gcd(int a, int b) 
{ 
    if (b == 0){
    	return a; 
	}
    return gcd(b, a % b);  
      
} 
main(){
	int n,m,k,t,t1,x1,y1,x2,y2,fact,p3,p4;
	std::cin>>n>>m>>k;
	fact=gcd(n,m);
	if(fact==1){
		for(t=0;t<k;t++){
			std::cin>>x1>>y1>>x2>>y2;
			std::cout<<"YES"<<std::endl;
		}
	}else{
		for(t=0;t<k;t++){
			std::cin>>x1>>y1>>x2>>y2;
			y1--;
			y2--;
			if(x1==1){
				p3=n/fact;
			}else{
				p3=m/fact;
			}
			if(x2==1){
				p4=n/fact;
			}else{
				p4=m/fact;
			}
			if(y1/p3==y2/p4){
				std::cout<<"YES"<<std::endl;
			}else{
				std::cout<<"NO"<<std::endl;
			}
		}
	}
}
