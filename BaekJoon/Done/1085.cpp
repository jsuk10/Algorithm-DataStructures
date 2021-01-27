#include <iostream>

using namespace std;

int  x, y, w, h, answer, answer1, answer2;

void process() {
    cin >> x >> y >> w >> h;

    cout << (((w - x) > x ? x : (w - x)) > ((h - y) > y ? y : (h - y)) ? ((h - y) > y ? y : (h - y)) : ((w - x) > x ? x : (w - x)));
}

int main()
{
    cin >> x >> y >> w >> h;
    cout << (((w - x) > x ? x : (w - x)) > ((h - y) > y ? y : (h - y)) ? ((h - y) > y ? y : (h - y)) : ((w - x) > x ? x : (w - x)));

}