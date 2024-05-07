#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(const vector<int>& snacks, int length, int M) {
    int count = 0;
    for (int snack : snacks) {
        count += snack / length;
        if (count >= M) return true;
    }
    return false;
}

int main() {
    int M, N;
    cin >> M >> N;
    vector<int> snacks(N);

    for (int i = 0; i < N; i++) {
        cin >> snacks[i];
    }

    sort(snacks.begin(), snacks.end());

    int low = 1, high = snacks.back(), max_length = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (canDivide(snacks, mid, M)) {
            max_length = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << max_length << '\n';

    return 0;
}
