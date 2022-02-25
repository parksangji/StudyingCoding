// https://www.acmicpc.net/problem/21920
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,x;
vector<int> arr;

void input(){
    
    cin >> n;
    int maxvalue = -1;
    for(int i=0,input; i<n; i++){
        cin >> input;
        arr.push_back(input);
    }
    cin >> x;
}

bool is_relatively_prime(int a,int b){
    while(b > 0){
        int c = a % b;
        a = b;
        b = c;
    }
    if(a == 1) return true;
    else return false;
}

void solution(){

    int sum = 0,count=0;

    for(auto a : arr){
        if(is_relatively_prime(a,x)){
            sum += a;
            count ++;
        }
    }
    cout << sum/count;
}

int main(){
    input();
    solution();

    return 0;
}