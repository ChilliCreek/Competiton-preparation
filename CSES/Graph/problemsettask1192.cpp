#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define MOD 1000000007
#define ll long long

int n, m, curr = 1;

void dfs(vector<vector<bool> >& visited, vector<vector<int> >& dp, int i, int j, int roomNum){
    if(visited[i][j] || dp[i][j] == -1){
        return;
    }
    else{
        visited[i][j] = true;
    }
    if(dp[i][j] == 0){
        if(roomNum == -1){
            roomNum = curr;
            curr++;
        }
        dp[i][j] = roomNum;
        if(i - 1 >= 0){
            dfs(visited, dp, i - 1, j, roomNum);
        }
        if(j - 1 >= 0){
            dfs(visited, dp, i, j - 1, roomNum);
        }
        if(i + 1 < n){
            dfs(visited, dp, i + 1, j, roomNum);
        }
        if(j + 1 < m){
            dfs(visited, dp, i, j + 1, roomNum);
        }
    }
}
void dfsHelper(){

}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    char temp;
    cin >> n >> m;
    vector<vector<int> > dp(n, vector<int>(m, -1));
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> temp;
            if(temp == '#'){
                dp[i][j] = -1;
            }
            else if(temp == '.'){
                dp[i][j] = 0;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dfs(visited, dp, i, j, -1);
        }
    }

    cout << curr - 1 << '\n';
}