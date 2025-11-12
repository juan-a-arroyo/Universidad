<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_empleados = "empleados_lista.php";
    $ruta_productos = "../Productos/productos_lista.php";
    $ruta_promociones = "../Promociones/promociones_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Detalles</title>
        <?php
            require "../Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM empleados
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $apellido = $row["apellidos"];
                $correo = $row["correo"];
                $rol = $row["rol"];
                $rol_txt = ($rol == 1) ? "Gerente" : "Ejecutivo";
                $status = $row["status"];
                $status_txt = ($status == 1) ? "Activo" : "Inactivo";
                $archivo = $row["archivo"];
                $ruta_archivo = "Archivos/Fotos/$archivo";
                $timestamp = time();
                $url_imagen = $ruta_archivo . "?v=" . $timestamp;
            }
        ?>
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        function atras(){
            window.location.href = 'empleados_lista.php';
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="3">DETALLES</td>
                </tr>
                <?php include('../Funciones/menu.php'); ?>
                <tr>
                    <td id="photo" class="first" width="500" rowspan="5">
                        <div class="image-container">
                            <?php
                                if(!is_file("archivos/fotos/$archivo"))
                                echo "<img class=\"preview\" src=\"../css/icons/default.png\" alt=\"Empleado\">";
                            else
                                echo "<img class=\"preview\" src=\"$url_imagen\" alt=\"Empleado\">";
                            ?>
                        </div>
                    </td>
                    <td class="first">ID: </td>
                    <?php
                        echo "<td>$id</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Nombre: </td>
                    <?php
                        echo "<td>$nombre $apellido</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Correo: </td>
                    <?php
                        echo "<td>$correo</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Rol: </td>
                    <?php
                        echo "<td>$rol_txt</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Estatus: </td>
                    <?php
                        echo "<td>$status_txt</td>";
                    ?>
                </tr>
                <tr>
                    <td class="bottom" colspan="3">
                        <input class="button" type="reset" value="Regresar al Listado" onclick="atras();">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>