// 자료 구조, 스택, 문자열
// 10828 참고

#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    stack<char> s; //스택 선언

    vector<string> v;
    string str;
    while (getline(cin, str)) {
        if (!str.compare(".")){ // compare한 결과 같으면 0, 다르면 1을 리턴함. 
                                // c++에서는 0을 false로, 0 이외의 값을 true로 이해함.
            break;
        }
        v.push_back(str);
    }

    for (int i = 0; i < v.size(); i++) {

        for (int j = 0; j < v[i].size(); j++){

            if((v[i][j]=='[') || (v[i][j]=='(') ) {
                s.push(v[i][j]);
               
            } else if (v[i][j]==']') {
                if(!s.empty() && s.top()=='['){
                    s.pop();

                } else {
                    s.push(v[i][j]);

                }
                
                
            } else if (v[i][j]==')') {
                if(!s.empty() && s.top()=='('){
                    s.pop();
                } else {
                    
                    s.push(v[i][j]);
                }
            }
        }

        if(s.empty()){
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
            while( !s.empty() ) {
                s.pop();
            }
        }
        
    }

    return 0;
}