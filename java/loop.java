
import java.io.*;

class Arr
{
	public static void main(String arg[])
	{
		try
		{
			int i;
			int a[] = new int[10];
			
			for(i=0;i<a.length;i++)
			{
				a[i] = i;
			}
			for(i=0;i<a.length;i++)
			{
				System.out.println("a[" + i + "] = " + a[i]);
			}
		}
		catch(Exception e)
		{
			System.out.println(e.toString());					
		}
	}
}
