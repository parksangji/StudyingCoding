// [GOLD4] 집합의 표현
// https://www.acmicpc.net/problem/1717
// 분리집합으로 해결
#include<iostream>
#include<vector>

using namespace std;

vector<int> root;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
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

bool SameRoot(int x,int y)
{
    x = FIND(x);
    y = FIND(y);
    if(x == y) return true;
    else return false;
}

void solve()
{
    int n,m;
    cin >> n >> m;
    root.resize(n+1);

    //makeset;
    for(int i=1; i<=n; i++) root[i] = i;
    for(int i=0,a,b,c; i<m; i++)
    {
        cin >> a >> b >> c;
        if(a)
        {
            if(SameRoot(b,c)) cout << "YES\n";
            else cout << "NO\n"; 
        }
        else
        {
            UNION(b,c);
        }
    }
}
int main(void)
{
    init();
    solve();

    return 0;
}