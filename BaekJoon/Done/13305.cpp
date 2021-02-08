
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cityNum, tempNum, minPrice;
long long priceSum;
vector<long long> oilPrice, cityDistence;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> cityNum;

    //입력받음.
    for (int i = 0; i < cityNum - 1; i++)
    {
        cin >> tempNum;
        cityDistence.push_back(tempNum);
    }

    for (int i = 0; i < cityNum; i++)
    {
        cin >> tempNum;
        oilPrice.push_back(tempNum);
    }

    // for (int i = 0; i < cityNum - 1; i++)
    // {
    //     cout << oilPrice[i] << "가격 거리" << cityDistence[i] << "\n";
    // }

    //최저값 초기 설정
    minPrice = oilPrice[0];
    priceSum += minPrice * cityDistence[0];

    //이후 최저값 갱신 해주면서 다음 거리까지 최저값값을 더해줌.
    for (int i = 1; i < cityNum - 1; i++)
    {
        minPrice = (minPrice > oilPrice[i]) ? oilPrice[i] : minPrice;
        priceSum += minPrice * cityDistence[i];
    }

    //출력
    cout << priceSum << "\n";
}