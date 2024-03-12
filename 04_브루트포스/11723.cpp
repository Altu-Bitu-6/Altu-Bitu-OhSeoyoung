#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    string str;
    int n;

    int s = 0;

    while(m--){
        cin >> str;

        if (str == "all"){
            s = (1<<21)-1;
        } else if (str == "empty") { 
            s = 0;
        } else {

            cin >> n;

            if (str == "add"){
                s |= (1<<n);
                
            } else if (str == "remove"){
                s &= ~(1<<n);
            } else if (str == "check") {
                if(s & (1<<n)){
                    cout << "1\n";
                } else {
                    cout << "0\n";
                }
            } else { // str == "toggle"
                if(s & (1<<n)){
                    s &= ~(1<<n);
                } else {
                    s |= (1<<n);
                }
            } 
        }
    }

    return 0;
}