import timeit
import math


def calc_primes(n):
    primes = [True] * (n + 1)
    primes[0] = primes[1] = False
    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    prime_list = [i for i, is_prime in enumerate(primes) if is_prime]
    return prime_list


def disasterCode():
    max_value = 2500
    max_prime_check = int(math.sqrt(max_value))
    primes = calc_primes(max_prime_check)
    prime_set = set(primes)

    uniquePrimes = []

    for i in range(2, max_value):
        if i in prime_set:
            uniquePrimes.append(i)
            continue

        currentPrime = i
        for prime in primes:
            if prime > max_prime_check or prime > i:
                break
            if currentPrime % prime == 0:
                uniquePrimes.append(prime)
                while currentPrime % prime == 0:
                    currentPrime //= prime

        if currentPrime > 1:
            uniquePrimes.append(currentPrime)


# Benchmark the code
if __name__ == "__main__":
    benchmark_code = "disasterCode()"
    setup_code = "from __main__ import disasterCode"

    # Measure the execution time of disasterCode function
    times = []
    for i in range(0, 5):
        times.append(timeit.timeit(benchmark_code, setup=setup_code, number=1))

    res = sum(times)/5

    print(f"Average execution time after 5 runs: {res:.6f} seconds")
