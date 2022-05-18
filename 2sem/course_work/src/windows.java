import javax.swing.*;
import java.awt.*;
import java.awt.event.*;


import java.util.ArrayList;


public class windows extends JFrame{

        ArrayList<Integer> main_list = new ArrayList<>();

        ArrayList<Integer> cash_left = new ArrayList<>();
        ArrayList<Integer> cash_mid = new ArrayList<>();
        ArrayList<Integer> cash_right = new ArrayList<>();
        Timer timer;
        //JFrame frame = new JFrame("binary search");
        String text_add = "";
        //String text_second = "";
        int cof = 5;

        int result_number_one;
        boolean Animation = false;
        int result_number_two;

        //JLabel second_laibel = new JLabel("");

        int Moment_left = 0;
        int Moment_mid = 0;
        int Moment_right = 0;

        int go_left = 0;
        int go_mid = 0;
        int go_right = 0;
        public windows(){
            super("binary search");
            start();
        }
        public void start() {
            Paint paint = new Paint();
            add(paint);
            setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            setSize(1000, 400);
            setLocationRelativeTo(null);




            JPanel panel = new JPanel(new FlowLayout(3));
            JTextField textField = new JTextField(20);

            JButton button_add = new JButton("add");
            JButton button_search = new JButton("search");
            //JButton button_remove = new JButton("remove");
            JLabel reuelt_laibel = new JLabel("");
            //JLabel main_laibel = new JLabel("");
            //main_laibel.setBounds(500, 200, 150, 50);
            //second_laibel.setBounds(500 - text_add.length() * 2, 210, 1000, 50);

            button_add.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    main_list.add(Integer.parseInt(textField.getText()));
                    text_add += Integer.parseInt(textField.getText());
                    text_add += "  ";

                    //main_laibel.setBounds(500 - text_add.length() * 2, 200, 1000, 50);
                    Animation = true;
                    //main_laibel.setText(text_add);

                    //System.out.println(main_list);

                }
            });
            button_search.addActionListener(new ActionListener() {
                @Override
                public void actionPerformed(ActionEvent e) {
                    int key = Integer.parseInt(textField.getText());

                    //second_laibel.setBounds(500 - text_add.length() * 2, 210, 1000, 50);

                    //second_laibel.setText(text_second);
                    binarySearch(key);
                    Animation = true;
                    reuelt_laibel.setText("Результат прошлого успешного поиска: " + result_number_one + "   На позиции: " + result_number_two);
                }
            });


            //JPanel TextPanel = new JPanel();


            panel.add(button_search);
            panel.add(button_add);
            //panel.add(button_remove);
            panel.add(textField);
            panel.add(reuelt_laibel);

            //getContentPane().add(BorderLayout.WEST, main_laibel);
            //frame.add(second_laibel);
            getContentPane().add(BorderLayout.NORTH,panel);


            setVisible(true);
        }

        void binarySearch(int key) {

            int low = 0;
            int high = main_list.size() - 1;


            while (low <= high) {

                int mid = (low + high) >>> 1;
                int midVal = main_list.get(mid);

                int x = text_add.indexOf(" " + main_list.get(low)) + 1;
                cash_left.add(200 + x * cof);

                x = text_add.indexOf(" " + main_list.get(high)) + 1;
                cash_right.add(200 + x * cof);

                if (midVal < key) {
                    low = mid + 1;
                } else if (midVal > key) {
                    high = mid - 1;
                } else {
                    result_number_two = mid;
                    result_number_one = main_list.get(mid);
                    x = text_add.indexOf(" " + main_list.get(mid)) + 1;
                    cash_mid.add(200 + x * cof);
                    break;
                    //return ;
                }
            }

        }

        public class Paint extends JComponent implements ActionListener {
            public Paint(){
                super();

                timer = new Timer(10, this);
                timer.start();
            }

            @Override
            public void actionPerformed(ActionEvent e){
                int x;
                if(Animation) {
                    if (Moment_left == go_left && Moment_left == go_mid && Moment_right == go_right) {
                        if (cash_left.size() > 0 || cash_mid.size() > 0 || cash_right.size() > 0) {

                            if (cash_left.size() > 0) {

                                x = cash_left.get(0);
                                //System.out.println(x);
                                Moment_left = 200;
                                cash_left.remove(0);
                                go_left = x;

                            }
                             if (cash_mid.size() > 0) {
                                Moment_mid = 500;
                                x = cash_mid.get(0);
                                cash_mid.remove(0);
                                go_mid = x;

                            }
                             if (cash_right.size() > 0) {
                                Moment_right = 900;
                                x = cash_right.get(0);
                                cash_right.remove(0);
                                go_right = x;

                            }
                        }
                        else {
                            Animation = false;
                        }
                    }
                }
                    //System.out.println("dadadada");
                    //System.out.println(Moment_left + "  " + go_left);
                    if (Moment_left > go_left) {
                        Moment_left -= 1;
                    }
                    else if (Moment_left < go_left) {

                        Moment_left += 1;
                    }
                    else if (Moment_right > go_right) {
                        Moment_right -= 1;
                    }
                    else if (Moment_right < go_right) {
                        Moment_right += 1;
                    }

                    else if (Moment_mid > go_mid) {
                        Moment_mid -= 1;
                    }
                    else if (Moment_mid < go_mid) {
                        Moment_mid += 1;
                    }




                    //Animation = false;
                    repaint();
                    timer.setDelay(10);

            }
            public void PaintElements(Graphics g2d){
                g2d.setColor(Color.BLUE);

                g2d.drawLine(Moment_left, 215, Moment_left - 50, 215);
                g2d.drawLine(Moment_left, 215, Moment_left - 50, 265);
                g2d.drawLine(Moment_left, 215, Moment_left, 265);



                g2d.setColor(Color.RED);

                g2d.drawLine(Moment_right, 200, Moment_right + 50, 200);
                g2d.drawLine(Moment_right, 200, Moment_right + 50, 150);
                g2d.drawLine(Moment_right, 200, Moment_right, 150);

                g2d.setColor(Color.BLACK);

                g2d.drawLine(Moment_mid, 200, Moment_mid + 25, 175);
                g2d.drawLine(Moment_mid, 200, Moment_mid - 25, 175);
                g2d.drawLine(Moment_mid, 200, Moment_mid, 200);


                g2d.setColor(Color.BLACK);
                g2d.drawString(text_add, 200, 210);
                //g2d.setColor(new Color(170, 255, 0));
                //g2d.fillRect(100, 100, 100, 100);
            }
            public void paintComponent(Graphics g){
                super.paintComponent(g);

                //System.out.println("dadadada");
                Graphics2D g2d = (Graphics2D) g;
                PaintElements(g2d);

            }
        }

        public static void main(String[] args) {
            windows start = new windows();
            //start.start();
            //start.pack();
            start.setVisible(true);


        }

}