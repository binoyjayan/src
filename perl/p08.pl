#!/usr/bin/perl

#Introducing operators..

print("Enter a number:");
$a=<STDIN>;
chomp($a);
print("Enter one more:");
$b=<STDIN>;
chomp($b);

$sum =$a + $b;
$diff = $a-$b;
$pro=$a*$b;
$quo=$a/$b;
@rem=$a % $b;
$p=$a**$b;
print "Sum = $sum\n";
print "Difference = $diff\n";
print "Product = $pro\n";
print "Quotient = $quo\n";
print "Remainder = $rem\n";
print "Raised to power=$p\n";

$a = $b++;

print 'Performing $a = $b++';
print "\nNow, a = $a b= $b\n";


