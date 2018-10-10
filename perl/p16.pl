#!/usr/bin/perl

#Normal Array

@arr = ("jsree", "17-12-85", "shami", "07-04-86", "bins", "28-08-84");

print "Array Elements:\n";

foreach $s(@arr)
{
        print "$s\n";
}

print "\n\n";

$n = @arr;
print "Array size = $n\n";



#Associative array(Hash)

%arr = ("jsree", "17-12-85", "shami", "07-04-86", "bins", "28-08-84");

print "DOB of 'jsree' = ". $arr{"jsree"}. "\n";

print "DOB of 'shami' = ". $arr{"shami"}. "\n";

print "DOB of 'bins'  = ". $arr{"bins"}. "\n";


