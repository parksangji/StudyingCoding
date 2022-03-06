#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,m,k;

vector<vector<int>> dp,matrix;
vector<int> friend_,answer;
void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    dp.resize(n+1,vector<int>(n+1,200000));
    for(int i=0,a,b,t; i<m ;i++){
        cin >> a >> b >> t;
        dp[a][b] = t;
    }

    for(int i=1; i<= n ;i++){
        dp[i][i] = 0;
    }

    cin >> k;
    friend_.resize(k);
    for(int i=0; i<k; i++) cin >> friend_[i];
}

void Floyed_Warshall(){
    for(int k=1; k<=n ;k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n;j++){
                if(dp[i][k] + dp[k][j] < dp[i][j]){
                    dp[i][j] = dp[i][k] + dp[k][j];
                }
            }
        }
    }
}

void result(){
    int tt =5000000;
    for(int i=1; i<= n; i++){
        int sum=0;
        bool flag = true;
        for(int j=0 ; j<k; j++){
            if(dp[friend_[j]][i] == 200000 or dp[i][friend_[j]] == 200000){
                flag = false;
                break;
            }
            sum = max(sum,dp[friend_[j]][i] + dp[i][friend_[j]]);
        }
        if(flag){
            if(sum <= tt){
                if(sum < tt){
                    answer.clear();
                    answer.push_back(i);
                    tt = sum;
                }
                else if(sum == tt){
                    answer.push_back(i);
                }
            }
        }
    }
    for(auto a : answer) cout << a << ' ';
}

void solution(){
    input();
    Floyed_Warshall();
    result();
}

int main(){
    solution();
    return 0;
}