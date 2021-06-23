#include<bits/stdc++.h>
 
using namespace std; 
 /*
ID: chiig.e1
TASK: gift1
LANG: C++                 
*/
main(){
	    ofstream fout ("gift1.out");
        ifstream fin ("gift1.in");
	    int n;
	    map<string,int>	a;
        
 
		fin >> n;
		string s[11],temp;
		int zeel,num;
		string name;
		string taker;
		
	    for(int i=1; i<=n; i++){
			fin >> temp;
	    	s[i]=temp;
			a[temp]=0; 
	    }
	    for(int i=1; i<=n; i++){
	    	fin >> name;
	    	fin >> zeel>> num;
	        for(int j=1; j<=num; j++){
				fin >> taker; 
				a[taker]=a[taker]+zeel/num;	
	        }
	        if(num!=0){a[name]+=zeel%num-zeel; 
	        }
	    }
	   for(int p=1; p<=n; p++){
	   	fout << s[p] <<" "<< a[s[p]]<< endl;
	   }
 
} 
