#!/usr/bin/perl

#Demonstrating Regular expression handling
$str = "Perl is absolutely Practical Everything Really Likable\n";


#'m' Match an expression

if($str =~ m/really/i)
{
	print "Matched..!!!\n";
}
else
{
	print "Sorry.. No match found...!\n";
}

#'m' is implied here. It need not be specified explicitly
print $str =~ /absolutely/i ? "Matched..!!!\n" : "Sorry.. No match found...!\n";

#'s' Substitute
$n = $str =~ s/absolutely/surely/i;
print "String after replacement : $str\n";
print "No: of replacements : $n\n";

