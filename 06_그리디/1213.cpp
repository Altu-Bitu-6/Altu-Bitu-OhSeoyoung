// 해결 완.

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // 영어 이름 입력 받기
    string name;
    cin >> name;

    vector<char> ans;
    // cout << ans.size();

    // 'A' : 65 ~ 'Z' : 90
    // 알파벳 개수 세기
    int alpha[26] = {0,};
    
    for (int i = 0; i < name.size(); i++){
        alpha[name[i] - 65]++;
    }

    // 홀수 개수 세기
    int odd_cnt = 0;
    for (int i = 0; i < 26; i++){

        if (alpha[i] % 2 != 0){
            odd_cnt++;
        }

    }

    char middle;

    // "I'm sorry Hansoo"를 출력해야 하는지 확인
    if ((name.size() % 2 == 0 && odd_cnt > 0) || (name.size() % 2 != 0 && odd_cnt != 1)){
        cout << "I'm Sorry Hansoo";
    }
    else if (name.size() % 2 == 0) {
        // cout << "짝수";
        for (int i = 0; i < 26; i++){

            if (alpha[i] != 0){

                for (int j=0; j<alpha[i]/2; j++){
                    ans.push_back(char(i + 65));
                }
            }

        }

        for (int i = ans.size()-1; i >= 0; i--){ // 데칼코마니로 뒤에도 넣어주기
            ans.push_back(ans[i]);
        }
    }
    else {
        // cout << "홀수";
        for (int i = 0; i < 26; i++){

            if (alpha[i] != 0){

                if (alpha[i] % 2 != 0){
                    middle = char(i + 65);
                }

                for (int j=0; j<alpha[i]/2; j++){
                    ans.push_back(char(i + 65));
                }
            }
        }

        ans.push_back(middle);

        for (int i = ans.size()-2; i >= 0; i--){ // 데칼코마니로 뒤에도 넣어주기
            ans.push_back(ans[i]);
        }

    }

    for (int i=0; i < ans.size(); i++){
        cout << ans[i];
    }

    return 0;
}