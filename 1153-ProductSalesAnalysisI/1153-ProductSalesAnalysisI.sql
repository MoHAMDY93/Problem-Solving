-- Last updated: 6/10/2026, 7:22:27 PM
-- Write your PostgreSQL query statement below
-- 1068 
SELECT p.product_name , s.year , s.price
FROM Sales s 
LEFT JOIN Product p ON(p.product_id = s.product_id);