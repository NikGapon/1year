import java.awt.geom.NoninvertibleTransformException;

public class MainNode {
    int value;
    MainNode left;
    MainNode right;

    MainNode(int value){
        this.value = value;
        left = null;
        right = null;
    }

    public void setValue(final int value) {
        this.value = value;
    } // на всякий случай для замены оставил

    public void add_right(final MainNode path){
        this.right = path;
    }
    public void add_left(final MainNode path){
        this.left = path;
    }
    public int get_this_Node() {
        return value;
    }

    public MainNode get_right(){
        return this.right;
    }
    public MainNode get_left(){
        return this.left;
    }


}
