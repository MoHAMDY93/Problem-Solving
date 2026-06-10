-- Last updated: 6/10/2026, 7:24:16 PM
-- Write your PostgreSQL query statement below
SELECT * FROM Cinema
WHERE id % 2 <> 0 AND description != 'boring'
ORDER BY rating DESC;