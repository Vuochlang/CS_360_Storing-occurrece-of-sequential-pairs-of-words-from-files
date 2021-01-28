# CS 360 - Systems Programming

# Assignment 1: Storing-occurrece-of-sequential-pairs-of-words-from-files

01/28/2021

<h1> Instruction:

"Write a program (in C) targeted at the Linux platform which reads words from one or more files, and prints out a list
of the most frequently occurring sequential pairs of words and the number of times they occurred, in decreasing order of
occurrence."

<h2> Program Interface (Required)

wordpairs <-count> fileName1 <fileName2> <fileName3> ...
Where: 
    _count is the integer number of word pairs to print out
    _ fileNameN are pathnames from which to read words 
    _ If no count argument is specified, ALL words pairs are printed to stdout
    _ (tokens enclosed in angular brackets are optional).
