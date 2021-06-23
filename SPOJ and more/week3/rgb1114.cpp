#include<bits/stdc++.h>

using namespace std;

#define blue true
#define red false


class strands{
	public:
		int st;
		int en;
		int len;
};

strands b[350],r[350];
int n,indexr,indexb;
string inp;
int nextval(char c,int st){
	while(st<n){
		if(inp[st]==c || inp[st]=='w'){
			return st;
		}
		st++;
	}
	return -1; 
}
int untilval(char c,int st){
	while(st<n){
		if(inp[st]!=c && inp[st]!='w'){
			return st-1;
		}
		st++;
	}
	return n-1;
}
void bsearch(){
	int t=0,index=0;
	strands temp;
	while(t<n){
		if(nextval('b',t)!=-1){
			temp.st=nextval('b',t);
		}else{
			break;
		}
		temp.en=untilval('b',temp.st);
		temp.len=temp.en-temp.st+1;
		b[index]=temp;
		index++;
		t=temp.en+1;
	}
	indexb=index;
}

void rsearch(){
	int t=0,index=0;
	strands temp;
	while(t<n){
		if(nextval('r',t)!=-1){
			temp.st=nextval('r',t);
		}else{
			break;
		}
		temp.en=untilval('r',temp.st);
		temp.len=temp.en-temp.st+1;
		r[index]=temp;
		index++;
		t=temp.en+1;
	}
	indexr=index;
}

main(){
	int maxx=0,i,j;
	strands temp;
	
	cin>>n;
	cin>>inp;
	
	bsearch();
	rsearch();
	if(b[0].st==0 && b[indexb-1].en==n-1)
	{
		temp.st=b[indexb-1].st;
		temp.en=b[0].en;
		temp.len=b[0].len+b[indexb-1].len;
		b[indexb]=temp;
		indexb++;
	}
	if(r[0].st==0 && r[indexr-1].en==n-1){
		temp.st=r[indexr-1].st;
		temp.en=r[0].en;
		temp.len=r[0].len+r[indexr-1].len;
		r[indexr]=temp;
		indexr++;
	}
	for(i=0;i<indexb;i++){
		for(j=0;j<indexr;j++){
			if(b[i].st==0){
				if(r[j].en==n-1){
					if(maxx<b[i].len+r[j].len){
						maxx=b[i].len+r[j].len;
					}
				}
			}else{
				if(r[j].en==b[i].st-1){
					if(maxx<b[i].len+r[j].len){
						maxx=b[i].len+r[j].len;
					}
				}
			}
			if(b[i].en==n-1){
				if(r[j].st==0){
					if(maxx<b[i].len+r[j].len){
						maxx=b[i].len+r[j].len;
					}
				}
			}else{
				if(r[j].st==b[i].en+1){
					if(maxx<b[i].len+r[j].len){
						maxx=b[i].len+r[j].len;
					}
				}
			}
		}
	}
	cout<<maxx;
}
