#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> visited,comp;
int n,answer = 0;

void dfs(vector<int> cur)
{
    int sheep = 0,wolf =0;
    for(int c : cur)
    {
        if(comp[c] == 1) wolf++;
        else sheep++;
    }
    
    if(sheep <= wolf)return ;
    
    answer = max(answer,sheep);
    
    vector<int> next = cur;    
    for(auto n : next)
    {
        for(auto g : tree[n])
        {
            if(visited[g]) continue;
            
            visited[g] = true;
            cur.push_back(g);
            dfs(cur);
            visited[g] =false;
            cur.pop_back();
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {

    int ret = 0;
    n = info.size();
    tree.resize(n,vector<int>());
    visited.resize(n,false);
    comp = info;
    for(auto e : edges)
    {
        int parent = e[0],child = e[1];
        tree[parent].push_back(child);
    }
    
    visited[0] = true;
    dfs({0});
    return answer;
}