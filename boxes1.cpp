#include <iostream>
#include <string>
using namespace std;

double A[7], B[7];

int main() {
    A[6] = 0;
    B[6] = 0;
    for (int i = 5; i >= 0; i--) {
        A[i] = 0;
        B[i] = 1;
        double c = 1;
        // choose inplace, don't change it
        c -= (i / 36.0);
        // choose inplace, change it
        A[i] += (5 * i) / 36.0;
        // choose outplace, change it improperly
        c -= (6 - i) * 5.0 / 36.0;
        // choose outplace, change it properly
        c -= A[i + 1] * (6 - i) / 36.0;
        B[i] += B[i + 1] * (6 - i) / 36.0;

        A[i] /= c;
        B[i] /= c;
    }
    double result = A[1] * B[0] + B[1];
    cout << result << endl;
    return 0;
}
