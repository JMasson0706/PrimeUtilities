# SieveOfEratosthenes
An ancient algorithm to calculate prime numbers

This algorithm, first referenced in Nicomachus of Gerasa's *Introduction to Arithmetic*, is a simple method of enumerating all prime numbers up to a certain value. It does this by effectively "crossing out" all multiples of numbers 1 to n/2 - after, any non "crossed-out" values are prime.

This algorithm iterates from 1 to n/2, and for each iteration iterates until n. Therefore, it runs in O(n^2) time.
