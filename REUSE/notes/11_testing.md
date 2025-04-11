# 11. Testing

Testing an embedded system is critical to ensure that it not only meets requirements but
also has a minimum bug count. Developers can rarely prove that their application has
no bugs in it, but they can develop extensive test cases that minimize the chances that a
bug is hiding in their application. Testing strategies can vary from manual system-level
testing to sophisticated automated tests that are performed on a continuous-integration
server and reported on a nightly basis.

**Regression testing:** is the ability to automatically run test cases that were previously
executed to verify that they still pass after the software has been modified.

In order to have a consistent test strategy, developers need two key features in their
tests: automation and regression. Automated tests are necessary because there is no way
that a developer or a team can dedicate the time and effort necessary to manually check
that every line of code is executed and behaves as expected. The only way to perform
these checks is to automate testing so that it can be executed without human interaction.

- Unit tests
- Functional tests
- Regression tests
- Integration tests

## Unit Testing

Unit testing is a software-development process in which the
smallest testable parts of an application are individually and independently scrutinized
for proper operation. For firmware engineers, a unit is an individual function. As
engineers develop their functions, they should also be developing test cases that will
validate the functions work as expected.

Unit tests can be performed manually, but they are far more effective if they can be
automated. Running any test case manually is a very time-consuming process. Always
try to find a way to automate the process. I don’t enjoy spending my time testing or
debugging, so the more automated these processes are, the better!

## Taking Advantage of Cyclomatic Complexity for Unit Testing

Cyclomatic complexity can be used to minimize function
complexity. The cyclomatic complexity measurement results in a finite number that is
assigned to a function and sets the reliability risk for bugs and testing.

| Complexity | Reliability Risk |
| --- | --- |
| 1 - 10 |A simple function, little risk |
| 11 - 20 | More complex, moderate risk |
| 21 - 50 | Complex, high risk |
| 51+ | Untestable, very high risk |

The second benefit that developers can leverage from the cyclomatic complexity
measurement is that it provides a value for the minimum number of test cases that need
to be defined and executed in order to fully test a function. This is because cyclomatic
complexity measures the number of linearly independent paths through the function.
A linearly independent path is any path through a program that introduces at least one
new edge that is not included in any other linearly independent path.

## Standard Interface... Standard Tests

The nice thing about reusable software is that once unit tests are developed for the HALs
and the APIs, the tests can also be reused. A carefully crafted HAL becomes a standard
interface that is used from one application to the next. That standard interface will
then have standard tests associated with it that can always be run to make sure that any
ported or reused code still behaves the way it is expected to on the new system.

## Functional Testing

Functional testing is a testing process that is used to verify that the software conforms
with all its requirements.8 In most instances, it’s a testing method that is used to verify
that the business needs or the end-user needs are being met. Functional testing is
most often executed at the application level to verify that the end users’ inputs provide
expected outputs.

When the developer who designed the system gets involved in creating the tests, the
testing is known as white-box testing. Since the developer has intricate knowledge of the
inner workings of the device, they can devise tests that not only verify the inputs/outputs
for the system but also test corner cases and specific internal actions.

### Test-Driven Development

In James Grenning’s book Test-Driven Development for Embedded C, he defines test-­
driven development as “a technique for building software incrementally where no
production code is written without first writing a failing unit test.”

The idea behind
TDD is that a developer first writes their test case, makes it fail, and then writes the code
necessary to make the test case pass. Once the test case passes, they write another test
case that fails, and then they write the code that resolves that test case. It then continues
in this manner until the entire software is completed.

## Hardware In-Loop Testing

Hardware in-loop (HIL) testing runs the test case code on the target microcontroller
rather than using a mocked software layer to act as the hardware. HIL testing can
be extremely useful for verifying that hardware accesses from a HAL are working
as expected and even for testing that all outputs from the system work as expected.

The debugger is used by the
test controller to load applications and test code onto the target microcontroller, and
also to control those tests through the debugger communications port. Most modern
debuggers act as a virtual communication port, and with minimal software a developer
can create a test command-control channel to manage the microcontroller. The
controller can request telemetry, register values, and even monitor the software trace
and event history.

A developer will normally have a communication channel via which to talk with
the product. For example, if the product is an automotive product, there may be CAN
messages that the product responds to that need to be tested. Another example would be a
device that has a COMM port.

Developers may also find that their system requires an analog or digital input or that
their system outputs an analog or digital signal. In these cases, using an ADC or DAC will
give the test harness access to these signals so that they can be recorded while executing
the test cases.

### Regression Testing

Developers who are creating reusable software absolutely need to make sure that
they can perform regression tests in a timely and automated manner. According to
Wikipedia, regression testing is “a type of software testing which verifies that software
which was previously developed and tested still performs the same way after it was
changed.”

The idea behind regression testing is that there is a test set that exists that can
be rerun on the system periodically to ensure that all the tests are still able to pass. If
regression testing is run often, any tests that fail should be easily traceable to the code
that changed and is causing the issue.

### Automating Tests

Any team or developer that is creating reusable software should be creating automated
tests. Even the simplest embedded system could require a hundred or more test cases to
ensure that the software behaves as expected. Attempting to manually run through these
tests will consume a lot of time and could be prone to errors. Therefore, automating test
cases is really the best solution for developers.

There are several example C/C++ test harnesses that developers can leverage, such
as Unity or Cpputest. Both C/C++ test harnesses are open source and can be found by
searching for them in your favorite web browser. The advantages to using a C/C++ test
harness is that

- they are open source;
- developers already know C/C++; and
- they can be used to create automated tests.

There are several disadvantages as well, including the following:

- Being open source, there is limited support to get them up and
running.

Python is an easy-to-learn
scripting language that is very powerful. It also includes libraries specifically designed to
perform testing.
The direction that any team chooses to go will be highly dependent on their skillsets
and their end requirements. It may also depend on when their products are due and how
much time and budget they have allocated for testing.

## Using Trace to Verify Application Software

A developer runs a small and efficient event-recording library that can
communicate with the debugging probe to store the event data on a host PC. The sample
rate for the event data will depend on the throughput to the PC along with the buffer
size given to the event-recording library. The larger the buffer, the more event data that
can be stored locally before it needs to be transmitted upstream. Even on resource-­
constrained microcontrollers, the event-tracing library uses no more than 1 percent of
the CPU and usually has a few kilobytes of RAM allocated to it.

## Modern Example: The Renesas Synergy

The Renesas Synergy Platform provides a wide range of microcontrollers, from
low-power microcontrollers with an ARM Cortex-M0+ cores all the way through to
high-performance ARM Cortex-M4 cores. Rather than expecting its customers to write
their own drivers, middleware, and application code, Renesas has built into its platform
an entire software framework that provides these components in a configurable and
portable manner across the entire microcontroller family! What is so surprising is that
Renesas doesn’t just supply example code but has also gone through a rigorous software-­
development cycle that has strict quality-assurance requirements that include many of
the testing methodologies that we have been discussing in this chapter.