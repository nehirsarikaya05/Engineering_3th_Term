def print_array(array):
    i = len(array)-1
    while (i >= 0):
        if (array[i] == 0):
            i = i - 1
        else:
            print(f"{i} indexed number is {array[i]}")
            i = i - 1
    print("\n")
def insert_array(array, index, num):
    i = len(array)-1
    while (i > index):
        array[i] = array[i-1]
        i = i - 1
    array[i] = num
def main():
    arr = [12, 9, 17, 6, 7, 0, 0]
    print_array(arr)
    insert_array(arr, 2, 13)
    print_array(arr)
main()
