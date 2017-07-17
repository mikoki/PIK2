<?php

	// Create connection
	$conn = new mysqli("localhost", "root", "", "mikoki");

	// Check connection
	if ($conn->connect_error) {
	    die("Connection failed: " . $conn->connect_error);
	} 
	echo "Connected successfully";


	include 'template.php';
	if(isset($_POST['code'] && $_POST['name'] && $_POST['price'])){
		$code =  $_POST['code'];
		$name =  $_POST["name"];
		$price =  $_POST["price"];
		echo $code, $name, $price;

		if(isset($_POST['submit'])){
			mysqli_query($conn,"SELECT * FROM products");
			mysqli_query($conn,"INSERT INTO products (Code, Name, Price) VALUES ($code, &name, $price)");
			
		}
	}else(isset(($_POST['code']&&$_POST['name']&&$_POST['price'])){
		$code =  $_POST['code'];
		$name =  $_POST["name"];
		$price =  $_POST["price"];
		echo $code, $name, $price;

		if(isset($_POST['submit'])){
			mysqli_query($conn,"SELECT * FROM products");
			mysqli_query($conn,"INSERT INTO products (Code, Name, Price) VALUES ($code, &name, $price)");
	}
	mysqli_close($conn);
?>


