// 브루트포스 알고리즘
// 해결 완.

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    string n;
    int count = 1;
    
    cin >> n;

    int n_int = stoi(n);

    string sub_str;

    int num = 1666;
    string num_str;

    if (n == "1"){
        cout << 666;
        return 0;
    }

    while (num < 1000000000){

        num_str = to_string(num);

        for (int i=0; i < num_str.size() - 2; i++){
            sub_str = num_str.substr(i, 3);

            if (sub_str == "666"){
                count++;
                
                if (count == n_int) {
                    cout << num;
                    return 0;
                }

                break;
            }
        }

        num++;
    }

}