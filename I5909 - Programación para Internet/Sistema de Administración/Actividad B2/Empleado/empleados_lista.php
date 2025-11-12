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
    </script>
    <body>
        <table>
            <tr>
                <td class="title" colspan="5">LISTADO DE EMPLEADOS</td>
            </tr>
            <tr>
                <td class="header">ID</td>
                <td class="header">Nombre completo</td>
                <td class="header">Correo</td>
                <td class="header">Rol</td>
                <td class="new"><a href=""><img src="css/icons/add.png" alt="Nuevo registro" width="35"></a><br></td>
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
                    echo "  <td>$id</td>";
                    echo "  <td>$nombre $apellidos</td>";
                    echo "  <td>$correo</td>";
                    echo "  <td>$rol_txt</td>";
                    echo "  <td class=\"delete\"><a href=\"javascript:void();\" onclick=\"eliminar($id);\"><img src=\"css/icons/delete.png\" alt=\"Eliminar\" width=\"35\"></a></td>";
                    echo "</tr>";
                }
            ?>
            <tr>
                <td class="bottom" colspan="5"></td>
            </tr>
        </table>
    </body>
</html>