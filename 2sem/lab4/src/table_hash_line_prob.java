import java.util.Hashtable;

public class table_hash_line_prob {
    int table[];

    public void Create(int len){
        table = new int[len];
    }

    public void append(int value){
        int key = value % table.length;


        if (key + 2 >= table.length){
            int upd_len[];
            int upd_len_len[];
            upd_len = new int[table.length + 1];
            System.arraycopy(table, 0, upd_len, 0, table.length);
            upd_len_len = new int[upd_len.length * 2];
            table = upd_len_len;
            for(int i = 0; i < upd_len.length; i++){
                if (upd_len[i] != 0){
                append(upd_len[i]);
                }
            }
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
    public void del(int del_item){
        int jj;
        int ii;
        ii =  del_item % table.length;
        jj = ii + 1 ;
        while ((table[jj] == 0) || (table[jj] % table.length != table[ii] % table.length)){
            if (table[jj] == 0){
                table[ii] = 0;
                return;
            }
            jj += 1;
        }
        table[ii] = table[jj];
        del(jj);
    }

    public void print(){
        for(int i = 0; i < table.length; i++){
            System.out.println(i + " => " + table[i]);
        }
    }
}
