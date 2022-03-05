#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<tuple>

using namespace std;

int n,m,q; //폴더,파일,쿼리의 개수

struct info
{
    vector<string> folder;
    map<string,bool> fileflag;
    int fileCnt;
};

map<string,info> dir;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n + m; i++){
        string p,f;
        int c;
        cin >> p >> f >> c;
        if(c ==1){
            dir[p].folder.push_back(f);
        }
        else{
            dir[p].fileCnt++;
            dir[p].fileflag[f] = true;
        }
    }
    return ;
}
map<string,bool> information;

int dfs(string s){
    if(dir[s].folder.size() == 0){
        for(auto a : dir[s].fileflag){
            information[a.first] = true;
        }
        return dir[s].fileCnt;
    }
    int FileCnt = dir[s].fileCnt;

    for(int i=0; i<dir[s].folder.size(); i++){
        FileCnt += dfs(dir[s].folder[i]);
    }
    for(auto a : dir[s].fileflag){
        information[a.first] = true;
    }
    return FileCnt;
}

void solution(){
    cin >> q;
    string query,token;
    string delimiter = "/";
    for(int i=0; i< q; i++){
        cin >> query;
        int pos = 0;
        while((pos = query.find(delimiter)) != string::npos){
            token = query.substr(0,pos);
            query.erase(0,pos + delimiter.length());
        }
        information = dir[query].fileflag;
        int a = dfs(query);
        cout << information.size() << ' ' << a << '\n';
    }
    return ;
}

int main(){
    input();
    solution();

    return 0;
}