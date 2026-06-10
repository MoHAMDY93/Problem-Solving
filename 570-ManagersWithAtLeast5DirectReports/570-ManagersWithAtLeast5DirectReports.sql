-- Last updated: 6/10/2026, 7:24:36 PM
-- Write your PostgreSQL query statement below
SELECT m.name
FROM Employee e
JOIN Employee m ON(m.id = e.managerId)
GROUP BY m.name, m.id
HAVING(COUNT(m.id) >= 5);