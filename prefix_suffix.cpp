#include<bits/stdc++.h>
using namespace std;

string pfx(const string& e){
    stack<string> s;
    for(int i=e.size()-1;i>=0;i--){
        if(isalnum(e[i])) s.push(string(1,e[i]));
        else{
            string a=s.top();s.pop();
            string b=s.top();s.pop();
            s.push(e[i]+a+b);
        }
    }
    return s.top();
}

string sfx(const string& e){
    stack<string> s;
    for(char c:e){
        if(isalnum(c)) s.push(string(1,c));
        else{
            string b=s.top();s.pop();
            string a=s.top();s.pop();
            s.push(a+b+c);
        }
    }
    return s.top();
}

int main(){
    string e="*+ab-cd";
    
    cout<<"Infix: (a+b)*(c-d)\n";
    cout<<"Prefix: "<<pfx(e)<<'\n';
    cout<<"Suffix: "<<sfx("ab+cd-*")<<'\n';
}
