public class alg {

    public static void main(String[] args) {


        int n = 5;
        int [][] MatrixVeight = {{99,10,99,99,99},{99,99,12,99,8},{99,99,99,8,99},{99,6,8,99,3},{99,99,99,3,99}};
        int [][] MatrixHistory = {{0,2,0,0,0},
                {0,0,3,0,5},
                {0,0,0,4,0},
                {0,2,3,0,5},
                {0,0,0,4,0}};

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                System.out.printf("%3d", MatrixVeight[i][j]);
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                System.out.printf("%3d", MatrixHistory[i][j]);
            }
            System.out.println();
        }


        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (MatrixVeight[i][j] != 99){
                    for (int w = 0; w < n; w++){
                        if (MatrixVeight[i][w] > MatrixVeight[i][j] + MatrixVeight[j][w]) {
                            MatrixVeight[i][w] = MatrixVeight[i][j] + MatrixVeight[j][w];
                            MatrixHistory[i][w] = MatrixHistory[i][j];
                        }
                    }

                }


            }
        }
        System.out.println();
        System.out.println();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                System.out.printf("%3d", MatrixVeight[i][j]);
            }
            System.out.println();
        }

        System.out.println();
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                System.out.printf("%3d", MatrixHistory[i][j]);
            }
            System.out.println();
        }


    }
}