<?php
$mysqli = new mysqli('localhost', 'root', '', 'sensores');
echo $_POST['ubicacion'];
?>
<html>
<head>
<title> Consulta 3 </title>
</head>
<body>
	<form method='POST'>
		<select name='ubicacion' onchange='submit()'>
			<?php
				$sql="SELECT DISTINCT `ubicacion`,`ID` FROM valores";
				$rec=mysql_query($sql);
				while($row=mysql_fetch_array($rec))
				{
					echo "<option value='".$row['ubicacion']."'>";
					echo $row['usuario'];
					echo "</option>";
				}
			?>
		</select>
	</form>
</body>
</html>