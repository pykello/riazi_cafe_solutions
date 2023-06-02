#include <iostream>
#include <string>
using namespace std;

int main() {
    int max_photos[20];
    max_photos[0] = max_photos[1] = max_photos[2] = 0;
    for (int n = 3; n < 20; n++)
    {
        max_photos[n] = 0;
        for (int left = 0; left <= n - 1; left++) {
            int right = n - 1 - left;
            int photos_this_level = (left >= 2 && right >= 2) ? 2 :
                                    ((left >= 2 && right >= 1) || (right >= 2 && left >= 1)) ? 1 :
                                    0;
            max_photos[n] = max(max_photos[n],
                                max_photos[left] + max_photos[right] + photos_this_level);
        }

        // exclude the root, as it doesn't appear in any photos
        cout << n - 1 << " " << max_photos[n] << endl;
    }
    return 0;
}
