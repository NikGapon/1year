import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;


public class windows extends JFrame{

        ArrayList<Integer> main_list = new ArrayList<>();

        ArrayList<String> cash = new ArrayList<>();


        JFrame frame = new JFrame("binary search");
        String text_add = "";
        String text_second = "";

        int result_number_one;
        int result_number_two;
        JLabel main_laibel = new JLabel("");
        JLabel second_laibel = new JLabel("");

        public void start() {

            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(1000, 400);
            frame.setLocationRelativeTo(null);


            JPanel panel = new JPanel(new FlowLayout(3));
            JTextField textField = new JTextField(20);

            JButton button_add = new JButton("add");
            JButton button_search = new JButton("search");
            //JButton button_remove = new JButton("remove");
            JLabel reuelt_laibel = new JLabel("");

            main_laibel.setBounds(500, 200, 150, 50);
            second_laibel.setBounds(500 - text_add.length() * 2, 210, 1000, 50);

            button_add.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    main_list.add(Integer.parseInt(textField.getText()));
                    text_add += Integer.parseInt(textField.getText());
                    text_add += "  ";

                    main_laibel.setBounds(500 - text_add.length() * 2, 200, 1000, 50);

                    main_laibel.setText(text_add);

                    System.out.println(main_list);

                }
            });
            button_search.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    int key = Integer.parseInt(textField.getText());

                    second_laibel.setBounds(500 - text_add.length() * 2, 210, 1000, 50);

                    second_laibel.setText(text_second);

                    binarySearch(key);

                    for(int i = 0; i == cash.size() - 1; i++){
                        second_laibel.setText(cash.get(i));
                        try {
                            Thread.sleep(3000);
                        } catch (InterruptedException a) {

                        }
                    }
                    reuelt_laibel.setText("Результат прошлого успешного поиска: " + result_number_one + "   На позиции: " + result_number_two);
                }
            });


            JPanel TextPanel = new JPanel();


            panel.add(button_search);
            panel.add(button_add);
            //panel.add(button_remove);
            panel.add(textField);
            panel.add(reuelt_laibel);

            frame.add(main_laibel);
            frame.add(second_laibel);
            frame.add(panel);


            frame.setVisible(true);
        }

        void binarySearch(int key) {

            int low = 0;
            int high = main_list.size() - 1;


            while (low <= high) {
                text_second = "";
                int mid = (low + high) >>> 1;
                int midVal = main_list.get(mid);

                int x = text_add.indexOf("" + main_list.get(low));
                System.out.println(x);
                for (int i = 0; i <= x; i++) {
                    text_second += " ";
                }
                text_second += "↑min";
                x = text_add.indexOf("" + main_list.get(mid));
                for (int i = 0; i <= x - 4; i++) {
                    text_second += " ";
                }
                text_second += "↑mid";
                x = text_add.indexOf("" + main_list.get(high));
                for (int i = 0; i <= x - 8; i++) {
                    text_second += " ";
                }
                text_second += "↑high";

                System.out.println(text_add);
                System.out.println(text_second);


                //second_laibel.setText(text_second);
                cash.add(text_second);
            /*SwingUtilities.updateComponentTreeUI(frame);
            frame.invalidate();
            frame.validate();
            frame.repaint();*/

                /*try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {

                }*/
                if (midVal < key) {
                    low = mid + 1;
                } else if (midVal > key) {
                    high = mid - 1;
                } else {
                    result_number_two = mid;
                    result_number_one = main_list.get(mid);
                    break;
                    //return ;
                }
            }
            //result_number_two = -1;
            //result_number_one = -1;
        }

        public static void main(String[] args) {
            windows start = new windows();
            start.start();
            start.setVisible(true);


        }

}