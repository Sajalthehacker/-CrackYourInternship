# Write your MySQL query statement below

# if(p_id == NULL) it is root node
# else if not present in p_id column then leaf
# else inner

SELECT id, 
    CASE
        WHEN p_id IS NULL THEN "Root"
        WHEN id NOT IN (SELECT p_id FROM Tree WHERE p_id IS NOT NULL) THEN "Leaf"
        ELSE "Inner"
    END AS type
FROM Tree;
