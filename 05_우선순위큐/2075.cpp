// 2075.cpp

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, greater<int> > pq; // 최소 힙

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int num;
            cin >> num;
            if (pq.size() < N) { // 우선순위 큐의 크기가 N보다 작으면 그냥 삽입
                pq.push(num);
            } else if (num > pq.top()) { // 현재 숫자가 큐의 최소값보다 크면 최소값 제거 후 새 값 삽입
                pq.pop();
                pq.push(num);
            }
        }
    }

    cout << pq.top(); // N번째 큰 수 출력

    return 0;
}


