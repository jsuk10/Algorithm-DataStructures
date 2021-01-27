#include <iostream>
using namespace std;

int width, height, answer = 999;
string *board;

char whiteStartBoard[8][8] = {
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'}};

char blackStartBoard[8][8] = {
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
    {'B', 'W', 'B', 'W', 'B', 'W', 'B', 'W'},
    {'W', 'B', 'W', 'B', 'W', 'B', 'W', 'B'},
};

//높이 넓이를 받고 동적 할당으로 string생성
//높이,폭 -8까지 기준점을 하나 잡아서 전부 체크함
//체크값 비교해줘서 제일 적은 값 출력
//계산 횟수
//계산하는점 42*42, 계산 프로세스 8*8 흑과백 2
// 42*42*8*8*2 = 225,792

int White(int startHeight, int startWidth)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i + startHeight][j + startWidth] != whiteStartBoard[i][j])
                count++;
    return count;
}

int Black(int startHeight, int startWidth)
{
    int count = 0;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (board[i + startHeight][j + startWidth] != blackStartBoard[i][j])
                count++;
    return count;
}

//높이, 넓이 -8까지 체크함
void Process()
{
    int less, white, black;
    for (int i = 0; i <= height - 8; i++)
    {
        for (int j = 0; j <= width - 8; j++)
        {
            white = White(i, j);
            black = Black(i, j);
            less = (white > black) ? black : white;
            if (less < answer)
                answer = less;
        }
    }
    cout << answer;
}

int main()
{
    cin >> height >> width;
    board = new string[height];

    for (int i = 0; i < height; i++)
    {
        cin >> board[i];
    }

    Process();
}