#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R;               // 라운드 수는 전역변수로 설정해준다. 함수에 2차원 배열이 매개변수로 들어갈건데 2차원 배열의 크기를 명시해줘야하기 때문
string chonnam_SPR;  // 전남이가 각 라운드에 낸 모양
int N;               // 친구의 수
string *friends_SPR; // 친구들이 각 라운드에 낸 모양 동적할당

// i번째 인덱스를 비교했을때 각 SPR이 몇번 나오는지 계산하여 가장 많이 나온 것의 수만큼 *2 하여 최고점수 합산
int BestScore()
{
    int sum = 0; // N명의 친구와 총 k번재 라운드를 한 끝에 나온 점수의 총합

    for (int k = 0; k < R; k++)
    {                               // k번째 라운드
        int Sc = 0, Pc = 0, Ro = 0; // SPR 0으로 초기화
        for (int i = 0; i < N; i++)
        { // i번째 친구
            // k번째 라운드에서 N명의 친구가 내는 가위바위보를 각각 나오는 수만큼 count
            if (friends_SPR[i][k] == 'S')
            {
                Sc++;
            }
            else if (friends_SPR[i][k] == 'P')
            {
                Pc++;
            }
            else
            {
                Ro++;
            }
        }

        sum += (Sc != 0 && Pc != 0 && Ro != 0) ? N : 2 * max({Sc, Pc, Ro});
    }
    return sum; // N명의 친구와 겨뤘을때 낼 수 있는 최고점수
}

// 전남이와 친구들의 가위바위보 연산 비교
int doingGame(int k)
{ // k는 친구들 중 몇번째인지 나타내는 것

    int total_score = 0; // 친구들과 게임 해서 얻은 전남이의 총 점수

    for (int i = 0; i < R; i++)
    { // 글자끼리 비교하므로 라운드 수 만큼 반복문 실행
        if (chonnam_SPR[i] == friends_SPR[k][i])
        { // 전남이와 친구가 비길때 +1점
            total_score += 1;
        }
        else if ((chonnam_SPR[i] == 'S' && friends_SPR[k][i] == 'P') || (chonnam_SPR[i] == 'P' && friends_SPR[k][i] == 'R') || (chonnam_SPR[i] == 'R' && friends_SPR[k][i] == 'S'))
        { // 전남이가 이길 경우 +2점
            total_score += 2;
        }
        else
        {
            continue; // 지면 0점이므로 다음 i 실행
        }
    }
    return total_score; // 최종 점수 반환
}

int main()
{
    freopen("input.txt", "r", stdin);

    cin >> R; // 라운드 수 입력받기

    cin >> chonnam_SPR;

    cin >> N;

    friends_SPR = new string[N]; // 친구들이 각 라운드에 낸 모양 동적할당

    for (int i = 0; i < N; i++)
    { // 친구수만큼 입력받기
        cin >> friends_SPR[i];
    }

    int answer = 0; // 전남이와 친구들이 겨뤘을 때 실제 합
    for (int K = 0; K < N; K++)
    {
        answer += doingGame(K);
    }

    cout << answer << "\n";
    cout << BestScore() << "\n";
}