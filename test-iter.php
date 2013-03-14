<?php

function main() {
  $a = array(1, 2, 3);
  foreach ($a as $b) {
    echo $b . "\n";
    array_push($a, $b);
  }
  echo "length = " . count($a) . "\n";
}

main();
