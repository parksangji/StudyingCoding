#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

using namespace std;

int n,t;
vector<int> turn;
map<int,bool> shareArea;
map<int,string> myCard;
map<int,int> myResource;
void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n >> t;

    for(int i=0,id; i<t; i++){
        cin >> id;
        turn.push_back(id);
    }
    string op;
    for(int i=0,cardid,opnum; i< turn.size(); i++){

        int myturn = turn[i];

        cin >> cardid >> op;

        if(myCard[myturn] != ""){
            cout << myCard[myturn].back() - '0' << '\n';
            string haveCard = myCard[myturn];
            myCard.erase(myturn);

            cout << haveCard.back() << '\n';

            if(!shareArea[haveCard.back() - '0']){
                shareArea[haveCard.back() - '0'] = true;
                myResource[myturn] = (int)(haveCard.back() - '0');
            }
            else if(myResource[myturn] == (int)( haveCard.back() - '0')){
                shareArea[haveCard.back() - '0'] = false;
                myResource[myturn] = -1;
            }
            continue;
        }
        if(op == "next"){
            cout << cardid << '\n';
            continue;
        }
        if(op == "acquire"){
            cin >> opnum ;
            cout << cardid << '\n';
            if(shareArea[opnum]){
                myCard[myturn] = op + to_string(opnum);
            }
            else{
                myResource[myturn] = opnum;
                shareArea[opnum] = true;
            }
        }
        if(op == "release"){
            cout << cardid << '\n';
            cin >> opnum;

            shareArea[opnum] = false;
            myResource[myturn] = -1;
        }
    }
}

int main(){
    solution();

    return 0;
}