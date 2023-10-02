# Write your MySQL query statement below
select SUBSTR(trans_date,1,7) as month,
country,
count(*) as trans_count,
sum(state='approved') as approved_count,
sum(amount) as trans_total_amount,
sum(case when state='approved' then amount else 0 END) as
approved_total_amount
from transactions
group by month,country
