# Chebyshev Distance
# TIME LIMIT EXCEEDED
def solution(drones):
    drones.sort(key=lambda x: x[2])
    second = 0
    for i in range(n):
        if second == drones[i][2]:
            print(-1)
            return
        second += 1
    for j in range(n):
        print(drones[j][1], end=" ")


if __name__ == "__main__":
    n = int(input())
    drones = []
    for i in range(n):
        x, y = map(int, input().split())
        drones.append([(x, y), i + 1, max(abs(x), abs(y))])
    solution(drones)
