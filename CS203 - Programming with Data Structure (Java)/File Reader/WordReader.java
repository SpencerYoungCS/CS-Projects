import java.util.LinkedList;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextArea;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontPosture;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;



//LAB 3 #2------------------------------------------
public class WordReader extends Application{

	BorderPane bp = new BorderPane();
	TextField tf = new TextField("test");
	TextArea text = new TextArea();
	@Override
	public void start(Stage primaryStage) throws Exception {
		// TODO Auto-generated method stub
		HBox hbox = new HBox();

		tf.setPrefColumnCount(20);
		bp.setTop(hbox);
		tf.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 20));
		text.setFont(Font.font("Times New Roman", FontWeight.BOLD, FontPosture.REGULAR, 18));
		bp.setCenter(text);

		Button wordBtn = new Button("Display");

		//set order on button click
		wordBtn.setOnAction(e -> {
			String userText = tf.getCharacters().toString();
			LinkedList<String> textList = new LinkedList<String>();
			for (String s: userText.split(" ")){
				textList.add(s);
			}
			for(int i =0; i != textList.size(); i++){
				text.appendText(textList.get(i));
				text.appendText(" ");
			}
		});

		hbox.getChildren().addAll(new Label("Enter Words"), tf, wordBtn);
		Scene scene = new Scene(bp, 700,400);
		primaryStage.setScene(scene);
		primaryStage.setTitle("Lab 2 Word Reader");
		primaryStage.show();

	}

	public static void main(String[] args) {
		Application.launch(args);
	}
}
