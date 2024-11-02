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

Execution of example:
Initialized with source: USD having rate 1.0

Processing currency: USD with current rate: 1
  Checking edge to EUR with exchange rate 0.9, potential new rate: 0.9
    Updated EUR: dist = 0.9, parent = USD
  Checking edge to GBP with exchange rate 0.75, potential new rate: 0.75
    Updated GBP: dist = 0.75, parent = USD
  Checking edge to JPY with exchange rate 110.5, potential new rate: 110.5
    Updated JPY: dist = 110.5, parent = USD

Processing currency: JPY with current rate: 110.5
  Checking edge to INR with exchange rate 0.67, potential new rate: 74.035
    Updated INR: dist = 74.035, parent = JPY

Processing currency: INR with current rate: 74.035
  Checking edge to CAD with exchange rate 0.016, potential new rate: 1.18456
    Updated CAD: dist = 1.18456, parent = INR

Processing currency: CAD with current rate: 1.18456
  Checking edge to AUD with exchange rate 1.1, potential new rate: 1.30302
    Updated AUD: dist = 1.30302, parent = CAD

Processing currency: AUD with current rate: 1.30302
  Checking edge to USD with exchange rate 0.7, potential new rate: 0.912111

Processing currency: EUR with current rate: 0.9
  Checking edge to GBP with exchange rate 0.83, potential new rate: 0.747
  Checking edge to JPY with exchange rate 130.02, potential new rate: 117.018
    Removing outdated entry of JPY with rate 110.5 from set
    Updated JPY: dist = 117.018, parent = EUR

Processing currency: JPY with current rate: 117.018
  Checking edge to INR with exchange rate 0.67, potential new rate: 78.4021
    Removing outdated entry of INR with rate 74.035 from set
    Updated INR: dist = 78.4021, parent = JPY

Processing currency: INR with current rate: 78.4021
  Checking edge to CAD with exchange rate 0.016, potential new rate: 1.25443
    Removing outdated entry of CAD with rate 1.18456 from set
    Updated CAD: dist = 1.25443, parent = INR

Processing currency: CAD with current rate: 1.25443
  Checking edge to AUD with exchange rate 1.1, potential new rate: 1.37988
    Removing outdated entry of AUD with rate 1.30302 from set
    Updated AUD: dist = 1.37988, parent = CAD

Processing currency: AUD with current rate: 1.37988
  Checking edge to USD with exchange rate 0.7, potential new rate: 0.965913

Processing currency: GBP with current rate: 0.75
  Checking edge to INR with exchange rate 98.57, potential new rate: 73.9275

The best path from USD to EUR with exchange rate: 0.9
The best path from USD to EUR is: USD -> EUR

Final exchange rates for each currency:
JPY: 117.018
GBP: 0.75
AUD: 1.37988
CAD: 1.25443
EUR: 0.9
USD: 1
INR: 78.4021

