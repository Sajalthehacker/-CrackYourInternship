# Write your MySQL query statement below

SELECT U.name , SUM(T.amount) as balance
FROM Users AS U , Transactions AS T
WHERE T.account = U.account
GROUP BY T.account
HAVING balance > 10000;