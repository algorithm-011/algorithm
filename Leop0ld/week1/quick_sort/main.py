def quick_sort(data, start, end):
    if start >= end:
        # 종료 조건
        return None
    
    left = start
    right = end
    pivot = data[(start + end) // 2]

    while left <= right:
        while data[left] < pivot:
            # 피벗값보다 큰 값을 찾을떄까지 left 증가
            left += 1

        while data[right] > pivot:
            # 피벗값보다 작은 값을 찾을떄까지 right 감소
            right -= 1
    
        # left 와 right 가 교차되지 않았다면 교환시켜줌
        if left <= right:
            data[left], data[right] = data[right], data[left]
            left += 1
            right -= 1

    quick_sort(data, start, right)
    quick_sort(data, left, end)


if __name__ == '__main__':
    data_list = [20, 39, 1, 2, 19, 12, 29, 38, 27, 7,]
    quick_sort(data_list, 0, len(data_list) - 1)
    print(data_list)
