<?php
#SELECT  sensor.id as sensor_id, location.x as x, location.y as y, readings.amgtemp as temperature, readings.co2_level as co2_level, readings.TVOC_level as TVOC_level, readings.audio as audio, readings.infraredreading as infraredreading FROM sensor JOIN location ON sensor.location_id = location.id JOIN readings ON sensor.id = readings.sensor_id where readings.date = (SELECT MAX(r2.date) FROM readings r2 WHERE sensor.id = r2.sensor_id)

$connection = mysqli_connect("localhost", "root", "root", "cosycafetaria");

$result = mysqli_query($connection, "SELECT sensor.id as sensor_id, location.x as x, location.y as y, readings.amgtemp as temperature, readings.co2_level as co2_level, readings.TVOC_level as TVOC_level, readings.audio as audio, readings.infraredreading as infraredreading FROM sensor JOIN location ON sensor.location_id = location.id JOIN readings ON sensor.id = readings.sensor_id where readings.date = (select max(r2.date) from readings r2 where sensor.id = r2.sensor_id)");

$data = array();

while($row= mysqli_fetch_assoc($result)){
    $data[]= $row;
}

echo json_encode($data);

?>