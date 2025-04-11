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

Once a developer has determined the results or the low-hanging fruit that they want to
go after first, they need to figure out how they are going to achieve that outcome. Before
going too far, it’s a good idea to quickly determine the status of the code

## Defining How to Get There

Being practical about reusable firmware really means that a developer doesn’t over-­
design and that they build in enough reuse for the job at hand. A formal process might be
the practical way to go, but in many instances just adapting on the fly might be the more
practical approach.

here is a safe balance
somewhere in the middle that allows developers to work very rapidly. That said, as
you move toward practical code reuse, you should still identify at least a few metrics by
which to track your progress.

## Getting the Most from Metrics

Metrics shouldn’t be something that are tracked just for the sake of tracking metrics.
A good metric will have several characteristics, including the following:

- Easily measurable
- Automatically trackable
- Meaningful

## Metrics Worth Tracking

Everybody loves metrics! Right? In general, while I believe engineers do like to have data
that they can use to track progress, most engineers find metric tracking to be a pain.
The development cycle is busy with engineers being pulled in every direction, yet they
are expected to be disciplined and stop occasionally to take measurements about the
development cycle. This can be a tough thing to do but is a necessary evil.

Any metric that is used needs to have meaning and
value if it is to serve any purpose to a team. Having a metric just to have it is not a good
use of engineers’ or managers’ time.

Each component should track several different metrics, which include the following:

- Maximum stack size
- Real-time function execution
- Code size
- RAM usage
- Cyclomatic complexity
- Development time

## Assess the Results

Once the implementation is under way, developers can continually monitor their
progress and assess where they are at in relation to getting the desired results. Having
good metrics is key to being able to assess the results appropriately. Once the results
have been achieved, developers can move back to the Identify step to determine what
their next focus point will be to improve the reusability of their firmware.

## Recognizing Design Patterns

