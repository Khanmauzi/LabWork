public class p3 {
        public static void main(String args[])
        {
         char a[][]=new char [9][9];
         int i,j;
         int j1;
         char n='1';j=4;j1=4;
         for(i=0;i<4;i++)
         {
             a[i][j++]=n;
             a[i][j1--]=n;
             n++;
         }
      for(i=4;i<9;i++)
      {
         a[i][j--]=n;
         a[i][j1++]=n;
         n--;
      }
         for(i=0;i<9;i++)
         {
             System.out.println();
             {
                 for(j=0;j<9;j++)
                     System.out.print(a[i][j]+" ");
             }
         }
         System.out.println();
         
        }
    
}