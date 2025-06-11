# Write your MySQL query statement below
select c.contest_id, round(count(c.user_id)*100/(select count(user_id) from users),2) percentage
from users u join register c
on u.user_id = c.user_id
group by c.contest_id
order by percentage desc, c.contest_id
