import sys

input = sys.stdin.readline

def print_result(arr):
    print('[' + ','.join(map(str, arr)) + ']')

t = int(input())

for i in range(t):
    insStr = input().rstrip()
    n = int(input())
    arr = []
    if n > 0:
        arr = list(map(int, input().rstrip()[1: -1].split(',')))
    else:
        input()

    r = 0
    removeFromFront = 0
    removeFromEnd = 0
    for f in insStr:
        if f == 'R':
            r += 1
        else:
            if r % 2 == 0:
                removeFromFront += 1
            else:
                removeFromEnd += 1

    if removeFromFront + removeFromEnd > n:
        print('error')
    else:
        if removeFromEnd == 0:
            arr = arr[removeFromFront:]
        else:
            arr = arr[removeFromFront:-removeFromEnd]
        if r % 2 == 1:
            arr.reverse()
        print_result(arr)
