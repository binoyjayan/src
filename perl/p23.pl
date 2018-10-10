#!/usr/bin/perl

#Display file contents

print "Enter file name:";
chomp($ff=<STDIN>);

if(open(FILE, $ff) != NULL)
{
	$f=<FILE>;
	while($f ne "")
	{
		print "$f";
		$f=<FILE>;
	}
	close(FILE);
}
else
{
	print "Could not open file : $ff\n";
}
print "\n";
