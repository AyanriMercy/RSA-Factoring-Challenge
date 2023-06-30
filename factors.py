#!/usr/bin/python3

import sys

def factorize_number(n):
    factors = []
    i = 2
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            factors.append(i)
    if n > 1:
        factors.append(n)
    return factors

def factorize_file(file_path):
    with open(file_path, 'r') as file:
        n = int(line.strip())
        factors = factorize_number(n)
        if len(factors) == 1:
            print(f'{n}={factors[0]}*{factors[0]}')
        else:
            p = factors[0]
            q = factors[1]
            print(f'{n}={p}*{q}')

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Usage: factors <file>')
        sys.exit(1)
    file_path = sys.argv[1]
    factorize_file(file_path)
