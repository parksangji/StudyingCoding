#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<algorithm>
#include<map>

using namespace std;

int n,c;

map<int,vector<int>> myCardList;
map<int,vector<pair<string,char>>> cardCalc;
void solution(){
    cin >> n >> c;

    for(int i=1,a,b; i<=n ;i++){
        // i번 사람이 낸 카드와 카드를 낸 순서
        cin >> a;
        vector<int> tmp(a);
        for(int j=0; j<a; j++) cin >> tmp[j];
        myCardList[i] = tmp;
    }
    string input;
    for(int i=1; i<=c ;i++){
        getline(cin,input);
        stringstream ss(input);
        string getlinetmp;
        vector<pair<string,char>> tmp;
        while(getline(ss,getlinetmp,',')){
            string op = getlinetmp.substr(0,3);
            char value = getlinetmp.back();
            tmp.push_back({op,value});
        }
        cardCalc[i] = tmp;
    }

    for(auto m : myCardList){
        string mystring = "";

        for(int i=0; i< m.second.size(); i++){
            int cardnum = m.second.at(i);
            for(int j=0; j<cardCalc[cardnum].size(); i++){
                if(cardCalc[cardnum].at(j).first == "add"){
                    mystring.push_back(cardCalc[cardnum].at(j).second);
                }
                else{
                    if(mystring.empty()){
                        
                    }
                }
            }
        }
    }
}