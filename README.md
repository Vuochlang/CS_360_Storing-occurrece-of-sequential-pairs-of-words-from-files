# CS 360 - Systems Programming

<h1> Assignment 1:  </h1>
<p> Storing-occurrece-of-sequential-pairs-of-words-from-files </p>

01/28/2021

<h2> Instruction: </h2>

<p>"Write a program (in C) targeted at the Linux platform which reads words from one or more files, and prints out a list
of the most frequently occurring sequential pairs of words and the number of times they occurred, in decreasing order of
occurrence."</p>

<h3> Program Interface (Required) </h3>

wordpairs <-count> fileName1 <fileName2> <fileName3> ...
    
Where: 
<ul>
    <li>count is the integer number of word pairs to print out</li>
    <li>fileNameN are pathnames from which to read words</li> 
    <li>If no count argument is specified, ALL words pairs are printed to stdout</li>
    <li>(tokens enclosed in angular brackets are optional).</li>
</ul>
