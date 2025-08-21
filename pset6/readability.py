from cs50 import get_string

def main():
    text = get_string("Text: ")

    words = countWords(text)
    letters = countLetters(text)
    sentences = countSentences(text)

    print(words)
    print(letters)
    print(sentences)

    S = round(((sentences / words) * 100) , 2)
    L = round(((letters / words) * 100) , 2)

    print(S)
    print(L)

    gradeLevel = (0.0588 * L) - (0.296 * S) - 15.8

    print(gradeLevel)

def countSentences(text):
    sentCount = 0
    for char in text:
        if char == "." or char == "?" or char == "!":
            sentCount += 1

    return sentCount


def countWords(text):
    wordCount = 0
    for char in text:
        if char.isspace():
                wordCount += 1

    return wordCount


def countLetters(text):
    letters = [char for char in text if char.isalpha()]
    return len(letters)

main()
