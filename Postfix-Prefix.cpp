#include <iostream>
#include <stack>
#include <string>

using namespace std;

string PostfixToPrefix(string pst){

    stack <string> st;
    int len = pst.length();

    for (int i = 0 ; i<len ; i++){
        if(pst[i] >= 'a' && pst[i] <= 'z' || pst[i] >= 'A' && pst[i] <= 'Z' ){
            st.push(string(1,pst[i]));
        }
        else{
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            string temp = pst[i]+c2+c1;
            st.push(temp);
        }
    }

    return st.top();

}

int main(){
    string pst = "ABC/-AK/L-*";
    cout << PostfixToPrefix(pst)<<endl;

    return 0;
}