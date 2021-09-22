//https://cses.fi/problemset/task/2205
#include<bits/stdc++.h>

using namespace std;

int main(){
	int bitNum, curr = 1, len = 2;
	bool arr[16][65536];
	cin >> bitNum;
	memset(arr, false, sizeof(arr));
	arr[15][1] = true;
	while(curr < bitNum){
		for(int i = 16 - curr; i < 16; i++){
			for(int j = 0; j < len; j++){
				arr[i][len * 2 - 1 - j] = arr[i][j];
			}
		}
		curr++;
		for(int i = len; i < len * 2; i++){
			arr[16 - curr][i] = true;
		}
		len *= 2;
	}
	for(int i = 0; i < len; i++){
		for(int j = 16 - curr; j < 16; j++){
			cout << arr[j][i];
		}
		cout << '\n';
	}
}
