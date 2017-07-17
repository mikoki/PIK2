<!DOCTYPE html>
<!--
To change this license header, choose License Headers in Project Properties.
To change this template file, choose Tools | Templates
and open the template in the editor.
-->
<html>
    <head>
        <script>
        function Products(){
            <meta charset="UTF-8">
            <form action="insert.php" method="POST">
            <input type="text" name = "code" placeholder = "Code"><br> 
            <input type= "text" name = "name" placeholder = "Name"><br>
            <input type="text" name = "price" placeholder = "Price"><br>
            <input type="submit" name = "insert"><br>
        }
        function Clients(){
            <meta charset="UTF-8">
            <form action="insert.php" method="POST">
            <input type="text" name = "bulstat" placeholder = "Bulstat">
            <input type= "text" name = "c_name" placeholder = 'Name of the company'><br>
        }
        </script>
        <title></title>
    </head>
    <body>
    <button onclick = "Products();">Table Products</button>
    <button onclick = "Clients();">Table Clients</button>

          
            <input type="text" name = "number" placeholder = "Number"><br> 
            </br>
            <input type= "text" name = "date" placeholder = "Date YYYY.MM.DD"><br>
            </br>
            <input type="text" name = "quantity" placeholder = "Quantity"><br>
            </br>

        </form>        
    </body>
</html>
