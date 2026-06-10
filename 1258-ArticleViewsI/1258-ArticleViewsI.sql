-- Last updated: 6/10/2026, 7:22:11 PM
# Write your MySQL query statement below
SELECT DISTINCT(author_id) AS id 
FROM Views
WHERE author_id = viewer_id
ORDER BY id ASC;