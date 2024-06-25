#include <bits/stdc++.h>
using namespace std;


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    bool iscovered = false;
    cin >> s;
    int n;
    int sum = 0;
    int sumTmp = 0;
    int p = 0;
    n = s.length();
    for (int i = 0; i < n; i++) {
        if (s[i] == '-' ) { // '-'가 나오면
            int num = 0;
            for (int j = 0; j < p; j++) {
                num += (s[i - j - 1] - '0') * int(pow(10, j));
            }
            //cout << num << "\n";
            if (!iscovered) { // 괄호가 사용중이지 않으면 뒤에 괄호 시작
                iscovered = true;
                sumTmp = 0;
                sum += num;
                //cout << "괄호 시작\n";
            }
            else { // 괄호가 사용중이면 앞에 괄호를 닫고 빼기
                sumTmp += num;
                sum -= sumTmp;
                sumTmp = 0;
                //cout << "괄호 끝\n";
                //cout << "괄호 시작\n";
            }
            p = 0;
        }
        else if (s[i] == '+') {
            int num = 0;
            for (int j = 0; j < p; j++) {
                num += (s[i - j - 1] - '0') * int(pow(10, j));
            }
            if (!iscovered) { // 괄호가 사용중이지 않으면 sum에 더하기
                sum += num;
            }
            else { // 괄호가 사용중이면 tmp에 더하기
                sumTmp += num;
            }
            p = 0;
        }
        else {
            p++;
        }
    }
    int num = 0;
    for (int j = 0; j < p; j++) {
        num += (s[n - j - 1] - '0') * int(pow(10, j));
    }
    if (!iscovered) { // 괄호가 사용중이지 않으면 sum에 더하기
        sum += num;
    }
    else { // 괄호가 사용중이면 tmp에 더하기
        sumTmp += num;
        sum -= sumTmp;
        //cout << "괄호 끝\n";
    }
    cout << sum;
}