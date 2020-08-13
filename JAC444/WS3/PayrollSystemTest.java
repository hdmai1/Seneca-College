/**********************************************
Workshop 3
Course: JAC444 - Semester
Last Name: MAI
First Name: HUU DUC 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date: June 16, 2020
**********************************************/
public class PayrollSystemTest {
	public static void main(String[] args) {
		System.out.println("----------------Part 1-----------------");
		SalariedEmployee salEmp = new SalariedEmployee("John", "Smith", "111-11-1111", 800.00);
		CommissionEmployee comEmp = new CommissionEmployee("Duc", "Mai","121-367-189", 100,0.8);
		HourlyEmployee HourEmp = new HourlyEmployee("Duck", "Mike", "981-763-121", 12, 160);
		BasePlusCommissionEmployee BaseEmp = new BasePlusCommissionEmployee("kcuD", "Ekim","999-99-9999", 6.1,0.9, -2);
		
		
		System.out.println("---------------------------------------");
		System.out.println("Employees processed individually:\n");
		System.out.printf("%s\n%s: $%,.2f\n\n", salEmp, "Earned", salEmp.getPaymentAmount());
		System.out.printf("%s\n%s: $%,.2f\n\n", comEmp, "Earned", comEmp.getPaymentAmount());
		System.out.printf("%s\n%s: $%,.2f\n\n", HourEmp, "Earned", HourEmp.getPaymentAmount());
		System.out.printf("%s\n%s: $%,.2f\n\n", BaseEmp, "Earned", BaseEmp.getPaymentAmount());
		System.out.println("---------------------------------------");


		System.out.println("----------------Part 2-----------------");
		Employee[] emps = {salEmp, comEmp, HourEmp, BaseEmp};			
		
		for (int i = 0; i < emps.length ; i++) {
			if (emps[i] instanceof BasePlusCommissionEmployee) {
				BasePlusCommissionEmployee newEmp = (BasePlusCommissionEmployee)emps[i];
				System.out.println(newEmp);
				System.out.printf("Current Period, employees will get 10%% adding to their base salaries: $%,.2f\n",newEmp.getBS()*0.1);
				newEmp.setBS(newEmp.getBS()*0.1 + newEmp.getBS());
				System.out.printf("Earned $%,.2f\n\n", newEmp.getPaymentAmount());
			}
			else{
				System.out.println(emps[i]);
				System.out.printf("Earned $%,.2f\n\n", emps[i].getPaymentAmount());
			}
		}
		System.out.println("---------------------------------------");

		System.out.println("----------------Part 3-----------------");
		for (int i = 0; i < emps.length; i++)
			System.out.printf("(Object) Employee %d is an instance of %s\n", i+1, emps[i].getClass()); 
		System.out.println("---------------------------------------");
	}
}
