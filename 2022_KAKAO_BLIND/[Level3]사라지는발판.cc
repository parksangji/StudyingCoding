#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

vector<vector<bool>> visited;
vector<vector<int>> table;

int nn,mm;

int dfs(int ax,int ay,int bx,int by)
{
    if(visited[ax][ay]) return 0;
    int ret = 0;
    for(int i=0; i<4; i++)
    {
        int nx = ax + dx[i];
        int ny = ay + dy[i];
        if(nx < 0 or ny < 0 or nx >= nn or ny >= mm or !table[nx][ny] or visited[nx][ny]) 
            continue;

        visited[ax][ay] = true;
        int cnt = dfs(bx,by,nx,ny) + 1;
        visited[ax][ay] = false;

        if(ret % 2 == 0 and cnt % 2 == 1)
            ret = cnt;
        else if(ret % 2== 0 and cnt % 2 == 0)
            ret = max(ret,cnt);
        else if(ret % 2 == 1 and cnt % 2 == 1)
            ret = min(ret,cnt);
    }

    return ret;
}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    nn = board.size(),mm = board[0].size();
    table = board;
    visited.resize(nn,vector<bool>(mm,false));
    return dfs(aloc[0],aloc[1],bloc[0],bloc[1]);
}