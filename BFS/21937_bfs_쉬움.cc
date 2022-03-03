#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m,x;

vector<vector<int>> process;
vector<int> visited;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    process.resize(n+1,vector<int>());
    visited.resize(n+1, 0);
    for(int i=0,a,b; i<m; i++){
        cin >> a >> b;
        process[b].push_back(a);
    }
    cin >> x;
}

int bfs(){
    visited[x] = true;
    queue<int> q;
    q.push(x);

    int cnt =0;
    while(!q.empty()){

        int cur = q.front();
        q.pop();

        for(int i=0; i<process[cur].size(); i++){
            int next = process[cur][i];
            if(!visited[next]){
                cnt++;
                visited[next] = true;
                q.push(next);
            }
        }
    }
    return cnt;
}

void solution(){

    input();
    cout << bfs();
}

int main(){
    solution();
    return 0;
}