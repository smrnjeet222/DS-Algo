#include <iostream>
#include <stack>
#include <string>

using namespace std;

int PostfixToInfix(string pst){

    stack <int> st;
    int len = pst.length();

    for (int i = 0 ; i<len ; i++){
        if (pst[i] == ' ')
            continue;
        if(pst[i] >= '0' && pst[i] <= '9' ){
            int count = 1;
            int x = 0;
            while(pst[i]!= ' '){
                x = x*count + (pst[i] - '0');
                count *=10;
                i++;
            }
            st.push(x);
        }
        else{
            int c1 = st.top();
            st.pop();
            int c2 = st.top();
            st.pop();
            switch (pst[i]){
            case '*':
                st.push(c2 * c1);
                break;
            case '+':
                st.push(c2 + c1);
                break;
            case '-':
                st.push(c2 - c1);
                break;
            case '/':
                st.push(c2 / c1);
                break;
            case '%':
                st.push(c2 % c1);
                break;
            }
        }
    }

    return st.top();

}

int main(){
    // place a space after every digit 
    string pst = "40 2 *10 -";
    cout << PostfixToInfix(pst)<<endl;

    return 0;
}