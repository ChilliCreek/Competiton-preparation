//https://cses.fi/problemset/task/1637
#include<bits/stdc++.h>

using namespace std;
#define MOD 1000000007
#define ll long long

bool ifDigitInNum(int digit, int num){
	int newDigit;
	while(num > 0){
		newDigit = num % 10;
		if(newDigit == digit){
			return true;
		}
		num /= 10;
	}
	return false;
}
int arr[1000011];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;
	fill(arr, arr+1000011, INT_MAX);
	arr[0] = 0;
	
	for(int i = 0; i <= 1000000; i++){
		for(int j = 1; j < 10; j++){
			if(ifDigitInNum(j, i + j)){
				//cout << i + j << ": " << arr[i + j] << " " << arr[i] + 1 << endl;
				if(arr[i + j] > arr[i] + 1){
					arr[i + j] = arr[i] + 1;
				}
			}
		}
	}
	
	cout << arr[n];
	
}
