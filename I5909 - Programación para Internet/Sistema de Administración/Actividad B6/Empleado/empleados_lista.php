<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Listado de Empleados</title>
        <?php
            require "funciones/conecta.php";
            $con = conecta();
            $sql = "SELECT * FROM empleados
                    WHERE status = 1 AND eliminado = 0";
            $res = $con->query($sql);
        ?>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <script>
        function eliminar(id){
            if(confirm("¿Desea eliminar la fila "+id+"?")){
                $.ajax({
                    url : 'empleados_elimina.php?id='+id,
                    success : function(ban){
                        if(ban == 1)
                            $('#fila'+id).remove();
                    },  
                    error : function(){
                        alert("Ha ocurrido un error al eliminar la fila");
                    }
                });
            }
        }
        function detalles(id){
            window.location.href = 'empleados_detalles.php?id=' + id;
        }
        function editar(id){
            window.location.href = 'empleados_edita.php?id=' + id;
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="7">LISTADO DE EMPLEADOS</td>
                </tr>
                <tr>
                    <td class="first" class="header">ID</td>
                    <td class="header">Nombre completo</td>
                    <td class="header">Correo</td>
                    <td class="header" colspan="3">Rol</td>
                    <td class="new"><a href="empleados_alta.php"><img src="css/icons/add.png" alt="Nuevo registro" width="35"></a><br></td>
                </tr>
            <?php
                while($row = $res->fetch_array()){
                    $id = $row["id"];
                    $nombre = $row["nombre"];
                    $apellidos = $row["apellidos"];
                    $correo = $row["correo"];
                    $rol = $row["rol"];
                    $rol_txt = ($rol == 1) ? "Gerente" : "Ejecutivo";
                    echo "<tr id=\"fila$id\">";
                    echo "  <td class=\"first\">$id</td>";
                    echo "  <td>$nombre $apellidos</td>";
                    echo "  <td>$correo</td>";
                    echo "  <td>$rol_txt</td>";
                    echo "  <td class=\"details\"><a href=\"javascript:void();\" onclick=\"detalles($id);\"><img src=\"css/icons/details.png\" alt=\"Detalles\" width=\"35\"></a></td>";
                    echo "  <td class=\"edit\"><a href=\"javascript:void();\" onclick=\"editar($id);\"><img src=\"css/icons/edit.png\" alt=\"Editar\" width=\"35\"></a></td>";
                    echo "  <td class=\"delete\"><a href=\"javascript:void();\" onclick=\"eliminar($id); return false;\"><img src=\"css/icons/delete.png\" alt=\"Eliminar\" width=\"35\"></a></td>";
                    echo "</tr>";
                }
            ?>
                <tr>
                    <td class="bottom" colspan="7"></td>
                </tr>
            </table>
        </div>
    </body>
</html>