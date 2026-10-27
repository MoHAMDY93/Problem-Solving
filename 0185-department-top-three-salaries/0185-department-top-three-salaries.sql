-- Write your PostgreSQL query statement below
-- for each department return the three highest distinct salaries, 
-- Then select the employees whose salary in the top 3 salaries of this employee's department
WITH RankedSalaries AS (
    SELECT 
        e.departmentId,
        e.name,
        e.salary,
        DENSE_RANK() OVER (
            PARTITION BY e.departmentId 
            ORDER BY e.salary DESC
        ) AS rnk
    FROM Employee e
)
SELECT d.name AS Department, r.name AS Employee , salary AS Salary
FROM RankedSalaries r
JOIN Department d ON r.departmentId = d.id
WHERE rnk <= 3
ORDER BY departmentId, rnk;