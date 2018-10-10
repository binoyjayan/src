
class str
{
	public static void main(String arg[])
	{
		String s = arg[0];
		
		int i;

		char ch;

		/*
		for(i=0;i<s.length();i++)
		{
			ch = s.charAt(i);
			System.out.println(ch);
		}
		if(s.equals("Hello"))
		{
			System.out.println("U entered Hello!!");
		}
		if(s.equalsIgnoreCase("Hai"))
		{
			System.out.println("U entered Hai!");
		}
		*/

		//i = s.indexOf('e');
		//System.out.println("Index of e is " + i);

		//i = s.lastIndexOf('e');
		//System.out.println("Last Index of e is " + i);

		System.out.println("substr = " + s.substring(2));
		System.out.println("substr = " + s.substring(2, 4));
		

		System.out.println("substr = " + s.replace('a', 'e'));
		

		String str = "    Hai   ";

		System.out.println(str.trim());

		System.out.println(str.toLowerCase());
		System.out.println(str.toUpperCase());

		
	}
}