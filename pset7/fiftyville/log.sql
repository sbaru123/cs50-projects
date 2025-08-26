-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description FROM crime_scene_reports WHERE month = 7 AND day = 28 AND street = 'Humphrey Street';
--10:15 am at bakery robbery intervies with 3 people

SELECT name, transcript FROM interviews WHERE month = 7 AND day = 28 AND year = 2024;
--Raymond says thief took earliest flight out of fiftyville tomorrow: 7/29/2024. Person bought the ticket around this time
--Eugune saw thief withdrawing money early in the morning.
--Ruth within 10 minutes of the theft, thief got into car and drove away
--As thief was leaveing bakery between 10:15 to 10:25, they called someone for less then a minute

SELECT id, origin_airport_id, destination_airport_id FROM flights WHERE month = 7 AND day = 29 AND year = 2024 ORDER BY hour;
--Earliest flight id is 36, time is 8:20 am, destination id is 4, LaGuardia Airport, NYC.


SELECT abbreviation, full_name, city FROM airports WHERE id = 4;
--Checking airport

SELECT account_number, atm_location, transaction_type FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2024 AND transaction_type = 'withdraw' AND atm_location = 'Humphrey Lane';
--Getting info for atm transaction


SELECT name FROM people WHERE id IN
(SELECT person_id FROM bank_accounts WHERE account_number IN
(SELECT account_number FROM atm_transactions WHERE month = 7 AND day = 28 AND year = 2024 AND transaction_type = 'withdraw' AND atm_location = 'Leggett Street'))
ORDER BY name;
--Names of all accounts that withdrew money at that day on Humphrey Lane


SELECT name FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE month = 7 AND day = 28 AND year = 2024 AND hour = 10 AND minute >= 15 AND minute <= 25 AND activity = 'exit')
ORDER BY name;
--Name of people within 10 minutes who were there at the robbery
--Bruce, Iman, and Luca matches both lists where they left from bakery in this 10 minute time frame


SELECT name FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id = 36)
ORDER BY name;
--Bruce and Luca were on the earliest flight.

SELECT name FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2024 AND duration < 60)
--Callers: Bruce

SELECT name FROM people WHERE phone_number IN
(SELECT receiver FROM phone_calls WHERE month = 7 AND day = 28 AND year = 2024 AND duration < 60)
--Recievers: Robin

SELECT
(SELECT account_number FROM bank_accounts WHERE person_id IN
(SELECT id FROM people WHERE name = 'Bruce');
