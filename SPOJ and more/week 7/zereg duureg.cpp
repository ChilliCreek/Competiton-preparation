#include<bits/stdc++.h>

using namespace std;

main(){
	bool n1;
	int i,j,len,div,t,too;
	string inp;
	char k;
	cin>>too;
	for(t=0;t<too;t++){
		cin>>inp;
		len=inp.size();
		for(div=1;div<=len/2;div++){
			if(len%div==0){
				for(i=0;i<div;i++){
					k=inp[i];
					n1=false;
					for(j=i+div;j<len;j+=div){
						if(k!=inp[j]){
							n1=true;
							break;
						}
					}
					if(n1==true){
						break;
					}
				}
				if(n1==false){
					break;
				}
			}
		}
		if(n1==false)cout<<len/div<<endl;
		else cout<<"1";
    }
}
