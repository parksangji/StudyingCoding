#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int n,K,L,answer = 0;
vector<vector<int>> matrix;
deque<pair<int,int>> snake;
int dir = 1;
int dx[] ={-1,0,1,0};
int dy[] ={0,1,0,-1};

void rotation(char c)
{
    if(c == 'L') dir = ((dir - 1) < 0) ? 3 : dir - 1;
    if(c == 'D') dir = ((dir + 1 ) == 4) ? 0 : dir + 1;
    
}
bool move()
{
    int x = snake.front().first;
    int y = snake.front().second;
    
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    
    if(nx < 1 or ny < 1 or nx > n or ny > n or matrix[nx][ny] == -1) return false;
    if(matrix[nx][ny] == 0)
    {
    	matrix[snake.back().first][snake.back().second] = 0;
        snake.pop_back(); 
    }
    
    snake.push_front({nx,ny});
    matrix[nx][ny] = -1;
    return true;
}

int solve()
{
    cin >> n;
    matrix.resize(n+1,vector<int>(n+1,0));
    cin >> K;
    for(int i=0,x,y; i<K; i++)
    {
        cin >> x >> y;
        matrix[x][y] = 1;
    }
    cin >> L;
    snake.push_back({1,1});
    matrix[1][1] = -1;
    vector<pair<int,char>> v(L);
    for(int i=0; i<L; i++) cin >> v[i].first >> v[i].second;
    for(auto vv : v)
    {
    	while(answer < vv.first)
    	{
    		if(!move()) return (answer + 1);
    		answer++;
    	}
    	rotation(vv.second);
    }
    while(1)
    {
    	if(!move()) return answer+1;
    	answer++;
    }
}

int main(void)
{
    cout << solve();
}
