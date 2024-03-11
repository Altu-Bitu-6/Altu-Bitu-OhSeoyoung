// 구현, 시뮬레이션
// 해결 완.

#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

    /*킹, 돌, 움직이는 횟수 입력받기*/
    string king, rock;
    int n;

    cin >> king >> rock >> n;

    // string king_c = king.substr(0,1);
    int king_r = stoi(king.substr(1,1));

    // string rock_c = rock.substr(0,1);
    int rock_r = stoi(rock.substr(1,1));

    /*column 지정해주기*/
    string sub_king = king.substr(0,1);
    string sub_rock = rock.substr(0,1);

    char king_c, rock_c;

    if (sub_king == "A") {
        king_c = 'A';
    } else if (sub_king == "B") {
        king_c = 'B';
    } else if (sub_king == "C") {
        king_c = 'C';
    } else if (sub_king == "D") {
        king_c = 'D';
    } else if (sub_king == "E") {
        king_c = 'E';
    } else if (sub_king == "F") {
        king_c = 'F';
    } else if (sub_king == "G") {
        king_c = 'G';
    } else {
        king_c = 'H';
    }
    
    if (sub_rock == "A") {
        rock_c = 'A';
    } else if (sub_rock == "B") {
        rock_c = 'B';
    } else if (sub_rock == "C") {
        rock_c = 'C';
    } else if (sub_rock == "D") {
        rock_c = 'D';
    } else if (sub_rock == "E") {
        rock_c = 'E';
    } else if (sub_rock == "F") {
        rock_c = 'F';
    } else if (sub_rock == "G") {
        rock_c = 'G';
    } else {
        rock_c = 'H';
    }

    // cout << king_c << " " << king_r;
    // cout << rock_c << " " << rock_r;

    /*횟수만큼 반복문 돌기 시작*/
    while (n--){ // n이 0이라면 거짓이 되므로 stop

        /*킹의 움직임 하나 입력받기*/
        string move;

        cin >> move;

        /*킹 움직임*/
        char init_king_c = king_c;
        char init_king_r = king_r;
        
        if (move == "R") {king_c++;}
        else if (move == "L") {king_c--;}
        else if (move == "B") {king_r--;}
        else if (move == "T") {king_r++;}
        else if (move == "RT") {king_c++; king_r++;}
        else if (move == "LT") {king_c--; king_r++;}
        else if (move == "RB") {king_c++; king_r--;}
        else {king_c--; king_r--;} // move == "LB"

        if (king_c == rock_c && king_r == rock_r){ // 킹과 돌의 위치가 겹침
            
            /*돌 움직임*/
            char init_rock_c = rock_c;
            char init_rock_r = rock_r;

            if (move == "R") {rock_c++;}
            else if (move == "L") {rock_c--;}
            else if (move == "B") {rock_r--;}
            else if (move == "T") {rock_r++;}
            else if (move == "RT") {rock_c++; rock_r++;}
            else if (move == "LT") {rock_c--; rock_r++;}
            else if (move == "RB") {rock_c++; rock_r--;}
            else {rock_c--; rock_r--;} // move == "LB"

            if ( rock_c < 'A' || rock_c >'H' || rock_r < 1 || rock_r > 8 ) {
                king_c = init_king_c;
                king_r = init_king_r;
                rock_c = init_rock_c;
                rock_r = init_rock_r;
            } 

        } else { // 킹과 돌의 위치가 겹치지 않음
            if ( king_c < 'A' || king_c >'H' || king_r < 1 || king_r > 8 ) { //king의 위치가 out
                king_c = init_king_c;
                king_r = init_king_r;
            } 
        }

    }
    /*반복문 끝*/

    /*킹, 돌 위치 각각 한 줄씩 출력*/
    cout << king_c << king_r << "\n" ;
    cout << rock_c << rock_r;


    return 0;
}