-- Last updated: 6/10/2026, 7:24:27 PM
# Write your MySQL query statement below
SELECT name 
FROM Customer 
WHERE referee_id IS NULL OR referee_id != 2;