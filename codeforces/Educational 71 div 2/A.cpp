#include<iostream>
main(){
	int b,p,f,h,c,t,temp,res;
	std::cin>>t;
	for(temp=0;temp<t;temp++){
		std::cin>>b>>p>>f;
		std::cin>>h>>c;
		b/=2;
		if(h>c){
			if(b>p){
				b-=p;
				if(b>f){
					res=p*h+f*c;
				}else{
					res=p*h+b*c;
				}
			}else{
				res=b*h;
			}
		}else{
			if(b>f){
				b-=f;
				if(b>p){
					res=f*c+p*h;
				}else{
					res=f*c+b*h;
				}
			}else{
				res=b*c;
			}
		}
		std::cout<<res<<std::endl;
	}
}