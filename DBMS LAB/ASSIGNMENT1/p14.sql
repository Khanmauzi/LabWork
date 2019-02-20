select salespersonnumber,sum(quantity)
from sales
group by salespersonnumber
order by salespersonnumber;