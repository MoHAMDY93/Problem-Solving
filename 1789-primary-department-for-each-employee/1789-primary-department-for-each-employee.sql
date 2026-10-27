-- Write your PostgreSQL query statement below
WITH emp_cnt AS (
    SELECT employee_id, COUNT(employee_id) AS cnt
    FROM Employee
    GROUP BY employee_id
)
SELECT e.employee_id, e.department_id
FROM Employee e
JOIN emp_cnt c USING(employee_id)
WHERE c.cnt = 1 OR e.primary_flag = 'Y';