// https://www.acmicpc.net/problem/21923

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector<vector<int>> matrix;

void input(){
    cin >> n >> m;

    matrix.resize(n,vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m ;j++)
            cin >> matrix[i][j];
}

vector<vector<int>> bfs(int x,int y,int flag){
    vector<vector<int>> temp(n,vector<int>(m,INT32_MIN));
    temp[x][y] = matrix[x][y];
    int dx[] = {-1,0};
    int dy[] = {0,1};

    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<2; i++){
            int nx = x + dx[i];
            int ny = y + dy[i] * flag;
            if( nx < 0 or ny < 0 or nx >= n or ny >= m) continue;
            if(temp[nx][ny] < temp[x][y] + matrix[nx][ny]){
                temp[nx][ny] = temp[x][y] + matrix[nx][ny];
                q.push({nx,ny});
            }
        }
    }
    return temp;
}

void solution(){
    vector<vector<int>> upper = bfs(n-1,0,1);
    vector<vector<int>> lower = bfs(n-1,m-1,-1);

    int ans = INT32_MIN;
    for(int i=0; i<n; i++)
        for(int j=0; j<m ;j++)
            if(upper[i][j] + lower[i][j] > ans){
                ans = upper[i][j] + lower[i][j];
            }
    cout << ans;
}

int main(){
    input();
    solution();
    return 0;
}