# Write your MySQL query statement below
select a.user_id, round(ifnull(avg(action = 'confirmed'),0),2) confirmation_rate from signups a left join confirmations c 
on a.user_id = c.user_id group by a.user_id
