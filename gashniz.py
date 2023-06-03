import random

def simulate():
    # start with 13 cards in each suit
    arr = [0] * 13 + [1] * 13 + [2] * 13 + [3] * 13
    remaining = [13, 13, 13, 13]
    for i in range(52):
        # choose a random card and remove it
        next = random.choice(arr)
        arr.remove(next)
        remaining[next] -= 1
        # if first suit (gashniz) is empty, then return number of steps it took
        if remaining[0] == 0:
            return i + 1
    print("not reachable")
    return -1

# simulate N times & take average
N = 200000
sum = 0
for i in range(N):
    sum += simulate()
print(sum / N)
