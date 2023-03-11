# Write your MySQL query statement below

SELECT P1.name AS Employee
FROM Employee AS P1, Employee AS P2
WHERE 
    P1.managerId = P2.id AND
    P1.salary > P2.salary;