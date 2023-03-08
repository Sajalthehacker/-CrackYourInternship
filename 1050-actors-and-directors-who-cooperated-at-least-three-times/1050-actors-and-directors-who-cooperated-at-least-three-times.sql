# Write your MySQL query statement below

# WHERE cannot be used in the aggregator function
# So HAVING can be used in place of WHERE


SELECT 
    actor_id, 
    director_id
FROM ActorDirector
GROUP BY actor_id, director_id
HAVING COUNT(director_id) >= 3;