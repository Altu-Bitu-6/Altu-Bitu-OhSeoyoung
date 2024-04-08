// 해결 완.

#include <iostream>
#include <vector>

using namespace std;

int n, m, v, t;
vector< vector<int> > li; // 연결되어 있는지를 저장한 배열 
vector<bool> visited_dfs;
int ans = -1;

void dfs(int index, int target, vector<int>& ans_dfs, int cnt) {
    visited_dfs[index] = true;
    ans_dfs.push_back(index);
    cnt++;

    if(index == target){
        ans = cnt;
    }

    for (int i = 1; i <= n; i++) { // 인접한 노드를 순회함 
        if (li[index][i] == 1 && !visited_dfs[i]) { // 아직 방문하지 않은 근처 노드
            dfs(i, target, ans_dfs, cnt);
        }
    }

}


int main() {

    cin >> n;
    cin >> v >> t;
    cin >> m;

    li.assign(n + 1, vector<int>(n + 1, 0));
    visited_dfs.assign(n + 1, false);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        li[a][b] = li[b][a] = 1;
    }

    vector<int> ans_dfs;
    dfs(v, t, ans_dfs, -1);

    if (ans != -1){
        cout << ans;
    }
    else {
        cout << "-1";
    }

    return 0;
}