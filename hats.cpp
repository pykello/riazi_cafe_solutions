#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int f[3][2][2];
int maxScore = 0;
int maxScoreCount = 0;

int score()
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        int a = (i & 1) ? 1 : 0;
        int b = (i & 2) ? 1 : 0;
        int c = (i & 4) ? 1 : 0;
        bool hasCorrect = (f[0][b][c] == a || f[1][a][c] == b || f[2][a][b] == c);
        bool hasIncorrect = (f[0][b][c] == (1 - a) || f[1][a][c] == (1 - b) || f[2][a][b] == (1 - c));
        if (hasCorrect && !hasIncorrect)
            result++;
    }
    return result;
}

string label(int a)
{
    return a == 0 ? "r" :
           a == 1 ? "b" :
           "p";
}

void print_startegy()
{
    for (int i = 0; i < 3; i++) {
        cout << i << ": ";
        for (int j = 0; j < 2; j++)
            for (int k = 0; k < 2; k++)
                cout << label(f[i][j][k]);
        cout << endl;
    }
    cout << endl;
}

void recurse(int p, int a, int b)
{
    if (p == 3)
    {
        int s = score();
        if (s > maxScore)
        {
            maxScore = s;
            maxScoreCount = 1;
        }
        else if (s == maxScore)
        {
            maxScoreCount++;
        }

        return;
    }
    if (b == 2)
    {
        recurse(p, a+1, 0);
        return;
    }
    if (a == 2)
    {
        recurse(p+1, 0, 0);
        return;
    }

    for (int i = 0; i < 3; i++)
    {
        f[p][a][b] = i;
        recurse(p, a, b+1);
    }
}

int main()
{
    recurse(0, 0, 0);
    cout << "maxScore: " << maxScore << ", # of strategies with maxScore: " << maxScoreCount << endl;
    return 0;
}
