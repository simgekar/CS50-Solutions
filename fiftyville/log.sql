-- Keep a log of any SQL queries you execute as you solve the mystery.
--output.txt
--SELECT * FROM crime_scene_reports WHERE street = 'Humphrey Street' AND year = 2021 AND day = 28;
--reviews.txt
--SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
--bakery_security_logs.txt
SELECT * FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND 15 < minute AND minute <25;
--atm.txt
--SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2021;
--phone_call.txt
--SELECT * FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021  AND duration <60;
--flights.txt
--SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29;

SELECT * FROM people WHERE license_plate IN
(SELECT license_plate FROM bakery_security_logs WHERE year = 2021 AND month = 7 AND day = 28 AND hour = 10 AND 15 < minute AND minute <25);
Bruce, Diana

SELECT * FROM people WHERE phone_number IN
(SELECT caller FROM phone_calls WHERE day = 28 AND month = 7 AND year = 2021  AND duration <60);

Sofia,Taylor,Diana,Kelsey,Bruce

SELECT * FROM people WHERE id IN(SELECT person_id FROM bank_accounts WHERE account_number IN (SELECT account_number FROM atm_transactions
WHERE atm_location = 'Leggett Street' AND day = 28 AND month = 7 AND year = 2021));
Taylor,Diana,Bruce

SELECT * FROM people WHERE passport_number IN
(SELECT passport_number FROM passengers WHERE flight_id IN (SELECT id FROM flights WHERE year = 2021 AND month = 7 AND day = 29));
Taylor, Diana, Bruce

diana passport 3592750733 license 322W7JE phonenumber (770) 555-1861
bruce passport 5773159633 license 94KL13X phonenumber (367) 555-5533

flight_id 36 plane goes from 8 to 4
SELECT * FROM passengers WHERE flight_id =36;
Bruce
SELECT * FROM people WHERE phone_number='(375) 555-8161';
Robin

SELECT * FROM airports WHERE id = 4;
LGA LaGuardia New York City
















