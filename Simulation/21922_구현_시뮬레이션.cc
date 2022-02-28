// https://www.acmicpc.net/problem/21922

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;

struct info{
    int dir;
    int x;
    int y;
};

vector<vector<int>> matrix,answer;
vector<vector<vector<int>>> visited;
queue<info> q;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input(){
    cin >> n >> m;

    matrix.resize(n,vector<int>(m));
    visited.resize(n,vector<vector<int>>(m,vector<int>(4)));
    answer.resize(n,vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            cin >> matrix[i][j];
            if(matrix[i][j] == 9){
                answer[i][j] = 1;
                for(int k=0; k<4 ; k++){
                    visited[i][j][k]= true;
                    q.push({k,i,j});
                }
            }
        }
}

void bfs(){

    while(!q.empty()){
        int dir = q.front().dir;
        int x = q.front().x + dx[dir];
        int y = q.front().y + dy[dir];
        q.pop();
        if(x < 0 or y < 0 or x >= n or y >= m or visited[x][y][dir]) continue;

        visited[x][y][dir] = true;
        answer[x][y] = 1;
        
        if(matrix[x][y] == 9) continue;
        else if(matrix[x][y] == 1 and dir % 2 == 0) continue;
        else if(matrix[x][y] == 2 and dir % 2 == 1) continue;
        else if(matrix[x][y] == 3){
            // 동남서북 0 1 2 3
            if(dir == 0) dir = 3;
            else if(dir == 1) dir = 2;
            else if(dir == 2) dir = 1;
            else if(dir == 3) dir = 0;
        }
        else if(matrix[x][y] == 4){
            if(dir == 0) dir = 1;
            else if(dir == 1) dir = 0;
            else if(dir == 2) dir = 3;
            else if(dir == 3) dir = 2;
        }
        q.push({dir,x,y});
    }
}

void print(){
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m ;j++){
            ans += answer[i][j];
        }
    }
    cout << ans;
}

void solution(){
    init();
    input();
    bfs();
    print();
}

int main(){
    solution();

    return 0;
}