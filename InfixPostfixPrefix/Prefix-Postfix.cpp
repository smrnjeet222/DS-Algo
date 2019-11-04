#include <iostream>
#include <stack>
#include <string>

using namespace std;

string PrefixToPostfix(string pr){

    stack <string> st;
    int len = pr.length();

    for (int i = len-1 ; i>=0 ; i--){
        if(pr[i] >= 'a' && pr[i] <= 'z' || pr[i] >= 'A' && pr[i] <= 'Z' ){
            st.push(string(1,pr[i]));
        }
        else{
            string c1 = st.top();
            st.pop();
            string c2 = st.top();
            st.pop();
            string temp = c1+c2+pr[i];
            st.push(temp);
        }
    }

    return st.top();

}

int main(){
    string pr = "*-A/BC-/AKL";
    cout << PrefixToPostfix(pr)<<endl;

    return 0;
}