#!/usr/bin/perl

#Read from file

print "Enter file name:";
chomp($ff=<STDIN>);
print "Enter no of characters to read:";
chomp($n=<STDIN>);

if(open(FILE, $ff) != NULL)
{
	$x = read(FILE, $str, $n);#read n characters
	close(FILE);
	print $str;
	print "\nRead $n characters\n";
}
else
{
	print "Could not open file : $ff\n";
}
print "\n";
