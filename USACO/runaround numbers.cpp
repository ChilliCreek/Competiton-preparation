#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: runround
*/
using namespace std;
ifstream fin("runround.in");
ofstream fout("runround.out");

int inp,used[10];

bool generate(char *a,int cur,int target){
	bool res;
	if(cur==target){
		a[cur]='\0';
		if(atoi(a)>inp && runaround(a)){
			fout<<a<<endl;
			return true;
		}
	}else{
		for(int i=1;i<10;i++){
			if(!used[i]){
				a[cur]=i+'0';
			    used[i]=1;
			    res=generate(a,cur+1,target);
			    if(res){
			    	return res;
				}
			    used[i]=0;
			}
		}
	}
	return false;
}

bool runaround(char *a){
	char temp[10];
	strcpy(temp,a);
	int i=0,b;
	while(temp[i]!='a'){
		b=temp[i];
		temp[i]='a';
		i=i+(b-'0');
		i%=strlen(a);
	}
	if(i!=0){
		return false;
	}
	for(int i=0;i<strlen(a);i++){
		if(temp[i]!='a'){
			return false;
		}
	}
	return true;
}

main(){
	fin>>inp;
	char s[10];
	int temp[10];
	for(int i=1;i<10;i++){
		if(generate(s,0,i)){
			break;
		}
	}
}
