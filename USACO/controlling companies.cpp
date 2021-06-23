#include<bits/stdc++.h>
 /*
ID: chiig.e1
LANG: C++
TASK: concom
*/
using namespace std;

#define MAX 101

int owns[MAX][MAX];         
bool controls[MAX][MAX];    

void addcontroller(int i, int j){
    int k;

    if(controls[i][j])return;

    controls[i][j] = 1;
    for(k=0; k<MAX; k++){
        owns[i][k] += owns[j][k];
    }

    for(k=0; k<MAX; k++){
        if(controls[k][i]){
            addcontroller(k, j);
        }
    }
    
    for(k=0; k<MAX; k++)
        if(owns[i][k] > 50)
            addcontroller(i, k);
}

void addowner(int i, int j, int p){
    int k;
    for(k=0; k<MAX; k++){
        if(controls[k][i]){
            owns[k][j] += p;
        }
    }
    for(k=0; k<MAX; k++){
        if(owns[k][j] > 50){
            addcontroller(k, j);
        }
    }
}

int main(){
    int i, j, n, a, b, p;

    ifstream fin("concom.in");
    ofstream fout("concom.out");

    for(i=0; i<MAX; i++)
        controls[i][i] = 1;

    fin >> n;
    for(i=0; i<n; i++) {
        fin >> a >> b >> p;
        addowner(a, b, p);
    }

    for(i=0; i<MAX; i++){
    	for(j=0; j<MAX; j++){
    		if(i != j && controls[i][j]){
    			fout << i << " " << j << endl;
			}
		}
	}
}
