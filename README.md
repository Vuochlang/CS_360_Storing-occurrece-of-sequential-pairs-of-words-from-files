# CS 360 - Systems Programming

<h1> Assignment 1: Storing-occurrece-of-sequential-pairs-of-words-from-files </h1>

01/28/2021

<h2> Instruction: </h2>

<p>"Write a program (in C) targeted at the Linux platform which reads words from one or more files, and prints out a list
of the most frequently occurring sequential pairs of words and the number of times they occurred, in decreasing order of
occurrence."</p>

<h3> Program Interface (Required) </h3>

<p>wordpairs <-count> fileName1 <fileName2> <fileName3> ...</p>
<p>Where: 
    <ul>_count is the integer number of word pairs to print out 
    <ul>_ fileNameN are pathnames from which to read words 
    <ul>_ If no count argument is specified, ALL words pairs are printed to stdout
    <ul>_ (tokens enclosed in angular brackets are optional).
