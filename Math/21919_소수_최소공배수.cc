// https://www.acmicpc.net/problem/21919
// 소수 최소 공배수 구하기

#include<iostream>
#include<cmath>

using namespace std;


bool is_Prime(long long x){

    if(x < 2) return false;

    for(int i=2 ; i<=sqrt(x) ; i++)
        if(x % i == 0) return false;
    return true;
}

long long gcd(long long a, long long b){

    while(b > 0){
        long long c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long lcb(long long a, long long b){
    return a * b / gcd(a,b);
}

void solution(){
    int n;
    cin >> n;
    long long answer = 1;
    for(int i=0,input; i<n; i++){
        cin >> input;
        if(is_Prime(input)) 
            answer = lcb(answer,input);
    }
    if(answer == 1) cout << -1;
    else cout << answer;
}

int main(void){
    solution();
    return 0;
}