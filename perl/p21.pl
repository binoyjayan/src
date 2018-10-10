#!/usr/bin/perl

#Demonstrating {m, n} 

$str = "coir";
$str = "caaar";
$str = "caaaaar";
$str = "caeaer";

#The pattern matches the above strings but not 'car', 'caaaaaar', caaaaaaar' etc
#The no: of characters b/w 'c' and 'r' should be in the range [2,5]

if($str =~ /c.{2,5}r/)
{
	print "Matched c{2,5}r\n";
}
else
{
	print "No match found for c{2,5}r\n";
}

