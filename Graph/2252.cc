//[GOLD3] 줄 세우기
//https://www.acmicpc.net/problem/2252
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,m;

vector<int> arr;
vector<vector<int>> graph;
queue<int> q;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> n >> m;

    arr.resize(n+1);
    graph.resize(n+1);

    for(int i=0,a,b; i<m; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        arr[b]++;
    }
}

void solve()
{
    vector<int> answer;
    for(int i=1; i<=n; i++) if(arr[i] == 0) q.push(i);
   
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        for(int next : graph[cur])
        {
            --arr[next];
            if(arr[next] == 0) q.push(next);
        }
        answer.push_back(cur);
    }
    for(auto ans : answer) cout << ans << " ";
}

int main()
{
    init();
    input();
    solve();

    return 0;
}

