

public class convolution1 {

    
    static void show(int m[][], int r, int c){
        for(int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                System.out.print(m[i][j] + " ");
            }
            System.out.println();
        }
    }
    static int calculate(int[][] paddedImage, int[][] kernel, int kernelSize, int r, int c){
        int s = 0;
        int rows = 0;
        int cols = 0;
        for(int i = r; i < r + kernelSize; i++){

            for(int j = c; j < c + kernelSize; j++){
                s += paddedImage[i][j] * kernel[rows][cols];
                cols++;
            }
            rows++;
            cols = 0;
        }
        return s;
    }

    public static void main(String[] args) {
        
        // Original Image.

        int n = 4;
        int[][] originalImage = {{1, 2, 3, 0},
                                {0, 1, 2, 3},
                                {3, 0, 1, 2},
                                {2, 3, 0, 1}};

        System.out.println("\nOriginal Image: ");
        show(originalImage, n, n);

        // We should apply padding.
        int paddedSize = n + 2;
        int[][] paddedImage = new int[paddedSize][paddedSize];
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                paddedImage[i][j] = originalImage[i - 1][j - 1];

            }
        }
        System.out.println("\nPadded Image: ");
        show(paddedImage, n + 2, n + 2);

        // Take a window.
        int kernelSize = 3;
        int[][] kernel = {{2, 0, 1},
                        {0, 1, 2},
                        {1, 0, 2}};
        
        System.out.println("\nKernel : ");
        show(kernel, kernelSize, kernelSize);

        int[][] superImposedImage = new int[n][n];

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                
                superImposedImage[i][j] = calculate(paddedImage, kernel, kernelSize, i, j);

            }
        }

        System.out.println("\nSuperImposed Image: ");
        show(superImposedImage, n, n);


    }
    
}
