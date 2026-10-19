-- Write your PostgreSQL query statement below
SELECT 
    TO_CHAR(trans_date, 'YYYY-MM') AS month, 
    country, 
    COUNT(*) AS trans_count,
    COUNT(*) FILTER(WHERE t.state = 'approved') AS approved_count,
    COALESCE(SUM(amount), 0) AS trans_total_amount,
    COALESCE(SUM(amount) FILTER(WHERE t.state = 'approved'), 0) AS approved_total_amount
FROM Transactions t
GROUP BY country, month;