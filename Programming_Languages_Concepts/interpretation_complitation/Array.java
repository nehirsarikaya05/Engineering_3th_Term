
public class Array{

    public static void print_array(int[] arr, int size) {
        int i = size - 1;

        while (i >= 0) {
            if (arr[i] != 0) {
                System.out.println(i + " indexed number is " + arr[i]);
            }
            i--;
        }
        System.out.println();
    }

    public static void insert_array(int[] arr, int ind, int num, int size) {
        int i;

        for (i = size - 1; i > ind; i--) {
            arr[i] = arr[i - 1];
        }

        arr[i] = num;
    }

    public static void main(String[] args) {
        int[] arr = {12, 9, 17, 6, 7, 0, 0};

        print_array(arr, 7);
        insert_array(arr, 2, 13, 7);
        print_array(arr, 7);
    }
}
