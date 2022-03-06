#include<iostream>
#include<vector>

using namespace std;

int tc,n,m,w;

struct info
{
    int start,end,cost;
};

vector<info> map;

bool cal(){

    vector<int> dist(n+1,5000000);
    int s,e,t;
    dist[1] = 0;
    for(int i=1; i<=n; i++){
        for(int j=0; j<map.size(); j++){
            s = map[j].start;
            e = map[j].end;
            t = map[j].cost;
            if(dist[e] > dist[s] + t){
                dist[e] = dist[s] + t;
                if(i == n) return true;
            }
        }
    }
    return false;
}

void solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> tc;

    while(tc--){
        cin >> n >> m >> w;
        map.clear();
        for(int i=0,a,b,c; i<m ;i++){
            cin >> a >> b >> c;
            map.push_back({a,b,c});
            map.push_back({b,a,c});

        }
        for(int i=0,a,b,c;i < w; i++){
            cin >> a >> b >> c;
            map.push_back({a,b,-c});
        }

        if(cal()) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(){
    solution();
    return 0;
}