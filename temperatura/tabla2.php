<?php  
//tomamos los datos del archivo conexion.php  
require("conexion.php");  
$link = Conectarse();  
//se envia la consulta  
if(isset($_POST['consulta5'])){

$datos_consulta5 = $_POST['Consulta5'];}

$result = mysqli_query($link, "SELECT `ID`, `valor`, `tiempo`,`ubicacion` FROM `valores` WHERE $datos ");
//se despliega el resultado  
echo "<table border=1>";  
echo "<tr>";  
echo "<th>ID </th>";
echo "<th> </th>";   
echo "<th>fecha </th>"; 
echo "<th> </th>"; 
echo "<th>temperatura</th>";  
echo "<th> </th>"; 
echo "<th>ubicacion</th>";
echo "</tr>";  
//muestra los datos en la table
while ($row = mysqli_fetch_row($result)){   
    echo "<tr>";  
    echo "<td>$row[0]  ></td>"; 
    echo "<th>  </th>";  
    echo "<td>$row[2]  </td>"; 
    echo "<th>  </th>";  
    echo "<td>$row[1] °C</td>";
    echo "<th>  </th>";  
    echo "<td>$row[3] </td>";	
    echo "</tr>";  
}  
echo "</table>";  
?>  