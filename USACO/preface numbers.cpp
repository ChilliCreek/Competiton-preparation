#include <bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: preface
*/
using namespace std;

int arr[10];

struct numtorom{
	bool char1exist=false;
	char char1;
	int num1;
	bool char2exist=false;
	char char2;
	int num2;
	void set1(char c,int n){
		char1exist=true;
		char1=c;
		num1=n;
	} 
	void set2(char c,int n){
		char2exist=true;
		char2=c;
		num2=n;
	}
	void setchar1(char c){
		char1=c;
	}
	void setchar2(char c){
		char2=c;
	}
	void add(map<char,int>& k,int multiplier){
		if(char1exist && multiplier !=0){
			k[char1]+=num1*multiplier;
		}
		if(char2exist && multiplier !=0){
			k[char2]+=num2*multiplier;
		}
	}
};
numtorom convertertable[4][10];
main(){
	ifstream fin("preface.in");
	ofstream fout("preface.out");
	int inp,denom=10,temp,temp1,index=1;
	map<char,int> res;
	fin>>inp;
	convertertable[1][1].set1('I',1);
	convertertable[1][2].set1('I',2);
	convertertable[1][3].set1('I',3);
	convertertable[1][4].set1('I',1);
	convertertable[1][4].set2('V',1);
	convertertable[1][5].set1('V',1);
	convertertable[1][6].set1('V',1);
	convertertable[1][6].set2('I',1);
	convertertable[1][7].set1('V',1);
	convertertable[1][7].set2('I',2);
	convertertable[1][8].set1('V',1);
	convertertable[1][8].set2('I',3);
	convertertable[1][9].set1('I',1);
	convertertable[1][9].set2('X',1);
	convertertable[2][1].set1('X',1);
	convertertable[2][2].set1('X',2);
	convertertable[2][3].set1('X',3);
	convertertable[2][4].set1('X',1);
	convertertable[2][4].set2('L',1);
	convertertable[2][5].set1('L',1);
	convertertable[2][6].set1('L',1);
	convertertable[2][6].set2('X',1);
	convertertable[2][7].set1('L',1);
	convertertable[2][7].set2('X',2);
	convertertable[2][8].set1('L',1);
	convertertable[2][8].set2('X',3);
	convertertable[2][9].set1('X',1);
	convertertable[2][9].set2('C',1);
	convertertable[3][1].set1('C',1);
	convertertable[3][2].set1('C',2);
	convertertable[3][3].set1('C',3);
	convertertable[3][4].set1('C',1);
	convertertable[3][4].set2('D',1);
	convertertable[3][5].set1('D',1);
	convertertable[3][6].set1('D',1);
	convertertable[3][6].set2('C',1);
	convertertable[3][7].set1('D',1);
	convertertable[3][7].set2('C',2);
	convertertable[3][8].set1('D',1);
	convertertable[3][8].set2('C',3);
	convertertable[3][9].set1('C',1);
	convertertable[3][9].set2('M',1);
	convertertable[4][1].set1('M',1);
	convertertable[4][2].set1('M',2);
	convertertable[4][3].set1('M',3);
	while(denom<=inp*10){
		for(int i=1;i<10;i++){
			convertertable[index][i].add(res,inp/denom*(denom/10));
		}
		temp=inp%denom;
		while(temp>9){
			temp/=10;
		}
		for(int i=1;i<temp;i++){
			convertertable[index][i].add(res,denom/10);
		}
		convertertable[index][temp].add(res,inp%(denom/10)+1);
		denom*=10;
		index++;
	}
	if(res.find('I')!=res.end()){
		fout<<"I "<<res['I']<<endl;
	}
	if(res.find('V')!=res.end()){
		fout<<"V "<<res['V']<<endl;
	}
	if(res.find('X')!=res.end()){
		fout<<"X "<<res['X']<<endl;
	}
	if(res.find('L')!=res.end()){
		fout<<"L "<<res['L']<<endl;
	}
	if(res.find('C')!=res.end()){
		fout<<"C "<<res['C']<<endl;
	}
	if(res.find('D')!=res.end()){
		fout<<"D "<<res['D']<<endl;
	}
	if(res.find('M')!=res.end()){
		fout<<"M "<<res['M']<<endl;
	}
}
