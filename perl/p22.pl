#!/usr/bin/perl

#Demonstrating '$' positional character
#Matching strings ending with 'car'

#$str = "blue car";
#$str = "chaircar";
$str = "scar";
if($str =~ /car$/)
{
	print 'Matched car$ (at the end of the string)'."\n";
}
else
{
	print 'No match found for car$' . "\n";
}


#The ^ positional character
#Matching strings starting with 'car'

$str = "cartoon";
$str = "carrot";
$str = "carpet";

if($str =~ /^car/)
{
        print 'Matched ^car (at the beginning of the string)'."\n";
}
else
{
        print 'No match found for ^car.'. "\n";
}

#Combination of the above two
#Matching string starting with 'this' and ending with 'car' with any no: of characters in between

#$str = "This car";
#$str = "This is a car";
$str = "This is Tom's car";


if($str =~ /^this.*car$/i)
{
        print 'Matched ^this.*car$/i'."\n";
}
else
{
        print 'No match found for ^this.*car$/i'. "\n";
}

