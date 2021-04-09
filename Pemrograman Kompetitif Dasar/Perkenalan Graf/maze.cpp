#include "bits/stdc++.h"
using namespace std;

using pii = pair<int,int>;

int mat[100][100];
int dist[100][100];
int r, c;

int bfs(int x, int y){
    queue<pii> q;
    memset(dist, -1, sizeof(dist));

    dist[x][y] = 1;
    q.push({x, y});

    pii check;
    while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        // pinggir
        if (x == 0 || y == 0 || x == r-1 || y == c-1)
            return dist[x][y];

        // cek all directions
        if (x > 0 && mat[x-1][y] == 0 && dist[x-1][y] == -1){
            q.push({x-1,y});
            dist[x-1][y] = dist[x][y] + 1;
        }
        if (y > 0 && mat[x][y-1] == 0 && dist[x][y-1] == -1){
            q.push({x,y-1});
            dist[x][y-1] = dist[x][y] + 1;
        }
        if (x < r-1 && mat[x+1][y] == 0 && dist[x+1][y] == -1){
            q.push({x+1,y});
            dist[x+1][y] = dist[x][y] + 1;
        }
        if (y < c-1 && mat[x][y+1] == 0 && dist[x][y+1] == -1){
            q.push({x,y+1});
            dist[x][y+1] = dist[x][y] + 1;
        }
    }
    return -1;
}

int main(){
    cin >> r >> c;
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> mat[i][j];
    int x, y;
    cin >> x >> y;
    cout << bfs(x-1, y-1) << '\n';;
}
