use strict;
use warnings;

my $line = <STDIN> + 0;
if($line % 4 == 0){
  print "Yes\n";
}else{
  print "No\n";
}