-- Last updated: 6/10/2026, 7:22:21 PM
SELECT
  ROUND(
    COUNT(DISTINCT A1.player_id)::numeric
    / (SELECT COUNT(DISTINCT A3.player_id) FROM Activity A3)::numeric
  , 2) AS fraction
FROM Activity A1
WHERE
  (A1.player_id, A1.event_date - INTERVAL '1 day') IN (
    SELECT
      A2.player_id,
      MIN(A2.event_date)
    FROM Activity A2
    GROUP BY A2.player_id
  );
