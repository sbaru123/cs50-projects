from cs50 import get_string

def main():
    text = get_string("Text: ")

    words = countWords(text)
    letters = countLetters(text)
    sentences = countSentences(text)

    print(words)
    print(letters)

def countSentences(text):
    sentCount = 0
    for char in text:
        if char == "." or char == "?" or char == "!":
            sentCount += 1

    return sentCount


def countWords(text):
    wordCount = 0
    for char in enumerate(text):
        if char.isspace():
                wordCount += 1

    return wordCount


def countLetters(text):
    letters = [char for char in text if char.isalpha()]
    return len(letters)

main()
