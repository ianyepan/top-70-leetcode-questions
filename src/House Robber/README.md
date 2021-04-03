# House Robber

## Question:

You are a professional robber planning to rob houses along a
street. Each house has a certain amount of money stashed, the only
constraint stopping you from robbing each of them is that adjacent
houses have security systems connected and it will automatically
contact the police if two adjacent houses were broken into on the same
night.

Given an integer array nums representing the amount of money of each
house, return the maximum amount of money you can rob tonight without
alerting the police.

## How to Solve:

Figure out recursive relation.

A robber has 2 options:
- rob current house i;
- don't rob current house.

If an option "a" is selected it means she can't rob previous i-1 house
but can safely proceed to the one before previous i-2 and gets all
cumulative loot that follows.

If an option "b" is selected the robber gets all the possible loot
from robbery of i-1 and all the following buildings.  So it boils down
to calculating what is more profitable:

- Robbery of current house + loot from houses before the previous
- Loot from the previous house robbery and any loot captured before
  that.

If we let `rob(k)` be the loot that we get from a cumulation up to
house k (, in which house k must be robbed). We have the following relation:

`rob(i) = max(rob(i - 2) + currentHouseValue, rob(k - 1))`
