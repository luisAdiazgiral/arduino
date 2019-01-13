<?php
$db_host = "localhost";
$db_user = "root";
$db_password = "";
$db_name = "panamahitek";
$db_table_name = "plot_values";
$db_connection = mysql_connect($db_host, $db_user, $db_password);
mysql_select_db($db_name, $db_connection);
$result = mysql_query("SELECT * FROM $db_table_name", $db_connection);
if (!$db_connection) {
    die('No se ha podido conectar a la base de datos');
}
$x = $_GET['x'];
$y = $_GET['y'];
$query = 'INSERT INTO `' . $db_name . '`.`' . $db_table_name .
        '` (`x` ,'
        . ' `y`) '
        . 'VALUES("' . $x . '",'
        . ' "' . $y . '")';
$retry_value = mysql_query($query, $db_connection);
if (!$retry_value) {
    die('Error: ' . mysql_error());
}
mysql_close($db_connection);
?>