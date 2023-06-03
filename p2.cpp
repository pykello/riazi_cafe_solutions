#include <iostream>
#include <string>
using namespace std;

int main() {
    /*
     * max_photos[n] = Maximum photos with a binary family tree of n nodes.
     *
     * We only consider binary trees because a non-binary tree can be transformed to a
     * binary tree of same or smaller size while max number of photos stay the same.
     */
    int max_photos[100];
    max_photos[0] = max_photos[1] = max_photos[2] = 0;
    for (int n = 3; n < 100; n++)
    {
        max_photos[n] = 0;
        for (int left = 0; left <= n - 1; left++) {
            int right = n - 1 - left;
            /*
             * Root of tree can't be in a photo, since it doesn't have a father or brother.
             *
             * photos_this_level = number of photos in which left child or right child of
             * root in father role.
             * 
             * So max number of photos with "left" children in left subtree, and "right"
             * children in right subtree will be photos_this_level + max_photos[left] +
             * max_photos[right].
             *
             * If both subtrees have size >= 2 (that means both left & right child will have
             * a child), we can take create 2 photos in which children of root are in "father"
             * role:
             *   * (father=left child, son=one of children of left child, uncle=right child)
             *   * (father=right child, son=one of children of right child, uncle=left child)
             * 
             * Similarly if one has size >=2 & other size == 1, then we can create one photo
             * using left or right child as father.
             *
             * Otherwise, there's no one to take the uncle role, so we will have 0 photos with
             * left or right child as father.
             */
            int photos_this_level = (left >= 2 && right >= 2) ? 2 :
                                    ((left >= 2 && right == 1) || (right >= 2 && left == 1)) ? 1 :
                                    0;

            max_photos[n] = max(max_photos[n],
                                max_photos[left] + max_photos[right] + photos_this_level);
        }

        if (max_photos[n] >= 10) {
            // exclude the root, as it doesn't appear in any photos
            cout << n - 1 << endl;
            break;
        }
    }
    return 0;
}
