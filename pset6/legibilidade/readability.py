def calculate_reading_level(text):
    """Calculates the reading level of a given text.

    Args:
        text (str): The text to analyze.

    Returns:
        int: The estimated reading level.
    """

    letters = 0
    words = 1  # Assuming at least one word
    sentences = 0

    for char in text:
        if char.isalpha():
            letters += 1
        elif char in '.!?':
            sentences += 1
        elif char.isspace():
            words += 1

    L = 100 * letters / words
    S = 100 * sentences / words
    index = round(0.0588 * L - 0.296 * S - 15.8)

    if index < 1:
        return "Before Grade 1"
    elif index >= 16:
        return "Grade 16+"
    else:
        return f"Grade {index}"

if __name__ == "__main__":
    text = input("Text: ")
    reading_level = calculate_reading_level(text)
    print(reading_level)
