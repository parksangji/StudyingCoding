#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;


struct info{
    vector<string> childFolder;
    map<string,bool> depFile;
};
map<string,info> dir;

string folderName(string s){

    int pos = 0;
    string delimeter = "/";
    while((pos = s.find(delimeter)) != string::npos){
        s.erase(0,pos+ delimeter.length());
    }
    return s;
}
map<string,bool> information ;

int dfs(string s){
    if(dir[s].childFolder.size() == 0){
        for(auto a : dir[s].depFile){
            information[a.first] = true;
        }
        return dir[s].depFile.size();
    }
    int FileCnt = dir[s].depFile.size();

    for(int i=0; i<dir[s].childFolder.size(); i++){
        FileCnt += dfs(dir[s].childFolder[i]);
    }
    for(auto a : dir[s].depFile){
        information[a.first] = true;
    }
    return FileCnt;
}

void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);

    int n,m,k,q;

    cin >> n >> m;

    for(int i=0; i<n + m ;i++){
        string p,f;
        int c;
        cin >> p >> f >> c;
        if(c == 1){
            dir[p].childFolder.push_back(f);
        }
        else {
            dir[p].depFile[f] = true;
        }
    }
    cin >> k;

    for(int i=0; i<k ; i++){
        string a,b;
        cin >> a >> b;
        a = folderName(a);
        b = folderName(b);

        if(!dir[a].childFolder.empty()){
            dir[b].childFolder.insert(dir[b].childFolder.end(),dir[a].childFolder.begin(),dir[a].childFolder.end());
            sort(dir[b].childFolder.begin(),dir[b].childFolder.end());
            dir[b].childFolder.erase(unique(dir[b].childFolder.begin(),dir[b].childFolder.end()),dir[b].childFolder.end());
        }
        if(!dir[a].depFile.empty()){

            for(auto df : dir[a].depFile){
                dir[b].depFile[df.first] = true;
            }
        }
        dir.erase(a);
    }

    cin >> q;

    for(int i=0; i<q; i++){
        string qq;
        cin >> qq;
        qq = folderName(qq);
        information = dir[qq].depFile;
        int a = dfs(qq);

        cout << information.size() << ' ' << a << '\n';
    }
}

int main(){
    solution();

    return 0;
}