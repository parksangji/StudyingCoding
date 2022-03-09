#include<iostream>
#include<vector>

using namespace std;

int n,k;
vector<long long> arr,dp;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;

    arr.resize(n+1);
    dp.resize(n+1,-1);

    for(int i=1; i<=n ; i++){
        cin >> arr[i];
    }
}


long long dfs(int i){
    if(i == n ) return 0;
    if(dp[i] != -1) return dp[i];

    long long ret = __LONG_LONG_MAX__;
    
    for(int j=i+1; j<=n ;j++){
        ret = min(ret,max(dfs(j),(j-i) * (1+ abs(arr[i]-arr[j]))));
    }
    return ret;
}

int main(){
    input();
    cout << dfs(1);

    return 0;
}