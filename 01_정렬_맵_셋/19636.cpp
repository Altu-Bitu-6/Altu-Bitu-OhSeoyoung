#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

// 체중과 기초 대사량을 저장하는 구조체
struct day { 
    int w; // 체중
    int b; // 기초 대사량
};

// 체중을 계산하는 함수
int calW(int b, int a, int w, int i) { // 기초 대사량 b, 활동 대사량 a, 체중 w, 에너지 섭취량 i
    int diff_w = i - (b + a); // 에너지 섭취량과 총 대사량의 차이
    return w + diff_w; // 새 체중 계산
}

// 기초 대사량을 계산하는 함수
int calB(int b, int a, int i, int t) { 
    int diff_w = abs(i - (b + a)); // 에너지 섭취량과 총 대사량의 차이(절대값)
    int diff_b = 0; // 기초 대사량 변화량 초기화

    if (diff_w > t) { // 차이가 역치보다 크면
        diff_b = floor(i - (b + a))/2; // 기초 대사량 변화 계산
    } else {
        diff_b = 0; // 변화 없음
    }

    return b + diff_b; // 새 기초 대사량 계산
}

int main() {
    int init_w, init_i= 0; // 초기 체중과 기초 대사량
    int i, d, t, a = 0; // 에너지 섭취량, 다이어트 일수, 역치, 활동 대사량

    cin >> init_w >> init_i >> t; // 사용자로부터 입력 받음
    cin >> d >> i >> a; // 사용자로부터 입력 받음

    /* T 고려 안 하는 경우 */
    vector<day> arr2(d+1); // 다이어트 일수만큼 구조체 배열 생성

    arr2[0].w = init_w; // 초기 체중 설정
    arr2[0].b = init_i; // 초기 기초 대사량 설정

    for (int k = 1; k <= d; k++) { // 다이어트 기간 동안 반복
        arr2[k].w = calW(arr2[0].b, a, arr2[k-1].w, i); // 체중 계산
    }
    if ( arr2[d].w <= 0 ) { // 체중이 0 이하면 사망
        cout << "Danger Diet" << '\n';
    } else { // 그렇지 않으면 결과 출력
        cout << arr2[d].w << " " << init_i << '\n';
    }

    /* T 고려하는 경우 */
    vector<day> arr(d+1); // 다이어트 일수만큼 구조체 배열 생성

    arr[0].w = init_w; // 초기 체중 설정
    arr[0].b = init_i; // 초기 기초 대사량 설정

    for (int k = 1; k <= d; k++) { // 다이어트 기간 동안 반복
        arr[k].w = calW(arr[k-1].b, a, arr[k-1].w, i); // 체중 계산
        arr[k].b = calB(arr[k-1].b, a, i, t); // 기초 대사량 계산
    }
    
    if ( arr[d].w <= 0 || arr[d].b <= 0 ) { // 체중이나 기초 대사량이 0 이하면 사망
        cout << "Danger Diet";
    } else if ( (init_i - arr[d].b) > 0 ) { // 기초 대사량이 감소했으면 요요 현상
        cout << arr[d].w << " " << arr[d].b << " " << "YOYO";
    } else { // 그렇지 않으면 요요 없음
        cout << arr[d].w << " " << arr[d].b << " " << "NO";
    }

    return 0;
}
