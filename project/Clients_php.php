<?php
	$conn = mysqli_connect("localhost", "root", "", "mikoki");
	if($conn==false){
		die("ERROR: Could not connect. " . mysqli_connect_error());
	}

if(isset($_POST['number'], $_POST['date'], $_POST['code'], $_POST['quantity'], $_POST['bulstat'])){
		$number = mysqli_real_escape_string($conn, $_POST['number']);
		$date = mysqli_real_escape_string($conn, $_POST['date']);
		$code = mysqli_real_escape_string($conn, $_POST['code']);
		$quantity = mysqli_real_escape_string($conn, $_POST['quantity']);
		$bulstat = mysqli_real_escape_string($conn, $_POST['bulstat']);
			

		$sql2 = "INSERT INTO sales (Number1, Date1, Code, Quantity, Bulstat) VALUES('$number', '$date', '$code', '$quantity', '$bulstat')";
			//"SELECT Code FROM table products INNER JOIN sales ON products.code = sales.code";
			//"SELECT Bulstat FROM table clients INNER JOIN sales ON clients.bulstat = sales.bulstat";

		
		if(mysqli_query($conn, $sql2)){
			echo "Records added successfully";
		}else{
			echo "ERROR: Could not able to execute $sql2. " . mysqli_error($conn);
		}
	}
	mysqli_close($conn);
	header("Location: http://localhost:1337/project/display.php");
	exit();
?>