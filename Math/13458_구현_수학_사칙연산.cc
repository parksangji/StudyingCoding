// https://www.acmicpc.net/problem/13458

#include<iostream>
#include<vector>

using namespace std;

long long N,b,c;

vector<long long> A;

void input(){
    cin >> N;
    A.resize(N,0);
    for(int i=0; i<N; i++)
        cin >> A[i];
    cin >> b >> c;
}

void solution(){

    long long answer = 0;
    for(auto a : A){
        a -= b;
        if(a <= 0){
            answer ++;
        }
        else if(a % c == 0){
            answer += ((a/c) + 1);
        }
        else{
            answer += ((a/c) + 2);
        }
    }
    cout << answer;
}

int main(){
    input();
    solution();

    return 0;
}