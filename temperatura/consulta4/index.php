<!DOCTYPE HTML>
<html lang="es">
<head>
	<meta charset="UTF-8">
	<title>Didesweb</title>
	<style type="text/css"> 
		* { text-align: center;}
		#aside {
		  float: left;
		  width: 23%;
		  margin: 1%;
		  padding: 1%;
		  border: 1px solid #000;
		}
		#section {
		  float: left;
		  width: 72%;
		  font-size: 1.6em;
		  margin: 1% 0;
		  background-color: #ffffff;
		   border: 1px solid #000;
		}
		h2, h3 { text-transform:capitalize;}
		.box { 
			border:1px solid #000;
			width: 80%;
			margin: 1% 10%;
		}
	</style>
	<script src="http://code.jquery.com/jquery-1.11.0.min.js"></script>
</head>
<body>
	<h1><a href="http://didesweb.com">Didesweb</a>
	<br>Mostrar tablas dinamicamente con AJAX</h1>
	<div id="main">
		<div id="aside">
			<?php include 'listado_tablas.php';?>
		</div>
		<div id="section">
			<div id="contenido"></div>
		</div>
		<script>
			$(document).ready(function(){	
				$(".enlaceajax").on("click", function(e){
					e.preventDefault();
					$("#contenido").load("traertablas.php");
				});
			});
			$(".f1").on("submit", function(e){
				e.preventDefault();
				$.post("traertablas.php", $(this).serialize(), function(respuesta){
					$("#contenido").html(respuesta);
				});
			});
		</script>
	</div>
</body>
</html>
