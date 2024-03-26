#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int t, k; // 톱니바퀴의 개수와 회전 횟수
    cin >> t;
    vector< vector<int> > arr(t, vector<int>(8)); // 각 톱니바퀴의 극을 저장하는 2차원 벡터

    // 톱니바퀴의 초기 상태 입력
    for (int i = 0; i < t; i++) {
        string input;
        cin >> input;
        for (int j = 0; j < 8; j++) {
            arr[i][j] = input[j] - '0'; // 문자열로 입력받은 톱니바퀴의 상태를 정수로 변환
        }
    }

    cin >> k; // 회전 횟수 입력

    for (int i = 0; i < k; i++) {
        int num, direction; // 회전시킬 톱니바퀴의 번호와 방향
        cin >> num >> direction;
        num--; // 사용자 입력은 1부터 시작하지만, 배열 인덱스는 0부터 시작하므로 조정

        vector<int> directions(t, 0); // 각 톱니바퀴의 회전 방향을 저장하는 벡터, 초기값은 0(회전하지 않음)
        directions[num] = direction; // 현재 회전시키려는 톱니바퀴의 방향 설정

        // 현재 톱니바퀴의 왼쪽에 있는 톱니바퀴들을 검사하며 회전 여부와 방향 결정
        for (int left = num - 1; left >= 0; left--) {
            if (arr[left][2] != arr[left + 1][6]) {
                directions[left] = -directions[left + 1]; // 인접 톱니바퀴의 극이 다르면 반대 방향으로 회전
            } else {
                break; // 극이 같으면 더 이상 검사하지 않고 반복문 탈출
            }
        }

        // 현재 톱니바퀴의 오른쪽에 있는 톱니바퀴들을 검사하며 회전 여부와 방향 결정
        for (int right = num + 1; right < t; right++) {
            if (arr[right - 1][2] != arr[right][6]) {
                directions[right] = -directions[right - 1]; // 인접 톱니바퀴의 극이 다르면 반대 방향으로 회전
            } else {
                break; // 극이 같으면 더 이상 검사하지 않고 반복문 탈출
            }
        }

        // 결정된 방향에 따라 각 톱니바퀴를 실제로 회전시킴
        for (int j = 0; j < t; j++) {
            if (directions[j] != 0) {
                if (directions[j] == 1) { // 시계 방향 회전
                    int temp = arr[j][7];
                    for (int m = 7; m > 0; m--) {
                        arr[j][m] = arr[j][m - 1];
                    }
                    arr[j][0] = temp;
                } else if (directions[j] == -1) { // 반시계 방향 회전
                    int temp = arr[j][0];
                    for (int m = 0; m < 7; m++) {
                        arr[j][m] = arr[j][m + 1];
                    }
                    arr[j][7] = temp;
                }
            }
        }
    }

    // 12시 방향이 S극인 톱니바퀴의 개수 계산
    int count = 0;
    for (int i = 0; i < t; i++) {
        if (arr[i][0] == 1) { // 각 톱니바퀴의 12시 방향이 S극(1)인 경우
            count++; // 개수를 증가시킴
        }
    }

    cout << count; // 최종적으로 S극인 톱니바퀴의 개수를 출력

    return 0; // 프로그램 종료
}