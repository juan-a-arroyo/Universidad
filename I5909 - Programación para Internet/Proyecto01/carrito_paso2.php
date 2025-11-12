<?php
    session_start();
    $id_usuario = $_SESSION['id_usuario'] ?? null;
    $nombre_usuario = $_SESSION['nombre_usuario'] ?? null;
    $correo_usuario = $_SESSION['correo_usuario'] ?? null;
    if($id_usuario == "" || $nombre_usuario == "" || $correo_usuario == "")
        header("Location: Funciones/cerrar_sesion.php");
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Carrito Paso 2</title>
        <?php
            require "Funciones/conecta.php";
            $con = conecta();
            $sql = "SELECT productos.id, productos.nombre, productos.stock, pedidos_productos.cantidad, pedidos_productos.precio
                    FROM pedidos_productos
                    INNER JOIN productos ON pedidos_productos.id_producto = productos.id
                    INNER JOIN pedidos ON pedidos.id = pedidos_productos.id_pedido
                    WHERE pedidos.status = 0";
            $res = $con->query($sql);
        ?>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <script>
        function regresar(){
            window.history.back();
        }
        function finalizar(){
            window.location.href = "Funciones/carrito02.php";
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="8">Carrito Paso 2</td>
                </tr>
                <?php include('Funciones/menu.php'); ?>
                <tr>
                    <td class="header">Producto</td>
                    <td class="header">Precio Unitario</td>
                    <td class="header">Cantidad</td>
                    <td class="header" colspan="4">Subtotal</td>
                </tr>
                    <?php
                        $cantidad_total = 0;
                        $precio_total = 0;
                        while($row = $res->fetch_array()){
                            $id = $row["id"];
                            $nombre = $row["nombre"];
                            $precio = $row["precio"];
                            $stock = $row["stock"];
                            $cantidad = $row["cantidad"];
                            $subtotal = $cantidad * $precio;
                            $cantidad_total += $cantidad;
                            $precio_total += $subtotal;
                            echo "<tr id=\"fila$id\">";
                            echo "  <td class=\"first\">$nombre</td>";
                            echo "  <td>$".number_format($precio, 2)."</td>";
                            echo "  <td>$cantidad</td>";
                            echo "  <td>$".number_format($cantidad*$precio, 2)."</td>";
                            echo "</tr>";
                        }
                        echo "<tr>";
                        echo "  <td></td>";
                        echo "  <td class=\"total\">Total:</td>";
                        echo "  <td class=\"total\">$cantidad_total</td>";
                        echo "  <td class=\"total\" colspan=\"3\">$".number_format($precio_total, 2)."</td>";
                        echo "</tr>";
                    ?>
                <tr>
                    <td class="bottom" colspan="8">
                        <input class="button" type="reset" value="Regresar" onclick="regresar();">
                        <input class="button" type="submit" value="Finalizar" onclick="finalizar();">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>