#include<bits/stdc++.h>

/*
ID: chiig.e1
TASK: maze1
LANG: C++                 
*/

using namespace std;

int w, h;

struct Tile{
	int val[2];
	bool visited = false;
	bool left = false;
	bool right = false;
	bool north = false;
	bool south = false;
	Tile(){
		val[0] = INT_MAX;
		val[1] = INT_MAX;
	}
};

struct Pos{
	int x;
	int y;
	Pos(){
		x = -1;
		y = -1;
	}
};

Pos findNext(Tile** tiles, int type){
	Pos res;
	int min = INT_MAX;
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(!tiles[i][j].visited && tiles[i][j].val[type] < min){
				min = tiles[i][j].val[type];
				res.x = i;
				res.y = j;
			}
		}
	}
	return res;
}

//#define fin cin
//#define fout cout


int main(){
	int curr_point = 0;
	ofstream fout ("maze1.out");
    ifstream fin ("maze1.in");
    fin >> w >> h;
    Tile** tiles = new Tile*[h];
    for(int i = 0; i < h; i++){
    	tiles[i] = new Tile[w];
	}
    string inp;
    Pos points[2];
    
    int i = 0;
    getline(fin, inp, '\n');
    while(i < (2*h + 1)){
    	getline(fin, inp, '\n');
    	if(i == 0){
    		for(int j = 1; j < 2*w+1; j+=2){
    			if(inp[j] == ' '){
    				tiles[i / 2][(j-1) / 2].val[curr_point] = 0;
    				points[curr_point].x = i / 2;
    				points[curr_point].y = (j-1)/2;
    				curr_point++;
				}
			}
		}else if(i == 2*h){
			for(int j = 1; j < 2*w+1; j+=2){
    			if(inp[j] == ' '){
    				tiles[i / 2 - 1][(j-1) / 2].val[curr_point] = 0;
    				points[curr_point].x = i / 2 - 1;
    				points[curr_point].y = (j-1)/2;
    				curr_point++;
				}
			}
		}else if(i % 2 == 1){
			if(inp[0] == ' '){
				tiles[i / 2][0].val[curr_point] = 0;
				points[curr_point].x = i / 2;
    			points[curr_point].y = 0;
    			curr_point++;
			}
			for(int j = 2; j < 2*w+1; j+=2){
				if(inp[j] == ' '){
					tiles[i/2][j/2-1].right = true;
					tiles[i/2][j/2].left = true;
				}
			}
			if(inp[2*w] == ' '){
				tiles[i/2][w - 1].val[curr_point] = 0;
				points[curr_point].x = i/2;
    			points[curr_point].y = w-1;
    			curr_point++;
			}
		}else if(i%2 == 0){
			for(int j = 1; j < 2*w+1; j+=2){
    			if(inp[j] == ' '){
    				tiles[i/2-1][(j-1)/2].south = true;
    				tiles[i/2][(j-1)/2].north = true;
				}
			}
		}
		//cout << i << endl;
    	i++;
	}
	
	curr_point = 0;
	Pos cp;
	while(1){
		cp = findNext(tiles, curr_point);
		if(cp.x == -1){
			if(curr_point == 1){
				break;
			}
			else{
				curr_point++;
				for(int j = 0; j < h; j++){
					for(int p = 0; p < w;p++){
						tiles[j][p].visited = false;
					}
				}
			}
		}else{
			tiles[cp.x][cp.y].visited = true;
			if(tiles[cp.x][cp.y].left && !tiles[cp.x][cp.y - 1].visited){
				tiles[cp.x][cp.y - 1].val[curr_point] = min(tiles[cp.x][cp.y].val[curr_point] + 1, tiles[cp.x][cp.y - 1].val[curr_point]);
			}
			if(tiles[cp.x][cp.y].right && !tiles[cp.x][cp.y + 1].visited){
				tiles[cp.x][cp.y + 1].val[curr_point] = min(tiles[cp.x][cp.y].val[curr_point] + 1, tiles[cp.x][cp.y + 1].val[curr_point]);
			}
			if(tiles[cp.x][cp.y].north && !tiles[cp.x - 1][cp.y].visited){
				tiles[cp.x - 1][cp.y].val[curr_point] = min(tiles[cp.x][cp.y].val[curr_point] + 1, tiles[cp.x - 1][cp.y].val[curr_point]);
			}
			if(tiles[cp.x][cp.y].south && !tiles[cp.x + 1][cp.y].visited){
				tiles[cp.x + 1][cp.y].val[curr_point] = min(tiles[cp.x][cp.y].val[curr_point] + 1, tiles[cp.x + 1][cp.y].val[curr_point]);
			}
		}
	}
	int res = 0;
//	cout << endl;
//	for(i = 0; i < h; i++){
//		for(int j = 0; j < w; j++){
//			cout << tiles[i][j].val[0] << " ";
//		}
//		cout << endl;
//	}
//	for(i = 0; i < h; i++){
//		for(int j = 0; j < w; j++){
//			cout << tiles[i][j].val[1] << " ";
//		}
//		cout << endl;
//	}
	for(i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			res = max(res, min(tiles[i][j].val[0], tiles[i][j].val[1]));
		}
	}
	fout << res + 1 << endl;
	for(i = 0; i < h; i++){
    	delete[] tiles[i];
	}
	delete[] tiles;
}
