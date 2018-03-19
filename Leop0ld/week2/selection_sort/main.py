def selection_sort(data):
    for x in range(len(data)-1):
        min_index = x
        for y in range(x+1, len(data)):
            if data[y] < data[min_index]:
                min_index = y
            
        data[x], data[min_index] = data[min_index], data[x]



if __name__ == '__main__':
    data_list = [10, 12, 18, 28, 2, 7, 60, 29, 34, 50,]
    selection_sort(data_list)
    print(data_list)
