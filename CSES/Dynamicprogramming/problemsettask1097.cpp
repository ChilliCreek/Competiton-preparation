#include<iostream>
#include<algorithm>
using namespace std;
#define MOD 1000000007
#define ll long long

ll DP[5000][5000], arr[5000];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    ll n, sum = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
                DP[i][j] = -1;
        }
    }
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    for(int i = n - 1; i >= 0; i--){
        for(int j = i; j < n; j++){
            if(i == j){
                DP[i][j] = arr[i];
            }
            else{
                DP[i][j] = max(arr[i] - DP[i + 1][j], arr[j] - DP[i][j - 1]);
            }
        }
    }

    cout << (sum + DP[0][n - 1]) / 2;

}