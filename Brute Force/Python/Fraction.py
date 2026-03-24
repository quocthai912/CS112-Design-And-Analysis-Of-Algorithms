# SOLUTION: Brute Force (Vét Cạn)
import math
import sys


def Fraction(a, b, c, d):
    """
    Hàm chính được dùng để giải quyết bài toán
    Args:
       a, b, c, d (int): Hai phân số tối giản a / b và c / d
    Returns:
       count (int): Số bước biến đổi từ phân số thứ nhất ban đầu nhận được thành phân số thứ 2 đã cho
    """
    count = 0
    while a * d != b * c:
        a += 1
        b += 1
        gcd = math.gcd(a, b)
        a //= gcd
        b //= gcd
        if a * d > b * c:
            return 0
        count += 1
    return count


if __name__ == "__main__":
    data = sys.stdin.read().strip().split()
    a, b, c, d = map(int, data)
    print(Fraction(a, b, c, d))
