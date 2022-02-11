#include <string>
#include <sstream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    map<string ,int>  ban_user_cnt; 
    map<string ,int> user_user;
    map<string ,vector<string>> list;
    for(auto i: id_list) ban_user_cnt[i] = 0;
    for(auto r : report)
    {
        stringstream ss(r);
        string user ,ban;
        ss >> user >> ban;
        
        if(user_user[r]) continue;
        
        user_user[r] = -1;
        ban_user_cnt[ban]++; // counting
        list[user].push_back(ban);
    }
    for(auto i : id_list)
    {
        int cnt = 0;
        for(auto l : list[i])
        {
            if(ban_user_cnt[l] >= k) cnt++;
        }
        answer.push_back(cnt);
    }
    return answer;
}