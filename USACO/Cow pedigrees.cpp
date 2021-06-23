#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: nocows
*/
using namespace std;

int table[101][202], N, K, factor;
int smalltrees[101][202];

int main() {
	//ifstream fin("nocows.in");
	//ofstream fout("nocows.out");
    fin >> N >> K;
    table[1][1] = 1;
    for (int i = 2; i <= K; i++) {
        for (int j = 1; j <= N; j += 2)
            for (int p = 1; p <= (j - 1 - p); p += 2) {
                if (p != (j - 1 - p)){
                	factor = 2;
				}else {
					factor = 1;  
				}  
                table[i][j] += factor * (smalltrees[i-2][p] * table[i-1][j-1-p] + table[i-1][p] * smalltrees[i-2][j-1-p] + table[i-1][p] * table[i-1][j-1-p]);
                table[i][j] %= 9901;
            }
        for (int p = 0; p <= N; p++) {        
            smalltrees[i-1][p] += table[i-1][p] + smalltrees[i-2][p]; 
            smalltrees[i-1][p] %= 9901;         
        }
    }
    
    fout << table[K][N] << endl;
}
