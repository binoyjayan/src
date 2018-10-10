

@echo off

if "%1" =="perl" goto here
echo "Manual page not available"

if "%1" =="" goto end

:here

iexplore "C:\Perl\html\index.html"

:end

echo on