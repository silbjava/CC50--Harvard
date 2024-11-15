from cs50 import get_float

def main():
    while True:
        change = get_float("Change owed: ")
        if change >= 0:
            break

    # Convertendo para centavos e arredondando para cima para evitar problemas de precisão
    cents = round(change * 100)

    coins = 0
    for coin in [25, 10, 5, 1]:
        coins += cents // coin
        cents %= coin

    print(coins)


if __name__ == "__main__":
    main()
