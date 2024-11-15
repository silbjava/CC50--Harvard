from cs50 import get_int

def luhn_checksum(number):
    """Calculates the Luhn checksum for a given number."""
    digits = [int(digit) for digit in str(number)]
    digits = digits[::-1]  # Reverse the digits

    # Double every other digit, starting from the second to last
    for i in range(0, len(digits), 2):
        digits[i] *= 2
        if digits[i] > 9:
            digits[i] -= 9

    # Sum all digits
    checksum = sum(digits)

    return checksum % 10 == 0

def is_valid_card(number):
    """Checks if the card number is valid based on Luhn algorithm and prefix."""
    if not luhn_checksum(number):
        return False

    # Check prefixes based on card type
    if 51 <= number // 10**14 <= 55 or 22 <= number // 10**15 <= 27:  # MasterCard
        return True
    elif number // 10**15 == 4:  # Visa
        return True
    elif number // 10**14 == 34 or number // 10**14 == 37:  # American Express
        return True
    else:
        return False

def main():
    card_number = get_int("Number: ")

    if is_valid_card(card_number):
        if 51 <= card_number // 10**14 <= 55 or 22 <= card_number // 10**15 <= 27:
            print("MASTERCARD")
        elif number // 10**15 == 4:
            print("VISA")
        elif number // 10**14 == 34 or number // 10**14 == 37:
            print("AMEX")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()
