-- Last updated: 6/10/2026, 7:18:44 PM
SELECT e.employee_id 
FROM Employees e 
WHERE e.salary < 30000
AND e.manager_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY e.employee_id