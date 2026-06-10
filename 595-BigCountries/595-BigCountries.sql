-- Last updated: 6/10/2026, 7:24:28 PM
# Write your MySQL query statement below
SELECT w.name, w.population, w.area
FROM World w
WHERE w.population >= 25000000 OR w.area >= 3000000;