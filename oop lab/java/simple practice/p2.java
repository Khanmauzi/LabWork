public class p2 {
    public static void main(String args[])
    {
        int i,j,k;
        char a[][]=new char[7][8];
        char ch;
        for(i=0;i<4;i++)
        {
            ch='A';
            for(j=0;j<4;j++)
            {
                if(j==0)
                {
                    a[i][j]=ch++;
                }
                else if(j<=i)
                {
                    a[i][j]=ch++;
                }
                else
                    a[i][j]=' ';
            }
        }
        int cnt=3;
        for(i=4;i<7;i++)
        {
            ch='A';
            for(j=0;j<4;j++)
                if(j<cnt)
                {
                  a[i][j]=ch++;  
                }
            else
                    a[i][j]=' ';
            cnt--;
        }
        cnt=4;
        for(i=0;i<4;i++)
        {
            k=0;
            ch='D';
            j=4;
            while(k<cnt)
            {
                k++;
                //j++;
                ch--;
                a[i][j++]=' ';
            }
            while(j<8)
            a[i][j++]=ch--;
            cnt--;
            }
        cnt=1;
          for(i=4;i<7;i++)
        {
            k=0;
            ch='D';
            j=4;
            while(k<cnt)
            {
                k++;
                //j++;
                ch--;
                a[i][j++]=' ';
            }
            while(j<8)
            a[i][j++]=ch--;
            cnt++;
            }
          a[3][4]='D';
          for(i=0;i<7;i++)
        {
            for(j=0;j<8;j++)
                System.out.print(a[i][j]+" ");
            System.out.println();
        
         }
    }
  
    
}