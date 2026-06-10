-- Last updated: 6/10/2026, 7:24:24 PM
-- Write your PostgreSQL query statement below
SELECT class 
FROM Courses
GROUP BY class
HAVING COUNT(*) > 4;