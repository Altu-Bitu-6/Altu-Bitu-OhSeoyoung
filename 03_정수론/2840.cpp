// 표준 입출력 라이브러리를 포함
#include <iostream>
// 벡터(동적 배열)를 사용하기 위한 라이브러리 포함
#include <vector>
// 알고리즘 함수를 사용하기 위한 라이브러리 포함
#include <algorithm>

// 표준 네임스페이스 사용 선언
using namespace std;

// main 함수 시작
int main() {
    // 입출력 속도 향상을 위해 동기화 해제
    ios::sync_with_stdio(false);
    // cin과 cout을 untie한다; cin으로 입력 받기 전에 cout을 자동으로 flush하지 않음
    cin.tie(NULL); cout.tie(NULL);

    // 변수 n과 k 선언 (n은 요소의 수, k는 입력 받을 회전 및 문자의 수)
    int n, k;
    // n과 k를 사용자로부터 입력받음
    cin >> n >> k;

    // 크기가 n인 char 벡터(원형 큐) 생성 및 '?'로 초기화
    vector<char> q(n);
    for(int i = 0; i < n; i++){
        q[i] = '?';
    }

    // 룰렛을 만들 수 있는지 판단하는 변수 및 기타 변수 초기화
    bool makeRoulette = true; // 룰렛을 만들 수 있는지 여부
    int last_idx = 0; // 마지막으로 문자를 삽입한 인덱스
    vector<char> arr; // 삽입된 문자를 저장하는 배열
    int cnt = 0; // 삽입된 고유 문자의 수

    // k번의 회전 및 문자 삽입을 처리
    for (int i=0; i < k; i++) {
        
        // 회전 수(s)와 삽입할 문자(c)를 입력 받음
        int s;
        char c;
        cin >> s >> c;

        // 회전 후의 인덱스 계산
        int after_idx = (last_idx - s >= 0) ? (last_idx - s) % n : ((last_idx - s) % n + n) % n;

        // 이미 삽입된 문자와 중복되는지 검사
        for (int j = 0; j < cnt; j++){
            if (arr[j] == c && q[after_idx] != c){
                makeRoulette = false;
            }
        }

        // 해당 위치에 다른 문자가 이미 존재하는 경우, 룰렛을 만들 수 없음
        if (q[after_idx] != '?' && q[after_idx] != c){
            makeRoulette = false;
        }
        // 해당 위치에 같은 문자가 이미 존재하는 경우, 아무 작업도 수행하지 않음
        else if (q[after_idx] != '?' && q[after_idx] == c){

        }
        // 그 외의 경우, 새 문자를 삽입
        else {
            q[after_idx] = c;
            arr.push_back(c); // 삽입된 문자를 arr에 추가
            cnt++; // 삽입된 고유 문자 수 증가
        }

        // 다음 회전을 위해 마지막 인덱스 업데이트
        last_idx = after_idx;
    }

    // 룰렛을 성공적으로 만들었는지 판단
    int i = last_idx; // 출력 시작 위치 설정
    int count = 0; // 출력된 문자 수
    if (makeRoulette == true){
        // 모든 문자를 출력할 때까지 반복
        while(1) {
            // 모든 문자를 출력했으면 반복 종료
            if (count == n){
                break;
            }
            // 현재 인덱스의 문자 출력
            cout << q[i];
            // 출력된 문자 수 증가
            count++;
            // 다음 인덱스로 이동 (원형 큐를 고려)
            i = (i+1) > 0 ? (i+1)%n : ((i+1)%n + n)%n;
        }
    } else {
        // 룰렛을 만들 수 없는 경우 '!' 출력
        cout << '!' << '\n';
    }

    // main 함수 종료
    return 0;
}
