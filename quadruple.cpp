#include<bits/stdc++.h>
using namespace std;

vector<tuple<char,string,string,string>> q;
vector<tuple<char,string,string>> t;
vector<int> it;

string gen(){
    return "t"+to_string(q.size()+1);
}

void proc(const string& s){
    stack<string> st;
    for(char c:s){
        if(isalnum(c)) st.push(string(1,c));
        else if(c=='@'){
            string a=st.top(); st.pop();
            it.push_back(stoi(a.substr(1))-1);
        }
        else{
            string b=st.top(); st.pop();
            string a=st.top(); st.pop();
            string r=gen();
            q.emplace_back(c,a,b,r);
            t.emplace_back(c,a,b);
            st.push(r);
        }
    }
}

int main(){
    string e="abc*+d-";
    proc(e);

    cout<<"Quadruples:\n";
    for(int i=0;i<q.size();i++){
        auto&[op,a,b,r]=q[i];
        cout<<i+1<<": ("<<op<<", "<<a<<", "<<b<<", "<<r<<")\n";
    }

    cout<<"\nTriples:\n";
    for(int i=0;i<t.size();i++){
        auto&[op,a,b]=t[i];
        cout<<i+1<<": ("<<op<<", "<<a<<", "<<b<<")\n";
    }

    it={0,1,2};
    cout<<"\nIndirect Triples:\n";
    for(int i=0;i<it.size();i++)
        cout<<i+1<<": "<<it[i]+1<<"\n";
}
