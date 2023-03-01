# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

# Refer to step wise solution

DELETE p1 FROM Person AS p1, Person AS p2 -- Join
    WHERE p1.email = p2.email AND p1.Id > p2.Id; 
