#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[100001]; // 트리 구조를 저장할 인접 리스트
int subtree_size[100001]; // 서브트리 크기를 저장할 배열
bool visited[100001];     // 방문 여부를 체크할 배열

// DFS를 이용하여 서브트리의 크기를 계산하는 함수
int calculateSubtreeSize(int node) {
    visited[node] = true; // 현재 노드를 방문 처리
    int size = 1; // 현재 노드 자신을 포함하여 초기 크기 1

    for (int neighbor : tree[node]) {
        if (!visited[neighbor]) {
            size += calculateSubtreeSize(neighbor); // 자식 노드의 서브트리 크기를 더함
        }
    }

    subtree_size[node] = size; // 현재 노드의 서브트리 크기를 저장
    return size;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, r, q;
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    calculateSubtreeSize(r); // 루트 노드 r을 기준으로 서브트리 크기 계산

    for (int i = 0; i < q; ++i) {
        int query;
        cin >> query;
        cout << subtree_size[query] << '\n'; // 각 쿼리에 대해 서브트리 크기 출력
    }

    return 0;
}
