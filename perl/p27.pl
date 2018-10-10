#!/usr/bin/perl

print "Enter a directory name:";
chomp($d=<STDIN>);
if(opendir(DIR, $d) != NULL)
{
	while($f=readdir(DIR))
	{
		print "$f\n";
	}
	closedir(DIR);
}
else
{
	print "Could not open directory\n";
}
