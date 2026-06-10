-- Last updated: 6/10/2026, 7:21:06 PM
-- Write your PostgreSQL query statement below
SELECT u.unique_id, e.name
FROM Employees e 
LEFT JOIN EmployeeUNI u ON(e.id = u.id);