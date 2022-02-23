//[GOLD4] 움직이는 미로 탈출 
// https://www.acmicpc.net/problem/16954

#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

string chess[8];

pair<int,int> start;

int dx[] = {0,0,1,-1,-1,-1,1,1,0};
int dy[] = {1,-1,0,0,-1,1,-1,1,0};

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    string input;
    for(int i=0; i<8; i++) cin >> chess[i];
}

void chessMove()
{
    for(int i=7; i>0; i--)
    {
        chess[i] = chess[i-1];
    }
    chess[0] = ".......";
}

bool bfs()
{
    queue<pair<int,int>> q;
    q.push({start.first,start.second});
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            if(x == 0)
                return true;

            for(int i=0; i<9; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 or ny < 0 or nx >= 8 or ny >= 8 ) continue;
                if(chess[nx][ny] == '#' ) continue;
                if(nx -1 >= 0 and chess[nx-1][ny] == '#') continue;
                q.push({nx,ny});
            }
        }
        chessMove();
    }
    return false;
}

void solve()
{
    start = {7,0};
    cout << bfs();
}

int main()
{
    init();
    input();
    solve();
    return 0;
}