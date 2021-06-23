#include<bits/stdc++.h>

using namespace std;

enum dir{
	null = 0, left = 1, up = 2, right = 3, down = 4
};

int res = 0;
bool mat[7][7];

void search(const std::string& inp, dir prev, int cur, int x, int y){
	if(x == 0 && y == 0){
		//cout << "aa " << cur << endl;
		if(cur == 48){
			res++;
			return;
		}
		else{
			return;
		}
	}
	if(inp[cur] != '?'){
		if(inp[cur] == 'R' && y < 6 && !mat[x][y + 1]){
			mat[x][y] = true;
			search(inp, dir::right, cur + 1, x, y + 1);
			mat[x][y] = false;
		}
		else if(inp[cur] == 'L' && y > 0 && !mat[x][y - 1]){
			mat[x][y] = true;
			search(inp, dir::left, cur + 1, x, y - 1);
			mat[x][y] = false;
		}
		else if(inp[cur] == 'D' && x > 0 && !mat[x - 1][y]){
			mat[x][y] = true;
			search(inp, dir::down, cur + 1, x - 1, y);
			mat[x][y] = false;
		}
		else if(inp[cur] == 'U' && x < 6 && !mat[x + 1][y]){
			mat[x][y] = true;
			search(inp, dir::up, cur + 1, x + 1, y);
			mat[x][y] = false;
		}
	}
	else{
		if(prev == dir::down){
			if(x == 0 || mat[x - 1][y]){
				bool lopen = false, ropen = false;
				if(y > 0 && !mat[x][y - 1]){
					lopen = true;
				}
				if(y < 6 && !mat[x][y + 1]){
					ropen = true;
				}
				if(lopen && ropen){
					return;
				}
			}
		}
		else if(prev == dir::up){
			if(x == 6 || mat[x + 1][y]){
				bool lopen = false, ropen = false;
				if(y > 0 && !mat[x][y - 1]){
					lopen = true;
				}
				if(y < 6 && !mat[x][y + 1]){
					ropen = true;
				}
				if(lopen && ropen){
					return;
				}
			}
		}
		else if(prev == dir::right){
			if(y == 6 || mat[x][y + 1]){
				bool dopen = false, uopen = false;
				if(x > 0 && !mat[x - 1][y]){
					dopen = true;
				}
				if(x < 6 && !mat[x + 1][y]){
					uopen = true;
				}
				if(dopen && uopen){
					return;
				}
			}
		}
		else if(prev == dir::left){
			if(y == 0 || mat[x][y - 1]){
				bool dopen = false, uopen = false;
				if(x > 0 && !mat[x - 1][y]){
					dopen = true;
				}
				if(x < 6 && !mat[x + 1][y]){
					uopen = true;
				}
				if(dopen && uopen){
					return;
				}
			}
		}
		if(y > 0 && !mat[x][y - 1]){
			mat[x][y] = true;
			search(inp, dir::left, cur + 1, x, y - 1);
			mat[x][y] = false;
		}
		if(y < 6 && !mat[x][y + 1]){
			mat[x][y] = true;
			search(inp, dir::right, cur + 1, x, y + 1);
			mat[x][y] = false;
		}
		if(x > 0 && !mat[x - 1][y]){
			mat[x][y] = true;
			search(inp, dir::down, cur + 1, x - 1, y);
			mat[x][y] = false;
		}
		if(x < 6 && !mat[x + 1][y]){
			mat[x][y] = true;
			search(inp, dir::up, cur + 1, x + 1, y);
			mat[x][y] = false;
		}
	}
}
void searchHelper(const std::string& inp){
	mat[6][0] = true;
	if(inp[0] == 'D'){
		search(inp, dir::down, 1, 5, 0);
	}
	else if(inp[0] == 'R'){
		search(inp, dir::right, 1, 6, 1);
	}
	else{
		search(inp, dir::down, 1, 5, 0);
		search(inp, dir::right, 1, 6, 1);
	}
}

int main(){
	string inp;
	cin >> inp;
	memset(mat, false, sizeof(mat));
	searchHelper(inp);
	cout << res;
}
