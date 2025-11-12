<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Alta de Administradores</title>
    </head>
    <link href="css/style.css" type="text/css" rel="stylesheet">
    <script src="js/jquery-3.3.1.min.js"></script>
    <script>
        var correoValido = true;
        function validarCorreo() {
            var correoInput = $('#correo');
            var correo = correoInput.val();
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
                if (nombre == "" || apellidos == "" || correo == "" || pass == "" || rol == "" || correoValido == false) {
                    $('#mensaje-error').text('Faltan Campos por Llenar').show();
                    if(nombre != "" && apellidos != "" && correo != "" && pass != "" && rol != "" && correoValido == false)
                        $('#mensaje-error').text('Correo electrónico inválido').show();
                    setTimeout(function() {
                        $('#mensaje-error').hide();
                    }, 5000);
                    return false;
                }
            }
    </script>
    <body>
        <form name="form" action="administradores_salva.php" method="POST" novalidate>
            <div>
                <table>
                    <tr>
                        <td class="title">ALTA DE ADMINISTRADORES</td> 
                    </tr>
                    <tr>
                        <td class="first">Nombre:<br>
                            <input type="text" name="nombre" placeholder="Nombre" required>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Apellidos:<br>
                            <input type="text" name="apellidos" placeholder="Apellidos" required>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Correo electrónico:<br>
                            <input type="email" name="correo" id="correo" placeholder="usuario@mail.com" required onblur="validarCorreo()">
                            <div id="correo-error" class="message"></div>
                        </td>
                    </tr>
                    <tr>
                        <td class="first">Contraseña:<br>
                            <input type="password" name="pass" placeholder="Contraseña" required>
                        </td>
                    </tr>
                    <tr >
                        <td class="first">Rol:
                            <select class="select" name="rol">
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