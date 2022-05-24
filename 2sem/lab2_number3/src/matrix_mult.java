public class matrix_mult {
    public static int[][] multiMatrix(int[][] firstMatrix, int[][] secondMatrix) {
        int[][] tempMatrix = new int[firstMatrix.length][firstMatrix.length];
        for (int i = 0; i < firstMatrix.length; i++) {
            for (int u = 0; u < secondMatrix[0].length; u++) {
                for (int j = 0; j < secondMatrix.length; j++) {
                    tempMatrix[i][u] += firstMatrix[i][j] * secondMatrix[j][u];
                }
            }
        }
        return tempMatrix;
    }
}