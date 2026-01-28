import java.util.Scanner;
class Matrix {
   int rows, cols;
   int[][] data;
   Matrix(int r, int c) { rows = r; cols = c; data = new int[r][c]; }
   void read(Scanner sc) {
      for (int i = 0; i < rows; i++)
         for (int j = 0; j < cols; j++)
            data[i][j] = sc.nextInt();
   }
   Matrix add(Matrix second) {
      Matrix res = new Matrix(rows, cols);
      for (int i = 0; i < rows; i++)
         for (int j = 0; j < cols; j++)
            res.data[i][j] = this.data[i][j] + second.data[i][j];
      return res;
   }
   void print() {
      for (int i = 0; i < rows; i++) {
         for (int j = 0; j < cols; j++)
            System.out.print(data[i][j] + " ");
         System.out.println();
      }
   }
}
class MatAddDrive {
   public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      System.out.println("enter number of rows:");
      int r = sc.nextInt();
      System.out.println("enter number of columns:");
      int c = sc.nextInt();
      Matrix a = new Matrix(r, c);
      Matrix b = new Matrix(r, c);
      System.out.println("enter elements in matrix a:");
      a.read(sc);
      System.out.println("enter elements in matrix b:");
      b.read(sc);
      Matrix sum = a.add(b);
      System.out.println("the result matrix:");
      sum.print();
      sc.close();
   }
}
