// 14235.cpp

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    priority_queue<int> gifts; // 선물의 가치를 내림차순으로 정렬하는 우선순위 큐

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 0) { // 아이를 만난 경우
            if (gifts.empty()) {
                // 줄 선물이 없는 경우
                cout << -1 << "\n";
            } else {
                // 가장 가치가 큰 선물을 준다
                cout << gifts.top() << "\n";
                gifts.pop(); // 선물을 주었으므로 큐에서 제거
            }
        } else { // 거점지에서 선물을 충전하는 경우
            for (int j = 0; j < a; j++) {
                int value;
                cin >> value;
                gifts.push(value); // 선물을 큐에 추가
            }
        }
    }

    return 0;
}

