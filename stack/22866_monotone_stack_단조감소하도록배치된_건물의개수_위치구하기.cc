#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int n;

vector<int> building,position,count;

struct info{
    int value;
    int index;
};

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    building.resize(n+1,0);
    position.resize(n+1,-1);
    count.resize(n+1,0);

    for(int i=1; i<=n; i++){
        cin >> building[i];
    }
}

void solution(){

    stack<info> st;
    for(int i=1; i<= n; i++){
        while(st.size() and st.top().value <= building[i]) st.pop();

        if(st.size()){
            count[i] += st.size();
            int d1 =abs(position[i]-i);
            int d2 =abs(st.top().index -i);
            if(position[i] == -1 or d1 > d2 or d1 == d2 and position[i] > st.top().index) position[i] = st.top().index;
        }
        st.push({building[i],i});
    }
    while(st.size())st.pop();
    for(int i=n; i> 0; i--){
        while(st.size() and st.top().value <= building[i]) st.pop();
        if(st.size()){
            count[i] += st.size();
            int d1 =abs(position[i]-i);
            int d2 =abs(st.top().index -i);
            if(position[i] == -1 or d1 > d2 or d1 == d2 and position[i] > st.top().index) position[i] = st.top().index;
        }
        st.push({building[i],i});
    }

    for(int i=1; i<=n; i++)
        if(count[i]) cout << count[i] << ' ' << position[i] <<'\n';
        else cout << 0 << '\n';
}

int main(){
    input();
    solution();

    return 0;
}