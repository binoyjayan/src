
import java.io.*;

class arr
{
	public static void main(String arg[])
	{
		try
		{
			int i, j;
			outerloop: for(i=0;i<4;i++)
			{
				for(j=0;j<3;j++)
				{
					System.out.println("i = "+ i +" j = " + j);
					if(j==1)
						break outerloop;
				}
									
			}

			out:
			{
				System.out.println("Outer block");
				inn:
				{
					System.out.println("Inner block");
					if(true)
						break inn;
					System.out.println("This is not printed");
				}
				System.out.println("Outer 2");
			}
		}
		catch(Exception e)
		{
			System.out.println(e.toString());					
		}
	}
}

