/**********************************************
Workshop #10
Course: JAC444 - Summer 2020
Last Name: Mai
First Name: Huu Duc
ID: 121367189
Section: NAA
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date: 10/08/2020
**********************************************/

public class T1_time implements Cloneable, Comparable<T1_time> {
   private long eTime;
   
   public T1_time() {}

   
   public T1_time(int h, int m, int s) {
	   eTime = (((h*60)+m)*60)+s;
	   
   }

   public T1_time(long e) {
	   eTime = e;
   }

   public int getHour() {
       return (int) ((eTime/60)/60);
   }

   public int getMinute() {
       return (int) (eTime-(getHour()*60*60)) / 60;
   }

   public int getSecond() {
	   return (int) (eTime-(getHour()*60*60)-(getMinute()*60));
   }
  
   public long getSeconds(){
       return  eTime;
   }

   
   
   @Override
   public int compareTo(T1_time obj) {
       return (int) (this.eTime - obj.eTime);
   }
  
   public T1_time clone(){
       T1_time nTime = new T1_time(eTime);
       return nTime;
   }
  
   
   public String toString() {
	   return String.format("%d hours %d minutes %d seconds", this.getHour()%24, this.getMinute(), this.getSecond());
   }
}