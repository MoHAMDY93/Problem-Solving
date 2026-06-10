-- Last updated: 6/10/2026, 7:21:56 PM
-- Write your PostgreSQL query statement below

select 
    to_char(trans_date, 'YYYY-MM')                                  as month,
    country                                                         as country,
    count(*)                                                        as trans_count,
    count(*) filter (where state = 'approved')                      as approved_count,
    sum(amount)                                                     as trans_total_amount,
    COALESCE(sum(amount) filter (where state = 'approved') , 0)     as approved_total_amount
from transactions 
group by to_char(trans_date, 'YYYY-MM'), country
order by month, country