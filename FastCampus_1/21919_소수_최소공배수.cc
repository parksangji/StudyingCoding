// https://www.acmicpc.net/problem/21919
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

long long n;
vector<long long> arr,prime;

void input(){
    cin >> n;
    arr.resize(n);
    for(long long i=0; i<n ;i++)
        cin >> arr[i];
}

bool is_prime(long long x){

    for(long long i=2; i<= (long long)sqrt(x); i++)
        if(x % i == 0) return false;
    return true;
}

bool find_prime(){

    for(long long i=0; i<n; i++){
        if(is_prime(arr[i])) prime.push_back(arr[i]);
    }
    if(prime.empty()) return false;
    return true;
}

long long gcd(long long a,long long b){
    long long c;
    while(b != 0){
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long lcm(long long a,long long b){
    return a* b / gcd(a,b);
}

long long find_lcm(){
    long long n= prime[0];
    for(long long i=1; i<prime.size(); i++){
        n = lcm(n,prime[i]);
    }
    return n;
}

void solution(){

    input();
    if(find_prime()) cout << find_lcm();
    else cout << -1;
}

int main(){
    solution();
    return 0;
}
