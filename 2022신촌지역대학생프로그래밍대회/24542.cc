#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;

vector<vector<int>> relation;
vector<int> visited;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    relation.resize(n+1,vector<int>());
    visited.resize(n+1,0);
    for(int i=0,u,v; i<m; i++){
        cin >> u >> v;
        relation[u].push_back(v);
        relation[v].push_back(u);
    }
}

long long bfs(int x){
    queue<int> q;
    long long cnt = 1;
    q.push(x);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<relation[cur].size(); i++){
            int next = relation[cur][i];

            if(!visited[next]){
                visited[next] = true;
                q.push(next);
                cnt = (cnt + 1) % 1000000007;
            }
        }
    }
    return (cnt % 1000000007);
}

void solution(){
    long long ans = 1;
    for(int i=1; i<= n ; i++){
        if(!visited[i]){
            visited[i] = true;
            ans =  (ans * bfs(i)) % 1000000007;
        }
    }
    cout << ans;
}

int main(){
    input();
    solution();
    return 0;
}