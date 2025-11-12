<html>
    <head>
        <meta charset="UTF-8">
        <title>Tabla</title>
    </head>
    <body>
        <table border="1" width="100">
            <?php
                $filas = $_POST['opciones'];
                for($i = 1; $i <= $filas; $i++)
                    echo "<tr><td font=".'"25"'.">$i</td></tr>";
            ?>
        </table>
    </body>
</html>