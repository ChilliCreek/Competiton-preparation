/*
ID: your_id_here
TASK: dualpal
LANG: C++                 
*/
#include<bits/stdc++.h>

using namespace std;

bool palindrom(int suuri,int too){
	string a;
	int lena;
	while(too>=suuri){
		a+=(too%suuri)+'0';
		too/=suuri;
	}
	a+=too+'0';
	lena=a.size();
	for(int i=0;i<lena/2;i++){
		if(a[i]!=a[lena-i-1]){
			return false;
		}
	}
	return true;
}

main(){
	ofstream fout ("dualpal.out");
    ifstream fin ("dualpal.in");
	int n,m,i,j,pal_left=2;
	bool b;
	
	fin>>m>>n;
	n++;
	while(m>0){
		j=0;
		for(i=2;i<=10;i++){
			if(palindrom(i,n)==true){
				j++;
				if(j==2){
					m--;
					fout<<n<<endl;
					break;
				}
			}
		}
		n++;
	}
}
