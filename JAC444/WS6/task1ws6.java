
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

import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.HBox;
import javafx.stage.Stage;
import java.io.*;
import java.util.Scanner;

public class task1ws6 extends Application{
	protected Pane pane = new Pane();
	final String str = "babynamesranking";
	
	
	@Override 
	public void start(Stage primaryStage) {
		// scene 1
		Scene scene1 = new Scene(pane, 359, 233);
		primaryStage.setTitle("Search Name Ranking Application"); 
		primaryStage.setScene(scene1);
		primaryStage.show();
		
		
	  
		// scene 2 
		
		
		Label Notify= new Label("");
		Label confirm = new Label("Do you want to find for another name?");
		Button Yes= new Button("Yes");
		Button No = new Button("No");
		Yes.setOnAction(e -> {
			primaryStage.setScene(scene1);
			pane.year.setText("");
			pane.Name.setText("");
			pane.Gender.setText("");
		});
		No.setOnAction(e -> Exit());
		
		FlowPane elements = new FlowPane(5, 15);
		elements.getChildren().add(Notify);
		elements.setPadding(new Insets(30, 30, 30, 30));
		
		FlowPane elements1= new FlowPane(5,15);
		elements1.getChildren().add(confirm);
		elements1.setPadding(new Insets(30, 30, 30, 30));
		
		HBox buttons = new HBox(5);
		buttons.getChildren().addAll(Yes, No);
		buttons.setAlignment(Pos.CENTER);
		
		BorderPane nPane = new BorderPane();
		nPane.setTop(elements);
		nPane.setCenter(elements1);
		nPane.setBottom(buttons);
		
		Scene scene2= new Scene(nPane,355,212);
		//finish scene 2
		
		//set actions for buttons
		pane.Submit.setOnAction(e -> {
			if (findRank() == 0) {
				Notify.setText("Can't find the name " + pane.Name.getText());
			}
			else {
				Notify.setText("Boy name "+ pane.Name.getText() + " is ranked #" +findRank() + " in " + pane.year.getText() + " year");
			}
			primaryStage.setScene(scene2);
		});
		pane.Exit.setOnAction(e -> Exit());
		
		
				
	}
	
	private int findRank() {
		File file=new File(str+pane.year.getText()+".txt");  
		try {
			Scanner file1 = new Scanner(file);
			String boy, girl;
			int rank;
			
			while (file1.hasNext()) {
					rank = file1.nextInt();
					boy = file1.next();
					file1.next();
					girl = file1.next();
					file1.next();
					if (pane.Gender.getText().equals("M")) {
						if (boy.equals(pane.Name.getText())) { 
							return rank;
						}
							
					}
					else if (pane.Gender.getText().equals("F")) {
						if (girl.contentEquals(pane.Name.getText())) {
							return rank;
						}
							
					}
					else 
						return 0;
			}
			file1.close();
		}catch (FileNotFoundException ex) {System.out.println(ex);};
		return 0;
	}
	private void Exit() {
		System.exit(0);
	}

}