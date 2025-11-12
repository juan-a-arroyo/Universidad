<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Detalles</title>
        <?php
            require "funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM administradores
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
            }
        ?>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="2">DETALLES</td>
                </tr>
                    <?php
                        echo "<tr>";
                        echo "  <td class=\"first\">ID: </td>";
                        echo "  <td>$id</td>";
                        echo "</tr>";
                        echo "<tr>";
                        echo "  <td class=\"first\">Nombre: </td>";
                        echo "  <td>$nombre $apellido</td>";
                        echo "</tr>";
                        echo "<tr>";
                        echo "  <td class=\"first\">Correo: </td>";
                        echo "  <td>$correo</td>";
                        echo "</tr>";
                        echo "<tr>";
                        echo "  <td class=\"first\">Rol: </td>";
                        echo "  <td>$rol_txt</td>";
                        echo "</tr>";
                        echo "<tr>";
                        echo "  <td class=\"first\">Estatus: </td>";
                        echo "  <td>$status_txt</td>";
                        echo "</tr>";
                        echo "<tr>";
                        echo "  <td class=\"bottom\" colspan=\"2\">";
                        echo "     <input class=\"button\" type=\"reset\" value=\"Regresar al Listado\" onclick=\"window.history.back(); return false;\">";
                        echo "  </td>";
                        echo "</tr>";
                    ?>
            </table>
        </div>
    </body>
</html>