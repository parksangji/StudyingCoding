#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int r,c,tt,cntS = 0;

vector<vector<char>> matrix;
pair<int,int> dog;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> r >> c >> tt;

    matrix.resize(r,vector<char>(c));
    for(int i=0; i<r; i++){
        string s;
        cin >> s;
        for(int j=0; j<s.length(); j++){
            matrix[i][j] = s[j];
            if(s[j] == 'G'){
                dog = {i,j};
                matrix[i][j] = '.';
            }
        }
    }
}

void dfs(int x,int y,int t,int potato){
    if(t == tt){
        cntS = max(cntS , potato);
        return;
    }

    for(int i=0; i<4 ;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 or ny < 0 or nx >= r or ny >=c) continue;
        if(matrix[nx][ny] == '#') continue;
        if(matrix[nx][ny] == 'S'){
            matrix[nx][ny] = '.';
            dfs(nx,ny,t+1,potato+1);
            matrix[nx][ny] = 'S';
        }
        if(matrix[nx][ny] == '.'){
            dfs(nx,ny,t+1,potato);
        }
    }
}

void solution(){
    input();
    dfs(dog.first,dog.second,0,0);
    cout << cntS;
}

int main(){
    solution();

    return 0;
}