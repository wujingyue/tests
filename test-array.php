<?php
echo "started\n";
$arr = array();
echo "inited\n";
for ($i = 0; $i < 3; ++$i)
  $arr[$i] = $i;
for ($i = 0; $i < 3; ++$i)
  echo $arr[$i] . "\n";
