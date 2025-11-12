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
        <title>Edición de Producto</title>
        <?php
            require "../../Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM productos
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $codigo = $row["codigo"];
                $descripcion = $row["descripcion"];
                $costo = $row["costo"];
                $stock = $row["stock"];
                $archivo = $row["archivo"];
                $ruta_archivo = "Archivos/Fotos/$archivo";
                $timestamp = time();
                $url_imagen = $ruta_archivo . "?v=" . $timestamp;
            }
        ?>
    </head>
    <link href="../../css/style.css" type="text/css" rel="stylesheet">
    <script src="../../js/jquery-3.3.1.min.js"></script>
    <script>
        var codigoValido = true;
        function validarCodigo() {
            var codigoInput = $('#codigo');
            var codigo = codigoInput.val();
            <?php
                echo "if(codigo == '".$codigo."'){return false;}";
            ?>
            $.ajax({
                url: 'Funciones/validar_codigo.php',
                method: 'POST',
                data: { codigo: codigo },
                success: function(res) {
                    if (res == 1){
                        $('#codigo-error').text('El código ya existe').show();
                        setTimeout(function() {
                            $('#codigo-error').hide();
                        }, 5000);
                        codigoValido = false;
                        return false;
                    }
                    else{
                        $('#codigo-error').text('');
                        codigoValido = true;
                    }
                }
            });
        }
        function validarFormulario() {
            var nombre = $('#nombre').val();
            var codigo = $('#codigo').val();
            var descripcion = $('#descripcion').val();
            var costo = $('#costo').val();
            var stock = $('#stock').val();
            if (nombre == "" || codigo == "" || descripcion == "" || costo == "" || stock == "" || codigoValido == false) {
                $('#mensaje-error').text('Faltan Campos por Llenar').show();
                if(nombre != "" && codigo != "" && descripcion != "" && costo != "" && stock == "" && correoValido == false)
                    $('#mensaje-error').text('Código inválido').show();
                setTimeout(function() {
                    $('#mensaje-error').hide();
                }, 5000);
                return false;
            }
        }
        function preview(event) {
        var input = event.target;
        var reader = new FileReader();
        reader.onload = function() {
            var previewImage = document.getElementById('preview-image');
            previewImage.src = reader.result;
        };
        reader.readAsDataURL(input.files[0]);
        }
        function atras(){
            window.location.href = 'productos_lista.php';
        }
    </script>
    <body>
    <?php
        echo "<form name=\"form\" action=\"productos_sobreescribe.php?id=' + $id\" method=\"POST\" enctype=\"multipart/form-data\">";
    ?>
            <div>
                <table>
                    <tr>
                        <td class="title" colspan="2">Edición de Producto</td> 
                    </tr>
                    <?php include('../Funciones/menu.php'); ?>
                    <tr>
                        <td id="photo" class="first" width="500" rowspan="5">
                            <label for="archivo">
                                <div class="image-container">
                                    <?php
                                        if(!is_file("archivos/fotos/$archivo"))
                                            echo "<img class=\"preview\" id=\"preview-image\" src=\"../../css/icons/light_default.png\" alt=\"Banner\">";
                                        else{
                                            echo "<div class=\"product-image-container\">";
                                            echo "  <img class=\"product-image\" id=\"preview-image\" src=\"$url_imagen\" alt=\"Producto\">";
                                            echo "</div>";
                                        }
                                    ?>
                                </div>
                            </label>
                            <input id="archivo" type="file" name="archivo" accept="image/*" onchange="preview(event)">
                        </td>
                        <td class="first">Nombre:<br>
                            <?php
                                echo "<input type=\"text\" name=\"nombre\" placeholder=\"Nombre\" value=\"$nombre\">"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Código:<br>
                            <?php
                                echo "<input type=\"text\" name=\"codigo\" id=\"codigo\" placeholder=\"Código\" value=\"$codigo\" onblur=\"validarCodigo()\">"
                            ?>
                            <div id="codigo-error" class="message"></div>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Descripción:<br>
                            <?php
                                echo "<input type=\"text\" name=\"descripcion\" placeholder=\"Descripción\" value=\"$descripcion\">"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Costo:<br>
                            <?php
                                echo "<input type=\"text\" name=\"costo\" placeholder=\"Costo\" value=\"$costo\">"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Stock:<br>
                            <?php
                                echo "<input type=\"text\" name=\"stock\" placeholder=\"Stock\" value=\"$stock\">"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom" colspan="2">
                            <input class="button" type="submit" value="Guardar" onclick="return validarFormulario();">
                            <input class="button" type="reset" value="Regresar" onclick="atras();">
                            <div class="message" id="mensaje-error"></div>
                        </td>
                    </tr>
                </table>
            </div>
        </form>
    </body>
</html>