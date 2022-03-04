#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
#include<tuple>
#include<map>


using namespace std;

map<int,multiset<pair<int,int>>> group;
multiset<pair<int,int>> level;
map<int,pair<int,int>> find_value_map;

void solve(string s){
    if(s == "recommend"){
        int g,x;
        cin >> g >> x;

        if(x == 1){
            //알고리즘 분류가 g인 문제 중 가장 어려운 문제
            // 여러 개라면 그중 문제 번호가 큰 것
            cout << prev(group[g].end())->second << '\n';
        }
        else if(x== -1){
            // 1가 반대
            cout << group[g].begin()->second << '\n';
        }
    }
    else if(s == "recommend2"){
        int x;
        cin >> x;
        if(x == 1){
            //알고리즘 분류와 상관 없이 가장 어려운 문제
            cout << prev(level.end())->second << '\n';
        }
        else if(x == -1){
            // 반대
            cout << level.begin()->second << '\n';
        }
    }
    else if(s == "recommend3"){
        int x,l;
        cin >> x >> l;
        //조건 만족하는 문제 번호 없으면 -1출력.
        if(x == 1){
            //알고리즘 분류 x 난이도 l보다 크거나 같은 문제 중 가장 쉬운 문제
            auto it = level.lower_bound({l,-1e9});
            if(it != level.end()) cout << it->second << '\n';
            else cout << -1 << '\n';
            
        }
        else if(x == -1){
            //반대
            auto it = level.upper_bound({l,-1e9});
            if(it != level.begin()) cout << (--it)->second << '\n';
            else cout << -1 << '\n';
        }
    }
    else if(s == "add"){
        int p,l,g;
        cin >> p >> l >> g;
        group[g].insert({l,p});
        level.insert({l,p});
        find_value_map[p] = {l,g};
    }
    else if(s == "solved"){
        int p;
        cin >> p;
        int l = find_value_map[p].first;
        int g = find_value_map[p].second;
        group[g].erase({l,p});
        level.erase({l,p});
        find_value_map.erase(p);
    }
    return;
}

void solution(){

    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int n,m;
    
    cin >> n;
    for(int i=0,p,l,g; i<n; i++){
        cin >> p >> l >> g;
        group[g].insert({l,p});
        level.insert({l,p});
        find_value_map[p] = {l,g};
    }
    cin >> m;
    for(int i=0; i< m; i++){
        string input;
        cin >> input;
        solve(input);
    }
}

int main(void){
    solution();
    return 0;
}