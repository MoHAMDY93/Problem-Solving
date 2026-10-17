-- Write your PostgreSQL query statement below
SELECT r.contest_id, ROUND(100.0 * COUNT(*) / (SELECT COUNT(*) FROM Users) , 2) AS percentage
FROM Users u
JOIN Register r ON u.user_id = r.user_id
GROUP BY r.contest_id
ORDER BY percentage DESC, r.contest_id ASC;