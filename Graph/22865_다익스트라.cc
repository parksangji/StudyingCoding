#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,a,b,c,m,DIST =0,answer = 999999;

vector<vector<pair<int,int>>> graph;
priority_queue<pair<int,int>> pq;
vector<int> dist;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> a >> b >> c >> m;

    graph.resize(n+1,vector<pair<int,int>>());
    dist.resize(n+1,0);
    for(int i=0,d,e,l; i<m ;i++){
        cin >> d >> e >> l;
        graph[d].push_back({l,e});
        graph[e].push_back({l,d});
    }
    
}

void dijkstra(){
    while(!pq.empty()){
        int cur = pq.top().second;
        int d = -pq.top().first;

        pq.pop();
        if(dist[cur]) continue;
        dist[cur] = d;

        if(d > DIST){
            answer = cur;
            DIST = d;
        }
        else if(DIST == d){
            if(answer > cur) answer = cur;
        }
        for(auto node : graph[cur]){
            if(!dist[node.second]){
                pq.push({-(d + node.first),node.second});
            }
        }
    }
}

void solution(){
    pq.push({1,a});
    pq.push({1,b});
    pq.push({1,c});

    dijkstra();

    cout << answer;
}

int main(){
    input();
    solution();

    return 0;
}