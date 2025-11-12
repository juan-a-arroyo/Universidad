<?php
    session_start();
    $idU = $_SESSION['idU'];
    $nombreU = $_SESSION['nombre'];
    $correoU = $_SESSION['correo'];
    $ruta_salir = "Funciones/salir.php";
    if($idU == "" || $nombreU == "" || $correoU == "")
        header("Location: $ruta_salir");
    $ruta_administradores = "administradores_lista.php";
    $ruta_productos = "../Productos/productos_lista.php";
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Edición de Administradores</title>
        <?php
            require "../Funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM administradores
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $apellido = $row["apellidos"];
                $correo = $row["correo"];
                $rol = $row["rol"];
                $status = $row["status"];
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
        var correoValido = true;
        function validarCorreo() {
            var correoInput = $('#correo');
            var correo = correoInput.val();
            <?php
                echo "if(correo == '".$correo."'){return false;}";
            ?>
            $.ajax({
                url: 'Funciones/validar_correo.php',
                method: 'POST',
                data: { correo: correo },
                success: function(res) {
                    if (res == 1){
                        $('#correo-error').text('El correo electrónico ya existe').show();
                        setTimeout(function() {
                            $('#correo-error').hide();
                        }, 5000);
                        correoValido = false;
                        return false;
                    }
                    else{
                        $('#correo-error').text('');
                        correoValido = true;
                    }
                }
            });
        }
        function validarFormulario() {
            var nombre = $('#nombre').val();
            var apellidos = $('#apellidos').val();
            var correo = $('#correo').val();
            var pass = $('#pass').val();
            var rol = $('#rol').val();
            if (nombre == "" || apellidos == "" || correo == "" || correoValido == false) {
                $('#mensaje-error').text('Faltan Campos por Llenar').show();
                if(nombre != "" && apellidos != "" && correo != "" && correoValido == false)
                    $('#mensaje-error').text('Correo electrónico inválido').show();
                setTimeout(function() {
                    $('#mensaje-error').hide();
                }, 5000);
                return false;
            }
        }
        window.onload = function() {
            var select = document.getElementById("rol");
            <?php
                echo "select.value = \"$rol\";"
            ?>
        };
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
            window.location.href = 'administradores_lista.php';
        }
    </script>
    <body>
    <?php
        echo "<form name=\"form\" action=\"administradores_sobreescribe.php?id=' + $id\" method=\"POST\" enctype=\"multipart/form-data\">";
    ?>
            <div>
                <table>
                    <tr>
                        <td class="title" colspan="2">EDICIÓN DE ADMINISTRADORES</td> 
                    </tr>
                    <?php include('../Funciones/menu.php'); ?>
                    <tr>
                        <td id="photo" class="first" width="500" rowspan="5">
                            <label for="archivo">
                                <div class="image-container">
                                    <?php
                                        if(!is_file("archivos/fotos/$archivo"))
                                            echo "<img class=\"preview\" id=\"preview-image\" src=\"../css/icons/default.png\" alt=\"Administrador\">";
                                        else
                                            echo "<img class=\"preview\" id=\"preview-image\" src=\"$url_imagen\" alt=\"Administrador\">";
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
                        <td class="first">Apellidos:<br>
                            <?php
                                echo "<input type=\"text\" name=\"apellidos\" placeholder=\"Apellidos\" value=\"$apellido\">"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Correo electrónico:<br>
                            <?php
                                echo "<input type=\"email\" name=\"correo\" id=\"correo\" placeholder=\"usuario@mail.com\" value=\"$correo\" onblur=\"validarCorreo()\">"
                            ?>
                            <div id="correo-error" class="message"></div>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Contraseña:<br>
                            <input type="password" name="pass" placeholder="Contraseña (Sin cambios)">
                        </td>
                    </tr>
                    <tr >
                        <td class="first">Rol:
                            <select class="select" name="rol" id="rol">
                                <option value="1">Gerente</option>
                                <option value="2">Ejecutivo</option>
                            </select>
                        </td>
                    </tr>
                    <tr>
                        <td class="bottom" colspan="2">
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