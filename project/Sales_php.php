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

	if(isset($_POST['insert2'])){
		
		if(isset($_POST['number']) && $_POST['number'] != "" &&  isset($_POST['date']) && $_POST['date'] != "" && isset($_POST['code']) && $_POST['code'] != "" && isset($_POST['quantity']) && $_POST['quantity'] != "" && isset($_POST['bulstat']) && $_POST['bulstat'] != ""){
			$number = mysqli_real_escape_string($conn, $_POST['number']);
			$date = mysqli_real_escape_string($conn, $_POST['date']);
			$code = mysqli_real_escape_string($conn, $_POST['code']);
			$quantity = mysqli_real_escape_string($conn, $_POST['quantity']);
			$bulstat = mysqli_real_escape_string($conn, $_POST['bulstat']);
			$sql2 = "INSERT INTO sales (Number1, Date1, Code, Quantity, Bulstat) VALUES('$number', '$date', '$code', '$quantity', '$bulstat')";
				//"SELECT Code FROM table products INNER JOIN sales ON products.code = sales.code";
				//"SELECT Bulstat FROM table clients INNER JOIN sales ON clients.bulstat = sales.bulstat";

				
			if(mysqli_query($conn, $sql2)){
				header("Location: http://localhost:1337/project/display.php");
				exit();
			}else{
				echo "ERROR: Could not able to execute $sql2. " . mysqli_error($conn);
			}
		}else{
			echo "Please fill all fields";
		}

	}

		else if(isset($_POST['print_table2'])){ 

			$sql1 = "SELECT * FROM sales";
			$result = $conn->query($sql1);

			if ($result->num_rows > 0) {
				echo "<table class='table table-striped'><tr><th>Number</th><th>Date</th><th>Code</th><th>Quantity</th><th>Bulstat</th></tr>";
		    	while($row = $result->fetch_assoc()) {
		       		echo "<tr><td>".$row["Number1"]."</td><td>".$row["Date1"]."</td><td>".$row["Code"]."</td><td>".$row["Quantity"]."</td><td>".$row["Bulstat"]."</td</tr>";
			    }
			    echo "</table></body></html>";
		} else {
	   	 echo "0 results";
		}	
	}
	mysqli_close($conn);
?>