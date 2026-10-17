-- Write your PostgreSQL query statement below
-- Determine the current price of the sold unit, then add this to the sum
SELECT
    p.product_id,
    COALESCE(
        ROUND(SUM(p.price * u.units)::numeric / NULLIF(SUM(u.units), 0) , 2),
        0
    ) AS average_price
From Prices p
LEFT JOIN UnitsSold u
ON p.product_id = u.product_id AND u.purchase_date BETWEEN p.start_date AND p.end_date
GROUP BY p.product_id;