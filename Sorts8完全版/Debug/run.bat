@echo off
date < cr.txt > results_debug.txt
time < cr.txt >> results_debug.txt

echo about 4 minutes, please wait ...
Sorts >> results_debug.txt
time < cr.txt >> results_debug.txt

echo another 4 minutes, please wait again ...
Sorts >> results_debug.txt
time < cr.txt >> results_debug.txt
