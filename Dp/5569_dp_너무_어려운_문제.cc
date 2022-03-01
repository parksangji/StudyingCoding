// https://www.acmicpc.net/problem/5569
// 참고 자료 : https://sosoeasy.tistory.com/75
#include<iostream>
#include<vector>

using namespace std;

int w,h;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> w >> h;
}


void solution(){

    int ret = 0;
    vector<vector<vector<int>>> dp(w+1,vector<vector<int>>(h+1,vector<int>(4)));
    for(int i=1; i<=w; i++) dp[i][1][0] = 1;
    for(int i=1; i<=h; i++) dp[1][i][2] = 1;

    for(int i=2; i<=w; i++){
        for(int j=2; j<=h ; j++){
            dp[i][j][0] = (dp[i-1][j][1] + dp[i-1][j][0]) % 100000;
            dp[i][j][1] = dp[i-1][j][2];

            dp[i][j][2] = (dp[i][j-1][3] + dp[i][j-1][2]) % 100000;
            dp[i][j][3] = dp[i][j-1][0];
        }
    }

    for(int o= 0; o<4; o++){
        ret += dp[w][h][o];
    }
    cout << (ret % 100000);
}

int main(){
    input();
    solution();
    return 0;
}