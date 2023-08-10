#include <iostream>
#include <string>
using namespace std;

double A[7], B[7];

int main() {
    A[6] = 0;
    B[6] = 0;
    for (int i = 5; i >= 0; i--) {
        // we will calculate following numbers such that
        // c * E[i] = A[i] * E[i - 1] + B[i]
        A[i] = 0;
        B[i] = 1; // we will throw a dice for sure
        double c = 1;
        // choose inplace, don't change it
        // then we go to E[i] again, so just decrease the coefficient on the left side
        c -= (i / 36.0);
        // choose inplace, change it
        // then we go to E[i - 1], so increase A[i] with the probability
        A[i] += (5 * i) / 36.0;
        // choose outplace, change it improperly
        // then we go to E[i] again, so just decrease the coefficient on the left side
        c -= (6 - i) * 5.0 / 36.0;
        // choose outplace, change it properly
        // then we go to E[i + 1], we already know how to calculate E[i + 1] from E[i],
        // so just adjust coefficient & the constant.
        c -= A[i + 1] * (6 - i) / 36.0;
        B[i] += B[i + 1] * (6 - i) / 36.0;

        A[i] /= c;
        B[i] /= c;
    }
    double result = A[1] * B[0] + B[1];
    cout << result << endl;
    return 0;
}
