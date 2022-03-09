#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<algorithm>

using namespace std;

int n,h,d;

vector<string> matrix;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};

pair<int,int> start_;

struct info
{
    int x;
    int y;
    int life;
    int u;
    int u_life;
    int move;
};

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> h >> d;

    matrix.resize(n);

    for(int i=0; i<n; i++){
        cin >> matrix[i];
        for(int j=0; j<n; j++){
            if(matrix[i][j] == 'S') start_ = {i,j};
        }
    }
}

bool outRange(int x,int y){
    if(x < 0 or y < 0 or x >= n or y >= n) return true;
    return false;
}

int bfs(int x,int y){
    queue<info> q;
    vector<vector<vector<bool>>> visited(n,vector<vector<bool>>(n,vector<bool>(11,false)));
    if(matrix[x][y] == 'U') {
        q.push({x,y,h,1,d,0});
        visited[x][y][1] = true;
    }
    else {
        q.push({x,y,h,0,0,0});
        visited[x][y][0] = true;
    }
    while(!q.empty()){
        info cur = q.front();
        q.pop();
        if(cur.life == 0) continue;
        for(int i=0; i<4; i++){
            info next = {cur.x+dx[i],cur.y + dy[i],cur.life,cur.u,cur.u_life,cur.move+1};
            if(outRange(next.x,next.y)) continue;
            if(visited[next.x][next.y][next.u]) continue;
            if(matrix[next.x][next.y] == 'E') return next.move;
            else if(matrix[next.x][next.y] == 'U') next.u ++, next.u_life = d-1, matrix[next.x][next.y] ='.';
            else if(next.u_life > 0) next.u_life--;
            else next.life--;
            if(next.life == 0) continue;
            visited[next.x][next.y][next.u] = true,q.push(next);
        }
    }
    return -1;
}

void solution(){
    input();
    cout << bfs(start_.first,start_.second);
}

int main(){
    solution();

    return 0;
}
