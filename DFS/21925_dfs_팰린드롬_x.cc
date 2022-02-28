// https://www.acmicpc.net/problem/21925

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> arr,visited;
int n;

void input(){
    cin >> n;
    arr.resize(n,0);
    visited.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}

int dfs(int cur){
    if(cur >= n) return 0;
    if(visited[cur]) return visited[cur];

    int ret = -1;

    for(int i=cur + 1; i<n; i += 2){
        bool flag = true;
        for(int j=0; j<= (i - cur)/ 2; j++ ){

            if(arr[cur + j] != arr[i-j]){
                flag = false;
                break;
            }
        }

        if(flag){
            int value = dfs(i + 1);
            if(value == -1) continue;
            ret = max(ret,value + 1);
        }
    }
    return visited[cur] = ret;
}

void solution(){
    input();
    cout << dfs(0);
}

int main(){
    solution();

    return 0;
}