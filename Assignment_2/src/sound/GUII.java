package sound;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.net.URL;

import javafx.application.Application;
import javafx.beans.value.ChangeListener;
import javafx.beans.value.ObservableValue;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.HPos;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.MenuButton;
import javafx.scene.control.MenuItem;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.control.Toggle;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.media.AudioClip;
import javafx.scene.text.Font;
import javafx.scene.text.Text;
import javafx.stage.Stage;
import sun.applet.Main;
import sun.audio.AudioPlayer;
import sun.audio.AudioStream;
public class GUII extends Application {
	
	InputStream in;
	AudioStream as ;
	
    public void start(Stage primaryStage) throws IOException {
	    
		GridPane pane = new GridPane();	
		pane.setAlignment(Pos.TOP_LEFT);
		pane.setHgap(10);
		pane.setVgap(10);
		pane.setPadding(new Insets(10, 10, 10, 10));
		
		Text txt1 = new Text("音調格式 : \"1\" -> C , \"2\" -> D , \"3\" -> E , \"4\" -> F , \"5\" -> G , \"6\" -> A , \"7\" -> B , \"-\" -> Rest");
		pane.add(txt1, 0, 0,2,1);
		
		Text txt4 = new Text("節拍格式 :  \"(\"  number  \")\"");
		pane.add(txt4, 0, 1);
		
		Text txt2 = new Text("建造音樂 :");
		
		
	
		
		TextArea tf = new TextArea();
		tf.setStyle("-fx-font: 20 arial;");
		tf.setPrefSize(25,150);
		pane.add(tf, 0, 3,1,1);
		
		Button btAdd = new Button("Create");
		btAdd.setPrefSize(100, 20);
		Button btAdd1 = new Button("Clear");
		btAdd1.setPrefSize(100, 20);
		
		
		
		
		HBox hbox = new HBox();
		hbox.getChildren().add(btAdd);
		hbox.getChildren().add(btAdd1);
		hbox.setSpacing(30);
		
		
		 VBox vbox5 = new VBox();
		 vbox5.getChildren().add(txt2);
		 vbox5.getChildren().add(hbox);
		 vbox5.setSpacing(10);
		 pane.add(vbox5, 0, 2);
		 
	
		
		Text txt3 = new Text("範例音檔 :");
		
		MenuButton btAdd2 = new MenuButton("請選擇");
		btAdd2.setPrefSize(100,20);
		MenuItem item1 = new MenuItem("小蜜蜂"); 
		MenuItem item2 = new MenuItem("小星星"); 
		MenuItem item3 = new MenuItem("王老先生有塊地");
		btAdd2.getItems().add(item1);
		btAdd2.getItems().add(item2);
		btAdd2.getItems().add(item3);

		HBox hbox1 = new HBox();
        hbox1.getChildren().add(txt3);
		hbox1.getChildren().add(btAdd2);
		hbox1.setSpacing(50);
		
		Text txt5 = new Text("變聲效果 :");
		pane.add(txt5, 1, 3);
		
		VBox vbox1 = new VBox();
		vbox1.getChildren().add(hbox1);
	    vbox1.getChildren().add(txt5);
	    vbox1.setSpacing(10);
		pane.add(vbox1,1,2);
		 
		final ToggleGroup group = new ToggleGroup();
		RadioButton rb1 = new RadioButton("100   ");
		rb1.setToggleGroup(group);
		rb1.setUserData("100");
		   
		RadioButton rb2 = new RadioButton("500   ");
		rb2.setToggleGroup(group);
		rb2.setUserData("500");

		RadioButton rb3 = new RadioButton("800   ");
		rb3.setToggleGroup(group);
		rb3.setUserData("800");
		
		RadioButton rb4 = new RadioButton("Normal");
		
		rb4.setToggleGroup(group);
		rb4.setUserData("0");
	
		
		group.selectedToggleProperty().addListener(
				new ChangeListener<Toggle>(){
					@Override public void changed(ObservableValue<? extends Toggle> observable, Toggle oldvaule,Toggle new_toggle) { 
		    				if (group.getSelectedToggle() != null) {
		    					
		    					   String h = group.getSelectedToggle().getUserData().toString();
		    	   		           RFile.ca(h);
		   
		    					}
		    				}
					});
		    
		    
		 HBox hbox2 = new HBox();
		 hbox2.getChildren().add(rb4);
		 hbox2.setSpacing(50);
		 
		 
		 HBox hbox6 = new HBox();
		 hbox6.getChildren().add(rb1);
		 hbox6.getChildren().add(rb2);
		 hbox6.getChildren().add(rb3);
		 hbox6.setSpacing(50);
		 
		 
		 
		 
		
		 
		 
		 VBox vbox4 = new VBox();
		 vbox4.getChildren().add(rb4);
		 vbox4.getChildren().add(hbox6);
		 vbox4.setSpacing(10);
		 
		 
		 Button btAdd6 = new Button("Create");
		 btAdd6.setPrefSize(250, 40);
		 
		 Button btAdd3 = new Button("Play");
		 btAdd3.setPrefSize(120, 40);
		 
		 Button btAdd4 = new Button("Stop");
		 btAdd4.setPrefSize(120, 40);
		 
		 
		 HBox hbox7 = new HBox();
		 hbox7.getChildren().add(btAdd3);
		 hbox7.getChildren().add(btAdd4);
		 hbox7.setSpacing(10);
		 
		 
		 VBox vbox3 = new VBox();
		 vbox3.getChildren().add(vbox4);
		 vbox3.getChildren().add(btAdd6);
		 vbox3.getChildren().add(hbox7);
		 vbox3.setSpacing(10);
		 
		 
		 pane.add(vbox3,1,3);
		 
		

		btAdd.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
            	String a = tf.getText();
            	FileWriter fw;
				try {
					AudioPlayer.player.stop(as);
					fw = new FileWriter("src/sound/test.txt");
					fw.write(a);
					fw.close();
					String[] args = null;
					RFile.main(args);	
				} 
				
				catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
            }
        	
        });
		
		btAdd6.setOnAction(new EventHandler<ActionEvent>() {
            @Override public void handle(ActionEvent e) {
            	String a = tf.getText();
            	FileWriter fw;
				try {
					AudioPlayer.player.stop(as);
					fw = new FileWriter("src/sound/test.txt");
					fw.write(a);
					fw.close();
					String[] args = null;
					RFile.main(args);	
				} 
				
				catch (IOException e1) {
					// TODO Auto-generated catch block
					e1.printStackTrace();
				}
            }
        	
        });
		
		
		btAdd1.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				// TODO Auto-generated method stub
				tf.clear();
			}   	
        });
		
		
		item1.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				// TODO Auto-generated method stub
				String t = item1.getText();
				tf.setText("5 3 3(2) - 4 2 2(2) - 1 2 3 4 5 5 5 - 5 3 3(2) - 4 2 2(2) - 1 3 5 5 3(2) -2 2 2 2 2 3 4(2) - 3 3 3 3 3 4 5(2) - 5 3 3(2) - 4 2 2(2) - 1 3 5 5 1(2) -");
				tf.setWrapText(true);
				btAdd2.setText(t);

			}
		});
		
		item2.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				// TODO Auto-generated method stub
				String t = item2.getText();
				tf.setText("1 1 5 5 6 6 5(2) - 4 4 3 3 2 2 1(2) - 5 5 4 4 3 3 2(2) - 5 5 4 4 3 3 2(2) - 1 1 5 5 6 6 5(2) - 4 4 3 3 2 2 1(3) - ");
				tf.setWrapText(true);
				btAdd2.setText(t);
					
			}
		});
		
		item3.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				// TODO Auto-generated method stub
				String t = item3.getText();
				tf.setText("5 5 5 2 3 3 2(2) - 7 7 6 6 5(2) - 5 5 5 2 3 3 2(2) - 7 7 6 6 5(2) - 2 2 5 5 5 - 2 2 5 5 5 -  5 5 5 - 5 5 5 - 5 5 5 5 5 5 5 - 5 5 5 2 3 3 2(2) - 7 7 6 6 5(3) - ");
				tf.setWrapText(true);
				btAdd2.setText(t);
			}
		});

		
	  
		
		btAdd3.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			
			public void handle(ActionEvent event) {
				AudioPlayer.player.stop(as);
				try {
					in = new FileInputStream("src/sound/audio.wav");
					as = new AudioStream(in);
					AudioPlayer.player.start(as);
					
				} catch (FileNotFoundException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
				
			}
        });
		
		
		btAdd4.setOnAction(new EventHandler<ActionEvent>() {
			@Override
			public void handle(ActionEvent event) {
				
					AudioPlayer.player.stop(as);
			}	
        });
		
		
		
		
		
		GridPane.setHalignment(btAdd, HPos.LEFT);
		Scene scene = new Scene(pane);
		primaryStage.setTitle("ShowGridPane");
		primaryStage.setScene(scene); 
		primaryStage.show(); // Display the stage
		
}



/**
* The main method is only needed for the IDE with limi
ted
* JavaFX support. Not needed for running from the comm
and line.
*/
public static void main(String[] args) {
launch(args);
}
}


