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
    $ruta_promociones = "../Promociones/promociones_lista.php";
    $ruta_pedidos = "pedidos_lista.php";
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
            $id_p = $id;
            $sql = "SELECT * FROM pedidos_productos
                    WHERE id_pedido = $id";
            $res = $con->query($sql);
        ?>
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        function detalles(id, id_p){
            window.location.href = 'pedidos_productos_detalles.php?id=' + id + '&id_p=' + id_p;
        }
        function atras(){
            window.location.href = 'pedidos_lista.php';
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="8">PEDIDO #<?php echo $id; ?></td>
                </tr>
                <?php include('../Funciones/menu.php'); ?>
                <tr>
                    <td class="first header">ID</td>
                    <td class="header">Producto</td>
                    <td class="header">ID Producto</td>
                    <td class="header">Precio Unitario</td>
                    <td class="header">Cantidad</td>
                    <td class="header" colspan="2">Subtotal</td>
                </tr>
                    <?php
                        $cantidad_total = 0;
                        $precio_total = 0;
                        while($row = $res->fetch_array()){
                            $id = $row["id"];
                            $id_producto = $row["id_producto"];
                            $cantidad = $row["cantidad"];
                            $precio = $row["precio"];
                            $sql2 = "SELECT nombre FROM productos
                                     WHERE id = $id_producto";
                            $res2 = $con->query($sql2);
                            if($res2){
                                $row = $res2->fetch_assoc();
                                $nombre = $row["nombre"];
                            }
                            $subtotal = $cantidad * $precio;
                            $cantidad_total += $cantidad;
                            $precio_total += $subtotal;
                            echo "<tr id=\"fila$id\">";
                            echo "  <td class=\"first\">$id</td>";
                            echo "  <td>$nombre</td>";
                            echo "  <td>$id_producto</td>";
                            echo "  <td>$".number_format($precio, 2)."</td>";
                            echo "  <td>$cantidad</td>";
                            echo "  <td>$".number_format($subtotal, 2)."</td>";
                            echo "  <td class=\"details\"><a href=\"javascript:void();\" onclick=\"detalles($id_producto, $id_p);\"><img src=\"../css/icons/p_details.png\" alt=\"Detalles\" width=\"35\"></a></td>";
                            echo "</tr>";
                        }
                            echo "<tr>";
                            echo "  <td colspan=\"3\"></td>";
                            echo "  <td class=\"total\">Total:</td>";
                            echo "  <td class=\"total\">$cantidad_total</td>";
                            echo "  <td class=\"total\" colspan=\"2\">$".number_format($precio_total, 2)."</td>";
                            echo "</tr>";
                    ?>
                <tr>
                    <td class="bottom" colspan="8">
                        <input class="button" type="reset" value="Regresar al Listado" onclick="atras();">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>