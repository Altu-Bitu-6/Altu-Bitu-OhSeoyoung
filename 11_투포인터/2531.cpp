#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d, k, c;
    cin >> n >> d >> k >> c;

    vector<int> sushi(n * 2);
    for (int i = 0; i < n; ++i) {
        cin >> sushi[i];
        sushi[i + n] = sushi[i];  // 벨트를 원형으로 처리하기 위해 두 배로 늘림
    }

    vector<int> count(d + 1, 0);  // 초밥 종류의 개수를 세기 위한 배열
    int total = 0;  // 현재 윈도우에 있는 서로 다른 초밥의 종류 수
    int maxTypes = 0;  // 최대로 먹을 수 있는 서로 다른 초밥의 종류 수

    // 초기 윈도우 설정 (0부터 k-1까지)
    for (int i = 0; i < k; ++i) {
        if (count[sushi[i]] == 0) total++;
        count[sushi[i]]++;
    }

    // 쿠폰 초밥 처리
    if (count[c] == 0) maxTypes = total + 1;
    else maxTypes = total;

    // 슬라이딩 윈도우 시작
    for (int i = 1; i < n; ++i) {
        // 벨트의 시작을 i, 끝을 i+k-1로 설정
        count[sushi[i - 1]]--;
        if (count[sushi[i - 1]] == 0) total--;

        if (count[sushi[i + k - 1]] == 0) total++;
        count[sushi[i + k - 1]]++;

        // 쿠폰 초밥이 포함되지 않았을 경우
        if (count[c] == 0) maxTypes = max(maxTypes, total + 1);
        else maxTypes = max(maxTypes, total);
    }

    cout << maxTypes << "\n";
    return 0;
}
