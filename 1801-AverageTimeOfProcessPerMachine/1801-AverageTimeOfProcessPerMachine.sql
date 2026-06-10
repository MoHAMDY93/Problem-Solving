-- Last updated: 6/10/2026, 7:19:57 PM
-- Write your PostgreSQL query statement below
SELECT m.machine_id , ROUND(
    (AVG(CASE WHEN m.activity_type = 'end' THEN m.timestamp::numeric END) -
    AVG(CASE WHEN m.activity_type = 'start' THEN m.timestamp::numeric END)) , 
    3
) AS processing_time
FROM Activity m
GROUP BY m.machine_id; 