# SOLUTION: Chặt Nhị Phân (Binary Search)
def trees_of_days(a, k, b, m, days) -> int:
    """
    Hàm được dùng để tính tổng số cây hai đội chặt được trong n ngày cho trước
    Args:
       a (int): Số cây đội I hạ được mỗi ngày
       k (int): Các ngày nghỉ của đội I (k, 2k, 3k,...)
       b (int): Số cây đội II hạ được mỗi ngày
       m (int): Các ngày nghỉ của đội II (m, 2m, 3m,...)
       days (int): Số ngày cho trước, hàm sẽ tính tổng số cây hai đội chặt được trong (days) ngày này
    Returns:
       trees_team_one + trees_team_two (int): Tổng số cây hai đội chặt được trong (days) ngày cho trước
    """
    trees_team_one = (days - (days // k)) * a
    trees_team_two = (days - (days // m)) * b
    return trees_team_one + trees_team_two


if __name__ == "__main__":
    a, k, b, m, n = map(int, input().split())
    left = 1
    right = n
    days = 1
    while left <= right:
        mid = (left + right) // 2
        trees = trees_of_days(a, k, b, m, mid)
        if trees >= n:
            days = mid
            right = mid - 1
        else:
            left = mid + 1
    print(days)
