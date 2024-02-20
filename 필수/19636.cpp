
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct day { // 요일 정보 구조체
    // 0초일 때 시간 : 체중 init_w, 에너지 섭취량 init_l, 기초 대사량 init_b, 
    // 활동 대사량 init_a, 역치 t, 다이어트 일수 d
    int init_w, init_l, init_b, init_a, t, d = 0; 

    // 다이어트 기간 : 에너지 섭취량 l, 활동 대사량 a
    int l, a = 0;

};

int main() {
    // 0초일 때 시간 : 체중 init_w, 에너지 섭취량 init_l, 기초 대사량 init_b, 
    // 활동 대사량 init_a, 역치 t, 다이어트 일수 d
    int init_w, init_l, init_b, init_a, t, d = 0; 

    cin >> init_w >> init_l >> t;

    // 다이어트 기간 : 에너지 섭취량 l, 활동 대사량 a
    int l, a = 0;
    vector<day> arr(n);

    cin >> d >> l >> a;

    return 0;
}
