#include <iostream>
using namespace std;

const int N = 1000;
double result[N + 1][N + 1];

double solve(int target) {
    for (int b = 0; b <= N; b++)
        for (int w = 0; w <= N; w++) {
            // we have used "1000 - b" black marbles & "1000 - w" white marbles so far,
            // so our current score is "(1000 - b) - (1000 - w) = w - b"
            int current_score = w - b;
            if (current_score > target) {
                // unreachable by this strategy
                result[b][w] = -1;
            } else if (current_score == target) {
                result[b][w] = current_score;
            } else {
                // throw a dice if any marbles are remaining
                result[b][w] = 0;
                if (b > 0) {
                    result[b][w] += (b * result[b-1][w]) / (b + w);
                }
                if (w > 0) {
                    result[b][w] += (w * result[b][w-1]) / (b + w);
                }
            }
        }
    return result[N][N];
}

int main() {
    for (int i = 0; i < 30; i++)
        cout << i << ": " << solve(i) << endl;
    return 0;
}

