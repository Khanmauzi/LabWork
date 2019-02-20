import java.util.*;
public class p5 {
   public static void main(String args[])
   {
        Scanner s=new Scanner(System.in);
        int x;
        System.out.println("enter the size of array");
        int n;
        n=s.nextInt();
        int a[]=new int[n];
        int i,min=9999,max=0;
        System.out.println("enter the elements ");
        for(i=0;i<n;i++)
            a[i]=s.nextInt();
        int j,k;
        j=0;k=0;
        for(i=0;i<n;i++)
        {
            if(a[i]>max)
            {
                max=a[i];
                j=i;
            }
            if(a[i]<min)
            {
                min=a[i];
                k=i;
            }
        }
        max=0;min=9999;
        for(i=0;i<n;i++)
        {
            if(a[i]>max&&i!=j)
                max=a[i];
            if(a[i]<min&&k!=i)
                min=a[i];
        }
    System.out.println("second max eleemnt is : "+max);
    System.out.println("second min element is : "+min);
   }
}