-- Last updated: 6/10/2026, 7:18:53 PM
-- Write your PostgreSQL query statement below
-- Left Join the signups with the Confirmations so we get all the users even if they didn't recieve any msgs
-- Then group by the user_id and Count all c.actions, and c.actions where action = confirmed
SELECT s.user_id, ROUND(SUM(CASE WHEN c.action = 'confirmed' THEN 1 ELSE 0 END)*1.0 /  COUNT(*) , 2) AS confirmation_rate
FROM Signups s
LEFT JOIN Confirmations c 
USING(user_id)
GROUP BY s.user_id;