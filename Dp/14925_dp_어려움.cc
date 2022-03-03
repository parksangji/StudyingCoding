#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int m,n,answer =0;

vector<vector<int>> matrix,dp;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> m >> n;
    matrix.resize(m,vector<int>(n));
    dp.resize(m,vector<int>(n));
    for(int i=0; i<m ;i++){
        for(int j=0; j<n; j++){
            cin >> matrix[i][j];
            if((i == 0 or j==0) and !matrix[i][j]) dp[i][j] =1;
        }
    }
}

void solution(){
    for(int i=1; i<m ;i++){
        for(int j= 1; j<n; j++){
            if(!matrix[i][j]){
                if(!matrix[i-1][j-1] and !matrix[i-1][j] and !matrix[i][j-1]){
                    dp[i][j] = min({dp[i-1][j-1] , dp[i-1][j], dp[i][j-1]}) + 1;
                }
                else{
                    dp[i][j] = 1;
                }
            }
            else{
                dp[i][j] = 0;
            }
        }
    }

    for(int i=0; i<m ; i++){
        for(int j=0; j<n; j++){
            answer = max(answer,dp[i][j]);
        }
    }
    cout << answer;
}

int main(){
    input();
    solution();

    return 0;
}