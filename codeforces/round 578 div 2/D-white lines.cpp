#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int, int> PII;
 
int n, k, whiteStart = 0;   //the number of rows and columns that are initially white, they are treated specially
 
string arr[2005];
 
PII rows[2005];     //rows[i] denotes the first and the last column that is black in the ith row
 
PII cols[2005];     //cols[i] denotes the first and the last row that is black in the ith column
 
int ansForRows[2005][2005];  //how many rows will become white if I click in the cell [i,j]
 
int ansForCols[2005][2005];  //how many columns will become white if I click in the cell [i,j]
 
//checks if a row can become white
bool check1(int row, int col) {
    if (rows[row].first == n) return false;    //white row since the beginning
    return rows[row].first >= col && rows[row].second < col+k;
}
 
//checks if a column can become white
bool check2(int col, int row) {
    if (cols[col].first == n) return false;    //white column since the beginning
    return cols[col].first >= row && cols[col].second < row+k;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    cin >> n >> k;
    for (int i=0; i<n; i++) {
        cin >> arr[i];
    }
 
    for (int i=0; i<n; i++) {          //fill the 'rows' table
        int bMin = n, bMax = -1;
        for (int j=0; j<n; j++) {
            if (arr[i][j] == 'B') {
                bMin = min(bMin, j);
                bMax = j;
            }
        }
        if (bMin == n) whiteStart++;
        rows[i] = {bMin, bMax};
    }
 
    for (int i=0; i+k-1<n; i++) {       //put the click point in the ith column
            int tmp = 0;
            for (int x=0; x<k; x++) {     //compute for [0][i]
                if (check1(x, i)) tmp++;
            }
            ansForRows[0][i] = tmp;
            for (int j=1; j+k-1<n; j++) {     //use the 'sliding window' to compute for [j][i]
                ansForRows[j][i] = ansForRows[j-1][i] - check1(j-1, i) + check1(j+k-1, i);
            }
    }
 
    for (int i=0; i<n; i++) {           //fill the 'cols' table
        int bMin = n, bMax = -1;
        for (int j=0; j<n; j++) {
            if (arr[j][i] == 'B') {
                bMin = min(bMin, j);
                bMax = j;
            }
        }
        if (bMin == n) whiteStart++;
        cols[i] = {bMin, bMax};
    }
 
    for (int i=0; i+k-1<n; i++) {       //put the click point in the ith row
            int tmp = 0;
            for (int x=0; x<k; x++) {   //compute for [i][0]
                if (check2(x, i)) tmp++;
            }
            ansForCols[i][0] = tmp;
            for (int j=1; j+k-1<n; j++) {   //use the 'sliding window' to compute for [i][j]
                ansForCols[i][j] = ansForCols[i][j-1] - check2(j-1, i) + check2(j+k-1, i);
            }
    }
 
    int ans = INT_MIN;
    for (int i=0; i<n; i++) {        //compute the answer
        for (int j=0; j<n; j++) {
            ans = max(ans, ansForRows[i][j] + ansForCols[i][j]);
        }
    }
 
    cout << ans + whiteStart;
 
    return 0;
