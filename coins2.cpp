#include <iostream>
using namespace std;

const int N = 4;
int c[N];

int bt(int idx, int rem) {
    if (idx == N) {
        if (rem)
            return 100;
        
        int a = 0;
        for (int i = 0; i < N; i++)
            a += i * c[i];
        int result = 0;
        for (int i = 0; i < N; i++) {
            int b = 0;
            for (int j = 0; j < c[i]; j++)
                if (j > i)
                    b += j - i;
            result = max(result, a + b);
        }
        return result;
    }
    int result = 100;
    for (int i = 0; i <= rem; i++)
    {
        c[idx] = i;
        result = min(result, bt(idx + 1, rem - i));
    }
    return result;
}

int main() {
    cout << bt(0, 10) << endl;
    return 0;
}