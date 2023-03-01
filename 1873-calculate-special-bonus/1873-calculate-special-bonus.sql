# Write your MySQL query statement below

SELECT employee_id, salary AS bonus FROM Employees 
    WHERE name NOT LIKE "M%" AND MOD(employee_id, 2) <> 0

UNION

SELECT employee_id, 0 AS bonus FROM Employees 
    WHERE name LIKE "M%" OR MOD(employee_id, 2) = 0
    
ORDER BY employee_id;