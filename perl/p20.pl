#!/usr/bin/perl

#Demonstrating + quantifier matches 'car' 'caar', 'caaaaaar' etc but not 'cr'

#$str = "car";
#$str = "caar";
$str = "caaaaaar";

if($str =~ /ca+r/)
{
	print "Matched ca?r\n";
}
else
{
	print "No Match found for ca?r\n";
}

