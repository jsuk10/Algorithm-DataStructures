#include<iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double radius;

void Euclid(double r) {
    cout << (r * r * 3.141592653589793) << endl;
}

void Texi(double r) {
    cout << (2 * r * r * 1.0f) << endl;
}

int main() {
    cout << fixed;
    cout.precision(6);
    cin >> radius;
    Euclid(radius);
    Texi(radius);
}