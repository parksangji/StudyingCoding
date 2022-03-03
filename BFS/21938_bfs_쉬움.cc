#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,t,answer=0;

vector<vector<int>> monitor;
vector<pair<int,int>> v;

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;

    monitor.resize(n,vector<int>(m));

    for(int i=0; i< n;i++){
        for(int j=0,r,g,b; j<m; j++){
            cin >> r >> g >> b;

            monitor[i][j] = (r+g+b)/3;
        }
    }
    cin >> t;
}

void transform(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(monitor[i][j] < t) monitor[i][j] = 0;
            else {
                monitor[i][j] = 255;
                v.push_back({i,j});
            }
        }
    }
}

void objectCount(){

    if(v.empty()){
        cout << 0;
        return;
    }
    vector<vector<bool>> visited(n,vector<bool>(m));
    for(auto vv : v){
        if(visited[vv.first][vv.second]) continue;
        visited[vv.first][vv.second] = true;
        queue<pair<int,int>> q;
        q.push({vv.first,vv.second});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];

                if(nx <0 or ny < 0 or nx >=n or ny >= m) continue;
                if(visited[nx][ny] or !monitor[nx][ny]) continue;
                visited[nx][ny] = true;
                q.push({nx,ny});
            }
        }
        answer++;
    }
    cout << answer;
}

void solution(){
    input();
    transform();
    objectCount();
}
int main(){
    solution();
    return 0;
}