select salespersonnumber,sum(quantity)
from sales
where salespersonnumber>=150
group by salespersonnumber
order by salespersonnumber;