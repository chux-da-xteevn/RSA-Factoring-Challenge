def factorize(n):
    for i in range(2, n):
        if n % i == 0:
            return i, n // i
    return None

def main(file_path):
    with open(file_path, 'r') as file:
        for line in file:
            number = int(line.strip())
            factors = factorize(number)
            if factors:
                print(f'{number}={factors[0]}*{factors[1]}')

if __name__ == "__main__":
    import sys

    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        sys.exit(1)

    file_path = sys.argv[1]
    main(file_path)

