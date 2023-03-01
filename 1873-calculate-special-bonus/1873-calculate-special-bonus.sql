# Write your MySQL query statement below

# In this Approach we are doing unin of bonus 100% and bonus 0 tuples
# SELECT employee_id, salary AS bonus FROM Employees WHERE name NOT LIKE "M%" AND MOD(employee_id, 2) <> 0
# UNION
# SELECT employee_id, 0 AS bonus FROM Employees WHERE name LIKE "M%" OR MOD(employee_id, 2) = 0
# ORDER BY employee_id;


# Efiicient Apporach

SELECT employee_id, 
    (salary * MOD(employee_id, 2) * (name NOT LIKE "M%")) AS bonus -- if e_id is even or name is not M% salary is *0;
FROM Employees ORDER BY employee_id; 