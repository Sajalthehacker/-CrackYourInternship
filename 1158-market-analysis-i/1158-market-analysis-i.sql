# Write your MySQL query statement below

# https://leetcode.com/problems/market-analysis-i/discuss/2319471/Simple-In-Depth-explanation-of-WHERE-and-IS-NULL!!


SELECT 
    u.user_id as buyer_id, 
    u.join_date, 
    count(o.order_id) as 'orders_in_2019'
FROM users u
LEFT JOIN Orders o
ON o.buyer_id=u.user_id AND YEAR(order_date) = 2019
GROUP BY u.user_id 