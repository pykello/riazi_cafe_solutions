#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;

const int N = 2000;

int score(bool *arr, int target) {
    int current = 0;
    for (int i = 0; i < N; i++) {
        if (current == target)
            return target;
        if (arr[i])
            current++;
        else
            current--;
    }
    return current;
}

double simulate(int target) {
    int C = 1000000;
    bool arr[N];
    for (int i = 0; i < N; i++)
        arr[i] = i % 2;
    double total = 0;
    for (int i = 0; i < C; i++) {
        random_shuffle(arr, arr + N);
        total += score(arr, target);
    }
    return total / C;
}

int main() {
    srand(time(0));
    for (int i = 22; i < 24; i++)
        cout << i << ": " << simulate(i) << endl;
    return 0;
}

