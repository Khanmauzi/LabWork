import java.io.*;
import java.lang.*;
class p
{
public static void main(String args[])
{
int i,j,k,cnt;
int a[][]=new int[5][3];
i=0;
j=0;
k=9;
cnt=0;
for(i=0;i<5;i++)
{
cnt=i+1;
a[i][0]=cnt;
cnt=cnt+k;
a[i][1]=cnt;
a[i][2]=cnt+10-k;
k=k-2;
}
System.out.println("pattern is ");
for(i=0;i<5;i++)
{
for(j=0;j<3;j++)
System.out.print(a[i][j]+" ");
System.out.println();
}

}}