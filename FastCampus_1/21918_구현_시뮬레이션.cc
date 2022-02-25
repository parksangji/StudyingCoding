// https://www.acmicpc.net/problem/21918
#include<iostream>
#include<vector>

using namespace std;

int n,m;

vector<int> bulb;


void solve(int a,int b,int c){
    if(a == 1){
        bulb[b] = c;
    }
    else if(a == 2){
        for(int i=b; i<=c ; i++)
        {
            if(bulb[i]) bulb[i] = 0;
            else bulb[i] = 1;
        }
    }
    else if(a == 3){
        for(int i=b; i<=c; i++){
            bulb[i] = 0;
        }

    }
    else if(a == 4){
        for(int i=b; i<=c ;i++){
            bulb[i] = 1;
        }
    }
}

void print(){
    for(int i=1; i<= n; i++) cout << bulb[i] << ' ';
}

void solution(){

    cin >> n >> m;
    bulb.resize(n+1);
    for(int i=1; i<=n; i++){
        cin >> bulb[i];
    }
    for(int i=0,a,b,c; i<m ;i++){
        cin >> a >> b >> c;
        solve(a,b,c);
    }
    print();
}

int main(){
    solution();
    return 0;
}