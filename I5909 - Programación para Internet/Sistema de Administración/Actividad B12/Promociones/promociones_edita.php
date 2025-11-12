<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "../Empleado/Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_empleados = "../Empleado/empleados_lista.php";
    $ruta_productos = "../Productos/productos_lista.php";
    $ruta_promociones = "promociones_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Edición de Promociones</title>
        <?php
            require "../Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM promociones
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $archivo = $row["archivo"];
                $ruta_archivo = "Archivos/Fotos/$archivo";
                $timestamp = time();
                $url_imagen = $ruta_archivo . "?v=" . $timestamp;
            }
        ?>
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        function validarFormulario() {
            var nombre = $('#nombre').val();
            if (nombre == "") {
                $('#mensaje-error').text('Faltan Campos por Llenar').show();
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
            window.location.href = 'promociones_lista.php';
        }
    </script>
    <body>
    <?php
        echo "<form name=\"form\" action=\"promociones_sobreescribe.php?id=' + $id\" method=\"POST\" enctype=\"multipart/form-data\">";
    ?>
            <div>
                <table>
                    <tr>
                        <td class="title">EDICIÓN DE PROMOCIONES</td> 
                    </tr>
                    <?php include('../Funciones/menu.php'); ?>
                    <tr>
                        <td class="first">Nombre:<br>
                            <?php
                                echo "<input id=\"nombre\" type=\"text\" name=\"nombre\" placeholder=\"Nombre\" value=\"$nombre\">"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td id="photo" class="first" width="500">
                            <label for="archivo">
                                <div class="image-container">
                                    <?php
                                        if(!is_file("Archivos/Fotos/$archivo"))
                                            echo "<img class=\"preview-banner\" id=\"preview-image\" src=\"../css/icons/wide_light_default.png\" alt=\"Banner\">";
                                        else
                                            echo "<img class=\"preview-banner\" id=\"preview-image\" src=\"$url_imagen\" alt=\"Banner\">";
                                    ?>
                                </div>
                            </label>
                            <input id="archivo" type="file" name="archivo" accept="image/*" onchange="preview(event)">
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom">
                            <input class="button" type="submit" value="Guardar" onclick="return validarFormulario();">
                            <input class="button" type="reset" value="Regresar al Listado" onclick="atras();">
                            <div class="message" id="mensaje-error"></div>
                        </td>
                    </tr>
                </table>
            </div>
        </form>
    </body>
</html>