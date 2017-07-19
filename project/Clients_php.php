
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
	
	if(isset($_POST['insert'])){
		if(isset($_POST['bulstat']) && $_POST['bulstat'] != "" && isset($_POST['c_name']) && $_POST['c_name'] != ""){

			$bulstat = mysqli_real_escape_string($conn, $_POST['bulstat']);
			$c_name = mysqli_real_escape_string($conn, $_POST['c_name']);
			/*if (empty($bulstat)||($c_name)){
				echo "Please fill all fields";
				exit();
			}*/
			
			$sql1 = "INSERT INTO clients (Bulstat, Name_of_the_company) VALUES ('$bulstat', '$c_name')";
	

			if(mysqli_query($conn, $sql1)){
				header("Location: http://localhost:1337/project/display.php");
				exit();
			}else{
				//echo "ERROR: Could not able to execute $sql. " . mysqli_error($conn);
			}
		}

		else{
			echo "Please fill all fields";
		}
	}	
	else if (isset($_POST['print_table'])){ 
		$sql = "SELECT * FROM clients";
		$result = $conn->query($sql);

		if ($result->num_rows > 0) {
			echo "<table class='table table-striped'><tr><th>Bulstat</th><th>Company's name</th></tr>";
	    	while($row = $result->fetch_assoc()) {
	       		echo "<tr><td>".$row["Bulstat"]."</td><td>".$row["Name_of_the_company"]."</td></tr>";
		    }
		    echo "</table></body></html>";
		} else {
	   	 echo "0 results";
		}	
	}
	

?>