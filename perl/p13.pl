#!/usr/bin/perl

$count=1;
my $x=1;
&display;	#calling 'display' defined later (forward refernce)

sub display
{
	my $x = 10;
	print "Inside 'display' function. count = $count\n";
	print "local x = $x\n";
	$count++;
}

print "Global x = $x\n";

display;	#calling 'display' already defined



