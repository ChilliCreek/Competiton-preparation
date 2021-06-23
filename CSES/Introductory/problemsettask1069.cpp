#include<bits/stdc++.h>

using namespace std;

int main(){
	char inp, prev = 'a';
	int count, max = INT_MIN;
	while(cin >> inp){
		if(inp != prev){
			count = 1;
		}
		else{
			++count; 
		}
		if(max < count){
			max = count;
		}
		prev = inp;
	}
	cout << max;
}
