<?php
class S {
  public $a = 0;
  public $b = 1;
}

function foo($s) {
  for ($t = 0; $t < 100; ++$t) {
    $s->a = 1;
    $s->b = 2;
  }
  var_dump($s);
}

function main() {
  $s = new S;
  foo($s);
}

main();
