#include<bits/stdc++.h>
using namespace std;

map<string, int> r = {{"eax", 0}, {"ebx", 1}, {"ecx", 2}};

void g(const string& v, int& ri) {
    cout << "mov eax, " << v << endl;
}

void g(char op, int& ri) {
    string t = ri == 0 ? "ebx" : "ecx";
    cout << (op == '+' ? "add eax, " : 
             op == '-' ? "sub eax, " :
             op == '*' ? "imul eax, " : "idiv ") << t << endl;
    ri--;
}

void m(const string& e) {
    stack<char> s;
    int ri = 0;
    
    for(char c : e) {
        if(isalnum(c)) g(string(1,c), ri);
        else if(c == '(') s.push(c);
        else if(c == ')') {
            while(s.top() != '(') g(s.top(), ri), s.pop();
            s.pop();
        }
        else {
            while(!s.empty() && s.top() != '(') 
                g(s.top(), ri), s.pop();
            s.push(c);
            ri++;
        }
    }
    
    while(!s.empty()) g(s.top(), ri), s.pop();
    cout << "mov result, eax" << endl;
}

int main() {
    m("a+b*c");
    return 0;
}
