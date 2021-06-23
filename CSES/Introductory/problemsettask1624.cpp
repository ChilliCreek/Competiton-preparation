#include <bits/stdc++.h>
using namespace std;

int res = 0;
char reserved[8][8];
bool rows[8];
bool columns[8];
bool diagonals1[15];
bool diagonals2[15];

void bad(int left){
	if(left == 0){
		res++;
		return;
	}
	bool qu;
	for(int i = 0; i < 8; i++){
		if(!rows[i]){
			for(int j = 0; j < 8; j++){
				if(reserved[i][j] == '.' && !columns[j] && !diagonals1[i + j] && !diagonals2[i + 7 - j]){
					rows[i] = true;
					columns[j] = true;
					diagonals1[i + j] = true;
					diagonals2[i + 7 - j] = true;
					reserved[i][j] = 'a';
					bad(left - 1);
					reserved[i][j] = '.';
					rows[i] = false;
					columns[j] = false;
					diagonals1[i + j] = false;
					diagonals2[i + 7 - j] = false;
				}
			}
			break;
		}
	}
}
int main()
{
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			cin >> reserved[i][j];
		}
	}
	memset(rows, false, sizeof(rows));
	memset(columns, false, sizeof(columns));
	memset(diagonals1, false, sizeof(diagonals1));
	memset(diagonals2, false, sizeof(diagonals2));
	bad(8);
	cout << res;
}
