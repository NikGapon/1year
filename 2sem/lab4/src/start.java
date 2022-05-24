import java.util.ArrayList;
import java.util.List;

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

        System.out.println("____________________________________");
        taibel2 g = new taibel2();
        g.Create(10);
        g.append(10);
        g.append(5);
        g.append(50);
        g.append(40);

        g.append(1500);
        g.append(500);
        g.append(1501);
        g.append(1769);
        g.print();
        g.del(1501);
        g.print();
    }
}
