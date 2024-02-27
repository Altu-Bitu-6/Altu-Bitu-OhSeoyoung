
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm> // reverse 함수를 사용하기 위해 추가

using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    // 두 문자열을 역순으로 만들기
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    const int length1 = s1.length();
    const int length2 = s2.length();

    // 최대 길이 계산
    int maxLen = max(length1, length2);
    vector<int> cal(maxLen + 1, 0); // 계산 결과를 저장할 벡터, 하나 더 크게 잡아 마지막 carry를 처리할 수 있도록 함

    int carry = 0;
    for (int i = 0; i < maxLen; i++) {
        int a = (i < length1) ? s1[i] - '0' : 0;
        int b = (i < length2) ? s2[i] - '0' : 0;
        int sum = a + b + carry;
        cal[i] = sum % 10; // 현재 자릿수의 합
        carry = sum / 10; // 다음 자리로 넘어가는 값
    }

    // 마지막 carry 처리
    if (carry > 0) {
        cal[maxLen] = carry;
    }

    // 결과 출력(역순으로 출력해야 정상적인 숫자 형태로 보임)
    bool leadingZero = true;
    for (int i = cal.size() - 1; i >= 0; i--) {
        if (cal[i] == 0 && leadingZero) {
            continue; // 앞쪽의 불필요한 0은 출력하지 않음
        }
        leadingZero = false; // 첫 번째로 0이 아닌 숫자를 만나면, 이후부터는 0도 출력
        cout << cal[i];
    }

    // 모든 결과가 0인 경우(두 입력이 모두 0인 경우) 0을 출력
    if (leadingZero) {
        cout << "0";
    }

    return 0;
}
