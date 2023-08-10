#include <iostream>
#include <cstdlib>
using namespace std;

int sim() {
    int x[6];
    for (int i = 0; i < 6; i++) x[i] = 0;
    for (int i = 0; i < 1000000000; i++) {
        bool f = true;
        for (int i = 0; i < 6; i++)
            f = f && (x[i] == i);
        if (f)
            return i;
        x[rand() % 6] = rand() % 6;
    }
    return 1000000000;
}

int main() {
    int N = 10000;
    double sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (i % 50 == 0) cout << i << endl;
        sum += sim();
    }
    cout << sum / N << endl;
    return 0;
}
