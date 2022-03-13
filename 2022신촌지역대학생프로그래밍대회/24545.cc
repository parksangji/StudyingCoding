#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,answer = 0;

vector<int> visited;
vector<vector<int>> graph;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin >> n;

    graph.resize(n+1,vector<int>());
    visited.resize(n+1,-1);

    for(int i=1,u,v; i<=n-1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void dfs(int x,int depth){

    for(int i=0; i< graph[x].size(); i++){
        int next = graph[x][i];
        int nextDepth = depth +1;
        if(visited[next] == -1){
            visited[next] = nextDepth;
            answer = max(visited[next],answer);
            dfs(next,nextDepth);       
        }
    }
}
void solution(){

    input();
    visited[1] = 1;
    dfs(1,1);

    cout << answer;
}

int main(){
    solution();
    return 0;
}