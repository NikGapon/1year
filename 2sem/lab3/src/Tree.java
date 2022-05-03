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
    public void del(int value) {
        MainNode cur_d = root;
        MainNode back_d = root;
        chek = true;
        while (chek) {

            if (value == cur_d.get_this_Node()) { //сравниваю не это ли значение уже
                chek = false;

                if ((cur_d.get_left() == null) && (cur_d.get_right() == null)) { // легкий узел (конечный)
                    //System.out.println(cur_d.value);
                    //System.out.println(back_d.value);
                    if (back_d.get_left() == cur_d)

                        back_d.del_left();

                    if (back_d.get_right() == cur_d)

                        back_d.del_right();
                }
                else if (cur_d.get_left() == null){ // узел с права
                    if (back_d.get_left() == cur_d) {
                        back_d.del_left();
                        back_d.add_left(cur_d.get_right());

                    }
                    if (back_d.get_right() == cur_d){
                        back_d.del_right();
                        back_d.add_right(cur_d.get_right());

                    }
                }

                else if (cur_d.get_right() == null){ // узел с лев
                    if (back_d.get_left() == cur_d) {
                        back_d.del_left();
                        back_d.add_left(cur_d.get_left());

                    }
                    if (back_d.get_right() == cur_d){
                        back_d.del_right();
                        back_d.add_right(cur_d.get_left());

                    }
                }
                else { //два наследника
                    MainNode priem = cur_d.get_left();
                    MainNode priem_back = cur_d;
                    while (priem.get_right() != null){
                        priem_back = priem;
                        priem = priem.get_right();
                    } // доходим ->left ->->right до конца пра


                    //System.out.println(priem_back.value);
                    //System.out.println(priem.value);
                    if (priem_back != cur_d) {
                        priem_back.del_right();
                        priem_back.add_right(priem.get_left());
                    }
                    if (priem != cur_d.get_left()){
                        priem.add_left(cur_d.get_left());
                    }
                    if (priem != cur_d.get_right()){
                        priem.add_right(cur_d.get_right());
                    }



                    if (back_d.get_left() == cur_d) {
                        back_d.del_left();
                        back_d.add_left(priem);
                    }
                    if (back_d.get_right() == cur_d) {
                        back_d.del_right();
                        back_d.add_right(priem);
                    }



                }



            } else if (value < cur_d.get_this_Node()) { //смотрю слева (наименьшее)
                back_d = cur_d;
                cur_d = cur_d.get_left();

            } else if (value > cur_d.get_this_Node()) {
                back_d = cur_d;
                cur_d = cur_d.get_right();
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
                    if (temp.get_left() != null || temp.get_right() != null)
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



