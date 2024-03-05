#include <iostream>
#include <vector>
using namespace std;

//재귀 이용하여 최대공약수(gcd) 구하기
int getGcdRecur(int a, int b)  {
    if (b == 0) {
        return a;
    }
    return getGcdRecur(b, a%b);
}

int main() {
    // 1. 입력받기
    int a, b, c, d;
    cin >> a >> b; // a/b
    cin >> c >> d; // c/d

    // 2. 분수의 합 구하기
    int e, f; // e/f

    int gcd = getGcdRecur(b, d);
    int lcm = b * d / gcd;

    f = lcm;
    e = (a * (lcm / b)) + (c * (lcm / d));

    // 3. 최대공약수로 약분하기
    int gcd2 = getGcdRecur(e, f);
    int res_e, res_f;

    res_e = e / gcd2;
    res_f = f / gcd2;
    
    // 4. 출력하기
    cout << res_e << " " << res_f;


    return 0;
}