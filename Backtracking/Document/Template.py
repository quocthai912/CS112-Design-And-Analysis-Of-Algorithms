# Template cho Backtracking (Quay Lui)
result = []
S = []


def invalid_state():
    pass


def is_solution():
    pass


def check(j):
    pass


# Không quan trọng thứ tự
# Lựa chọn j cho S[i] có thể là 1 số bất kì trong mảng nums
# Các bài sinh xâu nhị phân, sinh hoán vị,...
def backtracking(i, nums):
    if invalid_state():
        return
    if is_solution():
        solution = []
        for k in range(len(nums)):
            solution.append(S[k])
        result.append(solution)
    for j in range(len(nums)):
        if check(nums[j]):
            # Không thường các bài sinh xâu, sinh hoán vị là sẽ gán S[i] = nums[j]
            S.append(nums[j])
            backtracking(i + 1, nums)
            # Có thể trả trạng thái hoặc không, tùy bài
            S.pop()


# Có quan trọng thứ tự
# Sinh tập con, sinh chuỗi con đối xứng theo thứ tự, chuỗi cộng,...
def backtracking(start, nums):
    if invalid_state():
        return
    if is_solution():
        solution = []
        for k in range(len(nums)):
            solution.append(S[k])
        result.append(solution)
    for end in range(start, len(nums)):
        if check(nums[start : end + 1]):
            S.append(nums[start : end + 1])
            backtracking(end + 1, nums)
            S.pop()
