<?php

$connection = mysqli_connect("localhost", "root", "", "cossycafetaria");

$result = mysqli_query($connection, "SELECT sensor.id as sensor_id, location.x as x, location.y as y, readings.temperature as temperature, readings.airquality as airquality, readings.noiselevel as noiselevel, readings.infraredreading as infraredreading FROM sensor JOIN location ON sensor.location_id = location.id JOIN readings ON sensor.id = readings.sensor_id");

$data = array();

while($row= mysqli_fetch_assoc($result)){
    $data[]= $row;
}

echo json_encode($data);

?>