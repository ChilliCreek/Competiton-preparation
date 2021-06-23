#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: pprime
*/

using namespace std;


int n1,n2,mi_uni;
map <int,bool> gg;
void if_prime(int num){
	if(n1<=num && num<=n2){
		for(int i=2;i<=sqrt(num);i++){
			if(num%i==0){
				return;
			}
		}
		gg[num]=true;
	}
}

void make_pal(int mi,int ma,string num,int pos){
	if(mi>ma){
		return;
	}else{
		string temp;
		num+="0";
		for(int i=1;i<=10;i++){
			if(pos==0 && i==1){
			}else{
				if(pos*2+1>=mi_uni){
					make_pal(mi+2,ma,num,pos+1);
					temp=num;
					for(int j=num.size()-2;j>-1;j--){
						temp+=temp[j];
					}
					if_prime(stoi(temp));
				}else{
					make_pal(mi,ma,num,pos+1);
				}
			}
			num[pos]++;
		}
	}
}

main(){
	ifstream fin("pprime.in");
    ofstream fout("pprime.out");
	int mi=0,ma=0,in=0,n1_save,n2_save;
	string send;
	map <int,bool>::iterator it;
	fin>>n1>>n2;
	n1_save=n1;
	n2_save=n2;
	while(n1_save>0){
		n1_save/=10;
		mi++;
	}
	while(n2_save>0){
		n2_save/=10;
		ma++;
	}
	mi_uni=mi;
	make_pal(mi,ma,send,0);
	for(it=gg.begin();it!=gg.end();it++){
		if(n1<=11 && n2>=11 && in==0 && it->first==101){
			fout<<11<<endl;
			in=1;
		}
		fout<<it->first<<endl;
		if(n1<=11 && n2>=11 && in==0 && it->first==7){
			fout<<11<<endl;
			in=1;
		}
	}
}
