# SOLUTION: Brute Force (Vét Cạn)
# Hàm dùng để kiểm tra nguyên âm
def kiem_tra_nguyen_am(c):
    """
    Hàm được dùng để kiểm tra một kí tự có phải là nguyên âm hay không
    Args:
       c (char): Kí tự c (s[i]) cần kiểm tra
    Returns:
       True nếu c là nguyên âm và False nếu c không phải là nguyên âm
    """
    return (
        c == "a" or c == "e" or c == "o" or c == "u" or c == "i" or c == "w" or c == "y"
    )


def consonant(s: str) -> str:
    """
    Hàm chính được dùng để giải quyết bài toán
    Args:
       s (str): Xâu kí tự s cần biến đổi
    Returns:
       result (str): Xâu kí tự đã được biến đổi sao cho đối tính phụ âm là lớn nhất
    """
    # Mảng lưu index của các phụ âm
    # index ở đây chính là vị trí xuất hiện đầu tiên của phụ âm trong xâu
    # index này được dùng để tính bit của phụ âm tại xâu đó
    index_phu_am = [-1] * 256
    index = 0
    for i in range(len(s)):
        if kiem_tra_nguyen_am(s[i]) == False and index_phu_am[ord(s[i])] == -1:
            index_phu_am[ord(s[i])] = index
            index += 1
    # Tổng số xâu có thể được sinh ra từ số lượng phụ âm
    total_masks = 2**index
    # Mảng hai chiều được dùng để lưu tần suất các cặp phụ âm liên tiếp nhau
    freq_tuple_phu_am = []
    for i in range(19):
        rows = []
        for j in range(19):
            rows.append(0)
        freq_tuple_phu_am.append(rows)
    # Tính tần suất các cặp phụ âm
    for i in range(len(s) - 1):
        if kiem_tra_nguyen_am(s[i]) == False and kiem_tra_nguyen_am(s[i + 1]) == False:
            u = index_phu_am[ord(s[i])]
            v = index_phu_am[ord(s[i + 1])]
            freq_tuple_phu_am[u][v] += 1
    # Vòng lặp chính duyệt mask
    # Lưu ý là mask chỉ chứa các bit 0, 1 tương ứng với các phụ âm
    # ví dụ "abc" có 2 phụ âm thì mask là 00, 01, 10, 11
    max_mask = 0
    max_doi_tinh_phu_am = -1
    for mask in range(total_masks):
        doi_tinh_phu_am = 0
        for i in range(19):
            for j in range(19):
                bit_ki_tu_thu_nhat = (mask >> i) & 1
                bit_ki_tu_thu_hai = (mask >> j) & 1
                # Nếu một kí tự là hoa, 1 kí tự là thường tại Mask đó
                if bit_ki_tu_thu_nhat != bit_ki_tu_thu_hai:
                    doi_tinh_phu_am += freq_tuple_phu_am[i][j]
        if doi_tinh_phu_am > max_doi_tinh_phu_am:
            max_doi_tinh_phu_am = doi_tinh_phu_am
            max_mask = mask
    # Tính chuỗi kết quả từ Mask có đối tính phụ âm lớn nhất
    result = list(s)
    for i in range(len(result)):
        if kiem_tra_nguyen_am(result[i]) == False:
            bit_ki_tu = (max_mask >> index_phu_am[ord(result[i])]) & 1
            if bit_ki_tu == 1:
                result[i] = result[i].upper()
    return "".join(result)


if __name__ == "__main__":
    s = input().strip()
    print(consonant(s))
