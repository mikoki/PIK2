<html>
	<head>
		<link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css'>
	</head>
	<body>
<?php
	$conn = mysqli_connect("localhost", "root", "", "mikoki");
	if($conn==false){
		die("ERROR: Could not connect. " . mysqli_connect_error());
	}

		if(isset($_POST['insert1'])){

			if(isset($_POST['code']) && $_POST['code'] != "" && isset($_POST['name']) && $_POST['name'] != "" && isset($_POST['price']) && $_POST['price'] != ""){
		
				$code = mysqli_real_escape_string($conn, $_POST['code']);
				$name = mysqli_real_escape_string($conn, $_POST['name']);
				$price = mysqli_real_escape_string($conn, $_POST['price']);

				/*if (empty($number)||($date)||($code)||($quantity)||($bulstat)){
				echo "Please fill all fields";
				exit();
				}*/


				$sql = "INSERT INTO products (Code, Name, Price) VALUES ('$code', '$name', '$price')";

			if(mysqli_query($conn, $sql)){
				header("Location: http://localhost:1337/project/display.php");
				exit();
			}else{
				//echo "ERROR: Could not able to execute $sql. " . mysqli_error($conn);
			}
		}else{
			echo "Please fill all fields";
		}
	}

		elseif (isset($_POST['print_table1'])){ 
			$sql1 = "SELECT * FROM products";
			$result = $conn->query($sql1);

			if ($result->num_rows > 0) {
				echo "<table class='table table-striped'><tr><th>Code</th><th>Name</th><th>Price</th></tr>";
		    	while($row = $result->fetch_assoc()) {
		       		echo "<tr><td>".$row["Code"]."</td><td>".$row["Name"]."</td><td>".$row["Price"]."</td></tr>";
			    }
			    echo "</table></body></html>";
		} else {
	   	 echo "0 results";
		}	
	}
		
	mysqli_close($conn);
?>