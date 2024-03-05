#include <iostream>
#include <vector>

using namespace std;

const int N = 1000000;

int main() {
    //입출력 속도 향상
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 소수들 구하기
    int is_prime[N] = {0};
    
    for(int i=2; i*i<=N; i++){
        if(is_prime[i] == 0){
            for (int j = i*i; j<= N; j+= i){
                is_prime[j] = 1;
            }
        }
    }

    int n;

    while (1){ // 0이 아닌 모든 입력값에 대하여 반복
        cin >> n;

        if(n==0){
            break;
        }

        bool chk = false;
        // 소수 간의 합을 출력하기
        for (int i = 3; i <= n/2; i+=2) {

            if (is_prime[i]==0 && is_prime[n-i]==0){
                cout << n << " = " << i << " + " << n - i << "\n";
                chk = true;
                break;
            }
        }

        if (!chk) {
            cout << "Goldbach's conjecture is wrong.";
        }

    }
    return 0;
}