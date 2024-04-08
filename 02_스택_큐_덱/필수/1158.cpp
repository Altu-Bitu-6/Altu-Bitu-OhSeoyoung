// 자료 구조, 구현, 큐
// 10845 참고

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; 
    int k;
    cin >> n >> k;

    queue<int> q; //큐 선언
    int arr[k-1];

    for(int i = 1 ; i < n+1; i++){
        q.push(i);
    }

    cout << '<';

    for(int i = 0 ; i < n-2 ; i++){ //0~4

        for(int j = 0; j < k-1; j++){ //0~1
            arr[j]=q.front();
            q.pop();
            
        }

        cout << q.front() << ", ";
        q.pop();

        for(int j = 0; j < k-1; j++){
            q.push(arr[j]);
        }

    }

    //5, 6
    if(k%2 == 0) { // 짝수
        cout << q.back() << ", " << q.front() << ">";
    } else {
        cout << q.front() << ", " << q.back() << ">";
    }

    return 0;
}