import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.text.Collator;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.LinkedList;
import java.util.List;
import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import javafx.stage.FileChooser;
import javafx.stage.Modality;
import javafx.stage.Stage;



//Lab 3 #7--------------------------
public class VowelCounter extends Application {

	@Override
	public void start(Stage primaryStage) throws Exception {
		Stage window = new Stage();
		Button importBtn = new Button("Import File");
		importBtn.setPrefSize(100, 20);
		Button backBtn = new Button("Back");
		TextArea textArea = new TextArea();
		textArea.setEditable(false);
		textArea.setMaxSize(265, 450);
		//		textArea.setPadding(new Insets(12,15,12,15));

		//---------------Import Code---------------------

		//		Path writePath = Paths.get("C:\\EclipseFX\\TinveyRevised\\src\\Imported.csv");

		importBtn.setOnAction(new EventHandler<ActionEvent>(){
			@Override
			public void handle(ActionEvent e) {
				FileChooser fileChooser = new FileChooser();
				fileChooser.setTitle("Open Resource File");
				File file = fileChooser.showOpenDialog(window);
				if(file!=null){
					Path path = Paths.get(file.toURI());
					Charset charset = Charset.forName("US-ASCII");
					List<String> lines = new ArrayList<String>();
					try (BufferedReader reader = Files.newBufferedReader(path, charset)) {
						lines = Files.readAllLines(path, charset);
					} catch (IOException x) {
						return;
					}

					String userText = lines.get(0);
					LinkedList<String> textList = new LinkedList<String>();

					for (String s: userText.split(" ")){
							textList.add(s);

					}

					int aCounter = 0;
					int eCounter = 0;
					int iCounter = 0;
					int oCounter = 0;
					int uCounter = 0;


					for(int i = 0; i != textList.size();i++){
						for(int j = 0; j != textList.get(i).length(); j++){
							switch(textList.get(i).charAt(j)){
							case 'a': aCounter++;
								break;
							case 'e': eCounter++;
								break;
							case 'i': iCounter++;
								break;
							case 'o': oCounter++;
								break;
							case 'u': uCounter++;
								break;
							}
						}
					}

//					for(int i = 0; i != textList.size(); i++){
//						textArea.appendText(textList.get(i));
//						textArea.appendText(" ");
//					}
					textArea.appendText("Number of a: " + aCounter);
					textArea.appendText("\nNumber of e: " + eCounter);
					textArea.appendText("\nNumber of i: " + iCounter);
					textArea.appendText("\nNumber of o: " + oCounter);
					textArea.appendText("\nNumber of u: " + uCounter);

				}



				//confirmation window
				final Stage dialog = new Stage();
				dialog.initModality(Modality.APPLICATION_MODAL);
				dialog.initOwner(window);
				VBox dialogVbox = new VBox(20);
				dialogVbox.setAlignment(Pos.CENTER);
				Button closeDialog = new Button("Close");
				closeDialog.setOnAction(new EventHandler<ActionEvent>(){
					@Override
					public void handle(ActionEvent arg0){
						dialog.close();
					}
				}
						);
				dialogVbox.getChildren().addAll(new Text("File Successfully Imported!"), closeDialog);
				Scene dialogScene = new Scene(dialogVbox, 160, 100);
				dialog.setScene(dialogScene);
				dialog.show();

			}
		});


		//scene stuff
		//-------IMPORT SCENE--------
		VBox importVbox = new VBox();
		HBox importHbox = new HBox();

		backBtn.setOnAction(new EventHandler<ActionEvent>(){

			@Override
			public void handle(ActionEvent arg0) {
				window.close();
			}

		});

		backBtn.setPrefSize(100, 20);

		//import vbox
		importVbox.setAlignment(Pos.TOP_RIGHT);
		importVbox.getChildren().addAll(importBtn, backBtn);
		importVbox.setPadding(new Insets(15,12,15,12));
		importVbox.setSpacing(20);

		//import hbox
		importHbox.getChildren().addAll(textArea, importVbox);
		importHbox.setAlignment(Pos.CENTER_RIGHT);


		BorderPane importBorder  = new BorderPane();
		importBorder.setCenter(importHbox);
		Scene importScene = new Scene (importBorder, 400, 500);

		window.setTitle("Import File"); // Set the stage title
		window.setScene(importScene); // Place the scene in the stage
		window.show();

	}
	public static void main(String[] args) {
		Application.launch(args);
	}

}
