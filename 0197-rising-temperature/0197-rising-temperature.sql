# Write your MySQL query statement below

# https://leetcode.com/problems/rising-temperature/discuss/1308831/Faster-oror-Easy

SELECT w1.id FROM Weather AS w1, Weather AS w2
WHERE w1.temperature > w2.temperature AND DATEDIFF(w1.recordDate, w2.recordDate) = 1;