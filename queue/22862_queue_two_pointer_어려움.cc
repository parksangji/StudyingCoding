#include<iostream>
#include<queue>
using namespace std;

int n,k,answer =0;


void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    queue<int> q;

    for(int i=1,input,compare = 0; i<=n ; i++){
        cin >> input;
        if(input % 2) q.push(i);
        if(q.size() > k){
            compare = q.front();
            q.pop();
        }
        answer = max(answer,(int)(i - compare - q.size()));
    }
    cout << answer;
}

int main(){
    solution();
}