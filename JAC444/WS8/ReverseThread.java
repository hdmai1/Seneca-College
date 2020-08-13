/**********************************************
Workshop #8
Course: JAC444
Last Name: Mai
First Name: Huu Duc 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:August 2, 2020
**********************************************/
public class ReverseThread extends Thread {
	int counter;
	
    private ReverseThread(int ctr) {	
    	counter = ctr;    	
    }

    private void display() throws Exception {
    	counter++;
    	ReverseThread a = new ReverseThread(counter);
    	a.start();
    	a.join();
    	System.out.println("Hello from Thread " + (counter-1));
		
    }
    
    @Override
    public void run() {	
    	try {
    		if(counter < 51) 
    			display();
    	} 
    	catch(Exception e) {
    		System.out.println(e);
    	}
    }
    
    public static void main(String[] args) throws Exception {
    	ReverseThread newThread = new ReverseThread(1);
		newThread.start();
	}
}
 