#!/usr/bin/perl

#Demonstrating ? quantifier. 'car' and 'cr' is matched here

$str = "car";
$str = "cr";

if($str =~ /ca?r/)
{
	print "Matched ca?r\n";
}
else
{
	print "No Match found for ca?r\n";
}

