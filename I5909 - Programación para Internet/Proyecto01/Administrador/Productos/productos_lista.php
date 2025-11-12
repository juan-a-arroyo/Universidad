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
    $ruta_productos = "productos_lista.php";
    $ruta_promociones = "../Promociones/promociones_lista.php";
    $ruta_pedidos = "../Pedidos/pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Lista de Productos</title>
        <?php
            require "../../Funciones/conecta.php";
            $con = conecta();
            $sql = "SELECT * FROM productos
                    WHERE status = 1 AND eliminado = 0";
            $res = $con->query($sql);
        ?>
    </head>
    <link href="../../css/style.css" type="text/css" rel="stylesheet">
    <script src="../../js/jquery-3.3.1.min.js"></script>
    <script>
        function eliminar(id){
            if(confirm("¿Desea eliminar la fila "+id+"?")){
                $.ajax({
                    url : 'productos_elimina.php?id='+id,
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
            window.location.href = 'productos_detalles.php?id=' + id;
        }
        function editar(id){
            window.location.href = 'productos_edita.php?id=' + id;
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="8">Lista de Productos</td>
                </tr>
                <?php include('../Funciones/menu.php'); ?>
                <tr>
                    <td class="first" class="header">ID</td>
                    <td class="header">Nombre</td>
                    <td class="header">Código</td>
                    <td class="header">Costo</td>
                    <td class="header" colspan="3">Stock</td>
                    <td class="new"><a href="productos_alta.php"><img src="../../css/icons/add.png" alt="Nuevo registro" width="35"></a><br></td>
                </tr>
                    <?php
                        while($row = $res->fetch_array()){
                            $id = $row["id"];
                            $nombre = $row["nombre"];
                            $codigo = $row["codigo"];
                            $costo = $row["costo"];
                            $stock = $row["stock"];
                            echo "<tr id=\"fila$id\">";
                            echo "  <td class=\"first\">$id</td>";
                            echo "  <td>$nombre</td>";
                            echo "  <td>$codigo</td>";
                            echo "  <td>$".number_format($costo, 2)."</td>";
                            echo "  <td>$stock</td>";
                            echo "  <td class=\"details\"><a href=\"javascript:void();\" onclick=\"detalles($id);\"><img src=\"../../css/icons/p_details.png\" alt=\"Detalles\" width=\"35\"></a></td>";
                            echo "  <td class=\"edit\"><a href=\"javascript:void();\" onclick=\"editar($id);\"><img src=\"../../css/icons/p_edit.png\" alt=\"Editar\" width=\"35\"></a></td>";
                            echo "  <td class=\"delete\"><a href=\"javascript:void();\" onclick=\"eliminar($id); return false;\"><img src=\"../../css/icons/delete.png\" alt=\"Eliminar\" width=\"35\"></a></td>";
                            echo "</tr>";
                        }
                    ?>
                <tr>
                    <td class="bottom" colspan="8"></td>
                </tr>
            </table>
        </div>
    </body>
</html>