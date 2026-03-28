# Solution: Quay Lui (Backtracking)
# ACCEPT
S = []
Output = []


def Try(start: int, num: str):
    # Ghi nhận lời giải của bài toán
    if start == len(num):
        temp = []
        for i in range(len(S)):
            temp.append(S[i])
        Output.append(temp)
    for end in range(start, len(num)):
        # Lời giải đã hoàn thành
        if len(Output) > 0:
            return
        # Lời giải S chưa đủ thành phần S[i]
        # Nếu lời giải S chưa đủ thành phần S[i] và con trỏ đã đi tới cuối xâu, ta cắt bỏ nhánh đệ quy này
        if len(S) < 2 and end < len(num) - 1:
            # Thành phần S[i] được xem là không hợp lệ nếu chứa '0' ở đầu
            # VD: "012", "09",...
            if start != end and num[start] == "0":
                return
            # Ghi nhận lựa chọn j cho thành phần S[i]
            # Chấp nhận rủi ro lựa chọn j có thể không thỏa mãn chuỗi số cộng
            S.append(num[start : end + 1])
            # Chuyển sang trạng thái mới
            Try(end + 1, num)
            # Trả lại trạng thái cũ cho bài toán
            S.pop()
        elif len(S) >= 2:
            # Lựa chọn j thỏa mãn chuỗi số cộng
            if int(num[start : end + 1]) == int(S[len(S) - 1]) + int(S[len(S) - 2]):
                # Kiểm tra lựa chọn j có hợp lệ hay không
                if start != end and num[start] == "0":
                    return
                S.append(num[start : end + 1])
                Try(end + 1, num)
                S.pop()


def isAdditiveNumber(num: str) -> bool:
    Try(0, num)
    if len(Output) > 0:
        return True
    else:
        return False


if __name__ == "__main__":
    num = input()
    if isAdditiveNumber(num):
        print("true")
    else:
        print("false")
