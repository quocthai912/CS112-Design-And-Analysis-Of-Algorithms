# SOLUTION: Vét Cạn (Brute Force)
# Time Complexity: O(N^2)
# Space Complexity: O(N)
# ACCEPT
import math

if __name__ == "__main__":
    N, F0, D = map(int, input().split())
    nhiem_benh = []
    people = []
    for i in range(N):
        x, y = map(int, input().split())
        people.append((x, y))
        nhiem_benh.append(False)
    F0 -= 1
    count_F1 = 0
    count_F2 = 0
    # Duyệt tìm F1
    for i in range(N):
        if i != F0:
            if math.dist(people[i], people[F0]) < D:
                count_F1 += 1
                # Đánh dấu F1
                nhiem_benh[i] = True
    # Duyệt tìm F2
    for i in range(N):
        # Người [i] được xét phải thỏa:
        """
        - Không được là F0
        - Không được là F1
        - Chưa bị nhiễm bệnh
        """
        if i != F0 and nhiem_benh[i] == False:
            # Người [j] F1 bị xét phải thỏa:
            """
            - Là F1 và phải bị nhiễm bệnh từ F0
            - Không phải là F0 và không phải là chính người [i] đang xét
            """
            for j in range(N):
                if j != i and j != F0 and nhiem_benh[j] == True:
                    if math.dist(people[i], people[j]) < D:
                        count_F2 += 1
                        # Số lượng người F2 chỉ được tăng lên khi bị lây nhiễm bởi người F1 đầu tiên được xét
                        # Do một người F2 có thể ở gần nhiều người F1, dẫn tới số lượng bị sai, ta phải dừng vòng lặp ngay sau khi xét xong
                        # Ta không đánh dấu các người F2 bị nhiễm bệnh do:
                        """
                        - Nếu đánh dấu, đoạn code xét khoảng cách phía trên sẽ chạy, và nếu thỏa mãn khoảng cách < D thì người đó sẽ là F3 chứ không phải F2
                        - Ta không đánh dấu để tránh đếm nhầm những người F3
                        """
                        break
    print(f"{count_F1} {count_F2}")
