-- Last updated: 6/10/2026, 7:26:04 PM
-- Write your PostgreSQL query statement below
SELECT e.name As Employee FROM Employee e
JOIN Employee m
ON e.managerId = m.id
WHERE e.salary > m.salary;