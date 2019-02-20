public class p4 {
    public static void main(String args[])
    {
        char a[][]=new char [6][12];
        char ch='*';
        int i,j1,j2,n1,n2;
        j1=0;j2=11;n1=0;n2=11;
        for(i=0;i<5;i++)
        {
            a[i][j1]=ch;
            a[i][j2]=ch;
            a[i][n1++]=ch;
            a[i][n2--]=ch;
        }
        for(j1=0;j1<12;j1++)
            a[i][j1]=ch;
        for(i=0;i<6;i++)
        {
            System.out.println();
            for(j1=0;j1<12;j1++)
                System.out.print(a[i][j1]+" ");
        }
        
           System.out.println();
    }
    
}