# Algorithms and Data structures

## Introduction:
1) Some of the mind bending competitive programming problems, for which you can actually find the solution(s) on GeeksForGeeks (url: https://www.geeksforgeeks.org/), but this collection includes those problems which are NOT simply obvious.
2) Basic template for tree, trie and graph data structures included.
3) Standard Template Library (stl) has been used. 

## Programs: 
1) p1.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p1.cpp)
Problem: Count More than n/k Occurences.Given an array arr[] of size N and an element k. The task is to find all elements in array that appear more than n/k times. 
Time Complexity: O(nk)
Space Complexity: O(k)

=== Check out the solution, and contribute a real life scenario in which we can apply this solution ===

    Explanation: We cannot calculate and store occurance of every element because that leads to a space complexity O(n). 
    Let's take an analogy. Imagine a Leaderboard, which can show only top 5 entries (entries are not required to be sorted by the score, but they must be top 5). As a player "wins", it gets registered to Leaderboard.. 
    if there are less than 5 entries on the Leaderboard (insert) or
    if there is a player on Leaderboard who has 0 wins (replace).
    Else we decrement every players score on the Leaderboard.
    In the end, we will have top 5 players on the Leaderboard. 
    So, we count the number of toppers who won more than n/k times.
