
/**********************************************
Workshop #6
Course: JAC444
Last Name: Mai
First Name: Huu Duc 
ID: 121367189
Section:
This assignment represents my own work in accordance with Seneca Academic Policy.
Signature
Date:July 16, 2020
**********************************************/
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.HBox;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.BorderPane;
import javafx.geometry.Insets;
import javafx.geometry.Pos;

public class Pane extends BorderPane {
	
	//textfields
	protected TextField year = new TextField();
	protected TextField Gender = new TextField(); 
	protected TextField Name = new TextField(); 
	
	private FlowPane elements = new FlowPane(5, 5);
	
	// Buttons
	protected Button Submit = new Button("Submit Query");
	protected Button Exit = new Button("Exit");
	protected HBox Buttons = new HBox(10);

	
	public Pane() {
		elements.setVgap(20);
		year.setPrefColumnCount(15);
		Gender.setPrefColumnCount(15);
		Name.setPrefColumnCount(15);
		
		elements.setPadding(new Insets(20, 20, 0, 20));
		elements.getChildren().addAll(new Label("Enter The Year:     "), year, new Label("Enter the Gender: "), Gender, new Label("Enter the Name:   "), Name, new Label());

		Buttons.getChildren().addAll(Submit, Exit);
		Buttons.setAlignment(Pos.CENTER);

		setCenter(elements);
		setBottom(Buttons);
	}
}