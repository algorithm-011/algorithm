def bubble_sort(data):
    length = len(data)

    for i in range(length - 1): # 맨 마지막 인덱스 고정되는 부분
        for j in range(length - 1 - i):
            if data[j] > data[j+1]:
                data[j], data[j+1] = data[j+1], data[j]


if __name__ == '__main__':
    data_list = [10, 12, 18, 28, 2, 7, 60, 29, 34, 50,]
    bubble_sort(data_list)
    print(data_list)
