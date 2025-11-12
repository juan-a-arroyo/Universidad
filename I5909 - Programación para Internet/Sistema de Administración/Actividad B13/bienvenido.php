<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "Empleado/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_inicio = "bienvenido.php";
    $ruta_empleados = "Empleado/empleados_lista.php";
    $ruta_productos = "Productos/productos_lista.php";
    $ruta_promociones = "Promociones/promociones_lista.php";
    $ruta_pedidos = "Pedidos/pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Sistema de Administración</title>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="6">Sistema de Administración</td>
                </tr>
                <?php include('Funciones/menu.php'); ?>
                <tr>
                    <?php echo "<td class=\"subtitle\">Bienvenido/a $nombreU al Sistema de Administración</td>"; ?>
                </tr>
                <tr>
                    <td class="bottom" colspan="6">
                </tr>
            </table>
        </div>
    </body>
</html>