#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    unordered_set<int> cards;

    cin >> N;
    for (int i = 0, num; i < N; i++) {
        cin >> num;
        cards.insert(num);
    }

    cin >> M;
    for (int i = 0, query; i < M; i++) {
        cin >> query;
        cout << (cards.find(query) != cards.end() ? 1 : 0) << ' ';
    }

    return 0;
}
