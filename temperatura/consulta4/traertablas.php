<?php 
    $dbhost = "localhost"; 
    $dbuser = "root";
	$dpass = ""
    $dbname = "sensores";
    $bases = $_POST["valores"];
    $conexion = mysql_connect($dbhost,$dbuser,$dpass);
    mysql_select_db($dbname, $conexion);	
    $tablas = mysql_list_tables($dbname);
    echo "<h2>"."<br>".$_POST["bases"]."<br></h2>";
    $tabla = mysql_query("SELECT * FROM $bases");
    while ($registro = mysql_fetch_array($tabla)) {
		echo '<div class="box">'; 
		echo '<span>Numero de articulo: ' . $registro['ID'] . '<br></span>'; 
		echo '<h3>Nombre: ' . $registro['fecha'] . '<br></h3>'; 
		echo '<p>Descripcion: ' . $registro['temperatura'] . '<br></p>'; 
		echo '<p>Precio: ' . $registro['ubicacion'] . '€'.'<br></p>'; 
		echo '</div>';
    } 
    mysql_free_result($tablas); 
    mysql_close($conexion);
?>
