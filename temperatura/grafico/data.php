<?php
header('Content-Type: application/json');
$con = mysqli_connect("192.168.0.18", "root", "01", "sensores"); //conecta la base de datos
//require("conexion.php");  
//$link = Conectarse();  
if (mysqli_connect_errno($con)) {
    echo "Failed to connect to DataBase: " . mysqli_connect_error();
} else {
    $data_points = array();
    $result = mysqli_query($con, "SELECT * FROM valores");  //captura los datos para el grafico
    while ($row = mysqli_fetch_array($result)) {
        $point = array("valorx" => $row['id'], "valory" => $row['valor']);
        array_push($data_points, $point);
    }
    echo json_encode($data_points);
}
mysqli_close($con);
?>