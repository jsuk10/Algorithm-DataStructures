#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int number;
int arr[4000001];
vector<int> prime;

void eratoness()
{
    //처음과 끝 즉 0 + 13 이런거 찾기 위해서
    for (int i = 2; i <= number; i++)
    {
        if (arr[i] == 1)
            continue;

        prime.push_back(i);
        int temp = i;
        //배수 삽입
        while (temp <= number)
        {
            arr[temp] = 1;
            temp += i;
        }
    }
}

void Porcess()
{
    if (prime.size() < 1)
    {
        cout << 0;
        return;
    }

    int startIndex = 0, endIndex = 0, ans = 0, sum;

    sum = prime[startIndex];

    while (startIndex < prime.size() && endIndex < prime.size())
    {
        //같을 경우 답 찾음
        if (sum == number)
        {
            sum += prime[++endIndex];
            ans++;
        }
        //합이 부족한 경우 합을 늘려줘야함
        else if (sum < number)
            sum += prime[++endIndex];
        //합이 충분할 경우 합을 줄여줘야함
        else if (sum > number)
            sum -= prime[startIndex++];
    }
    cout << ans;
}

int main()
{
    cin >> number;
    eratoness();
    Porcess();
}