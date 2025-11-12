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
        <title>Carrito Paso 1</title>
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
        var cantidadFinal = 0;
        function actualizarCantidad(id, cantidad, stock) {
            if(cantidad < 1)
                cantidad = 1;
            if(cantidad > stock)
                cantidad = stock;
            $.ajax({
                type: 'POST',
                url: 'Funciones/modificar_cantidad.php',
                data: {id: id, cantidad: cantidad},
                success: function(response) {
                    console.log('Cantidad actualizada correctamente');
                    var xhr = new XMLHttpRequest();
                    xhr.open('GET', 'Funciones/cantidad_carrito.php', true);
                    xhr.onload = function () {
                        if (xhr.status === 200) {
                            var cantidad = xhr.responseText;
                            document.getElementById('carrito').value = 'Carrito (' + cantidad + ')';
                        } else {
                            console.error('Error al obtener la cantidad del carrito.');
                        }
                    };
                    xhr.send();
                },
                error: function() {
                    alert('Ha ocurrido un error al actualizar la cantidad');
                }
            });
        }
        function actualizarTotal() {
            var cantidadTotal = 0;
            var precioTotal = 0;
            $('.cantidad-carrito').each(function() {
                var id = $(this).closest('tr').attr('id').replace('fila', '');
                var cantidad = parseFloat($(this).val());
                var precioTexto = $(this).closest('tr').find('td:nth-child(2)').text();
                var precioUnitario = parseFloat(precioTexto.replace(/[^\d.-]/g, ''));
                var subtotal = cantidad * precioUnitario;
                cantidadTotal += cantidad;
                precioTotal += subtotal;
            });
            $('#cantidad-total').text(cantidadTotal);
            $('.total[colspan="3"]').text('$' + precioTotal.toFixed(2).replace(/\B(?=(\d{3})+(?!\d))/g, ','));
            document.getElementById('carrito').value = 'Carrito (' + cantidadTotal + ')';
        }
        $(document).ready(function() {
            $('.cantidad-carrito').on('blur', function() {
                var id = $(this).closest('tr').attr('id').replace('fila', '');
                var stock = $(this).closest('input').attr('max');
                var nuevaCantidad = $(this).val();
                var precioTexto = $(this).closest('tr').find('td:nth-child(2)').text();
                var precioUnitario = parseFloat(precioTexto.replace(/[^\d.-]/g, ''));
                var nuevoSubtotal = nuevaCantidad * precioUnitario;
                var formattedSubtotal = nuevoSubtotal.toFixed(2).replace(/\B(?=(\d{3})+(?!\d))/g, ',');
                $('#fila' + id + ' .subtotal').text('$' + formattedSubtotal);
                actualizarCantidad(id, nuevaCantidad, stock);
                actualizarTotal();
            });
        });
        function eliminar(id, nombre){
            if(confirm("¿Desea eliminar el producto: "+nombre+"?")){
                $.ajax({
                    url : 'Funciones/borrar_producto.php?id='+id,
                    success : function(ban){
                        if(ban == 1)
                            $('#fila'+id).remove();
                        actualizarTotal();
                    },  
                    error : function(){
                        alert("Ha ocurrido un error al eliminar la fila");
                    }
                });
            }
        }
        function regresar(){
            window.history.back();
        }
        function paso2(){
            actualizarTotal();
            if(cantidadFinal > 0)
                window.location.href = "carrito_paso2.php";
            else
                alert("No hay productos en el carrito");
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="8">Carrito Paso 1</td>
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
                            echo "  <td>";
                            echo "      <input class=\"cantidad-carrito\" type=\"number\" value=\"$cantidad\" min=\"1\" max=\"$stock\">";
                            echo "  </td>";
                            echo "  <td class=\"subtotal\">$".number_format($cantidad*$precio, 2)."</td>";
                            echo "  <td class=\"delete\"><a href=\"javascript:void();\" onclick=\"eliminar($id, '$nombre'); return false;\"><img src=\"css/icons/delete.png\" alt=\"Eliminar\" width=\"35\"></a></td>";
                            echo "</tr>";
                        }
                        echo "<tr>";
                        echo "  <td></td>";
                        echo "  <td class=\"total\">Total:</td>";
                        echo "  <td class=\"total\" id=\"cantidad-total\">$cantidad_total</td>";
                        echo "  <td class=\"total\" colspan=\"3\">$".number_format($precio_total, 2)."</td>";
                        echo "</tr>";
                    ?>
                <tr>
                    <td class="bottom" colspan="8">
                        <input class="button" type="reset" value="Regresar" onclick="regresar();">
                        <?php  echo "<input class=\"button\" type=\"submit\" value=\"Siguiente\" onclick=\"paso2();\">"; ?>
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>