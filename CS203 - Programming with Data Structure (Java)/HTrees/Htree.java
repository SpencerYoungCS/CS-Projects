import javafx.application.Application;
import javafx.geometry.Insets;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.shape.Line;
import javafx.stage.Stage;


public class Htree extends Application {
	@Override
	public void start(Stage primaryStage) throws Exception {

		HTreePane hTreePane = new HTreePane();
		BorderPane pane = new BorderPane(hTreePane);

		//label
		Label orderLabel = new Label("Enter an Order: ");

		//text field for order
		TextField orderField = new TextField("0");

		//order button
		Button orderButton = new Button("Order To Display");

		//set order on button click
		orderButton.setOnAction(e -> {
			//convert string to int
			int order = Integer.parseInt(orderField.getText());
			hTreePane.setOrder(order);
			//execute

			hTreePane.draw();
		});


		//hbox to put everything in
		HBox orderHBox = new HBox(10, orderLabel, orderField, orderButton);
		orderHBox.setAlignment(Pos.BOTTOM_CENTER);
		pane.setBottom(orderHBox);
		orderHBox.setPadding(new Insets(10));

		//Set up stage
		Scene scene = new Scene(pane);
		primaryStage.setScene(scene);
		primaryStage.setTitle("HTree Fractal");

		//draw the 0 order tree first
		hTreePane.draw();
		primaryStage.show();


	}

	//class for fractal
	public class HTreePane extends Pane {

		//private values
		private double lastSize;
		private int order = 0;
		private double width;
		private double height;

		//constructors
		public HTreePane() {
			width = 500;
			height = 500;

			//i need a way to offset the left line from the center
			lastSize = Math.min(width, height) * 0.4;

			setMinSize(width, height);

		}

		//mutators
		public void setOrder(int order) {
			this.order = order;
		}


		//functions

		//user draw call
		public void draw() {
			//delete past lines
			getChildren().clear();

			double x = width * 0.30;
			double y = height * 0.70;
			draw(x, y, order, lastSize);
		}

		//private draw call
		private void draw(double x, double y, int order, double lastSize) {

			//line( start x, start y, end x, end y)
			Line leftLine = new Line(x, y, x, y - lastSize);
			Line middleLine = new Line(x, y - (lastSize / 2), x + lastSize, y - (lastSize / 2));
			Line rightLine = new Line(x + lastSize, y, x + lastSize, y - lastSize);
			//add the pane
			getChildren().addAll(leftLine, middleLine, rightLine);


			//recursion check
			if (order != 0) {
				double halfSize = lastSize/2;
				double offset = halfSize/2;

				//start on top left H
				draw(leftLine.getStartX() - offset, leftLine.getEndY() + halfSize/2, order-1, halfSize);
				//then on top right H
				draw(rightLine.getStartX() - offset, leftLine.getEndY() + halfSize/2, order-1, halfSize);
				//then bottom left H
				draw(leftLine.getEndX() - offset, leftLine.getStartY() + halfSize/2, order-1, halfSize);
				//then bottom right H
				draw(rightLine.getEndX() - offset, leftLine.getStartY() + halfSize/2, order-1, halfSize);
			}
			else{
				//end recursion
			}
		}
	}

	public static void main(String[] args) {
		launch(args);
	}
}