#include <iostream>
#include <algorithm> // max 함수 사용을 위해 필요
using namespace std;

int main() {
    int n; // 계단의 수
    cin >> n;

    int stairs[301]; // 각 계단의 점수를 저장할 배열
    for (int i = 1; i <= n; i++) {
        cin >> stairs[i];
    }

    int dp[301]; // dp[i]는 i번째 계단에 도달했을 때 얻을 수 있는 최대 점수
    // 초기 조건 설정
    dp[0] = 0; // 시작점의 점수는 0
    dp[1] = stairs[1];
    if (n >= 2) {
        dp[2] = stairs[1] + stairs[2];
    }

    // 점화식에 따른 dp 배열 채우기
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-2] + stairs[i], dp[i-3] + stairs[i-1] + stairs[i]);
    }

    cout << dp[n]; // 마지막 계단에 도달했을 때의 최대 점수 출력

    return 0;
}
