#include<iostream>
#include<vector>

using namespace std;

int n,k;
bool flag;
vector<int> arr,dp;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k;

    arr.resize(n+1);
    dp.resize(n+1);

    for(int i=1; i<=n ; i++){
        cin >> arr[i];
    }
}


void dfs(int i){
    if(i == n){
        flag = true;
        return;
    }
    if(i > n){
        return;
    }
    int Ai = arr[i];
    for(int j=i+1; j<=n ;j++){
        int Aj  = arr[j];
        int power = (j-i) * (1+ abs(arr[i] - arr[j]));
        if(power <= k and !dp[j]){
            dp[j] = true;
            dfs(j);

        }
    }
}

void solution(){

    dp[1] = true;
    dfs(1);
    if(flag) cout << "YES";
    else cout << "NO";
}

int main(){
    input();
    solution();

    return 0;
}