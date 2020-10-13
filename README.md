# Algorithms and Data structures

## Introduction:
1) Some of the mind bending programming problems, for which you can actually find the solution(s) on GeeksForGeeks (url: https://www.geeksforgeeks.org/), but this collection includes those problems which are NOT simply obvious.
2) Basic template for tree, trie and graph data structures included.
3) Standard Template Library (stl) has been used. 
4) You can contribute sample test cases for particular program below it.
5) Text written between two "==="s instructs about contribution. 
6) All of these programs are the standard programming interview questions.

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

Sample testcases: 

2) p2.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p2.cpp)
Problem: Generate valid parenthesis patterns. Given N numbers for opening brackets.

=== Check out the solution, and contribute a real life scenario in which we can apply this solution ===

    Explanation: The fundamental thought, which comes accross mind whenever creating valid parenthesis pattern on pen and paper is that, at any point of time, number of opening brackets "(" must be greater than or equal to number of closing brackets ")". 
    So, we add an "(" first. If count of ")" is less than "(", add a ")". To make sure this loop don't reiterate to itself in infinite loop, we have a cap on count of "(" which is... N.
    So, to keep track of every sub-pattern generated, we maintain a queue of struct {sub-pattern string, count of "(", count of ")"}.
    This will help us generating different patterns.

Sample testcases:     

3) p3.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p3.cpp) 
Template for Graph data structure added.

=== Contribute solutions for DFS, BFS, Topological sorting ===

Sample testcases: 

4) p4.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p4.cpp) 
Problem: Find largest length BST in given Binary tree.

=== Contribute REFACTORED CODE for this problem, give appropriate names to functions "returner" and "postorder". ===

    Explanation: Refer to this video by Sir Tushar Roy: https://youtu.be/4fiDs7CCxkc and contribute a text explanation

Sample testcases: 

5) p5.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p5.cpp)
Problem: Find median of two sorted arrays. 

=== Contribute text Explanation ===

    Explanation: Refer to this video by Sir Tushar Roy: https://youtu.be/4fiDs7CCxkc and contribute a text explanation

Sample testcases: 

6) p6.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p6.cpp) 
Problem: Smallest Positive missing number. You are given an array arr[] of N integers including 0. The task is to find the smallest positive number missing from the array.

=== Contribute Explanation ===

    Explanation: Hint: Combination of two basic problems.
    
Sample testcases: 

7) p7.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p7.cpp)
Problem: Solve Sudoku

=== Contribute Explanation ===

    Explanation: Hint: Backtracking
   
Sample testcases: 
 
8) p8.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p8.cpp) Problem: Implementation of Tree data structure and traversals.

=== Contribute Explanation for any of the remaining functions ===

    Explanation: Make sample test cases and dry run them on pen paper. 
    
Sample testcases: 

9) p9.cpp (url: https://github.com/OmPals/Algorithms-and-Data-structures/blob/main/p9.cpp)
Problem: Implemented Trie data structure

=== Contribute Explanation ===

    Explanation: Video explanation by Sir Tushar Roy: https://youtu.be/AXjmTQ8LEoI

Sample testcases: 
