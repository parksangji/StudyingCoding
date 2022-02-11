#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
int base_time,base_fee,per_time,per_time_fee;

int calTime(string time)
{
    int hh = 60 * stoi(time.substr(0,2));
    int mm = stoi(time.substr(3));
    return hh + mm;
}

int calFee(int time)
{
    if(time <= base_time) return base_fee;
    else return base_fee + (ceil((time - base_time)/(double)per_time) * per_time_fee);
}

void init(vector<int> fees)
{
    base_time = fees[0];
    base_fee = fees[1];
    per_time = fees[2];
    per_time_fee = fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string,string> inout;
    
    map<string, int> carFee;
    map<string, int> carTime;
    map<string, int> totalTime;
    
    init(fees);
    
    priority_queue<pair<string,int>> pq;
    for(int i=0; i< records.size(); i++)
    {
        stringstream ss(records[i]);
        string tt,nn,op;
        ss >> tt >> nn >> op;
        
        int curtime = calTime(tt);
        
        if(op == "IN")
        {
            carTime[nn] = curtime;
            inout[nn] = "IN";
        }
        else
        {
            curtime -= carTime[nn];
            inout[nn] = "OUT";
            totalTime[nn] += curtime;
        }
    }
    for(auto &m : inout)
    {
        string num = m.first;
        string op = m.second;
        if(op == "IN")
        {
            int time = calTime("23:59") - carTime[num];
            totalTime[num] += time;
        }
    }
    for(auto &m : totalTime)
    {
        int time = m.second;
        answer.push_back(calFee(time));
    }
    
    return answer;
}