

class integralimage1 {


    static void show(int m[][], int r, int c){

        for(int i = 0; i < r;i++){

            for(int j = 0; j < c; j++){
                System.out.print(m[i][j] + " ");
            }
            System.out.println();
    
        }
    }

    static int calculate(int m[][], int r, int c){
        int s = 0;

        for(int i = 0; i <= r; i++){
            for(int j = 0; j <= c; j++){
                s += m[i][j];
            }
        }

        return s;

    }

    public static void main(String[] args) {
        
        int rows = 5;
        int cols = 5;

        // Original image
        int[][] originalImage = {{98, 101, 200, 122, 129},
                                {110, 134, 110, 116, 134},
                                {99, 130, 124, 118, 142},
                                {98, 120, 147, 108, 137},
                                {95, 111, 131, 126, 130}};
        
        // Integral Image
        int[][] integralImage = new int[rows][cols];
        System.out.println("\nOriginal Image: ");
        show(originalImage, rows, cols);
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                integralImage[i][j] = calculate(originalImage, i, j);
            }
        }
        System.out.println("\nIntegral Image: ");
        show(integralImage, rows, cols);


    }
}