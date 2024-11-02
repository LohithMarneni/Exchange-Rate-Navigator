# Q) why we are taking set giving max exchange rate instead min value?
A: In this exchange rate problem, the goal is to maximize the product of exchange rates along a path from a source currency to a target currency.
each conversion rate is a "multiplicative gain" rather than an additive cost.
# Goal Of Maximization:
In a typical currency conversion, you start with a certain amount of one currency (say USD) and want to maximize the equivalent amount in another currency (say INR).
Each exchange rate between two currencies represents a multiplicative gain. This means that if you start with $1, each step in your path multiplies this amount by a rate.
To maximize the final amount you end up with, you need to maximize the product of exchange rates along the path from the source currency to the destination currency.
# Multiplicative Nature of Exchange Rates:
Suppose you have a path like USD -> EUR -> JPY -> INR, where each conversion multiplies your money by a specific rate.
If you convert USD to EUR at 0.9, and then EUR to JPY at 130.02, and finally JPY to INR at 0.67, your final amount is a product of these rates:
1×0.9×130.02×0.67=78.71286
So, the overall amount in INR after these conversions depends on the product of rates along the path. The larger this product, the better the final outcome.
# Maximizing Each Step:
At each conversion step, you want to choose the rate or path that maximizes your current product. This way, by the time you reach your destination currency, you’ve accumulated the highest possible amount.
In contrast, if you chose paths with lower rates, you’d end up with less money by the time you finish the conversions.
# why not minimize
Minimizing only makes sense in scenarios where you’re reducing a cost, distance, or time. In the case of currency conversion, there’s no cost to minimize; rather, you’re aiming to maximize your return in the target currency. This is why you maximize the rate at each step rather than minimize it.