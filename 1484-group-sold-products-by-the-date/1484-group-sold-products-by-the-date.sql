# Write your MySQL query statement below

# GROUPCONCAT(DISTINCT <what to cncatenate> ORDER BY <> SEPERATOR <in between concts>)  Agg fn. used for concatenating group

SELECT sell_date, 
    COUNT(DISTINCT product) AS num_sold,
    GROUP_CONCAT(DISTINCT product ORDER BY product SEPARATOR ',') AS products  
FROM Activities GROUP BY sell_date ORDER BY sell_date;