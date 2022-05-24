import java.util.ArrayList;
import java.util.List;

public class main {
    public static void main(String[] args) {
        Runtime memory = Runtime.getRuntime();
        memory.gc();
        long starttime = System.currentTimeMillis();
        ArrayList<Integer> g = new ArrayList<Integer>();
        g.add(1);
        g.add(3);
        g.add(10);
        g.add(111);
        g.add(1000);
        binar_search h = new binar_search();
        System.out.println(h.binarySearch(g, 3));

        long endtime = System.currentTimeMillis();
        int Memory = (int) (memory.totalMemory() - memory.freeMemory());
        System.out.println("Time:" + (endtime - starttime) + "> Memory:" + Memory);
        memory.gc();

        memory = Runtime.getRuntime();
        memory.gc();
        starttime = System.currentTimeMillis();

        alg j = new alg();
        j.go_Go();


        endtime = System.currentTimeMillis();
        Memory = (int) (memory.totalMemory() - memory.freeMemory());
        System.out.println("Time:" + (endtime - starttime) + "> Memory:" + Memory);
        memory.gc();


        memory = Runtime.getRuntime();
        memory.gc();
        starttime = System.currentTimeMillis();
        int[][] firstMatrix = {
                {5, 6, 4, 3},
                {5, 6, 4, 3},
                {5, 6, 4, 3}
        };
        int[][] secondMatrix = {
                {5, 6, 4},
                {5, 6, 4},
                {5, 6, 4},
                {5, 6, 4}
        };

        matrix_mult y = new matrix_mult();
        int[][] gg = y.multiMatrix(firstMatrix, secondMatrix);
        for (int i = 0; i < gg.length; i++) {
            for (int e = 0; e < gg[i].length; e++) {
                System.out.print(gg[i][e] + " ");
            }
            System.out.println();
        }
            endtime = System.currentTimeMillis();
            Memory = (int) (memory.totalMemory() - memory.freeMemory());
            System.out.println("Time:" + (endtime - starttime) + "> Memory:" + Memory);
            memory.gc();
        }

}

