-- Last updated: 6/10/2026, 7:24:21 PM
select requester_id id,( select count(*)
                        from RequestAccepted
                        where id= requester_id or
                        id = accepter_id ) as num
From RequestAccepted
group by requester_id
 
UNION
select accepter_id id, ( select count(*)
                        from RequestAccepted
                        where id= requester_id or
                        id = accepter_id ) as num
From RequestAccepted
group by accepter_id
 
order by num Desc
limit 1