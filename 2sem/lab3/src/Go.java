import java.util.Scanner;

public class Go {
    public static void main(String[] args) {
        Tree h = new Tree();
        //System.out.println(1);

        h.add(6);
        //System.out.println(2);
        h.add(4);
        //System.out.println(3);
        h.add(5);
        //System.out.println(4);
        h.add(7);
        //System.out.println(5);
        h.add(6);

        h.add(2);
        h.add(3);
        h.add(1);
        //System.out.println(6);
        // проверка на адекватное добавление
        Scanner myObj = new Scanner(System.in);
        int command = myObj.nextInt();
        while (command != 0){

            switch (command){
                case(1):
                    System.out.println("write the number to add");
                    command = myObj.nextInt();
                    h.add(command);

                    System.out.println("Complete");
                    break;
                case(2):
                    h.printTree();
                    System.out.println("Complete");
                    break;
                case(3):
                    System.out.println("write the number to del");
                    command = myObj.nextInt();
                    h.del(command);

                    System.out.println("Complete");
                    break;
            }
            command = myObj.nextInt();
        }
    }
}
