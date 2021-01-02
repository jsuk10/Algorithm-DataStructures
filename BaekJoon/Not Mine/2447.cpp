#include <iostream>
using namespace std;


char** map;

void Process(int startX, int startY, int num) {
    if (num <= 1) {
        map[startY][startX] = '*';
        return;
    }
    else {
        int size = num / 3;
        int count = 0;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                if (count++ != 4)
                    Process(startX + i * size, startY + j * size, size);
    }
}
int main() {
    int num;
    cin >> num;

    map = new char* [num];
    for (int i = 0; i < num; ++i) {
        map[i] = new char[num];
    }

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j)
            map[i][j] = ' ';
    }

    Process(0,0,num);

    for (int i = 0; i < num; ++i) {
        for (int j = 0; j < num; ++j)
           cout << map[i][j];
        cout << "\n";
    }

}