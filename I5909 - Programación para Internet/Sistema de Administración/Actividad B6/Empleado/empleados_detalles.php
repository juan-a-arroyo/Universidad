<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Detalles</title>
        <?php
            require "funciones/conecta.php";
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
            }
        ?>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="3">DETALLES</td>
                </tr>
                <tr>
                    <td id="photo" class="first" width="500" rowspan="5">
                        <div class="image-container">
                            <?php
                                echo "<img class=\"preview\" src=\"archivos/fotos/$archivo\" alt=\"Empleado\">";
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
                        <input class="button" type="reset" value="Regresar al Listado" onclick="window.history.back(); return false;">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>