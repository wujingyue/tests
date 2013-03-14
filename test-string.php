<?php
function main() {
  $a = "";
  for ($i = 0; $i < 10000000; ++$i) {
    $a .= chr(ord('a') + rand(0, 25));
  }
};

main();
