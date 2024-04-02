#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N; // 수열 A의 크기
    cin >> N;

    vector<int> A(N); // 수열 A를 저장할 벡터
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    vector<int> dp(N, 1); // dp[i]는 i번째 원소를 마지막으로 하는 LIS의 길이

    // LIS 알고리즘 구현
    for(int i = 1; i < N; ++i) {
        for(int j = 0; j < i; ++j) {
            if(A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // dp 벡터에서 가장 큰 값을 찾음
    int maxLength = *max_element(dp.begin(), dp.end());
    cout << maxLength << endl; // 가장 긴 증가하는 부분 수열의 길이 출력

    return 0;
}
