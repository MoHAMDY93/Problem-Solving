-- Last updated: 6/10/2026, 7:21:52 PM
-- Write your PostgreSQL query statement below
SELECT q.query_name , 
ROUND((SUM(1.0 * q.rating / q.position)) / COUNT(*) , 2) AS quality, 
ROUND(SUM(CASE WHEN q.rating < 3 THEN 100.0 ELSE 0 END) / COUNT(*) , 2) AS poor_query_percentage
FROM Queries q
GROUP BY q.query_name;