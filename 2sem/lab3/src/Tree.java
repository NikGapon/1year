import java.util.Stack;

public class Tree {
    MainNode root;
    boolean chek = false;
    public Tree() { // Пустое дерево
        root = null;
    }


    public void add(int value) {
        MainNode neww = new MainNode(value);
        // neww.setValue(value);

        if (root == null) {
            root = neww;
        } else {
            MainNode cur = root;
            MainNode back;
            chek = true;
            while (chek) {
                back = cur;
                if (value == cur.get_this_Node()) { //сравниваю не это ли значение уже
                    chek = false;

                } else if (value < cur.get_this_Node()) { //смотрю слева (наименьшее)
                    cur = cur.get_left();
                    if (cur == null) {
                        back.add_left(neww);
                        chek = false;

                    }
                } else if (value > cur.get_this_Node()) { //смотрю справа (наибольшее)
                        cur = cur.get_right();
                        if (cur == null) {
                            back.add_right(neww);
                            chek = false;
                        }
                    }
                }
            }

        }


    public void printTree() {
        Stack globalStack = new Stack();
        globalStack.push(root);
        int gaps = 32;
        boolean isRowEmpty = false;
        String separator = "-----------------------------------------------------------------";
        System.out.println(separator);
        while (isRowEmpty == false) {
            Stack localStack = new Stack();
            isRowEmpty = true;

            for (int j = 0; j < gaps; j++)
                System.out.print(' ');
            while (globalStack.isEmpty() == false) {
                MainNode temp = (MainNode) globalStack.pop();
                if (temp != null) {
                    System.out.print(temp.get_this_Node());
                    localStack.push(temp.get_left());
                    localStack.push(temp.get_right());
                    if (temp.get_left() != null ||
                            temp.get_right() != null)
                        isRowEmpty = false;
                }
                else {
                    System.out.print("__");
                    localStack.push(null);
                    localStack.push(null);
                }
                for (int j = 0; j < gaps * 2 - 2; j++)
                    System.out.print(' ');
            }
            System.out.println();
            gaps /= 2;
            while (localStack.isEmpty() == false)
                globalStack.push(localStack.pop());
        }
        System.out.println(separator);
    }

    }



