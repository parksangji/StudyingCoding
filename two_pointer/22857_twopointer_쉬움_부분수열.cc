#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> v;
int n,k;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;

    v.resize(n);

    for(int i=0; i<n; i++) cin >> v[i];
}

void solution(){
    int answer =0;
    for(int i=0; i<n; i++){
        if(v[i] % 2 != 0) continue;
        
        int kk = 1;
        int delCnt = 0;
        int nextIndex= i+1;
        while(1){
            if(nextIndex >= n) break;
            if(v[nextIndex] % 2 != 0){
                if(delCnt < k){
                    delCnt ++;
                    nextIndex ++ ;
                    continue;
                }
                else {
                    break;
                }
            }
            kk++;
            nextIndex++;
        }
        answer = max(answer,kk);
    }
    cout << answer;
}

int main(){
    input();
    solution();

    return 0;
}