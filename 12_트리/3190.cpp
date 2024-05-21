#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;

struct Position {
    int x, y;
};

int n;  // 보드의 크기
int k;  // 사과의 개수
vector<vector<int> > board;  // 보드
map<int, char> directions;  // 방향 변환 정보
deque<Position> snake;  // 뱀의 위치

// 방향 이동을 위한 배열 (오른쪽, 아래, 왼쪽, 위)
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int simulate() {
    int time = 0;
    int direction = 0;  // 현재 방향 (0: 오른쪽, 1: 아래, 2: 왼쪽, 3: 위)
    
    while (true) {
        time++;
        
        // 뱀의 머리 다음 위치 계산
        int nx = snake.front().x + dx[direction];
        int ny = snake.front().y + dy[direction];
        
        // 벽에 부딪히거나 자기 자신과 부딪히면 종료
        if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 2) {
            break;
        }
        
        // 사과가 있는 경우
        if (board[nx][ny] == 1) {
            board[nx][ny] = 0;  // 사과를 먹음
        } else {
            // 사과가 없는 경우 꼬리 제거
            Position tail = snake.back();
            snake.pop_back();
            board[tail.x][tail.y] = 0;
        }
        
        // 새로운 머리 위치 추가
        snake.push_front({nx, ny});
        board[nx][ny] = 2;  // 뱀의 몸 표시
        
        // 방향 변환이 필요한 시간인지 확인
        if (directions.count(time)) {
            char turn = directions[time];
            if (turn == 'L') {
                direction = (direction + 3) % 4;  // 왼쪽 회전
            } else {
                direction = (direction + 1) % 4;  // 오른쪽 회전
            }
        }
    }
    
    return time;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> k;
    
    board = vector<vector<int> >(n, vector<int>(n, 0));
    
    // 사과 위치 입력
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = 1;
    }
    
    int l;
    cin >> l;
    
    // 방향 변환 정보 입력
    for (int i = 0; i < l; ++i) {
        int time;
        char dir;
        cin >> time >> dir;
        directions[time] = dir;
    }
    
    // 뱀의 초기 위치 설정
    snake.push_back({0, 0});
    board[0][0] = 2;
    
    // 시뮬레이션 실행
    int result = simulate();
    cout << result << '\n';
    
    return 0;
}
