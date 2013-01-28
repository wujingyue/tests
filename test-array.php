<?php
$arr = array();
for ($i = 0; $i < 3; ++$i)
  $arr[$i] = $i;

unset($arr[0]);

for ($i = 0; $i < 3; ++$i)
  echo $arr[$i] . "\n";
