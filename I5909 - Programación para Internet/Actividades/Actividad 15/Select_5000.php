<html>
    <head>
        <meta charset="UTF-8">
        <title>Filas dinámicas</title>
    </head>
    <body>
        <form method="post" action="tabla.php" name="forma01" id="">
            <select name="opciones" id="opciones">
                <option value="0">Selecciona</option>
                <?php
                    for($i = 1; $i <= 5000; $i++)
                        echo "<option value=$i>$i</option>";
                ?>
            </select><br>
            <input onclick="if(document.forma01.opciones.value == 0){ alert('Seleccione un valor válido'); return false;}" type="submit" value="Enviar" />
        </form>
    </body>
</html> 