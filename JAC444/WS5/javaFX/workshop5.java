/**********************************************
Workshop #5
Course: JAC444
Last Name: Mai
First Name: Huu Duc 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:June 7, 2020
**********************************************/
package javaFX;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import java.io.*;

public class workshop5 extends Application {
	
	protected Pane pane = new Pane();
	final String str = "Books.txt";
	final int NAME = 32; 
	final int LNAME = 32; 
	final int CITY = 20; 
	final int PROV = 2; 
	final int PCODE = 6; 
	final int sum = NAME+LNAME+CITY+PROV+PCODE;
	protected int address = 0;

	@Override 
	public void start(Stage primaryStage) {
		// scene
		Scene scene = new Scene(pane, 463, 300);
		primaryStage.setTitle("Address Book"); 
		primaryStage.setScene(scene);
		primaryStage.show();
		//set actions for buttons
		pane.Add.setOnAction(e -> add());
		pane.First.setOnAction(e -> first());
		pane.Next.setOnAction(e -> next());
		pane.Prev.setOnAction(e -> previous());
		pane.Last.setOnAction(e -> last());
		pane.Update.setOnAction(e -> update());
				
	}
	private void clear() {
		pane.fName.setText("");
	 	pane.lName.setText("");
	 	pane.City.setText("");
	 	pane.pCode.setText("");
	}
	private boolean check(Pane pane) {
		return (pane.fName.getText().isEmpty() || pane.lName.getText().isEmpty() || pane.City.getText().isEmpty() || pane.Prov.getValue().toString().isEmpty() || pane.pCode.getText().isEmpty());
	}
	private void add() {
		try ( RandomAccessFile raf = new RandomAccessFile(str, "rw");) {
			raf.seek(raf.length());
			export(raf);
		 	clear();
		 	
		}
		catch (FileNotFoundException ex) {pane.curpage.setText("Cannot find the file "+ str);}
		catch (NullPointerException ex) { pane.curpage.setText("Invalid information, all fields must be filled.");}
		catch (IOException ex) {pane.curpage.setText("Something is wrong, contact dev for more information");}
	}
	private void first() {
		try ( RandomAccessFile raf = new RandomAccessFile(str, "r");) {
			if (raf.length() > 0) {
				raf.seek(0);
				display(raf);
				address = 1;
				pane.curpage.setText("Current profile: "+address);
				
			}
			else {
				pane.curpage.setText("No address available in address book");
			}
		}
		catch (IOException ex) {pane.curpage.setText("Something is wrong, contact dev for more information");}
	}
	private void next() {
		try (RandomAccessFile raf = new RandomAccessFile(str, "r");) {
			if (raf.length() <= 0) {
				pane.curpage.setText("No address available in address book");
			}
			else {
				if (address * sum < raf.length()) {
					raf.seek(address * sum);
					display(raf);
					address++;
					pane.curpage.setText("Current profile: "+address);
				}
				else {
					pane.curpage.setText("This is last record in the address book");
				}
			}
		}
		catch (IOException ex) {pane.curpage.setText("Something is wrong, contact dev for more information");}
	}
	private void previous() {
		try ( RandomAccessFile raf = new RandomAccessFile(str, "r");) {
			if (raf.length() <= 0) {
				pane.curpage.setText("No address available in address book");
			}
			else {
				if (address > 1) 
					address--;
				else 
					address = 1;
				raf.seek((address * sum) - sum);
				display(raf);
				pane.curpage.setText("Current profile: "+address);
			}
		}
		catch (IOException ex) {pane.curpage.setText("Something is wrong, contact dev for more information");}
	}
	private void last() {
		try ( RandomAccessFile raf = new RandomAccessFile(str, "r");) {
			if (raf.length() <= 0) {
				pane.curpage.setText("No address available in address book");
			}
			else {
				address = ((int)raf.length()) / sum;
				raf.seek((address * sum) - sum);
				display(raf);
				pane.curpage.setText("Current profile: "+address);
			}
		}
		catch (IOException ex) {pane.curpage.setText("Something is wrong, contact dev for more information");}
	}	
	private void update() {
		
		try ( RandomAccessFile raf = new RandomAccessFile(str, "rw");) {
			if (raf.length() <= 0) {
				pane.curpage.setText("No address available in address book, please add at least one address!");
			}
			else{
				raf.seek(address * sum - sum);
				export(raf);
				pane.curpage.setText("Record #"+ address + " updated!");
				clear();
			}
		}
		catch (NullPointerException ex) { pane.curpage.setText("Invalid information, all fields must be filled.");}
		catch (FileNotFoundException ex) {pane.curpage.setText("Cannot find the file "+ str);}
		catch (IOException ex) {pane.curpage.setText("Something is wrong, contact dev for more information");}
	}
	private void display(RandomAccessFile raf) throws IOException {
		
		byte[] fname = new byte[NAME];	
		int pos = raf.read(fname);
		pane.fName.setText(new String(fname));

		byte[] lname = new byte[LNAME];	
		pos += raf.read(lname);
		pane.lName.setText(new String(lname));

		byte[] city = new byte[CITY];	
		pos += raf.read(city);
		pane.City.setText(new String(city));

		byte[] prov = new byte[PROV];	
		pos += raf.read(prov);
		pane.Prov.setValue(new String(prov));

		byte[] pcode = new byte[PCODE];	
		pos += raf.read(pcode);
		pane.pCode.setText(new String(pcode));
	}
	private void export(RandomAccessFile raf) throws IOException {
		if (!check(pane)) {
			raf.write(toBytesArray(pane.fName.getText().getBytes(), NAME)); 
			raf.write(toBytesArray(pane.lName.getText().getBytes(), LNAME));
			raf.write(toBytesArray(pane.City.getText().getBytes(), CITY));
			raf.write(toBytesArray(pane.Prov.getValue().toString().getBytes(), PROV));
			raf.write(toBytesArray(pane.pCode.getText().getBytes(), PCODE));
			pane.curpage.setText(pane.fName.getText() + " " + pane.lName.getText() + " added!");
		}
		else {
			pane.curpage.setText("Invalid information, all fields must be filled.");
		}
	}
	private byte[] toBytesArray(byte[] x, int n) {
		byte[] a = new byte[n];
		for (int i = 0; i < x.length; i++) {
			a[i] = x[i];
		}
		return a;
	}
}