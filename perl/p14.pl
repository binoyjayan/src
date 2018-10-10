#!/usr/bin/perl

$n = 0;
for($i=0;$i<$n;$i++)
{
	print "$i\n";
}


$a = 10;
$b = $a >> 1;
printf "a(10)   >> 1 = %d\n", $b;

$a = -10;
$b = $a >>> 1;

# >>> operator is not working

#printf "a(-10) >>> 1 = %d\n", $b;


