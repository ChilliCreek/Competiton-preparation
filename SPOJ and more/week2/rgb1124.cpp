/*
ID: your_id_here
TASK: palsquare
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

char tob(int num){
	if(num>9){
		switch(num){
			case 10:
				return 'A';
				break;
			case 11:
				return 'B';
				break;
			case 12:
				return 'C';
				break;
			case 13:
				return 'D';
				break;
			case 14:
				return 'E';
				break;
			case 15:
				return 'F';
				break;
			case 16:
				return 'G';
				break;
			case 17:
				return 'H';
				break;
			case 18:
				return 'I';
				break;
			case 19:
				return 'J';
				break;
		}
	}else{
		return num+48;
	}
}


string topal(int inp,int b){
	string res;
	while(inp>0){
		res+=tob(inp%b);
		inp/=b;
	}
	reverse(res.begin(),res.end());
	return res;
}


bool ifpal(string inp){
	for(int i=0;i<inp.size()/2;i++){
		if(inp[i]!=inp[inp.size()-1-i]){
			return false;
		}
	}
	return true;
}

main(){
	ofstream fout ("palsquare.out");
    ifstream fin ("palsquare.in");
	string receive,receive1;
	int b,i,j;
	fin>>b;
	for(i=1;i<301;i++){
		receive=topal(i*i,b);
		if(ifpal(receive)){
			fout<<topal(i,b)<<" "<<receive<<endl;
		}
	}
}
