# Write your MySQL query statement below


-- Left Join from Person Table to Address Table
SELECT 
    P.firstName, P.lastName, A.city, A.state  -- Columns We Needed
    FROM Person AS P LEFT JOIN Address AS A   -- Left join Syntax
    ON P.personId = A.personId;               -- Condition