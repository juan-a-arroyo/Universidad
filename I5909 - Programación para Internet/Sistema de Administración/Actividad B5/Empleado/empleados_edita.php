<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Edición de Empleados</title>
        <?php
            require "funciones/conecta.php";
            $con = conecta();
            $id = $_REQUEST['id'];
            $sql = "SELECT * FROM empleados
                    WHERE id = $id";
            $res = $con->query($sql);
            while($row = $res->fetch_array()){
                $id = $row["id"];
                $nombre = $row["nombre"];
                $apellido = $row["apellidos"];
                $correo = $row["correo"];
                $rol = $row["rol"];
                $status = $row["status"];
            }
        ?>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
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
                if (nombre == "" || apellidos == "" || correo == "" || rol == "" || correoValido == false) {
                    $('#mensaje-error').text('Faltan Campos por Llenar').show();
                    if(nombre != "" && apellidos != "" && correo != "" && rol != "" && correoValido == false)
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
    </script>
    <body>
    <?php
        echo "<form name=\"form\" action=\"empleados_cambios.php?id=' + $id\" method=\"POST\" novalidate>";
    ?>
            <div>
                <table>
                    <tr>
                        <td class="title">EDICIÓN DE EMPLEADOS</td> 
                    </tr>
                    <tr>
                        <td class="first">Nombre:<br>
                            <?php
                                echo "<input type=\"text\" name=\"nombre\" placeholder=\"Nombre\" value=\"$nombre\" required>"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Apellidos:<br>
                            <?php
                                echo "<input type=\"text\" name=\"apellidos\" placeholder=\"Apellidos\" value=\"$apellido\" required>"
                            ?>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Correo electrónico:<br>
                            <?php
                                echo "<input type=\"email\" name=\"correo\" id=\"correo\" placeholder=\"usuario@mail.com\" value=\"$correo\" required onblur=\"validarCorreo()\">"
                            ?>
                            <div id="correo-error" class="message"></div>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Contraseña:<br>
                            <input type="password" name="pass" placeholder="Contraseña (Sin cambios)" required>
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
                        <td class="bottom">
                            <input class="button" type="submit" value="Guardar" onclick="return validarFormulario();">
                            <input class="button" type="reset" value="Regresar al Listado" onclick="window.history.back(); return false;">
                            <div class="message" id="mensaje-error"></div>
                        </td>
                    </tr>
                </table>
            </div>
        </form>
    </body>
</html>