#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#include<queue>
using namespace std;

int t,n;
priority_queue<tuple<int,int,int>> pq;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> t >> n;

    for(int i=0,a,b,c; i<n ; i++){
        cin >> a >> b >> c; //프로세스 id, 종료 시간, 우선순위
        //실행 시킬 프로세스 선택 기준
        // 우선순위가 가장 높은 프로세스
        // id값이 가장 작은 프로세스

        pq.push({c,-a,b});
    }
}

void solution(){

    for(int i=0; i<t; i++){
        int priority = get<0>(pq.top());
        int id = get<1>(pq.top());
        int time = get<2>(pq.top());
        pq.pop();
        cout << -id <<'\n';
        time--;
        if(time > 0) pq.push({priority-1,id,time});
    }
}

int main(){
    input();
    solution();
    return 0;
}