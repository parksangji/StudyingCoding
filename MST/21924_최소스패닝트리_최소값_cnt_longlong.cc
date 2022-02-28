// https://www.acmicpc.net/problem/21924
// 최소스패닝트리 - return 값 long long
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long n,m,totalCost = 0;


vector<pair<int,pair<int,int>>> v;
vector<int> root;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input(){
    cin >> n >> m;

    root.resize(n+1,0);
    for(int i=0,a,b,c; i<m ;i++){
        cin >> a >> b >> c;
        v.push_back({c,{a,b}});
        totalCost += c;
    }
}

int find(long long x){
    if(root[x] == x) return x;
    else return root[x] = find(root[x]);
}
void UNION(long long x,long long y){
    x = find(x);
    y = find(y);

    if(x != y) root[y] = x;
}

bool SAMEROOT(long long x,long long y){
    x = find(x);
    y = find(y);

    if(x == y) return true;
    else return false;
}

void solution(){

    init();
    input();

    sort(v.begin(),v.end());

    for(int i=1; i<=n ;i++) root[i] = i;
    long long answer = 0,cnt = 0;
    for(auto vv : v){
        int a = vv.second.first;
        int b = vv.second.second;
        int c = vv.first;

        if(!SAMEROOT(a,b)){
            UNION(a,b);
            totalCost -= c;
            cnt ++;
            if(cnt == n-1) break;
        }
    }
    if(cnt != n-1) cout << -1;
    else cout << totalCost;
}

int main(){
    solution();

    return 0;
}