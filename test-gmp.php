<?php
function main() {
  $a = gmp_init(123);
  $b = gmp_init(456);
  $c = gmp_mul($a, $b);
  echo gmp_strval($c) . "\n";
}

main();
