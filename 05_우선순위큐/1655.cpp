// 1655.cpp

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    // 최대 힙과 최소 힙
    priority_queue<int, vector<int>, less<int> > maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;

        // 두 힙의 크기를 조절하며 숫자를 추가
        if (maxHeap.size() == minHeap.size()) maxHeap.push(num);
        else minHeap.push(num);

        // 중간값 
        if (!minHeap.empty() && !maxHeap.empty() && minHeap.top() < maxHeap.top()) {
            int maxTop = maxHeap.top();
            int minTop = minHeap.top();
            maxHeap.pop();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(maxTop);
        }

        cout << maxHeap.top() << '\n';
    }

    return 0;
}

