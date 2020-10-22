@echo off
date < cr.txt > results_release.txt
time < cr.txt >> results_release.txt

echo about 2 minutes, please wait ...
Sorts >> results_release.txt
time < cr.txt >> results_release.txt

echo another 2 minutes, please wait again ...
Sorts >> results_release.txt
time < cr.txt >> results_release.txt
