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
