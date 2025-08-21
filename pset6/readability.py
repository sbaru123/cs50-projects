from cs50 import get_string


def main():
    text = get_string("Text: ")

    words = countWords(text)
    letters = countLetters(text)
    sentences = countSentences(text)

    S = round(((sentences / words) * 100), 2)
    L = round(((letters / words) * 100), 2)

    gradeLevel = (0.0588 * L) - (0.296 * S) - 15.8
    gradeLevel = int(round(gradeLevel, 0))

    if gradeLevel < 1:
        print("Before Grade 1")
    elif gradeLevel > 16:
        print("Grade 16+")
    else:
        print("Grade", gradeLevel)


def countSentences(text):
    sentCount = 0
    for char in text:
        if char == "." or char == "?" or char == "!":
            sentCount += 1

    return sentCount


def countWords(text):
    wordCount = 0
    for i, char in enumerate(text):
        if char.isspace():
            wordCount += 1
        elif i+1 == len(text):
            wordCount += 1

    return wordCount


def countLetters(text):
    letters = [char for char in text if char.isalpha()]
    return len(letters)


main()
