public class start {
    public static void main(String[] args) {
        table_hash_line_prob h = new table_hash_line_prob();
        h.Create(10);
        h.append(10);
        h.append(5);
        h.append(50);
        h.append(40);

        h.append(1500);
        h.append(500);
        h.append(1501);
        h.append(1769);
        h.print();
        h.del(1501);
        h.print();

        /*h.Create(10);
        h.append(1);
        h.append(5);
        h.append(55);
        h.append(555);
        h.print();
        h.del(555);
        h.print();*/
    }
}
