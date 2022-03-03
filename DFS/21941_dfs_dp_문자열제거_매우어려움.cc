#include<string>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

vector<pair<string,int>> v;
vector<int> dp;
string input;
int n;


int dfs(int idx){
    if(idx >= input.length()) return 0;
    if(dp[idx] != -1) return dp[idx];
    int maxValue = 0;

    for(int i=0; i<n; i++){
        int pos = idx;
        while(1){
            pos = input.find(v[i].first,pos);
            if(pos != string::npos){
                maxValue = max(maxValue,dfs((pos++) + v[i].first.length()) + v[i].second);
            }
            else break;
        }
    }

    maxValue = max(maxValue,1 + dfs(idx + 1));
    return dp[idx] = maxValue;
}

void solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    
    cin >> input >> n;
    v.resize(n);
    dp.resize(input.length(),-1);
    for(int i=0; i<n; i++) cin >> v[i].first >> v[i].second;

    cout << dfs(0);
}

int main(){
    solution();

    return 0;
}
