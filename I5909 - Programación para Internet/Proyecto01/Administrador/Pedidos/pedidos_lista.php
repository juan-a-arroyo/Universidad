<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $cantidad_total = $_GET['cantidad_total'] ?? 0;
    $precio_total = $_GET['precio_total'] ?? 0;
    $ruta_salir = "../Empleado/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_inicio = "../bienvenido.php";
    $ruta_empleados = "../Empleado/empleados_lista.php";
    $ruta_productos = "../Productos/productos_lista.php";
    $ruta_promociones = "../Promociones/promociones_lista.php";
    $ruta_pedidos = "pedidos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Listado de Pedidos</title>
        <?php
            require "../../Funciones/conecta.php";
            $con = conecta();
            $sql = "SELECT * FROM pedidos
                    WHERE status = 1";
            $res = $con->query($sql);
        ?>
    </head>
    <link href="../../css/style.css" type="text/css" rel="stylesheet">
    <script src="../../js/jquery-3.3.1.min.js"></script>
    <script>
        function detalles(id){
            window.location.href = 'pedidos_detalles.php?id=' + id;
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="6">Lista de Pedidos</td>
                </tr>
                <?php include('../Funciones/menu.php'); ?>
                <tr>
                    <td class="first" class="header">ID</td>
                    <td class="header">Fecha y Hora</td>
                    <td class="header">Usuario</td>\
                    <td class="header">Cantidad</td>
                    <td class="header" colspan="2">Precio</td>
                </tr>
                    <?php
                        while($row = $res->fetch_array()){
                            $id = $row["id"];
                            $fecha = $row["fecha"];
                            $id_usuario = $row["id_usuario"];
                            $sql2 = "SELECT * FROM pedidos_productos
                                    WHERE id_pedido = $id";
                            $res2 = $con->query($sql2);
                            $cantidad_total = 0;
                            $precio_total = 0;
                            while($row = $res2->fetch_array()){
                                $cantidad = $row["cantidad"];
                                $precio = $row["precio"];
                                $cantidad_total += $cantidad;
                                $precio_total += $precio * $cantidad;
                            }
                            echo "<tr id=\"fila$id\">";
                            echo "  <td class=\"first\">$id</td>";
                            echo "  <td>$fecha</td>";
                            echo "  <td>$id_usuario</td>";
                            echo "  <td>$cantidad_total</td>";
                            echo "  <td>$".number_format($precio_total, 2)."</td>";
                            echo "  <td class=\"details\"><a href=\"javascript:void();\" onclick=\"detalles($id);\"><img src=\"../../css/icons/p_details.png\" alt=\"Detalles\" width=\"35\"></a></td>";
                            echo "</tr>";
                        }
                    ?>
                <tr>
                    <td class="bottom" colspan="6"></td>
                </tr>
            </table>
        </div>
    </body>
</html> 