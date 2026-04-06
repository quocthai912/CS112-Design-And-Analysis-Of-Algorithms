# ACCEPT
if __name__ == "__main__":
    n, m = map(int, input().split())
    gifts = list(map(int, input().split()))
    gifts.sort()
    minDistance = float("inf")
    end = m - 1
    for i in range(len(gifts)):
        # Duyệt qua các cửa sổ có kích thước m món quà
        if gifts[end] - gifts[i] < minDistance:
            minDistance = gifts[end] - gifts[i]
        end += 1
        if end > len(gifts) - 1:
            break
    print(minDistance)
