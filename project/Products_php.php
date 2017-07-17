<?php
	$conn = mysqli_connect("localhost", "root", "", "mikoki");
	if($conn==false){
		die("ERROR: Could not connect. " . mysqli_connect_error());
	}

	if(isset($_POST['code'], $_POST['name'], $_POST['price'])){
	
		$code = mysqli_real_escape_string($conn, $_POST['code']);
		$name = mysqli_real_escape_string($conn, $_POST['name']);
		$price = mysqli_real_escape_string($conn, $_POST['price']);

		$sql = "INSERT INTO products (Code, Name, Price) VALUES ('$code', '$name', '$price')";

		if(mysqli_query($conn, $sql)){
			echo "Records added successfully";
		}else{
			echo "ERROR: Could not able to execute $sql. " . mysqli_error($conn);
		}
	}
		
	mysqli_close($conn);
	//header("Location: http://localhost:1337/project/display.php");
	exit();
?>