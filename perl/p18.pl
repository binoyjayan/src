#!/usr/bin/perl

#Demonstrating Quantifiers
$str = "perrrrrrl\n";
print $str =~ /per*l/ ? "Match\n" : "No Match\n";


$str="Remesh";
#The following will match 'Ramesh' 'Remesh' 'Rimesh' 'Romesh' 'Rumesh'

if($str =~ /r.mesh/i)
{
	print "R.mesh Matched\n";
}
else
{
	print "No match found for R.mesh\n";
}

#Combination of . and *


$str = "abracadabra";
#$str = "zeebra";

if($str =~ ".*bra")
{
	print "Matched '.*bra'\n";
}
else
{
	print "No match found for .*bra\n";
}

