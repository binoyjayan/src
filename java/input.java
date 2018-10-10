
import java.io.*;

class Inp
{
	public static void main(String arg[])
	{
		try
		{
			int x;
			DataInputStream d = new DataInputStream(System.in);
			String s1 = d.readLine();
			String s2 = d.readLine();
			x = Integer.parseInt(s1) + Integer.parseInt(s2);
			System.out.println("Sum = " + x);
			System.out.println(s1 + s2);
		}
		catch(Exception e)
		{
			System.out.println(e.toString());					
		}
	}
}
