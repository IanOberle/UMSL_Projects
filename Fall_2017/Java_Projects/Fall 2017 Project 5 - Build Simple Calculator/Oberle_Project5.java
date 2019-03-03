/*
 * Created by: Ian Oberle
 * Class: CS 2261
 * Completed On: 11/14/17
 * Resubmitted On: 11/18/17
 */

import javafx.application.Application;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import javafx.geometry.Insets;
import java.text.DecimalFormat;

public class Oberle_CS2261_Project5 extends Application { 
	public void start(Stage primaryStage) {

		 //Declaring and setting up Grid pane
		 GridPane gridpane = new GridPane();
		 gridpane.setVgap(4);
		 gridpane.setAlignment(Pos.CENTER);
		 gridpane.setPadding(new Insets(30));
		 
		 //Declaring Text Fields
		 TextField input1 = new TextField();
		 TextField input2 = new TextField();
		 TextField input3 = new TextField();
		 TextField result = new TextField();
		 result.setEditable(false);
		
		 //Setting Formatting Style for Text Fields
		 input1.setPrefColumnCount(15);
		 input1.setAlignment(Pos.CENTER_RIGHT);
		 input2.setPrefColumnCount(15);
		 input2.setAlignment(Pos.CENTER_RIGHT);
		 input3.setPrefColumnCount(15);
		 input3.setAlignment(Pos.CENTER_RIGHT);
		 result.setPrefColumnCount(15);
		 result.setAlignment(Pos.CENTER_RIGHT);
		
		 //Creating Labels for Text Fields
		 Label label1 = new Label("Money used in investment: ");
		 Label label2 = new Label("Years: ");
		 Label label3 = new Label("Annual Interest Rate: ");
		 Label label4 = new Label("Final financial worth: ");
		 
		 //Creating Button and Setting Button Orientation
		 Button calculate = new Button("Calculate");
		 calculate.setTranslateX(117);
		 
		 //Adding "Objects" to the Grid pane
		 gridpane.add(label1, 0, 0);
		 gridpane.add(input1, 1, 0);
		 gridpane.add(label2, 0, 1);
		 gridpane.add(input2, 1, 1);
		 gridpane.add(label3, 0, 2);
		 gridpane.add(input3, 1, 2);
		 gridpane.add(label4, 0, 3);
		 gridpane.add(result, 1, 3);
		 gridpane.add(calculate, 1, 4);
		 
		 //Setting Border pane
		 BorderPane borderPane = new BorderPane();
		 borderPane.setCenter(gridpane);
		
		 //Setting Scene
		 Scene scene = new Scene(borderPane, 400, 200);
		 primaryStage.setTitle("Financial Calculator");
		 primaryStage.setScene(scene);
		 primaryStage.show();
	 
		 //Setting Format for Output, Show Only Two Decimal Places
	 	 DecimalFormat df = new DecimalFormat ("#.00");
	 
	 	 //Performing calculation of value to be displayed when button is clicked/pressed
	 	 calculate.setOnAction(e -> { result.setText("$" + (df.format(Double.parseDouble(input1.getText()) *
	 	 Math.pow((1 + (Double.parseDouble(input3.getText()))/1200), (12*Double.parseDouble(input2.getText()))))) + "");});
 
 }

 public static void main(String[] args) {
	 //Launching Project
	 launch(args);
 }
} 

