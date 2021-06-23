#include<bits/stdc++.h>

/*
ID: your_id_here
TASK: transform
LANG: C++                 
*/
using namespace std;

int n;

bool rotate_90(bool img[11][11],bool res[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(img[i][j]!=res[j][n-1-i])return false;
		}
	}
	return true;
}

bool rotate_180(bool img[11][11],bool res[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(img[i][j]!=res[n-1-i][n-1-j])return false;
		}
	}
	return true;
}

bool rotate_270(bool img[11][11],bool res[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(img[i][j]!=res[n-1-j][i])return false;
		}
	}
	return true;
}

bool mirror(bool img[11][11],bool res[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(img[i][j]!=res[i][n-1-j])return false;
		}
	}
	return true;
}

bool case_anton(bool img[11][11],bool res[11][11]){
	bool temp[11][11];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp[i][j]=img[i][n-1-j];
		}
	}
	if(rotate_90(temp,res))return true;
	else if(rotate_180(temp,res))return true;
	else if(rotate_270(temp,res))return true;
	return false;
}

bool check(bool img[11][11],bool res[11][11]){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(img[i][j]!=res[i][j])return false;
		}
	}
	return true;
}

main(){
	ofstream fout ("transform.out");
    ifstream fin ("transform.in");
	int i,j;
	char temp;
	
	fin>>n;
	
	bool img[11][11],res[11][11];
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		    fin>>temp;
		    if(temp=='@'){
		    	img[i][j]=true;
		    }else{
		    	img[i][j]=false;
		    }
		}
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
		    fin>>temp;
		    if(temp=='@'){
		    	res[i][j]=true;
		    }else{
		    	res[i][j]=false;
		    }
		}
	}
	if(rotate_90(img,res))fout<<'1'<<endl;
	else if(rotate_180(img,res))fout<<'2'<<endl;
	else if(rotate_270(img,res))fout<<'3'<<endl;
	else if(mirror(img,res))fout<<'4'<<endl;
	else if(case_anton(img,res))fout<<'5'<<endl;
	else if(check(img,res))fout<<'6'<<endl;
	else fout<<'7'<<endl;
}
