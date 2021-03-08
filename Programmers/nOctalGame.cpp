#include <string>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string change(int number, int n) {
    string answer = "";

    if (number == 0) {
        return "0";
    }

    while (number != 0)
    {
        int change = number % n;
        number /= n;

        answer = (change >= 10) ? char(change - 10 + 'A') + answer : char(change + '0')+ answer;
    }
    
    return answer;
}


string solution(int n, int t, int m, int p) {
    string answer = "";
    int number = 0;
    int count = 0;
    char c;

    while (true)
    {
        string str = change(number, n);

        for (int i = 0; i < str.length(); i++) {

            count++;
            if (p == m) {
                if (count % m == 0) {
                    answer += str[i];
                }
            }
            else {
                if (count % m == p) {
                    answer += str[i];
                }
            }

            if (answer.length() >= t)
                return answer;
        }
        number++;
    }

}