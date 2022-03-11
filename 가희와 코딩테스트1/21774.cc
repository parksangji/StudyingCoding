#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

int n,q;

vector<string> log[7];

void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    cin >> n >> q;
    cin.ignore();
    string input;
    for(int i=0; i<n; i++){
        getline(cin,input);

        stringstream ss(input);
        string getlinetmp;

        vector<string> tmp;

        while(getline(ss,getlinetmp,'#')){
            tmp.push_back(getlinetmp);
        }

        string logs = tmp[0];
        int lv = stoi(tmp[1]);

        for(int i=1; i<=lv ;i++){
            log[i].push_back(logs);
        }
    }

    for(int i=1; i< 7 ; i++) sort(log[i].begin(),log[i].end());
    for(int i=0; i<q; i++){
        getline(cin,input);

        stringstream ss(input);
        string getlinetmp;

        vector<string> tmp;

        while(getline(ss,getlinetmp,'#')){
            tmp.push_back(getlinetmp);
        }

        string start = tmp[0];
        string end = tmp[1];
        int lv = stoi(tmp[2]);

        auto it1 = lower_bound(log[lv].begin(),log[lv].end(),start);
        auto it2 = upper_bound(log[lv].begin(),log[lv].end(),end);

        cout << it2 - it1 <<'\n';
    }
}

int main(){
    solution();
    return 0;
}