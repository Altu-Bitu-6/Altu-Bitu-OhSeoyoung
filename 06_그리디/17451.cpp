// 해결 완.

#include <iostream>
#include <vector>
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);

    // 입력받기
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 계산하기
    long long velo = 0;
 
    for (int i = 0; i < n; i++) {
        // cout << velo << "-> ";
       
        if (velo <= arr[n-i-1]) {
            velo = arr[n-i-1];
        } else {
            if (velo % arr[n-i-1] != 0) {
                velo = arr[n-i-1] * (velo/arr[n-i-1] + 1);
            }
            
        }

        //  cout << velo << '\n';

    }

    // 출력하기
    cout << velo;

    return 0;
}