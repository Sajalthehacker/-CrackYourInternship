# Write your MySQL query statement below

# https://leetcode.com/problems/second-highest-salary/discuss/1168444/Summary-Five-ways-to-solve-the-top-n-nth-problems

SELECT MAX(salary) as SecondHighestSalary FROM Employee 
    WHERE salary NOT IN (SELECT MAX(salary) FROm Employee);