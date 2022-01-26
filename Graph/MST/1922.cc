//[GOLD4]네트워크 연결 
//https://www.acmicpc.net/problem/1922

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n,m,answer=0;
vector<pair<int,pair<int,int>>> MST;
vector<int> root;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> n >> m;
    root.resize(n+1,0);
    for(int i=0,a,b,c; i<m; i++)
    {
        cin >> a >> b >> c;
        MST.push_back({c,{a,b}});
    }
}

int FIND(int x)
{
    if(root[x] == x) return x;
    else return root[x] = FIND(root[x]);
}

void UNION(int x,int y)
{
    x = FIND(x);
    y = FIND(y);

    if(x != y) root[y] = x; 
}

bool sameRoot(int x, int y)
{
    x = FIND(x);
    y = FIND(y);

    if(x == y) return true;
    else return false;
}
void solve()
{
    sort(MST.begin(),MST.end());
    for(int i=1; i<= n ; i++) root[i] = i; //make_set
    for(int i=0; i<m; i++)
    {
        int x = MST[i].second.first;
        int y = MST[i].second.second;
        int w = MST[i].first;
        if(!sameRoot(x,y))
        {
            UNION(x,y);
            answer += w;
        }
    }

    cout << answer;
}

int main(void)
{
    init();
    input();
    solve();

    return 0;
}