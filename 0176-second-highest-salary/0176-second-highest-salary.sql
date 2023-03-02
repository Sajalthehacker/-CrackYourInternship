# Write your MySQL query statement below

SELECT MAX(salary) as SecondHighestSalary FROM Employee 
    WHERE salary NOT IN (SELECT MAX(salary) FROm Employee);