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
import javafx.scene.control.Button;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.BorderPane;
import javafx.collections.FXCollections;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

public class Pane extends BorderPane {
	String st[] = {"ON", "QC", "NS", "NB", "MB", "BC", "PE", "SK", "AB", "NL"};
	
	//textfields
	protected TextField fName = new TextField();
	protected TextField lName = new TextField(); 
	protected TextField City = new TextField(); 
	protected ChoiceBox<String> Prov = new ChoiceBox<String>(FXCollections.observableArrayList(st));
	protected TextField pCode = new TextField(); 
	private FlowPane elements = new FlowPane(5, 5);
	
	protected Label curpage = new Label();
	// Buttons
	protected Button Add = new Button("Add");
	protected Button First = new Button("First");
	protected Button Next = new Button("Next");
	protected Button Prev = new Button("Previous");
	protected Button Last = new Button("Last");
	protected Button Update = new Button("Update");
	protected HBox Buttons = new HBox(10);

	
	public Pane() {
		elements.setVgap(20);
		fName.setPrefColumnCount(35);
		lName.setPrefColumnCount(35);
		City.setPrefColumnCount(6);
		pCode.setPrefColumnCount(5);
		
		elements.setPadding(new Insets(20, 20, 0, 20));
		elements.getChildren().addAll(new Label("First Name: "), fName, new Label("Last Name: "), lName, new Label("City: "), City, new Label("Province: "), Prov, new Label("Postal Code: "), pCode, new Label(), curpage);


		Buttons.getChildren().addAll(Add, First, Next, Prev, Last, Update);
		Buttons.setAlignment(Pos.BASELINE_CENTER);

		setCenter(elements);
		setBottom(Buttons);
	}
}