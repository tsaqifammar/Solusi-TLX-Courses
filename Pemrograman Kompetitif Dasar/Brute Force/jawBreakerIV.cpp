#include "bits/stdc++.h"
using namespace std;

vector<vector<char>> mat (25, vector<char>(25)), tmp, tmp1;
int m, n;

// dfs at idx i, j and return area of destruction

int dfs(int i, int j, char c){
    tmp[i][j] = '.';
    int cnt = 0;
    if (i > 0 && tmp[i-1][j] == c)
        cnt += dfs(i-1, j, c);
    if (j > 0 && tmp[i][j-1] == c)
        cnt += dfs(i, j-1, c);
    if (i < m-1 && tmp[i+1][j] == c)
        cnt += dfs(i+1, j, c);
    if (j < n-1 && tmp[i][j+1] == c)
        cnt += dfs(i, j+1, c);
    return 1 + cnt;
}

void gravity(){
    int k;
    for (int i = m-1; i >= 0; i--){
        for (int j = 0; j < n; j++){
            k = i;
            while (k < m-1 && tmp[k+1][j] == '.'){
                swap(tmp[k][j], tmp[k+1][j]);
                k++;
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    int tmpVal, tmpVal2, maxo = 0;
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            tmp = mat;

            // first dfs
            tmpVal = dfs(i, j, tmp[i][j]);
            gravity();
            if (tmpVal == 1) // can only take if there's > 1
            	continue;

            tmp1 = tmp;
            // second dfs
            int maxo2 = 0;
            for (int k = 0; k < m; k++)
                for (int l = 0; l < n; l++){
                    if (tmp[k][l] == '.') continue;
                    tmp = tmp1;
                    tmpVal2 = dfs(k, l, tmp[k][l]);
                    maxo2 = max(maxo2, tmpVal2);
                }
            maxo = max(maxo, tmpVal*(tmpVal-1) + maxo2*(maxo2-1));
        }
    }
    cout << maxo << '\n';
}
