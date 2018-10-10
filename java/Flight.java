
import  java.io.*;
import java.sql.*;

class flight
{
	public static void disp(ResultSet r)
	{
		String str;
		try
		{
			while(r.next())
			{
				str = r.getString(1)+" "+ r.getString(2)+" "+r.getString(3)  + " " + r.getString(4) +
				 " " + r.getString(5)+" " + r.getInt(6)+" " + r.getInt(7)+" " + r.getInt(8) +
				 " " + r.getInt(9) + " " + r.getInt(10) + " " + r.getTime(11) + " " + r.getTime(12);
				System.out.println(str);
			}
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
	}
	public static void main(String arg[])
	{
		Connection con;
		Statement st;
		PreparedStatement pt;
		ResultSet r=null;
		String str="";
		
		int ch =0, n=0;
		try
		{
			DataInputStream dr = new DataInputStream(System.in);
			Class.forName("sun.jdbc.odbc.JdbcOdbcDriver");
			con=DriverManager.getConnection("jdbc:odbc:flight","","");
			st=con.createStatement();
			pt=con.prepareStatement("insert into flight values('?', '?', '?', '?', '?', ?, ?, ?, ?, ?, '?', '?');");			
			//System.out.println("Flight Details.");			
			//disp(r);
			while_loop:

			while(true)
			{
				System.out.println("\nOPTIONS\n---------");
				System.out.println("[0] EXIT");
				System.out.println("[1] INSERT");
				System.out.println("[2] DISPLAY");
				System.out.println("[3] DELETE");
				try
				{
					ch = Integer.parseInt(dr.readLine());
				}catch(Exception e){System.out.println("Enter valid no;");continue;}				
				switch(ch)
				{
				case 0:
					break while_loop;
				case 1:
					System.out.println("Enter flight no:");
					str = dr.readLine();
					pt.setString(1, str);
					System.out.println("Enter flight name:");
					str = dr.readLine();
					pt.setString(2, str);

					System.out.println("Enter source:");
					str = dr.readLine();
					pt.setString(3, str);

					System.out.println("Enter dest:");
					str = dr.readLine();
					pt.setString(4, str);

					System.out.println("Enter route:");
					str = dr.readLine();
					pt.setString(5, str);

					System.out.println("Enter no of seats:");
					try{
					n = Integer.parseInt(dr.readLine());
					}catch(Exception e){System.out.println("Invalid no");}
					pt.setInt(6, n);

					System.out.println("Enter no of economy seats:");
					try{
					n = Integer.parseInt(dr.readLine());
					}catch(Exception e){System.out.println("Invalid no");}
					pt.setInt(7, n);

					System.out.println("Enter no of ex-seats:");
					try{
					n = Integer.parseInt(dr.readLine());
					}catch(Exception e){System.out.println("Invalid no");}
					pt.setInt(8, n);


					System.out.println("Enter economy fare:");
					try{
					n = Integer.parseInt(dr.readLine());
					}catch(Exception e){System.out.println("Invalid no");}
					pt.setInt(9, n);

					System.out.println("Enter executive fare:");
					try{
					n = Integer.parseInt(dr.readLine());
					}catch(Exception e){System.out.println("Invalid no");}
					pt.setInt(10, n);


					System.out.println("Enter arrival date(hh:mm:ss):");
					try{
					n = Integer.parseInt(dr.readLine());
					}catch(Exception e){System.out.println("Invalid no");}
					pt.setString(11, str);


					System.out.println("Enter departure date(hh:mm:ss):");
					try{
					n = Integer.parseInt(dr.readLine());
					}catch(Exception e){System.out.println("Invalid no");}
					pt.setString(12, str);
					pt.executeQuery();
					break;
				case 2:
					r = st.executeQuery("select * from flight;");
					disp(r);
					break;
				case 3:
					System.out.println("Enter flight no.");
					str = dr.readLine();
					try{
					st.executeUpdate("delete from flight where fno='"+str+"';");
					System.out.println("Delete entry successfully...");
					}
					catch(SQLException e)
					{
						System.out.println("Error....!" + e);
					}					
					
					break;
				default:
					break;
				}
			}
			con.close();
		}
		catch(Exception e)
		{
			System.out.println(e);
		}		 
	}
}

