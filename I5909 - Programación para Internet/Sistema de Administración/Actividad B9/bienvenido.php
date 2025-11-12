<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "Administrador/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Sistema de Administración</title>
    </head>
    <link href="Administrador/css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="6">Sistema de Administración</td>
                </tr>
                <?php include('Administrador/Funciones/menu.php'); ?>
                <tr>
                    <td class="bottom" colspan="6">
                </tr>
            </table>
        </div>
    </body>
</html>