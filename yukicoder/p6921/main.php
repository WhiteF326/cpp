<?php
fscanf(STDIN, "%s", $s);
$n = intval($s);
if ($n % 4 == 0){
  echo "Yes";
}else{
  echo "No";
}
