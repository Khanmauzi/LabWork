import java.util.*;
public class p7 {
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
        int j;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    int temp;
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
                
        }
        for(i=0;i<n;i++)
            System.out.print(a[i]+" ");
   }
   
}
