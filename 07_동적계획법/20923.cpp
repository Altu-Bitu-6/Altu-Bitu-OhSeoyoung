#include <iostream>
#include <deque>

using namespace std;

int main() {

    int n, m;
    cin >> n >> m;

    deque<int> dodo(n);
    deque<int> suyeon(n);

    for(int i=0; i<n; i++){
        cin >> dodo[i] >> suyeon[i];
    }

    deque<int> doGround;//도도의 그라운드 카드더미
    deque<int> suGround;//수연의 그라운드 카드더미

    bool dodoTurn = true; //true는 도도의 차례, false는 수연의 차례
    int cnt = 0;//게임 진행 횟수
    string winner = "";//이긴 사람

    //풀이
    while(true){
        cnt++;//게임 진행 횟수 증가

        //차례인 사람이 카드 내려놓기
        if(dodoTurn) {//도도의 차례면
            doGround.push_back(dodo.back());//도도가 카드 내려놓기
            dodo.pop_back();
        }
        else {//수연의 차례면
            suGround.push_back(suyeon.back());//수연이가 카드 내려놓기
            suyeon.pop_back();
        }

        //0개 됐는지 체크
        if(dodo.size() == 0){//도도의 카드 수가 0이면
            winner = "su";
            break;
        }
        else if(suyeon.size() == 0){//수연이의 카드 수가 0이면
            winner = "do";
            break;
        }

        //수연이가 종치기
        if(doGround.size() != 0 && suGround.size() != 0 && doGround.back() + suGround.back() == 5){
            //도도의 그라운드의 카드더미를 수연이의 덱 밑에 합치기
            while(doGround.size() > 0){
                suyeon.push_front(doGround.front());
                doGround.pop_front();
            }
            //수연의 그라운드의 카드더미를 수연이의 덱 밑에 합치기
            while(suGround.size() > 0){
                suyeon.push_front(suGround.front());
                suGround.pop_front();
            }
        }
        //도도가 종치기
        else if(doGround.size() != 0 && doGround.back() == 5 || suGround.size() != 0 && suGround.back() == 5){
            //수연의 그라운드의 카드더미를 도도의 덱 밑에 합치기
            while(suGround.size() > 0){
                dodo.push_front(suGround.front());
                suGround.pop_front();
            }
            //도도의 그라운드의 카드더미를 도도의 덱 밑에 합치기
            while(doGround.size() > 0){
                dodo.push_front(doGround.front());
                doGround.pop_front();
            }
        }

        //M번 진행한 후
        if(cnt == m){
            int result = dodo.size() - suyeon.size();
            if(result < 0) winner = "su";
            else if(result > 0) winner = "do";
            else winner = "dosu";
            break;
        }

        dodoTurn = !dodoTurn;//차례 변경
    }

    cout << winner;

    return 0;
}