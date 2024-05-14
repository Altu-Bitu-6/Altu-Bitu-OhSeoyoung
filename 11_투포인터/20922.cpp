#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
int arr[200001];
int cnt[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    int max_len = 0;
    int left = 0;
    int right = 0;
    
    while (right < N) {
        if (cnt[arr[right]] < K) {
            cnt[arr[right]]++;
            right++;
        } else {
            cnt[arr[left]]--;
            left++;
        }
        max_len = max(max_len, right - left);
    }
    
    cout << max_len << '\n';
    
    return 0;
}
