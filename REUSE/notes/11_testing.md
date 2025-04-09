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

