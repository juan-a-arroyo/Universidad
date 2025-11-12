<?php
    session_start();
    $id_usuario = $_SESSION['id_usuario'] ?? null;
    $nombre_usuario = $_SESSION['nombre_usuario'] ?? null;
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Detalles de producto</title>
        <?php
            require "Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT *
                    FROM productos
                    WHERE productos.id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $nombre = $row["nombre"];
                $codigo = $row["codigo"];
                $descripcion = $row["descripcion"];
                $costo = $row["costo"];
                $stock = $row["stock"];
                $archivo = $row["archivo"];
                $ruta_archivo = "Administrador/Productos/Archivos/Fotos/$archivo";
                $timestamp = time();
                $url_imagen = $ruta_archivo . "?v=" . $timestamp;
            }
            $sql = "SELECT * FROM productos
                    WHERE eliminado = 0
                    ORDER BY rand() LIMIT 3";
            $res = $con->query($sql);
        ?>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <script>
        function regresar(){
            window.history.back();
        }
        function add_carrito(id){
            var cantidad = $("#"+id).val();
            $.ajax({
                url: 'Funciones/carrito01.php',
                method: 'POST',
                data: { id: id, cantidad: cantidad},
                success: function(response) {
                    console.log('Respuesta del servidor:', response);
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
                error: function(xhr, status, error) {
                    console.error('Error en la solicitud AJAX:', error);
                }
            });
        }
        function detalles(id){
            window.location.href = 'productos_detalle.php?id=' + id;
        }
        function iniciarSesion(){
            window.location.href = "iniciar_sesion.php";
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title" colspan="3">Detalles de Producto</td>
                </tr>
                <?php include('Funciones/menu.php'); ?>
                <tr>
                    <td id="photo" class="first" width="500" rowspan="6">
                        <div class="image-container">
                            <?php
                                if(!is_file("Administrador/Productos/archivos/fotos/$archivo"))
                                    echo "  <img class=\"preview\" src=\"css/icons/light_default.png\" alt=\"Producto\">";
                                else{
                                    echo "<div class=\"product-image-container\">";
                                    echo "  <img class=\"product-image\" src=\"$url_imagen\" alt=\"Producto\">";
                                    echo "</div>";
                                }
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
                        echo "<td>$nombre</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Código: </td>
                    <?php
                        echo "<td>$codigo</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Descripción: </td>
                    <?php
                        echo "<td>$descripcion</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Precio: </td>
                    <?php
                        echo "<td>$".number_format($costo, 2)."</td>";
                    ?>
                </tr>
                <tr>
                    <td class="first">Disponibles: </td>
                    <?php
                        echo "<td>$stock</td>";
                    ?>
                </tr>
                <tr>
                    <td></td>
                    <td colspan="2">
                        <?php
                            echo "<input class=\"button\" id=\"product-button\" type=\"button\" value=\"Agregar\" onclick=\"add_carrito($id);\">";
                            echo "<input class=\"cantidad\" id=\"$id\" type=\"number\" name=\"cantidad\" value=\"1\" min=\"1\" max=\"$stock\">";
                        ?>
                    </td>
                </tr>
                <tr>
                    <td class="first" colspan="3">Otros productos similares: </td>
                </tr>
                <tr>
                    <?php
                        while($row = $res->fetch_array()){
                            $id_producto = $row["id"];
                            $producto = $row["archivo"];
                            $nombre_producto = $row["nombre"];
                            $costo_producto = $row["costo"];
                            $stock_producto = $row["stock"];
                            $ruta_producto = "Administrador/Productos/Archivos/Fotos/$producto";
                            echo "<td class=\"products\">";
                            echo "  <div class=\"product\" onclick=\"detalles($id_producto);\">";
                            echo "      <div class=\"product-thumbnail-container\">";
                            echo "          <img class=\"product-thumbnail\" src=\"$ruta_producto\" alt=\"Producto\">";
                            echo "      </div>";
                            echo "      <div class=\"product-text\">";
                            echo            $nombre_producto;
                            echo "      </div>";
                            echo "      <div class=\"product-price\">";
                            echo            '$'.number_format($costo_producto, 2);
                            echo "      </div>";
                            echo "      <div class=\"button-container\">";
                                            if($id_usuario  != "")
                                                echo "<input class=\"button\" id=\"product-button\" type=\"button\" value=\"Agregar\" onclick=\"add_carrito($id); event.stopPropagation();\">";
                                            else
                                                echo "<input class=\"button\" id=\"product-button\" type=\"button\" value=\"Agregar\" onclick=\"iniciarSesion(); event.stopPropagation();\">";
                            echo "          <input class=\"cantidad\" id=\"$id_producto\" type=\"number\" name=\"cantidad\" value=\"1\" min=\"1\" max=\"$stock_producto\" onclick=\"event.stopPropagation();\">";
                            echo "      </div>";
                            echo "  </div>";
                            echo "</td>";
                        }
                    ?>
                </tr>
                <tr>
                    <td class="bottom" colspan="3">
                        <input class="button" type="reset" value="Regresar" onclick="regresar();">
                    </td>
                </tr>
            </table>
        </div>
    </body>
</html>