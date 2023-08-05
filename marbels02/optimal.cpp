#include <iostream>
using namespace std;

const int N = 1000;

// result[black][white] = optimal expected score if remaining counts are as given.
double result[N + 1][N + 1];

int main() {
    // if only black remains, then we can throw the dice everytime and be sure we will get a dollar
    for (int black = 0; black <= N; black++)
        result[black][0] = black;
    // if only white remains, we will lose a dollar if we throw the dice. So we quite with 0 dollars.
    for (int white = 0; white <= N; white++)
        result[0][white] = 0;
    for (int black = 1; black <= N; black++)
        for (int white = 1; white <= N; white++) {
            // expected optimal score if we throw the dice
            double s = ((result[black-1][white] + 1) * black + ((result[black][white - 1] - 1) * white)) / (black + white);
            // if the expected optimal score when throwing a dice is greater than 0, then we throw the dice,
            // otherwise we quite.
            result[black][white] = max(s, 0.0);
        }
    cout << result[N][N] << endl;
    return 0;
}
