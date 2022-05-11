import java.util.Hashtable;

public class table_hash_line_prob {
    int table[];

    public void Create(int len){
        table = new int[len];
    }

    public void append(int value){
        int key = value % table.length;


        if (key >= table.length / 1.5){
            int upd_len[];
            upd_len = new int[table.length * 2];
            System.arraycopy(table, 0, upd_len, 0, table.length);
            table = upd_len;
        }


        boolean good = true;
        while (good){
            if (table[key] == 0){
                table[key] = value;
                good = false;
            }
            else{
                key += 1;
            }
        }
    }

    public void print(){
        for(int i = 0; i < table.length; i++){
            System.out.println(i + " => " + table[i]);
        }
    }
}
