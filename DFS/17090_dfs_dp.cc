// [Gold2] 미로탈출하기
// https://www.acmicpc.net/problem/17090
#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

int n,m;
vector<string> matrix;
vector<vector<int>> dp;

int dx[] ={-1,0,1,0};
int dy[] ={0,1,0,-1};

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> n >> m;
    dp.resize(n,vector<int>(m,0));
    for(int i=0; i<n; i++)
    {
        string s;
        cin >> s;
        matrix.push_back(s);
    }
}

int direction(char c)
{
    if(c == 'U') return 0;
    else if(c == 'R') return 1;
    else if(c == 'D') return 2;
    else return 3;
}

int dfs(int x,int y)
{
    if(x < 0 or y < 0 or x >=n or y >= m) return 1;
    if(dp[x][y] != 0) return dp[x][y];

    dp[x][y] = -1;
    dp[x][y] = dfs(x + dx[direction(matrix[x][y])],y + dy[direction(matrix[x][y])]);
    return dp[x][y];
}
// bfs 시간초과 발생 -> 안하게 할 수 있는 경로 업데이트 해줘야함
// bool bfs(int x,int y)
// {
//     queue<pair<int,int>> q;
//     vector<vector<bool>> visited(n,vector<bool>(m,false));

//     q.push({x,y});
//     while(!q.empty())
//     {
//         int x = q.front().first;
//         int y = q.front().second;
//         int dir = direction(matrix[x][y]);
//         q.pop();

//         if(visited[x][y]) return false;
//         visited[x][y] = true;

//         int nx = x + dx[dir];
//         int ny = y + dy[dir];

//         if(nx < 0 or ny < 0 or nx >=n or ny >= m) return true;
//         if(visited[nx][ny]) return false;
        
//         q.push({nx,ny});
//     }

//     return false;
// }

void solve()
{
    int answer = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<m ;j++)
        {
            if(dp[i][j] == 0)
            {
                if(dfs(i,j) == 1) answer++;
            }
            else if(dp[i][j] == 1)
                answer++;
        }

    cout << answer;
}

int main()
{
    init();
    input();
    solve();

    return 0;
}