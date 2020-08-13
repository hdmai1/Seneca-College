/**********************************************
Workshop #9
Course:JAC444
Last Name: Mai
First Name: Huu Duc
ID: 121367189
Section: 
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date: August 09, 2020.
**********************************************/

package ws111;

import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ConnectException;
import java.net.Socket;
import java.util.NoSuchElementException;
import java.util.Scanner;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.border.EmptyBorder;

@SuppressWarnings("serial")
public class Client extends JFrame {
	
	private JTextArea msg = new JTextArea("Initializing, please wait! \n");
	private PrintWriter toServer;
	private JTextField cName = new JTextField();
	private JTextField cMsg = new JTextField();
	
	class incomingMsg implements Runnable {
		  private Socket socket;
	
		  public incomingMsg(Socket s) {
		   socket = s;
		   Thread thread = new Thread(this);
		   thread.start();
		  }
		  
		  public void run() {
			  try {
				  @SuppressWarnings("resource")
				  Scanner getText = new Scanner(socket.getInputStream());
				  while(true) {msg.append(getText.nextLine() + "\n");}
			  } catch (IOException e) {e.printStackTrace();}
			  catch (NoSuchElementException e) {System.out.println(e);}
		  }
	}

	
	
	 
 
	 public Client() throws ConnectException {
		 try {
			 Socket socket = new Socket("localhost", 8000); 
			 if (socket.isConnected()) 
				 msg.append("Connected succesfully, running on "+ socket + "\n");
			 toServer = new PrintWriter(socket.getOutputStream());
			 new incomingMsg(socket);
		 } catch (IOException e) {
			 msg.append("ERROR, Server is not running\n");
		 } 
		 
		 
		 
		 setLayout(new BorderLayout(5, 5));
		 JPanel mainPanel = new JPanel(new BorderLayout(5, 5));
		 mainPanel.setBorder(new EmptyBorder(5, 5, 5, 5));
		 msg.setEditable(false);
		 
		 JScrollPane pane = new JScrollPane(msg);
		 mainPanel.add(pane, BorderLayout.CENTER);
		 
		 JButton b = new JButton("Send");
		 b.setBounds(10,10,10,10);
		 
		 JPanel cNamePanel = new JPanel(new GridLayout(2, 1, 5, 5));
		 JPanel TextBox = new JPanel(new BorderLayout(10, 10));
		 TextBox.add(new JLabel("Name "), BorderLayout.WEST);     
		 TextBox.add(cName, BorderLayout.CENTER);
		 
		 JPanel cTextPanel = new JPanel(new BorderLayout(5, 5));
		 cTextPanel.add(new JLabel("Text "), BorderLayout.WEST);
		 cTextPanel.add(cMsg, BorderLayout.CENTER);
		 
		 cNamePanel.add(TextBox);
		 cNamePanel.add(b);
		 cNamePanel.add(cTextPanel);
		 
		 mainPanel.add(cNamePanel, BorderLayout.SOUTH);
		 add(mainPanel, BorderLayout.CENTER);
		 setVisible(true);
		 setSize(500, 400);
		 setTitle("Client");
		 setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		 setLocationRelativeTo(null);
		 
		 //event handler
		 
		 ActionListener sendMsg = new ActionListener() {

			 @Override
			 public void actionPerformed(ActionEvent e) {
				 
				 try {
					 if (!cMsg.getText().equals("") && !cName.getText().equals("") ) {
						 toServer.println(cName.getText() + ": " + cMsg.getText());
						 cMsg.setText("");
						 toServer.flush();
						 cMsg.requestFocus();
					 }
					 else {
						 JOptionPane.showMessageDialog(null, "Name and Text must not be blanked", "Warning", JOptionPane.WARNING_MESSAGE);
					 }
				 } catch (NullPointerException n) {JOptionPane.showMessageDialog(null, "Server is not running, client will exit"); System.exit(0);};
			 }
			 
		 };
		 b.addActionListener(sendMsg);
		 cMsg.addActionListener(sendMsg);
		  	
	 }
 

	 public static void main(String[] args) throws ConnectException{
		 new Client();
	 }
}
