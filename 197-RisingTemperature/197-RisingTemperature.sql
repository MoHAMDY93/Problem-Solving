-- Last updated: 6/10/2026, 7:25:54 PM
-- Write your PostgreSQL query statement below
SELECT w1.id
FROM Weather w1
JOIN Weather w2 ON(w2.recordDate = (w1.recordDate - 1))
WHERE w1.temperature > w2.temperature;