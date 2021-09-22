//https://cses.fi/problemset/task/2165
#include<bits/stdc++.h>

using namespace std;
stringstream res;
int k = 0;
void hanoi(int steps, int a, int b, int c){
	if(steps == 1){
		res << '\n' << a << " " << c;
		k++;
	}
	else{
		hanoi(steps - 1, a, c, b);
		res << '\n' << a << " " << c;
		k++;
		hanoi(steps - 1, b, a, c);
	}
}


int main(){
	int n;
	cin >> n;
	hanoi(n, 1, 2, 3);
	cout << k;
	cout << res.str();
}
