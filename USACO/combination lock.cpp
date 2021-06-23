#include<bits/stdc++.h>
/*
ID: chiig.e1
TASK: combo
LANG: C++                 
*/
using namespace std;

struct tri{
	int a;
	int b;
	int c;
	bool operator<(const tri& it) const{
		return a<it.a||(a==it.a && (b<it.b || (b==it.b && c<it.c)));
	}
	bool operator==(const tri& it) const{
		return a==it.a && b==it.b && c==it.c;
	}
};

main(){
	ofstream fout ("combo.out");
    ifstream fin ("combo.in");
	tri temp;
	int n,i,j,p,aa,bb,cc;
	map<tri,bool>save;
	fin>>n;
	fin>>aa>>bb>>cc;
	if(n==1){
		fout<<1<<endl;
	}else if(n==2){
		fout<<8<<endl;
	}else{
		for(i=aa-2;i<=aa+2;i++){
			if(i==0){
				temp.a=n;
			}else if(i==-1){
				temp.a=n-1;
			}else if(i==n+1){
				temp.a=1;
			}else if(i==n+2){
				temp.a=2;
			}else{
				temp.a=i;
			}
			for(j=bb-2;j<=bb+2;j++){
				if(j==0){
					temp.b=n;
				}else if(j==-1){
					temp.b=n-1;
				}else if(j==n+1){
					temp.b=1;
				}else if(j==n+2){
					temp.b=2;
				}else{
					temp.b=j;
				}
				for(p=cc-2;p<=cc+2;p++){
					if(p==0){
						temp.c=n;
					}else if(p==-1){
						temp.c=n-1;
					}else if(p==n+1){
						temp.c=1;
					}else if(p==n+2){
						temp.c=2;
					}else{
						temp.c=p;
					}
					save[temp]=1;
				}
			}
		}
		fin>>aa>>bb>>cc;
		for(i=aa-2;i<=aa+2;i++){
			if(i==0){
				temp.a=n;
			}else if(i==-1){
				temp.a=n-1;
			}else if(i==n+1){
				temp.a=1;
			}else if(i==n+2){
				temp.a=2;
			}else{
				temp.a=i;
			}
			for(j=bb-2;j<=bb+2;j++){
				if(j==0){
					temp.b=n;
				}else if(j==-1){
					temp.b=n-1;
				}else if(j==n+1){
					temp.b=1;
				}else if(j==n+2){
					temp.b=2;
				}else{
					temp.b=j;
				}
				for(p=cc-2;p<=cc+2;p++){
					if(p==0){
						temp.c=n;
					}else if(p==-1){
						temp.c=n-1;
					}else if(p==n+1){
						temp.c=1;
					}else if(p==n+2){
						temp.c=2;
					}else{
						temp.c=p;
					}
					if(save.find(temp)==save.end()){
						save[temp]=1;
					}
				}
			}
		}
		fout<<save.size()<<endl;
	}
}
