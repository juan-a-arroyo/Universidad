<?php
    session_start();
    $id_usuario = $_SESSION['id_usuario'] ?? null;
    $nombre_usuario = $_SESSION['nombre_usuario'] ?? null;
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Inicio</title>
        <?php
            require "Funciones/conecta.php";
            $con = conecta();
            $sql = "SELECT archivo FROM promociones
                    ORDER BY rand() LIMIT 1";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $banner = $row["archivo"];
                $ruta_banner = "Administrador/Promociones/Archivos/Fotos/$banner";
            }
            $sql = "SELECT * FROM productos
                    WHERE eliminado = 0
                    ORDER BY rand() LIMIT 6";
            $res = $con->query($sql);
        ?>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <script>
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
                    <td class="title" colspan="6">Inicio</td>
                </tr>
                <?php include('Funciones/menu.php'); ?>
                <tr>
                    <td colspan="6">
                        <?php echo "<img class=\"banner\" src=\"$ruta_banner\" alt=\"LOGO\" width=\"75\">"; ?>
                    </td>
                </tr>
                    <?php
                        $count = 0;
                        $rows = 28;
                        while($row = $res->fetch_array()){
                            $count++;
                            $id = $row["id"];
                            $producto = $row["archivo"];
                            $nombre = $row["nombre"];
                            $costo = $row["costo"];
                            $stock = $row["stock"];
                            $ruta_producto = "Administrador/Productos/Archivos/Fotos/$producto";
                            $pos = $count -1;
                            if($pos % 3 == 0)
                                echo "<tr ID=\"light\">";
                            echo "<td class=\"products\">";
                            echo "  <div class=\"product\" onclick=\"detalles($id);\">";
                            echo "      <div class=\"product-thumbnail-container\">";
                            echo "          <img class=\"product-thumbnail\" src=\"$ruta_producto\" alt=\"Producto\">";
                            echo "      </div>";
                            echo "      <div class=\"product-text\">";
                            echo            $nombre;
                            echo "      </div>";
                            echo "      <div class=\"product-price\">";
                            echo            '$'.number_format($costo, 2);
                            echo "      </div>";
                            echo "      <div class=\"button-container\">";
                                            if($id_usuario  != "")
                                                echo "<input class=\"button\" id=\"product-button\" type=\"button\" value=\"Agregar\" onclick=\"add_carrito($id); event.stopPropagation();\">";
                                            else
                                                echo "<input class=\"button\" id=\"product-button\" type=\"button\" value=\"Agregar\" onclick=\"iniciarSesion(); event.stopPropagation();\">";
                            echo "          <input class=\"cantidad\" id=\"$id\" type=\"number\" name=\"cantidad\" value=\"1\" min=\"1\" max=\"$stock\" onclick=\"event.stopPropagation();\">";
                            echo "      </div>";
                            echo "  </div>";
                            echo "</td>";
                            if ($count % 3 == 0)
                                echo "</tr>";
                        }
                        if ($count % 3 != 0) {
                            $remain = 3 - ($count % 3);
                            for ($i = 0; $i < $remain; $i++) {
                                echo "<td></td>";
                            }
                            echo "</tr>";
                        }
                    ?>
                <tr>
                    <td class="bottom" id="dark"  colspan="6">
                </tr>
            </table>
        </div>
    </body>
</html>