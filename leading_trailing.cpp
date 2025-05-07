#include<bits/stdc++.h>
using namespace std;

map<char,vector<string>> p;
map<char,set<char>> l,t;

bool nt(char c){return c>='A'&&c<='Z';}

void lead(char c){
    for(auto& s:p[c]){
        char f=s[0];
        if(nt(f)){if(f!=c)lead(f);l[c].insert(l[f].begin(),l[f].end());}
        else l[c].insert(f);
        if(nt(f)&&s.size()>1&&!nt(s[1]))l[c].insert(s[1]);
    }
}

void trail(char c){
    for(auto& s:p[c]){
        char b=s.back();
        if(nt(b)){if(b!=c)trail(b);t[c].insert(t[b].begin(),t[b].end());}
        else t[c].insert(b);
        if(nt(b)&&s.size()>1&&!nt(s[s.size()-2]))t[c].insert(s[s.size()-2]);
    }
}

int main(){
    p['E']={"E+T","T"};
    p['T']={"T*F","F"};
    p['F']={"(E)","i"};
    
    for(auto& x:p)lead(x.first),trail(x.first);
    
    for(auto& x:l){
        cout<<"Leading("<<x.first<<") = { ";
        for(auto y:x.second)cout<<y<<" ";
        cout<<"}\n";
    }
    for(auto& x:t){
        cout<<"Trailing("<<x.first<<") = { ";
        for(auto y:x.second)cout<<y<<" ";
        cout<<"}\n";
    }
}
