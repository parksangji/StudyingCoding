#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int k,w,h;

vector<vector<int>> matrix;

struct info{
    int cnt;
    int k;
    int x;
    int y;
};

int dx[] = {-2,-1,1,2,2,1,-1,-2};
int dy[] = {1,2,2,1,-1,-2,-2,-1};
int dxx[] = {0,0,1,-1};
int dyy[] = {1,-1,0,0};
void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> k >> w >> h;

    matrix.resize(h,vector<int>(w));

    for(int i=0; i<h; i++){
        for(int j=0 ;j <w ; j++){
            cin >>  matrix[i][j];
        }
    }
}

bool outRange(int x,int y){
    if(x < 0 or y < 0 or x >= h or y >= w) return true;
    return false;
}

void solution(){
    vector<vector<vector<bool>>> visited(h,vector<vector<bool>>(w,vector<bool>(31)));
    queue<info> q;

    visited[0][0][0] = true;
    q.push({0,0,0,0});
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        int kk = q.front().k;
        q.pop();

        if(x == h-1 and y == w-1){
            cout << cnt ;
            return;
        }
        if(kk < k){
            for(int i=0; i<8; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(outRange(nx,ny)) continue;
                if(visited[nx][ny][kk+1] or matrix[nx][ny]) continue;

                visited[nx][ny][kk+1] = true;
                q.push({cnt+1,kk+1,nx,ny});
            }
        }
        
        for(int i=0; i<4; i++){
            int nx = x + dxx[i];
            int ny = y + dyy[i];

            if(outRange(nx,ny)) continue;
            if(visited[nx][ny][kk] or matrix[nx][ny]) continue;

            visited[nx][ny][kk] = true;
            q.push({cnt+1,kk,nx,ny});
        }
        
    }

    cout << -1;
}

int main(){
    input();
    solution();

    return 0;
}