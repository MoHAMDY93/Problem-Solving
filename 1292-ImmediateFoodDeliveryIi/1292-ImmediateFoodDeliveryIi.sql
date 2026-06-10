-- Last updated: 6/10/2026, 7:22:04 PM
-- Write your PostgreSQL query statement below
SELECT ROUND(100.0 * COUNT(CASE WHEN (SELECT MIN(order_date) FROM Delivery b WHERE b.customer_id = d.customer_id) 
= customer_pref_delivery_date THEN 1 END) / (SELECT COUNT(DISTINCT customer_id) FROM Delivery) , 2) AS immediate_percentage
FROM Delivery d;