<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "../Empleado/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_inicio = "../bienvenido.php";
    $ruta_empleados = "../Empleado/empleados_lista.php";
    $ruta_productos = "../Productos/productos_lista.php";
    $ruta_promociones = "promociones_lista.php";
    $ruta_pedidos = "../Pedidos/pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Detalles de Promoción</title>
        <?php
            require "../../Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM promociones
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $archivo = $row["archivo"];
                $ruta_archivo = "Archivos/Fotos/$archivo";
                $timestamp = time();
                $url_imagen = $ruta_archivo . "?v=" . $timestamp;
            }
        ?>
    </head>
    <link href="../../css/style.css" type="text/css" rel="stylesheet">
    <script src="../../js/jquery-3.3.1.min.js"></script>
    <script>
        function atras(){
            window.location.href = 'promociones_lista.php';
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="2">Detalles de Promoción</td>
                </tr>
                <?php include('../Funciones/menu.php'); ?>
                <tr>
                    <td class="first">ID: 
                    <?php
                        echo "$id";
                    ?>
                    </td>
                    <td>Nombre:  
                    <?php
                        echo "$nombre";
                    ?>
                    </td>
                </tr>
                <tr>
                    <td id="photo" class="first" colspan="2">
                        <div class="image-container">
                            <?php
                                if(!is_file("archivos/fotos/$archivo"))
                                echo "<img class=\"preview-banner\" src=\"../../css/icons/wide_dark_default.png\" alt=\"Banner\">";
                            else
                                echo "<img class=\"preview-banner\" src=\"$url_imagen\" alt=\"Banner\">";
                            ?>
                        </div>
                    </td>
                </tr>
                <tr>
                    <td class="bottom" colspan="2">
                        <input class="button" type="reset" value="Regresar al Listado" onclick="atras();">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>