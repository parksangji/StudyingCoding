#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int n,k;


int answer(){
    int ans = 0;
    while(1){
        int tmp = n,cnt = 0;

        while(tmp > 0){
            if(tmp % 2){
                tmp /= 2 ;
                cnt ++;
            }
            else{
                tmp /=2 ;
            }
        }
        if(k >= cnt){
            break;
        }
        n++;
        ans++;
    }
    return ans;
}

void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> k;
    cout << answer();
}

int main(){
    solution();
    return 0;
}