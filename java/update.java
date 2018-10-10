
import java.io.*;
import java.sql.*;

class updatedb
{
	public static void main(String arg[])
	{
		try
		{
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			Connection con;
			PreparedStatement st;
			con = DriverManager.getConnection("jdbc:odbc:stud", "", "");
			st = con.prepareStatement("update stud set grade='FAIL' where mark < ?;");
			st.setInt(1, 50);
			//st.executeQuery();
			st.executeUpdate();
			con.close();
			//System.out.println();
		}
		catch(Exception e)
		{
			System.out.println("...ERROR..." + e);
		}
	}
}