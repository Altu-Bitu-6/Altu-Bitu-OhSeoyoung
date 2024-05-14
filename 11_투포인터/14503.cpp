#include <iostream>
using namespace std;

int N, M, r, c, d;
int map[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    while (true) {
        if (map[r][c] == 0) {
            map[r][c] = 2;
            count++;
        }

        bool moved = false;
        for (int i = 0; i < 4; i++) {
            d = (d + 3) % 4;
            int nr = r + dx[d];
            int nc = c + dy[d];

            if (map[nr][nc] == 0) {
                r = nr;
                c = nc;
                moved = true;
                break;
            }
        }

        if (!moved) {
            int back = (d + 2) % 4;
            r += dx[back];
            c += dy[back];

            if (map[r][c] == 1) {
                break;
            }
        }
    }

    cout << count << '\n';

    return 0;
}
