// https://www.acmicpc.net/problem/14499
// 시뮬레이션, 구현

#include<iostream>
#include<vector>

using namespace std;

int n,m,x,y,k;

vector<vector<int>> matrix;

int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

int cube[] = {0,0,0,0,0,0}; //위0,북1,동2,남3,서4,아래5

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

void input(){
    cin >> n >> m >> x >> y >> k;

    matrix.resize(n,vector<int>(m,0));

    for(int i=0; i< n ; i++){
        for(int j=0; j<m ; j++){
            cin >> matrix[i][j];
        }
    }
}

void rotation(int dir,int r,int c){
    if(dir == 1){
        int buttom = cube[5];
        cube[5] = cube[2];//동 -> 아래
        cube[2] = cube[0];//위 - > 동
        cube[0] = cube[4];//서 -> 위
        cube[4] = buttom;//아래 -> 서
        if(matrix[r][c] == 0){
            matrix[r][c] = cube[5];
        }
        else{
            cube[5] = matrix[r][c];
            matrix[r][c] = 0;
        }
    }
    else if(dir == 2){
        int buttom = cube[5];
        cube[5] = cube[4];//서 -> 아래
        cube[4] = cube[0];//위 -> 서
        cube[0] = cube[2];//동 -> 위
        cube[2] = buttom;//아래 -> 동
        if(matrix[r][c] == 0){
            matrix[r][c] = cube[5];
        }
        else{
            cube[5] = matrix[r][c];
            matrix[r][c] = 0;
        }
    }
    else if(dir == 3){
        int buttom = cube[5];
        cube[5] = cube[1];//북 -> 아래
        cube[1] = cube[0];//위 -> 북
        cube[0] = cube[3];//남 -> 위
        cube[3] = buttom;//아래 -> 남

        if(matrix[r][c] == 0){
            matrix[r][c] = cube[5];
        }
        else{
            cube[5] = matrix[r][c];
            matrix[r][c] = 0;
        }
    }
    else if(dir == 4){
        int buttom = cube[5];
        cube[5] = cube[3];//남 -> 아래
        cube[3] = cube[0];//위 -> 남
        cube[0] = cube[1];//북 -> 위
        cube[1] = buttom;//아래 -> 북
        if(matrix[r][c] == 0){
            matrix[r][c] = cube[5];
        }
        else{
            cube[5] = matrix[r][c];
            matrix[r][c] = 0;
        }
    }

    cout << cube[0] << '\n';
}

void solution(){

    for(int i=0,input;i <k ;i++){
        cin >> input;
        int nx = x + dx[input];
        int ny = y + dy[input];

        if(nx < 0 or ny < 0 or nx >= n or ny >=m ) continue;
        else{
            x = nx, y= ny;
            rotation(input,x,y);
        }
    }
}

int main(){
    input();
    solution();
}