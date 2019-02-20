import java.util.Scanner;
public class p8 {
      public static void main(String args[])
   {
        Scanner s=new Scanner(System.in);
        int x;
        System.out.println("enter the size of array");
        int n;
        n=s.nextInt();
        int a[]=new int[n];
        int i,key;
        System.out.println("enter the elements ");
        for(i=0;i<n;i++)
            a[i]=s.nextInt();
        int j=0;
        for(i=1;i<n;i++)
        {
            key=a[i];
            j=i-1;
            while(j>=0&&a[j]>key)
            {
                a[j+1]=a[j];
                j=j-1;
            }
            a[j+1]=key;
                
        }
        for(i=0;i<n;i++)
        {
            System.out.print(a[i]+" ");
        }
   }
}