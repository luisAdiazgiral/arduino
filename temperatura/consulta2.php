<?php
 
  $mysqli = new mysqli('localhost', 'root', '', 'sensores');

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" lang="en">

<head>
  <title>Manejo Variables Temperatura</title>
  <meta http-equiv="content-type" content="text/html;charset=utf-8" />
  <meta name="generator" content="Geany 1.23.1" />
</head>

<body>
  <div align="center">
  <form name="envio" method="GET" action="tabla.php">
    <h1>Manejo Variables Temperatura</h1>
	<?php 
	$valor = mysqli_real_escape_string($con, $_GET['valor']);
	echo ("La temperatura actual es de : " , $valor , "° C");
	?>
								
    <p>Seleccione la ciudad en la que desa consultar</p>
    <p>Ciudad:
      <select name="y">
        <option value="todos">Selección:</option>
        <?php
										
          $query = $mysqli -> query ("SELECT DISTINCT `ubicacion` FROM valores"); // distintc distingue valores y no repite
											
          while ($valores = mysqli_fetch_array($query)) {
												
            echo '<option value="'.$valores[ubicacion].'">'.$valores[ubicacion].'</option>'; 
													
          }
        ?>
      </select>
      <input type="submit" value="enviar" name="enviar">
    </p>
  </form>
  </div>
  
</body>

</html>