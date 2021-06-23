#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: milk3
*/
using namespace std;

int res[21],a_cap,b_cap,c_cap,arr[1000][3],arrsize=0;

void check(int a,int b,int c){
	if(!(0<=a && a<=a_cap && 0<=b && b<=b_cap && 0<=c && c<=c_cap))return;
	for(int i=0;i<arrsize;i++){
		if(a==arr[i][0] && b==arr[i][1] && c==arr[i][2])return;
	}
	arr[arrsize][0]=a;
	arr[arrsize][1]=b;
	arr[arrsize][2]=c;
	arrsize++;
	if(res[c]==0){
		res[c]=1;
	}
	//c->b
	if(b+c>b_cap){
		check(a,b_cap,c-b_cap+b);
	}else{
		check(a,b+c,0);
	}
	//c->a
	if(a_cap<c){
		check(a_cap,b,c-a_cap);
	}else{
		check(c,b,0);
	}
	//b->a
	if(a_cap<b){
		check(a_cap,b-a_cap,c);
	}else{
		check(b,0,c);
	}
	//a->b
	if(a+b<=b_cap){
		check(0,a+b,c);
	}else{
		check(0,b_cap,c+(a+b-b_cap));
	}
	//b->c
	if(b!=0){
		if(c+b<c_cap){
			check(a,0,c+b);
		}else{
			check(a,b-(c_cap-c),c_cap);
		}
	}
	if(a+c<c_cap){
		check(0,b,a+c);
	}else{
		check(0,b+(c+a-c_cap),c_cap);
	}
}

main(){
	ifstream fin("milk3.in");
	ofstream fout("milk3.out");
	int n,i,j;
	cin>>a_cap>>b_cap>>c_cap;
	check(0,0,c_cap);
	j=0;
	for(i=0;i<21;i++){
		if(res[i]==1){
			if(j!=0){
				cout<<" ";
			}
			cout<<i;
			j++;
		}
	}
	cout<<endl;
}
