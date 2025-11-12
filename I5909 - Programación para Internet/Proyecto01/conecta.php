<?php
    define("HOST",'localhost');
    define("BD",'if0_37623148_cliente01');
    define("USER_BD",'if0_37623148');
    define("PASS_BD",'OWAgZyFKkMTEB4');
    function conecta(){
        $con = new mysqli(HOST, USER_BD, PASS_BD, BD);
        return $con;
    }
?>