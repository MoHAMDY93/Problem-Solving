-- Last updated: 6/10/2026, 7:20:05 PM
-- Write your PostgreSQL query statement below
SELECT c.contest_id , ROUND(((100.0 * COUNT(*)) / (SELECT COUNT(*) FROM Users)) , 2) AS percentage 
FROM Register c
LEFT JOIN Users u ON c.user_id = u.user_id
GROUP BY(c.contest_id)
ORDER BY percentage DESC, c.contest_id ASC;