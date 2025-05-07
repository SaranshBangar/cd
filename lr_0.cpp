#include<bits/stdc++.h>
using namespace std;

using it=vector<pair<char,vector<string>>>;
map<int,map<char,int>> g;
map<int,set<pair<char,string>>> s;

void clo(it& p,int k){
    for(auto& x:s[k]){
        if(x.second.size()>x.second.find('.')+1){
            char n=x.second[x.second.find('.')+1];
            if(n>='A'&&n<='Z')
                for(auto& y:p)
                    if(y.first==n)
                        for(auto& z:y.second)
                            if(!s[k].count({n,"."+z}))
                                s[k].insert({n,"."+z}),clo(p,k);
        }
    }
}

void lr0(it& p){
    s[0].insert({p[0].first,"."+p[0].second[0]});
    clo(p,0);
    for(int k=0;k<s.size();k++){
        for(auto& x:s[k]){
            string a=x.second;
            size_t d=a.find('.');
            if(d+1<a.size()){
                char c=a[d+1];
                string t=a;swap(t[d],t[d+1]);
                if(!g[k][c]){
                    int n=s.size();
                    g[k][c]=n;
                    s[n].insert({x.first,t});
                    clo(p,n);
                }
                else s[g[k][c]].insert({x.first,t}),clo(p,g[k][c]);
            }
        }
    }
}

int main(){
    it p={{'E',{"E+T","T"}},{'T',{"T*F","F"}},{'F',{"(E)","i"}}};
    lr0(p);
    
    for(auto& x:s){
        cout<<"I"<<x.first<<":\n";
        for(auto& y:x.second)
            cout<<" "<<y.first<<" -> "<<y.second<<"\n";
    }
    cout<<"\nGOTO:\n";
    for(auto& x:g)
        for(auto& y:x.second)
            cout<<" I"<<x.first<<" --"<<y.first<<"--> I"<<y.second<<"\n";
}
