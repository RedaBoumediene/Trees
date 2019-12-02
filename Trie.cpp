#include<bits/stdc++.h>
using namespace std;

vector<vector<int> > v;
vector<bool> e;

void insert(string &s){
    int curr=0;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'a';
        if(v[curr][c]==-1){
            v[curr][c]=v.size();
            v.push_back(vector<int>(26,-1));
            e.push_back(false);
        }
        curr=v[curr][c];
    }
    e[curr]=true;
}

bool find(string &s){
    int curr=0;
    for(int i=0;i<s.size();i++){
        int c = s[i]-'a';
        if(v[curr][c]==-1)
            return false;
        curr = v[curr][c];
    }
    return e[curr];

}

int main(){

    v.resize(1);
    v[0].resize(26,-1);
    e.push_back(false);

    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        insert(s);
    }

    int q;
    cin>>q;
    while(q--){
        string s;
        cin>>s;
        if(find(s))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

return 0;
}
