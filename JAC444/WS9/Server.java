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
import java.awt.event.AdjustmentEvent;
import java.awt.event.AdjustmentListener;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.NoSuchElementException;
import java.util.Scanner;

import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;


@SuppressWarnings("serial")
public class Server extends JFrame {
 private JTextArea res = new JTextArea();
 private ArrayList<Client> clients = new ArrayList<>();
 
 public Server() {
  setLayout(new BorderLayout());
  res.append("MultiThreadServer Started at " + new Date() + "\n");
  res.setEditable(false);
  JScrollPane pane = new JScrollPane(res);
    
  add(pane, BorderLayout.CENTER);
  setTitle("Admin");
  setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
  setSize(700, 800);
  setVisible(true);
  setLocationRelativeTo(null);

  
  try {
	  @SuppressWarnings("resource")
	  ServerSocket serverSocket = new ServerSocket(8000);
	  while(true) {
		  Socket socket = serverSocket.accept();
		  Client newClient = new Client(socket);
		  clients.add(newClient);
	  }
  } catch (IOException e) {e.printStackTrace();}
 }
 
 class Client implements Runnable {
  private Socket socket;
  private PrintWriter toClient;
  
  public Client(Socket socket) {
   this.socket = socket;
   Thread thread = new Thread(this);
   thread.start();
  }
  
  public void run() {
   try {
    @SuppressWarnings("resource")
    Scanner fromClient = new Scanner(socket.getInputStream());
    toClient = new PrintWriter(socket.getOutputStream());
    res.append("Connection from  " + socket + " at " + new Date() + "\n");
    while(true) {
     String text = fromClient.nextLine();
     display(text, 's');
     for (Client newClient : clients) 
      newClient.display(text, 'c');
    }
   } catch (IOException e) {e.printStackTrace();} 
   catch (NoSuchElementException e) {};
  }
  
  public void display(String text, char c) {
   Calendar time = new GregorianCalendar();
   if (c == 'c') {
	   toClient.printf("%02d:%02d:%02d " + text + "\n", time.get(Calendar.HOUR_OF_DAY), time.get(Calendar.MINUTE), time.get(Calendar.SECOND));
   	   toClient.flush();
   }
   else if (c == 's') {
	   res.append(time.get(Calendar.HOUR_OF_DAY) +":"+time.get(Calendar.MINUTE) + ":" + time.get(Calendar.SECOND) +" " + text + "\n");
   }
  }
  
 }

 public static void main(String[] args) {
  new Server();
 }
}