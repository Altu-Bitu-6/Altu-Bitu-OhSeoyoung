// 10825와 비슷 
// 해결완

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const string& s1, const string& s2) {
    if (s1.size() != s2.size()) { // 짧은 것이 먼저
        return s1.size() < s2.size();
    }

    int sum1 = 0;
    int sum2 = 0;
    int int_s1 = 0;
    int int_s2 = 0;
    for (int i=0; i < s1.size(); i++) { // A의 모든 자리수의 합과 B의 모든 자리수의 합을 비교해서 작은 합을 가지는 것이 먼저
        if (s1[i] > 47 && s1[i] < 58) {
            int_s1 = s1[i] - '0';
            sum1 += int_s1;
        }
        if (s2[i] > 47 && s2[i] < 58) {
            int_s2 = s2[i] - '0';
            sum2 += int_s2;
        }
    }
    if (sum1 != sum2) {
        return sum1 < sum2;
    }

    return s1 < s2; // 사전순으로 비교

}


int main() {
    int n;
	// 입력
	cin >> n;

    vector<string> arr(n);
    for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

    // 연산
	sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++) {
		cout << arr[i] << '\n';
	}

    return 0;
}
