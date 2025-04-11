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

- improve code readability;
- decrease number of bugs; and
- improve reuse and portability.

From a business perspective, management and shareholders are going to be looking at

- decreasing time to market;
- decreasing development costs; and
- increasing product quality (at least I hope so).

The trick is to identify desired engineering results that also mesh with the results
management is looking for. If developers want to decrease bugs and rewrite modules,
while management is looking to decrease costs, the two are going to clash.

Developers
need to understand a business need or result first and then translate what can be done
at the engineering level to get that result while simultaneously achieving their own
desired goals.

### Desired Results: Decreasing Time to Market

Getting a product to market before
the competition can be a major advantage for a business, especially if a product is new.

### Desired Results: Decreasing Development Costs

Decreasing development costs may seem like something that a developer wouldn’t
necessarily care about. They are paid to design a successful product, not minimize costs.
However,the lower the costs are, the
more profitable the company is.

Decreasing development costs could be the difference between failing and being
able to successfully launch a new product, company, or widget that could benefit
millions or even billions of people.

There are many different things that can be done to decrease costs, such as buying a
professional debugger and good development tools. Spending money on the right tools
for the job can make a huge impact on total cost.

### Desired Results: Increased Quality

A product gets to market and is buggy or has terrible
performance, which then turns off users and requires marketing to perform damage
control. Quality is one of the elements that is critical to every embedded system and
sadly can be a major product differentiator.

There are several different strategies that developers can follow to increase their
firmware quality, such as:

- Adopt coding standards
- Utilize automated tests
- Perform static and dynamic code analysis
- Perform code reviews
- Follow industry best practices
- Implement a robust software development lifecycle plan

## Evaluating Where You Are