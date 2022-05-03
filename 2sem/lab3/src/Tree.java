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

    }



