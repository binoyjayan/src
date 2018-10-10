#!/usr/bin/perl

print "Enter two nos:\n";
chomp($first = <STDIN>);
chomp($second = <STDIN>);

if($first == $second)
{
	printf("Values are equal\n");
}
else
{
	print "Unequal values.\n";	
}

print "Enter a string:";
chomp($s=<STDIN>);

if($s eq "Binoy")
{
	print "Its me\n";
}
elsif($s eq "binoy") 
{
	print "Its me\n";
}
elsif($s eq "BINOY")
{
	print "Its me\n";
}
else
{
	print "Its not me\n";
}

