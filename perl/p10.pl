#!/usr/bin/perl

print "String Operations\n";
print "hello " x 5;
@a = 1 x 5;
print "\n";

print @a;


print "String Concatenation.\n";
print "Enter 1st string:";
chomp($s1=<STDIN>);
print "Enter 2nd string:";
chomp($s2=<STDIN>);
print "Concatenated string:". $s1. $s2;

print "\nString Comparison\n";

print "Enter 1st string:";
chomp($s1=<STDIN>);
print "Enter 2nd string:";
chomp($s2=<STDIN>);


if($s1 eq $s2)
{
	print "Strings are equal.";
}
else
{
	print "Strings are not equal.";
}

print "\n";



