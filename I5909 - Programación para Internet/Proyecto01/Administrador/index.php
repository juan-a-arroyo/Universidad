<?php
    session_start();
    if(isset($_SESSION['idU']) && isset($_SESSION['nombre']) && isset($_SESSION['correo']))
        header("Location: bienvenido.php");
?>
<!doctype html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Iniciar Sesión</title>
    </head>
    <link href="../css/style.css" type="text/css" rel="stylesheet">
    <script src="../js/jquery-3.3.1.min.js"></script>
    <script>
        function autentificar() {
            var usuarioInput = $('#usuario');
            var passInput = $('#pass');
            var user = usuarioInput.val();
            var pass = passInput.val();
            if(user != "" && pass != ""){
                $.ajax({
                    url: 'Empleado/Funciones/valida.php?user='+user+'&pass='+pass,
                    method: 'POST',
                    success: function(res) {
                        if (res == 1){
                            window.location.href = 'bienvenido.php';
                        }
                        else {
                            $('#user-error').text('Usuario o contraseña inválidos').show();
                            setTimeout(function() {
                                $('#user-error').hide();
                            }, 5000);
                        }
                    }
                });
            }
            else{
                $('#user-error').text('Introduzca un usuario y una contraseña').show();
                setTimeout(function() {
                    $('#user-error').hide();
                }, 5000);
            }
        }
    </script>
    <body>
        <div>
            <table>
                <tr>
                    <td class="title">Iniciar Sesión</td>
                </tr>
                <tr>
                    <td class="first">Usuario:
                        <input type="text" name="usuario" id="usuario" placeholder="admin@mail.com" required>
                    </td>
                </tr>
                <tr>
                    <td class="first">Contraseña:
                        <input type="password" name="pass" id="pass" placeholder="Contraseña" required>
                    </td>
                </tr>
                <tr>
                    <td class="bottom">
                        <input class="button" type="submit" value="Iniciar Sesión" onclick="return autentificar();">
                        <div id="user-error" class="message"></div>
                    </td>
                </tr>
            </table>
        </div>
        <script>
            function handleEnterKeyPress(event) {
                if (event.keyCode === 13) {
                    event.preventDefault();
                    var inputs = document.querySelectorAll("input");
                    var index = Array.prototype.indexOf.call(inputs, event.target);
                    if (index < inputs.length - 1) {
                        inputs[index + 1].focus();
                    } else {
                        autentificar();
                    }
                }
            }
            var formInputs = document.querySelectorAll("input");
            formInputs.forEach(function(input) {
                input.addEventListener('keydown', handleEnterKeyPress);
            });
        </script>
    </body>
</html>