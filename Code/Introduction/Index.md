## **Effective programmers tests**
## #EncoraHackingHouse
------------------------------------------
## **Should a programmer tests?**

* Testing is not only responsability of QA
* Tesing is not something that somebody else does
* We (programmers) must take responsability
* We (programmers) must automate tests
  
## **Types of software testing**

* Unit tests
* integration tests
* End-to-end tests
* Acceptance testsperformance tests
* Smoke tests

## **Value of having tests**

* Tests help us catching mistakes
- Tests help us shape the design
    - When appliying Test Driven Development (TDD) 
    - When refactoring
* Tests hel us **avoid gold-plating** by being explicit about the actual behavior

## **Java testing tools**

* **Unit tests:** JUnit, TestNG, EasyMock, Mockito, Spock
* **Integration tests:** DBUnit
* **End-to-end tests:** Selenium webdriver, Selenide, Geb, Cucumber
* **Perfomance tests:** Apache Jmeter
* **Supporting tools:** AssertJ, Hamcrest, Liquidbase, Flyway, Testcontainers

## **Concept and patterns**

### Asertions: How do you know tests work correctly?
write code that automate your asertions

## Test doubles
Generic term for any case you replace the production object with a test-object

- **Dummy**: passed around, not really used. To fill parameter lists
- **Fake:** working implementations but tanking shortcuts. For example, InMemoryTestDatabase
- **Stubs:** provide canned answers for the test, not responding to everything outside the test
- **Spies:** Stubs to record information to be verified later (in asserts)
- **Mocks:** Pre-programmed with expectations. They can throw.
- **Exceptions:** when call is unexpected, or the number of unexpected calls is different.

## AAA pattern

The AAA Pattern (3A Pattern) suggest to split each test into 3 parts:

- Arrange
- Act
- Assert

## Test Fixture

- Code that is run to configure the system under test
- Test data that needs to be set up as a precondition before a test is run
- Often this means populating the database with some information

## **Test readability**

## Primitive assertions
- Assertions should express an assumption or intent
- Primitive assertions hidden the intent behind some meaningless words or numbers

``` JAVA
assertTrue(out.index("Text im looking for) != -1);
/*
Expected: true
Actual: False
*/
```

## Hyperassertions
- Too scrupulous to become brittle and hides intent
- Overwhelming! Checking too many things
- Fragile, breaking frequentrly 

## Split logic
- Nobody likes long methods
- Use "Chunking" to improve redability
  - Cognitive phychology


## **Test maintability**

- Duplication
- Conditional logic
- Flaky Tests
- Crippling file path
- Persistent tem files
  - Temporary file should be temporary
  - Delete resources tests
- Sleeping snail
- Parameterized tests 
- Never-failing tests
- Conditional tests

## **Simple guidelines for testable design**

- Avoid complex private mehtods
- Avoid final methods
- Avoid statics methods
- Use 'new' with care
- Avoid logic in contructors
- Avoid singleton
- Favor compositing over inheritance
- Wrap external libraries
- Avoid service lookups
- Favor dependency injection

## **Books**
Test infected, Effective Unit Testing, Growing-oriented Software Guide by tests, test-driven development by exa,ple, Unit testing principles.