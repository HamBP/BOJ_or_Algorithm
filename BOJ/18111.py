import sys
input = sys.stdin.readline

def cal(grid, height, block):
    result = 0
    for row in grid:
        for column in row:
            cnt = height - column
            block -= cnt
            if cnt > 0:
                result += cnt
            else:
                result += (-cnt) * 2

    if block < 0:
        return 2000000000
    else:
        return result

def go():
    n, m, b = map(int, input().split())

    grid = list()

    for i in range(n):
        grid.append(list(map(int, input().split())))

    time = 2000000000
    height = 0
    for h in range(257):
        temp = cal(grid, h, b)
        if temp <= time:
            time = temp
            height = h

    print(time, height)

go()
