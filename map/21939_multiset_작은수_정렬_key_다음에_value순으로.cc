#include<iostream>
#include<string>
#include<set>
#include<map>

using namespace std;

int n,m;

multiset<pair<int,int>> ms;
map<int,int> mm;

void solution(){

    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n;

    for(int i=0,p,l; i<n ; i++){
        cin >> p >> l;
        ms.insert({l,p});
        mm[p] = l;
    }

    cin >> m;

    for(int i=0; i< m ;i++){
        string op;
        cin >> op;
        if(op == "add"){
            int p,l;
            cin >> p >> l;
            ms.insert({l,p});
        }
        else if(op == "recommend"){
            int x;
            cin >> x;
            if(x == 1){
                cout << prev(ms.end())->second << '\n';
            }
            else{
                cout << ms.begin()->second << '\n';
            }  
        }
        else if(op == "solved"){
            int p;
            cin >> p;
            ms.erase({mm[p],p});
        }
    }
}
int main(){
    solution();
    return 0;
}