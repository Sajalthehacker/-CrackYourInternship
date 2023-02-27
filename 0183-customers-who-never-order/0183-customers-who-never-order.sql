# Write your MySQL query statement below

# C.name AS Customers -> helps changing the header name in the OUTPUT

SELECT C.name AS Customers 
    FROM Customers AS C LEFT JOIN Orders AS O 
    ON C.id = O.customerId
    WHERE O.id IS NULL;