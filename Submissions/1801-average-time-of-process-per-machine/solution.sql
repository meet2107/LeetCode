# Write your MySQL query statement below
select m.machine_id, round(avg(a.timestamp - m.timestamp),3) as processing_time 
from activity m join activity a 
on m.machine_id = a.machine_id 
and m.process_id = a.process_id 
and m.activity_type = 'start' 
and a.activity_type = 'end' 
group by m.machine_id
