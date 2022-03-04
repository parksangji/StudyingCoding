#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

using namespace std;

int month[] ={0,31,28,31,30,31,30,31,31,30,31,30,31};

struct info
{
    string mm;
    string dd;
    string time;
    string obj;
    string name;
    bool flag;
};
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
}
long long feeCal(string m,string d,string t,string mm,string dd,string tt){

    long long t2 = stoll(tt.substr(0,2)) * 60 + stoll(tt.substr(3,2));
    long long t1 = stoll(t.substr(0,2)) * 60 + stoll(t.substr(3,2));
    if(m == mm){
        long long day = (stoll(dd) - stoll(d)) * 60 * 24;
        return day + (t2 -t1);
    }
    else{
        long long day = 0;
        if(stoll(mm) - stoll(m) > 1){

            for(long long i=stoll(m) + 1 ; i< stoll(mm); i++){
                day += (month[i] * 60 * 24);
            }
        }
        day += (stoll(dd) + (month[stoll(m)] - stoll(d))) * 60 * 24;
        return day + (t2 - t1);
    }
    
}

void solution(){
    long long n,f;
    string l;

    cin >> n >> l >> f;

    string day = l.substr(0,3);
    string hour = l.substr(4,2);
    string min = l.substr(7,2);

    long long reservedTime = (stoll(day) * 24 + stoll(hour)) * 60 + stoll(min);

    map<string,info> objInfo;
    map<string,long long> peopleFee;

    for(long long i=0; i<n; i++){
        string date,time,obj,name;
        cin >> date >> time >> obj >> name;

        string mm = date.substr(5,2);
        string dd = date.substr(8,2);

        if(objInfo[obj+name].flag){
            info i = objInfo[obj+name];
            long long used = feeCal(i.mm,i.dd,i.time,mm,dd,time);
            if(reservedTime < used){
                peopleFee[name] += (used - reservedTime) * f;
            }
            objInfo.erase(obj+name);
        }
        else{
            objInfo[obj+name] = {mm,dd,time,obj,name,true};
        }
    }
    if(peopleFee.empty()) 
    {
        cout << -1;
        return ;
    }
    vector<pair<string,long long>> v;
    for(auto p : peopleFee){
        v.push_back({p.first,p.second});
    }
    sort(v.begin(),v.end());
    for(auto vv : v){
        cout << vv.first << ' ' << vv.second << '\n';
    }
}

int main(){
    init();
    solution();
    return 0;
}