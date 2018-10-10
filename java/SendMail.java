
import java.io.DataInputStream;
import javax.mail.*;
import javax.mail.internet.*;
import javax.mail.Authenticator;
import javax.mail.PasswordAuthentication;
import java.util.Properties;

public class SendMail
{
	String SMTP_HOST_NAME = "blr-ec-mbx03.wipro.com";//"10.201.50.173";
	String SMTP_AUTH_USER = "";
	String SMTP_AUTH_PWD  = "";

	public static void main(String[] args) throws Exception
	{
		new SendMail().test();
	}
	public void test() throws Exception
	{
		Properties props = new Properties();
		props.put("mail.transport.protocol", "smtp");
		props.put("mail.smtp.host", SMTP_HOST_NAME);
		props.put("mail.smtp.auth", "true");
	
		String from = null;
		String to = null;
		String subject=null;
		String msgbody = null;
		DataInputStream dis = new DataInputStream(System.in);

		System.out.println("Using SMTP Server : blr-ec-mbx03.wipro.com");
		System.out.println("Enter Credentials:");
		System.out.print("User name:");
		SMTP_AUTH_USER = dis.readLine();
		System.out.print("Password:");
		SMTP_AUTH_PWD = dis.readLine();
		System.out.print("From:");
		from = dis.readLine();		
		System.out.print("To:");
		to = dis.readLine();
		System.out.print("Subject:");
		subject = dis.readLine();
		System.out.print("Message:");
		msgbody = dis.readLine();

		Authenticator auth = new SMTPAuthenticator();
		Session mailSession = Session.getDefaultInstance(props, auth);

		//uncomment for debugging infos to stdout
		mailSession.setDebug(true);

		Transport transport = mailSession.getTransport();
		MimeMessage message = new MimeMessage(mailSession);
		message.setSubject(subject);
		message.setContent(msgbody, "text/plain");
		message.setFrom(new InternetAddress(from));
		message.addRecipient(Message.RecipientType.TO, new InternetAddress(to));

		transport.connect();
		transport.sendMessage(message, message.getRecipients(Message.RecipientType.TO));
		transport.close();
	}
	private class SMTPAuthenticator extends javax.mail.Authenticator
	{
		public PasswordAuthentication getPasswordAuthentication()
		{
			String username = SMTP_AUTH_USER;
			String password = SMTP_AUTH_PWD;
			return new PasswordAuthentication(username, password);
		}
	}
}
