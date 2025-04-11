# 12. Pratical

The problem that many teams and
individual developers face is that they find themselves in an environment where doing
things the right way, whether it is through code reuse, automated tests, or any other
technique that we have been discussing, is just not possible. Developers could find
themselves in an environment where

- management doesn’t understand software development and has
unrealistic expectations;
- development timelines are short or impossible and the only option is
to crank out code;
- budgets and resources are scarce but the end results still need to be
delivered;
- upper management doesn’t care about quality, reuse, or even
accuracy as long as sales remain strong; and

## Phases and Baby Steps

First, it is important to recognize that reusability and portability in the long run
will help decrease the total cost of ownership. Second, given how chaotic firmware
development can be when developers don’t follow a strict process or best practices or
continually jump through management hoops, the chances are that building some reuse
into the code up front will still be cheaper and faster in the short term. The trick is to
not go overboard and overdesign the reuse, but rather to identify where the maximum
benefit will be and aim to achieve it.

Design a HAL with the expectation that it will need to be updated in future
releases. Create configuration tables so that drivers and application modules are easily
configurable rather than hard coded. Add enough flexibility so that at a later time the
software can be improved without bringing down a house of cards.

The
best results are achieved by focusing on one to three improvements until the desired
outcome has been achieved.

## Identifying Desired Results and Outcomes
