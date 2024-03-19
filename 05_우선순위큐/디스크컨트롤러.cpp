// 디스크컨트롤러.cpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

bool compareJobs(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0];
}

int solution(vector<vector<int> > jobs) {
    
    sort(jobs.begin(), jobs.end(), compareJobs);

    int time = 0, total_wait_time = 0;
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    size_t i = 0;
    while (i < jobs.size() || !pq.empty()) {
        // 힙에 추가
        while (i < jobs.size() && jobs[i][0] <= time) {
            pq.push(make_pair(jobs[i][1], jobs[i][0]));
            i++;
        }
        
        // 처리할 작업이 있는 경우
        if (!pq.empty()) {
            pair<int, int> job = pq.top(); pq.pop();
            int job_duration = job.first;
            int job_start = job.second;
            time += job_duration; // 작업을 처리하고 시간을 업데이트
            total_wait_time += time - job_start; // 대기 시간을 업데이트
        } else {
            // 처리할 작업이 없으면 다음 작업의 시작 시간으로 시간을 설정
            time = jobs[i][0];
        }
    }

    // 평균 대기시간을 계산하고 반환
    return total_wait_time / jobs.size();
}

int main() {
    vector<vector<int> > jobs;
    jobs.push_back(vector<int>(2, 0)); // 2개의 요소를 갖는 벡터를 추가하고, 모든 값을 0으로 초기화
    jobs.push_back(vector<int>(2, 0));
    jobs.push_back(vector<int>(2, 0));

    jobs[0][0] = 0; jobs[0][1] = 3;
    jobs[1][0] = 1; jobs[1][1] = 9;
    jobs[2][0] = 2; jobs[2][1] = 6;

    cout << solution(jobs) << endl;
    return 0;
}

