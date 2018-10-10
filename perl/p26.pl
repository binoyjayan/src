#!/usr/bin/perl

#Print to file

print "Enter file to append:";
chomp($ff=<STDIN>);
print "Enter string to write : ";
chomp($str=<STDIN>);

$ff = ">>".$ff;

if(open(FILE, $ff) != NULL)
{
	print FILE $str;
	close(FILE);
}
else
{
	print "Could not open file : $ff\n";
}
print "\n";
