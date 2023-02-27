# Write your MySQL query statement below

# SELECT name FROM Customer  
#     WHERE referee_id IS NULL OR referee_id <> 2;  -- Can even use this

# In SQL : <>  means  not equals to
    
SELECT name FROM Customer
    WHERE IFNULL(referee_id, 0) <> 2; -- if referee_id is NULL it takes it as 0
