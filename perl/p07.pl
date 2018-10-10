#!/usr/bin/perl

#Scalar Variables

print("Enter your name:");
$username = <STDIN>;
chomp($username);#To remove trailing newline
print("Enter your age:");
chomp($age=<STDIN>);

print("Thank you, $username.\n");
if($age >17)
{
	print("Congrats..!!! You are an adult. Your age is $age.\n");
}
else
{
	print("Oh! Buddy.. you are still a kiddie....!!!\n");
}

$age = $age + 1;
print("Next year you'll be $age years.\n");



