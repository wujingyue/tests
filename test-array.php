<?php
function main() {
  $n = 4;
  $arr = array();
  for ($i = 0; $i < $n; ++$i) {
    $arr[$i] = 0;
  }
  echo "initialized\n";

  for ($t = 0; $t < 100000000; ++$t) {
    for ($i = 0; $i < $n; ++$i) {
      $arr[$i] = $i;
    }
  }
  echo "set\n";

  for ($i = 0; $i < $n; ++$i)
    echo $arr[$i] . "\n";
  echo "get\n";
}

main();
