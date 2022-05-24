import java.util.List;

public class binar_search {
    public int binarySearch(List<Integer> main_list, int key) {

        int low = 0;
        int high = main_list.size() - 1;


        while (low <= high) {

            int mid = (low + high) >>> 1;
            int midVal = main_list.get(mid);


            if (midVal < key) {
                low = mid + 1;
            } else if (midVal > key) {
                high = mid - 1;
            } else {
                return mid; // key found
            }

        }
        return -1;

    }
}