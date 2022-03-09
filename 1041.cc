#include<iostream>
#include<vector>

using namespace std;

int n;

vector<int> dice(7);

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin >> n;
    for(int i=1; i<=7; i++){
        cin >> dice[i];
    }
}

void solution(){
    
}