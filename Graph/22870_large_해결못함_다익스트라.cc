#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n,m,s,e;
int answer = 0;

vector<vector<pair<int,int>>> matrix;
vector<bool> visited;
vector<int> distS,distE;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;

    matrix.resize(n+1,vector<pair<int,int>>());
    visited.resize(n+1);
    for(int i=0,a,b,c; i<m ;i++){
        cin >> a >> b >> c;
        matrix[a].push_back({b,c});
        matrix[b].push_back({a,c});
    }

    cin >> s >> e;
}

struct info{
    int cur;
    int weight;

    info(int _cur, int _weight){
        cur = _cur;
        weight = _weight;
    }
};

struct compare{
    int operator()(const info i1,const info i2){
        if(i1.weight < i2.weight){
            return -1;
        }
        else if(i1.weight == i2.weight){
            return 0;
        }
        else return 1;
    }
};

vector<int> dijkstra(int start_){
    vector<int> dp(n+1,987654321);
    priority_queue<info,vector<info>,compare> pq;
    pq.push({start_,0});
    dp[start_] = 0;
    while(!pq.empty()){
        int cur = pq.top().cur;
        int dist = pq.top().weight;
        pq.pop();

        if(dp[cur] != dist) continue;

        for(int i=0; i<matrix[cur].size(); i++){
            int next = matrix[cur][i].first;
            int nextDist = dist + matrix[cur][i].second;
            if(visited[next]) continue;
            if(dp[next] > nextDist){
                dp[next] = nextDist;
                pq.push({next,nextDist});
            }
        }
    }
    return dp;
}

void erase(){

    int pre = s;
    int start_ = s;

    while(start_ != e){
        int minValue = 987654321;

        for(int i=0; i < matrix[start_].size(); i++){
            int next = matrix[start_][i].first;
            int nextdist = matrix[start_][i].second;

            if(next == pre) continue;
            if(distS[start_] + nextdist + distE[next] == distS[e]){
                minValue = min(minValue,next);
            }
        }
        if(start_ != e){
            visited[minValue] = true;
        }
        pre = start_;
        start_ = minValue;
    }
}



void solution(){

    distS = dijkstra(s),distE = dijkstra(e);
    answer += distS[e];
    erase();
    distE = dijkstra(e);
    answer += distE[s];
    cout << answer;
}

int main(){
    input();
    solution();
    return 0;
}