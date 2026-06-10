-- Last updated: 6/10/2026, 7:24:31 PM
-- Write your PostgreSQL query statement below
SELECT e.name , b.bonus
FROM Employee e
LEFT JOIN Bonus b ON(e.empId = b.empId)
WHERE b.bonus IS NULL OR b.bonus < 1000;
