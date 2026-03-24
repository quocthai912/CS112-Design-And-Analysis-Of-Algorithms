# SOLUTION: Brute Force (Vét Cạn)
import math


def Canarium(k):
    """
    Hàm chính được sử dụng để giải quyết bài toán
    Args:
       k (int): Số hạt trám thu thập được
    Returns:
       m, n (int): Cặp nghiệm của bài toán
    """
    N = 4 * k - 1
    start = int(math.sqrt(N))
    if start % 2 == 0:
        start -= 1
    for i in range(start, 2, -2):
        if N % i == 0:
            a = i
            b = N // i
            m = (a - 1) // 2
            n = (b - 1) // 2
            return m, n
    return -1, -1


if __name__ == "__main__":
    t = int(input())
    test_case = []
    for i in range(t):
        k = int(input())
        test_case.append(k)
    for j in range(len(test_case)):
        m, n = Canarium(test_case[j])
        print(m, n, sep=" ")
