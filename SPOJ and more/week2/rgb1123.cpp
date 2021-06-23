#include<bits/stdc++.h>
using namespace std;

/*
ID: chiig.e1
TASK: namenum
LANG: C++                 
*/
ifstream dict ("dict.txt");
ofstream fout ("namenum.out");
ifstream fin ("namenum.in");
long long n,t=0;
bool func(string inp){
	long long res=0;
	for(long long i=0;i<inp.size();i++){
		switch(inp[i]){
			case 'A':
				res=res*10+2;
				break;
			case 'B':
				res=res*10+2;
				break;
			case 'C':
				res=res*10+2;
				break;
			case 'D':
				res=res*10+3;
				break;
			case 'E':
				res=res*10+3;
				break;
			case 'F':
				res=res*10+3;
				break;
			case 'G':
				res=res*10+4;
				break;
			case 'H':
				res=res*10+4;
				break;
			case 'I':
				res=res*10+4;
				break;
			case 'J':
				res=res*10+5;
				break;
			case 'K':
				res=res*10+5;
				break;
			case 'L':
				res=res*10+5;
				break;
			case 'M':
				res=res*10+6;
				break;
			case 'N':
				res=res*10+6;
				break;
			case 'O':
				res=res*10+6;
				break;
			case 'P':
				res=res*10+7;
				break;
			case 'R':
				res=res*10+7;
				break;
			case 'S':
				res=res*10+7;
				break;
			case 'T':
				res=res*10+8;
				break;
			case 'U':
				res=res*10+8;
				break;
			case 'V':
				res=res*10+8;
				break;
			case 'W':
				res=res*10+9;
				break;
			case 'X':
				res=res*10+9;
				break;
			case 'Y':
				res=res*10+9;
				break;
		}
	}
	if(res==n){
		fout<<inp<<endl;
		t=1;
	}
}
main(){
	string str;
	vector<string>finder;
	long long i,j;
	fin>>n;
	while(dict>>str){
		finder.push_back(str);
	}
	for(i=0;i<finder.size();i++){
		func(finder[i]);
	}
	if(t==0){
		fout<<"NONE"<<endl;
	}
}
