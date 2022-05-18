import java.util.*;

public class Main {
    public static void main(String[] args){
        Runtime memory = Runtime.getRuntime();
        memory.gc();
        Scanner scanner = new Scanner(System.in);
        int N[] = {scanner.nextInt(), scanner.nextInt()};

        //Стек
        System.out.println("Stack:");
        Stack stack = new Stack();
        for (int i = 0; i < N[0]; ++i){
            long starttime = System.currentTimeMillis();
            for (int j = 0; j < N[1]; ++j){
                stack.push((int)(Math.random() * 100));
            }
            long endtime = System.currentTimeMillis();
            int Memory = (int)(memory.totalMemory() - memory.freeMemory());
            System.out.println((endtime - starttime) + ">" + Memory);
            memory.gc();

            stack = new Stack();
        }

        //Очередь
        System.out.println("LinkedList:");
        Queue queue = new LinkedList();
        for (int i = 0; i < N[0]; ++i){
            long starttime = System.currentTimeMillis();
            for (int j = 0; j < N[1]; ++j){
                queue.add((int)(Math.random() * 100));
            }
            long endtime = System.currentTimeMillis();
            int Memory = (int)(memory.totalMemory() - memory.freeMemory());
            System.out.println((endtime - starttime) + ">" + Memory);
            memory.gc();

            queue = new LinkedList();
        }

        //Хэш таблица
        System.out.println("Hashtable:");
        Hashtable Ht = new Hashtable();
        for (int i = 0; i < N[0]; ++i){
            long starttime = System.currentTimeMillis();
            for (int j = 0; j < N[1]; ++j){
                Ht.put(j, (int)(Math.random() * 100));
            }
            long endtime = System.currentTimeMillis();
            int Memory = (int)(memory.totalMemory() - memory.freeMemory());
            System.out.println((endtime - starttime) + ">" + Memory);
            memory.gc();

            Ht = new Hashtable();
        }



        //Дек
        System.out.println("Dek:");
        Deque deque = new LinkedList();
        for (int i = 0; i < N[0]; ++i){
            long starttime = System.currentTimeMillis();
            for (int j = 0; j < N[1]; ++j){
                deque.addFirst((int)(Math.random() * 100));
            }
            long endtime = System.currentTimeMillis();
            int Memory = (int)(memory.totalMemory() - memory.freeMemory());
            System.out.println((endtime - starttime) + ">" + Memory);
            memory.gc();

            deque = new LinkedList();
        }



        //Массив
        System.out.println("ArrayList:");
        ArrayList arrayList = new ArrayList();
        for (int i = 0; i < N[0]; ++i){
            long starttime = System.currentTimeMillis();
            for (int j = 0; j < N[1]; ++j){
                arrayList.add((int)(Math.random() * 100));
            }
            long endtime = System.currentTimeMillis();
            int Memory = (int)(memory.totalMemory() - memory.freeMemory());
            System.out.println((endtime - starttime) + ">" + Memory);
            memory.gc();

            arrayList = new ArrayList();
        }
    }
}
