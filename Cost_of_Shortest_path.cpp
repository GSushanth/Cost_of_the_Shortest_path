#include <bits/stdc++.h> 
using namespace std; 

#define r 5 
#define c 5 

int pathdetector(int i, int j, int k[r][c], int g[r][c]){
    int east,west,north,south;
    int min = INT_MAX;
    int dir;
    if( 0<=(i-1) && (i-1)<c && 0<=j && j<r && k[i-1][j]!=1){
        if(g[i-1][j]<min){
            min=g[i-1][j];
            dir = 0; //north
        }
    }
    if( 0<=i && i<c && 0<=(j+1) && (j+1)<r && k[i][j+1]!=1){
        if(g[i][j+1]<min){
            min=g[i][j+1];
            dir = 1; //east
        }
    }
    if( 0<=(i+1) && (i+1)<c && 0<=j && j<r && k[i+1][j]!=1){
        if(g[i+1][j]<min){
            min=g[i+1][j];
            dir = 2; //south
        }
    }
    if( 0<=i && i<c && 0<=(j-1) && (j-1)<r && k[i][j-1]!=1){
        if(g[i][j-1]<min){
            min=g[i][j-1];
            dir = 3; //west
        }
    }
    cout << "(" << i << "," << j << ")" << endl;
    return dir;
}

int leastdist(int g[r][c]){
    int k[r][c] = {0};
    int i=r-1, j=0;
    int ans = g[i][j];
    
    cout << "STEPS:" << endl;
    while((i!=0 || j!=r-1)){
        int dir = pathdetector(i, j, k , g);
        // cout << dir << endl;
        k[i][j] = 1;
        if(dir == 0){
            ans += g[i-1][j];
            i = i-1;
        }
        if(dir == 1){
            ans += g[i][j+1];
            j = j+1;
        }
        if(dir == 2){
            ans += g[i+1][j];
            i = i+1;
        }
        if(dir == 3){
            ans += g[i][j-1];
            j = j-1;
        }
    }
    
    return ans;
}

int main() {
	int g[r][c] = 
	{ 
		31, 100, 65, 12, 18, 
		10, 13, 47, 157, 6, 
		100, 113, 174, 11, 33, 
		88, 124, 41, 20, 140, 
		99, 32, 111, 41, 20 
	}; 
	
	cout << "\nCOST OF THE SHORTEST PATH=>>" << leastdist(g);
	
	return 0;
}
