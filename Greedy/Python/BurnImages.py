# ACCEPT
if __name__ == "__main__":
    n, W = map(int, input().split())
    images = list(map(int, input().split()))
    images.sort()
    count = 0
    # Greedy: Ưu tiên ghi các ảnh có kích thước nhỏ nhất trước
    for i in range(len(images)):
        if W >= images[i]:
            count += 1
            W -= images[i]
        else:
            break
    print(count)
