
import  java.io.*;
import java.sql.*;

class DBTest
{
	public static void main(String arg[])
	{
		System.out.println("Hello World");
		Connection con;
		Statement st;
		ResultSet r;
		String ename;
		int eno, esal;
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			con=DriverManager.getConnection("jdbc:odbc:emp","","");
			st=con.createStatement();		
			r=st.executeQuery("select * from emp;");
			while(r.next())
			{
				System.out.println(r.getString(1)+"  "+r.getInt(2)+"  "+r.getInt(3));
			}
			con.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}		
	}
}
