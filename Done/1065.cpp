#include <iostream>

using namespace std;

int main()
{
    //각각 입력값, 잠시 값을 담아두는 공간, 정답, 카운트로 변수 선언
    int input, tmp, answer, count;
    cin >> input;
    //정답과 인풋을 맞춘 뒤에 한수가 아니면 제거
    answer = input;

    //1의 자리는 전부 한수로 취급하기에 10부터 시작
    for (int i = 10; i <= input; i++)
    {
        int arr[4] = {-1, -1, -1, -1};
        count = 0;
        tmp = i;

        //자리수를 전부 arr에 대입
        while (tmp > 0)
        {
            arr[count++] = tmp % 10;
            tmp /= 10;
        }

        //등비를 구함
        tmp = abs(arr[0] - arr[1]);

        //4자리 만큼 반복
        for (int j = 1; j < 4; j++)
        {
            //-1일경우 입력값 없기 떄문에 탈출 (한수)
            if (arr[j] == -1)
                break;

            //등차가 다를 경우 답을 빼주고 탈출
            if (abs(arr[j] - arr[j - 1]) != tmp)
            {
                answer--;
                break;
            }

            //1자리와 3자리가 같을 경우 ex)121는 한수가 아니므로 탈출
            if (arr[0] == arr[2] && arr[0] != arr[1])
            {
                answer--;
                break;
            }
        }
    }
    cout << answer;
}