#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

int n;


struct info
{
    int position;
    int door;
    int number;
};

vector<info> arr;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=0,x,r; i<n ;i++){
        cin >> x >> r;
        arr.push_back({x-r,0,i});
        arr.push_back({x+r,1,i});
    }
}

bool answer(){
    for(int i=1; i<arr.size(); i++){
        if(arr[i-1].position == arr[i].position) return false;
    }
    stack<int> st;
    for(auto a : arr){
        if(!a.door) st.push(a.number);
        else if(st.top() != a.number) return false;
        else st.pop();
    }
    return true;
}

void solution(){
    sort(arr.begin(),arr.end(),[](const info& a,const info& b){
        return a.position < b.position;
    });

    cout << (answer() ? "YES" : "NO") << '\n';
}

int main(){
    input();
    solution();

    return 0;
}