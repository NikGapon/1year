import java.util.*;

public class taibel2 {
    ArrayList<List> table = new ArrayList<List>();

    public void Create(int len) {
            for(int i = 0; i < len; i++){
                LinkedList<Integer> key_saver = new LinkedList<>();
                table.add(key_saver);
            }
    }

    public void append(int value){
        int key = value % table.size();

        if (key > table.size()) {
            /*int difference = key - table.size() + 1;*/
            taibel2 doll = new taibel2();
            doll.Create(key + 1);
            for(int i = 0; i < table.size(); i++){

                for(int j = 0; j < table.get(i).size(); i++){

                    List<Integer> o = table.get(i);
                    doll.append(o.get(j));
                }

            }
            table = doll.give_me_my_table();
            key = value % table.size();
        }
        table.get(key).add(value);
    }
    public void del(int del_item){
        int key = del_item % table.size();
        try {
            List<Integer> dsa = table.get(key);
            for(int i = 0; i< dsa.size(); i++){
                if (dsa.get(i) == del_item) {
                    table.get(key).remove(i);
                    break;
                }
            }

        }
        catch (NullPointerException e){

        }
    }
    public ArrayList<List> give_me_my_table(){
        return table;
    }
    public void print(){
        for(int i = 0; i < table.size(); i++){
            System.out.println(i + " => " + table.get(i));
        }
    }
}