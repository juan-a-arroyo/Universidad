<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombre = $_SESSION['nombre'];
    $correo = $_SESSION['correo'];
    if($idU == "" || $nombre == "" || $correo == "")
        header("Location: Administrador/Funciones/salir.php");
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Sistema de Administración</title>
    </head>
    <link href="Administrador/css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <script>
        function administradores(){
            window.location.href = 'Administrador/administradores_lista.php';
        }
        function cerrarSesion(){
            window.location.href = 'Administrador/Funciones/salir.php';
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="6">Sistema de Administración</td>
                </tr>
                <tr>
                    <td class="tab">
                        <input class="button" type="button" value="Inicio" onclick="">
                    </td>
                    <td class="tab">
                        <input class="button" type="button" value="Administradores" onclick="administradores();">
                    </td>
                    <td class="tab">
                        <input class="button" type="button" value="Productos" onclick="">
                    </td>
                    <td class="tab">
                        <input class="button" type="button" value="Pedidos" onclick="">
                    </td>
                    <td class="tab">
                        <input class="button" type="button" value="Bienvenido/a <?php echo $nombre;?>" onclick="">
                    </td>
                    <td class="tab">
                        <input class="button" type="button" value="Cerrar Sesión" onclick="cerrarSesion();">
                    </td>
                </tr>
                <tr>
                    <td class="bottom" colspan="6">
                </tr>
            </table>
        </div>
    </body>
</html>