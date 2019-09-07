#include <iostream>
#include <stack>
#include <string>
using namespace std;

int prec(char ch){
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return -1;
}

void InfixToPostfix(string in){
    stack <char> st;
    st.push('N');
    int len = in.length();
    string pst;

    for(int i=0 ; i < len ; i++){
        if(in[i] >= 'a' && in[i] <= 'z' || in[i] >= 'A' && in[i] <= 'Z' ){
            pst +=in[i];
        }
        else if (in[i] == '('){
            st.push('(');
        }
        else if (in[i] == ')' ){
            while(st.top() != '(' && st.top() != 'N'){
                char c = st.top();
                st.pop();
                pst += c;
            }
            if(st.top() == '('){
                char c = st.top();
                st.pop();
            }
        }
        else{
            while(st.top() != 'N' && prec(in[i]) <= prec(st.top())){
                char c = st.top();
                st.pop();
                pst += c;
            }
            st.push(in[i]);
        }
    }

    while(st.top() != 'N'){
        char c =  st.top();
        st.pop();
        pst += c;
    }

    cout<< pst <<endl;

}


int main(){

    string exp = "a+b*(c^d-e)^(f+g*h)-i";
    InfixToPostfix(exp);

    return 0;
}